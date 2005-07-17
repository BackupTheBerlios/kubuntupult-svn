/***************************************************************************
 *   Copyright (C) 2005 by Joe Ferris                                      *
 *   jferris@optimistictech.com                                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <kiconloader.h>
#include <kglobal.h>
#include <kwin.h>
#include <kkeydialog.h>
#include <kaction.h>
#include <kparts/componentfactory.h>
#include <kpopupmenu.h>
#include <klocale.h>
#include <kaboutapplication.h>

#include <qpopupmenu.h>
#include <qmenudata.h>

#include "katapult.h"
#include "actioncatalog.h"
#include "katapultcatalog.h"
#include "katapultdisplay.h"
#include "katapultsettings.h"

Katapult::Katapult()
	: KSystemTray(0, "katapultSysTray")
{

	setPixmap(loadIcon("katapult"));

	display = 0;
	globalAccel = 0;
	actions = 0;
	
	settings = new KatapultSettings();

	loadCatalogPlugins();
	initDisplay();
	
	hideTimer = new QTimer(this);
	connect(hideTimer, SIGNAL(timeout()), this, SLOT(hideLauncher()));
	clearTimer = new QTimer(this);
	connect(clearTimer, SIGNAL(timeout()), this, SLOT(clearQuery()));
	
	connect(settings, SIGNAL(catalogsChanged()), this, SLOT(loadCatalogPlugins()));
	connect(settings, SIGNAL(displayChanged()), this, SLOT(initDisplay()));
	
	show();
}

Katapult::~Katapult()
{
	if(globalAccel != 0)
		delete globalAccel;
	if(actions != 0)
		delete actions;
	delete settings;
}

void Katapult::loadCatalogPlugins()
{
	catalogs = settings->activeCatalogs();
}

void Katapult::initDisplay()
{
	display = settings->display();
	if(display == 0) {
		initAccel(this);
	} else {
		initAccel(display);
		setQuery("");
		connect(display, SIGNAL(keyReleased(QKeyEvent *)), this, SLOT(keyReleased(QKeyEvent *)));
		connect(display, SIGNAL(focusOut()), this, SLOT(hideLauncher()));
	}
}

void Katapult::initAccel(QWidget *parent)
{
	globalAccel = new KGlobalAccel(parent);
	globalAccel->insert("show_katapult", i18n("Show Launcher"), i18n("Shows the Katapult launcher"), ALT+Key_Space, ALT+Key_Space,
		this, SLOT(showLauncher()));
	globalAccel->readSettings();
	globalAccel->updateConnections();
	
	actions = new KActionCollection(parent);
	actionCollection()->clear();
	
	contextMenu()->clear();
	
	new KAction(i18n("Select Item"), "button_ok", Key_Return, this, SLOT(execute()), actions, "execute");
	new KAction(i18n("Close"), "fileclose", Key_Escape, this, SLOT(hideLauncher()), actions, "close");
	new KAction(i18n("Clear Query / Back"), "back", Key_Left, this, SLOT(clearOrBack()), actions, "clear_or_back");
	new KAction(i18n("Complete Query"), "forward", Key_Right, this, SLOT(completeQuery()), actions, "complete_query");
	new KAction(i18n("Previous Item / Hide Mutiple Results"), "up", Key_Up, this, SLOT(previous()), actions, "previous");
	new KAction(i18n("Next Item / Show Multiple Results"), "down", Key_Down, this, SLOT(next()), actions, "next");
	new KAction(i18n("Select Action"), "run", Key_Tab, this, SLOT(selectAction()), actions, "select_action");
	
	(new KAction(i18n("Refresh Catalogs"), "reload", Key_F5, settings, SLOT(refreshCatalogs()), actions, "refresh_catalogs"))->plug((QWidget *) contextMenu());
	contextMenu()->insertSeparator();
	
	KAction *actGlobAccel = KStdAction::keyBindings(this, SLOT(showGlobalShortcutsDialog()), actions);
	actGlobAccel->setText(i18n("Configure &Global Shortcuts..."));
	actGlobAccel->plug((QWidget *) contextMenu());
	
	KStdAction::keyBindings(this, SLOT(showShortcutsDialog()), actions)->plug((QWidget *) contextMenu());
	KStdAction::preferences(settings, SLOT(configure()), actions)->plug((QWidget *) contextMenu());
	
	contextMenu()->insertSeparator();
	KStdAction::aboutApp(this, SLOT(showAboutDialog()), actions)->plug((QWidget *) contextMenu());
	contextMenu()->insertSeparator();
	
	KStdAction::quit(this, SLOT(close()), actions)->plug((QWidget *) contextMenu());
	
	actions->readShortcutSettings();
}

void Katapult::completeQuery()
{
	if(matches.count() > selected) {
		Match match = *matches.at(selected);
		QString newQuery = match.item()->text();
		clearQuery();
		setQuery(newQuery);
	}
}

void Katapult::clearQuery()
{
	if(hideTimer->isActive())
		hideTimer->stop();
	if(clearTimer->isActive())
		clearTimer->stop();
	executing = FALSE;
	selected = 0;
	display->setSelected(0);
	if(selecting != SelectAction) {
		multi = FALSE;
		display->setMulti(FALSE);
	}
	setQuery("");
}

void Katapult::clearOrBack()
{
	if(_query == "") {
		selecting = SelectItem;
		clearQuery();
	} else {
		clearQuery();
	}
}

void Katapult::setQuery(QString _query)
{
	int allStatus=0;
	matches.clear();
		
	this->_query = _query;
	if(display != 0)
		display->setQuery(_query);
		
	if(selecting == SelectAction) {
		ActionCatalog::self()->setQuery(_query);
		allStatus = ActionCatalog::self()->status();
		if(allStatus & S_HasResults)
			ActionCatalog::self()->addMatches(matches, settings->maxResults(), 0);
	} else {
		if(_query == "") {
			QDictIterator<KatapultCatalog> it(catalogs);
			KatapultCatalog *catalog;
			while((catalog = it.current()) != 0)
			{
				++it;
				catalog->setQuery("");
			}
			if(selecting == SelectItem)
				item = Match();
			else
				indirectItem = Match();
		} else if(catalogs.count() == 0) {
			allStatus = S_Active | S_NoResults;
		} else {
			QDictIterator<KatapultCatalog> it(catalogs);
			KatapultCatalog *catalog;
			int status;
			
			while((catalog = it.current()) != 0)
			{
				++it;
				catalog->setQuery(_query);
					
				status = catalog->status();
				if(status & S_HasResults)
				{
					if(allStatus & S_HasResults)
						allStatus |= S_Multiple;
					const KatapultAction *actionInstance;
					if(_autoSelectAction)
						actionInstance = 0;
					else
						actionInstance = (const KatapultAction *) action.item();
					catalog->addMatches(matches, settings->maxResults(), actionInstance);
				}
				allStatus |= status;
			}
		}
	}
	
	if(!(allStatus & S_HasResults) && allStatus & S_Active) {
		// no results
		switch(settings->noResultsAction()) {
		case KatapultSettings::NR_HideDisplay:
			hideTimer->start(settings->noResultsDelay(), TRUE);
			break;
		case KatapultSettings::NR_ClearQuery:
			clearTimer->start(settings->noResultsDelay(), TRUE);
			break;
		default:
			break;
		}
	}
	
	if(!action.isNull()) {
		allStatus |= S_Active;
	}
		
	display->setStatus(allStatus);
	selectMatch(0);
	
/*	if(display != 0)
	{
		
		switch(selecting) {
		case SelectItem:
			display->setItems(matches);
			if(matches.count() > 0) {
				Match match = matches.first();
				autoSelectAction();
			}
			break;
		case SelectAction:
			display->setActions(matches);
			if(matches.count() > 0)
				action = matches.first();
			break;
		case SelectIndirectItem:
			display->setIndirectItems(matches);
			if(matches.count() > 0)
				indirectItem = matches.first();
			break;
		}
		
		display->update();
	}*/
	
	/*if(!executing && settings->isAutoExecute() && allStatus & S_HasResults && !(allStatus & S_Multiple))
		execute();*/
}

void Katapult::showAboutDialog()
{
	KAboutApplication *aboutDialog = new KAboutApplication(this);
	aboutDialog->exec();
	delete aboutDialog;
}

void Katapult::showLauncher()
{
	if(!settings->isConfiguring() && display != 0)
	{
		selecting = SelectItem;
		item = Match();
		action = Match();
		indirectItem = Match();
		QValueList<Match> empty;
		display->setItems(empty);
		display->setActions(empty);
		display->setIndirectItems(empty);
		clearQuery();
		_autoSelectAction = TRUE;
		display->setSelecting(selecting);
		display->show();
		display->update();
		KWin::forceActiveWindow(display->winId());
	}
}

void Katapult::hideLauncher()
{
	if(display != 0)
		display->hide();
	setQuery("");
}

void Katapult::showShortcutsDialog()
{
	KKeyDialog::configure(actions);
}

void Katapult::showGlobalShortcutsDialog()
{
	KKeyDialog::configure(globalAccel);
}

void Katapult::autoSelectAction()
{
	if(_autoSelectAction && selecting == SelectItem) {
		QValueList<Match> actionMatches;
		KatapultAction * actionInstance = 0;
		if(!item.isNull())
			actionInstance = ActionCatalog::self()->defaultAction(item.item());
		if(actionInstance == 0) {
			action = Match();
		} else {
			action = Match(actionInstance, 100, 0);
		}
		actionMatches.append(action);
		display->setActions(actionMatches);
	}
}

void Katapult::execute()
{
	switch(selecting) {
	case SelectItem:
		executing = TRUE;
		if(!item.isNull() && !action.isNull()) {
			completeQuery();
			const KatapultAction *actionInstance = (const KatapultAction *) action.item();
			actionInstance->execute(item.item());
			hideTimer->start(settings->hideDelay(), TRUE);
		}
		break;
	case SelectAction:
		if(!action.isNull()) {
			selecting = SelectItem;
			if(item.isNull()) {
				QValueList<Match> actionList;
				actionList.append(action);
				display->setActions(actionList);
				clearQuery();
			} else {
				QValueList<Match> itemList;
				itemList.append(item);
				matches = itemList;
				execute();
			}
		}
		break;
	case SelectIndirectItem:
		break;
	}
}

void Katapult::selectAction()
{
	if(selecting == SelectItem) {
		_autoSelectAction = FALSE;
		selecting = SelectAction;
		if(item.isNull()) {
			ActionCatalog::self()->setAccepts(Match());
		} else {
			QValueList<Match> itemMatches;
			itemMatches.append(item);
			display->setItems(itemMatches);
			ActionCatalog::self()->setAccepts(item);
		}
		clearQuery();
		multi = TRUE;
		display->setMulti(TRUE);
		selectMatch(0);
	} else if(selecting == SelectAction) {
		completeQuery();
		selecting = SelectItem;
		clearQuery();
	}
}

void Katapult::keyReleased(QKeyEvent *e)
{
	if(!executing) {
		if(e->key() == Key_BackSpace) {
			if(hideTimer->isActive())
				hideTimer->stop();
			if(clearTimer->isActive())
				clearTimer->stop();
			QString newQuery = _query.left(_query.length()-1);
			setQuery("");
			setQuery(newQuery);
		} else {
			char c;
			if((c = e->ascii()) >= 32)
				setQuery(_query + c);
		}
	}
}

void Katapult::mousePressEvent(QMouseEvent *e)
{
	if(e->button() == LeftButton)
		showLauncher();
	else
		KSystemTray::mousePressEvent(e);
}

void Katapult::selectMatch(unsigned int matchNo)
{
	Match match;
	if(matchNo < matches.count()) {
		selected = matchNo;
		match = *matches.at(selected);
	} else {
		selected = 0;
		match = Match();
	}
		
	display->setSelected(selected);
	switch(selecting) {
	case SelectItem:
		item = match;
		display->setItems(matches);
		autoSelectAction();
		break;
	case SelectAction:
		action = match;
		display->setActions(matches);
		break;
	case SelectIndirectItem:
		indirectItem = match;
		display->setIndirectItems(matches);
	}
	
	display->update();
}

void Katapult::next()
{
	if(multi) {
		if(selected < matches.count() - 1)
			selectMatch(selected+1);
	} else {
		multi = TRUE;
		display->setMulti(TRUE);
		display->update();
	}
}

void Katapult::previous()
{
	if(multi) {
		if(selected > 0) {
			selectMatch(selected-1);
		} else {
			multi = FALSE;
			display->setMulti(FALSE);
			display->update();
		}
	}
}

#include "katapult.moc"

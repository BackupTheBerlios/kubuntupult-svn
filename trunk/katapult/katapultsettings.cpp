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

#include <kapplication.h>
#include <kconfig.h>
#include <kparts/componentfactory.h>

#include <qstring.h>
#include <qstringlist.h>
 
#include "katapultsettings.h"
#include "katapultcatalog.h"
#include "katapultconfigdlg.h"
#include "katapultdisplay.h"
#include "actionregistry.h"

KatapultSettings::KatapultSettings()
{
	readSettings();
	_isConfiguring = FALSE;
	_activeCatalogs.setAutoDelete(TRUE);
	_display = 0;
	
	loadCatalogPlugins();
	loadDisplayPlugins();
}


KatapultSettings::~KatapultSettings()
{
	if(_display != 0)
		delete _display;
}

void KatapultSettings::readSettings()
{
	KConfig *config = kapp->config();
	_hideDelay = config->readUnsignedNumEntry("HideDelay", 1000);
	_noResultsDelay = config->readUnsignedNumEntry("NoResultsDelay", 2500);
	_noResultsAction = (NRAction) config->readUnsignedNumEntry("NoResultsAction", NR_ClearQuery);
	_autoExec = config->readBoolEntry("AutoExec", TRUE);
	_displayName = config->readEntry("Display", "Glass Display");
	
	QStringList defCatalogs;
	defCatalogs << "Program Catalog" << "Bookmark Catalog" << "Document Catalog";
	_activeCatalogNames = config->readListEntry("Catalogs", defCatalogs);
}

void KatapultSettings::writeSettings()
{
	KConfig *config = kapp->config();
	config->writeEntry("HideDelay", _hideDelay);
	config->writeEntry("NoResultsDelay", _noResultsDelay);
	config->writeEntry("NoResultsAction", (int) _noResultsAction);
	config->writeEntry("AutoExec", _autoExec);
	config->writeEntry("Catalogs", _activeCatalogNames);
	config->writeEntry("Display", _displayName);

	QDictIterator<KatapultCatalog> it(_activeCatalogs);
	KatapultCatalog *catalog;
	while((catalog = it.current()) != 0)
	{
		KConfigGroup group(config, QString("Catalogs/%1").arg(it.currentKey()));
		catalog->writeSettings(&group);
		++it;
	}
	
	if(_display != 0)
	{
		KConfigGroup group(config, QString("Displays/%1").arg(_displayName));
		_display->writeSettings(&group);
	}

	config->sync();
}

void KatapultSettings::configure()
{
	if(!_isConfiguring)
	{
		_isConfiguring = TRUE;
		
		KatapultConfigDlg *dlg = new KatapultConfigDlg(this);
		if(dlg->exec() == QDialog::Accepted) {
			writeSettings();
			loadCatalogPlugins();
			emit catalogsChanged();
		} else {
			readSettings();
			loadCatalogPlugins();
			loadDisplayPlugins();
			emit catalogsChanged();
			emit displayChanged();
		}
		delete dlg;
		
		_isConfiguring = FALSE;
	}
}

bool KatapultSettings::isConfiguring() const
{
	return _isConfiguring;
}

bool KatapultSettings::isAutoExecute() const
{
	return _autoExec;
}

void KatapultSettings::setAutoExecute(bool _autoExec)
{
	this->_autoExec = _autoExec;
}

int KatapultSettings::hideDelay() const
{
	return _hideDelay;
}

void KatapultSettings::setHideDelay(int _hideDelay)
{
	this->_hideDelay = _hideDelay;
}

int KatapultSettings::noResultsDelay() const
{
	return _noResultsDelay;
}

void KatapultSettings::setNoResultsDelay(int _noResultsDelay)
{
	this->_noResultsDelay = _noResultsDelay;
}

KatapultSettings::NRAction KatapultSettings::noResultsAction() const
{
	return _noResultsAction;
}

void KatapultSettings::setNoResultsAction(NRAction _noResultsAction)
{
	this->_noResultsAction = _noResultsAction;
}

QString KatapultSettings::displayName() const
{
	return _displayName;
}

QStringList KatapultSettings::displayNames() const
{
	return _displayNames;
}

KatapultDisplay * KatapultSettings::display() const
{
	return _display;
}

void KatapultSettings::setDisplayName(QString name)
{
	_displayName = name;
	loadDisplayPlugins();
	emit displayChanged();
}

QStringList KatapultSettings::catalogNames() const
{
	return _catalogNames;
}

QStringList KatapultSettings::activeCatalogNames() const
{
	return _activeCatalogNames;
}

QStringList KatapultSettings::inactiveCatalogNames() const
{
	QStringList inactiveCatalogs, catalogs = _catalogNames;
	for(QStringList::Iterator it = catalogs.begin(); it != catalogs.end(); ++it)
	{
		if(!_activeCatalogNames.contains(*it))
			inactiveCatalogs.append(*it);
	}
	return inactiveCatalogs;
}

QDict<KatapultCatalog> KatapultSettings::activeCatalogs() const
{
	return _activeCatalogs;
}

void KatapultSettings::activateCatalog(QString catalogName)
{
	_activeCatalogNames.append(catalogName);
	loadCatalogPlugins();
	emit catalogsChanged();
}

void KatapultSettings::deactivateCatalog(QString catalogName)
{
	_activeCatalogNames.remove(catalogName);
	loadCatalogPlugins();
	emit catalogsChanged();
}

void KatapultSettings::loadCatalogPlugins()
{
	_activeCatalogs.clear();
	_catalogNames.clear();
	ActionRegistry::self()->clear();

	KTrader::OfferList offers = KTrader::self()->query("Katapult/Catalog");
	KTrader::OfferList::ConstIterator it;
	for(it = offers.begin(); it != offers.end(); ++it)
	{
		KService::Ptr service = *it;
		KatapultCatalog *catalog;
		QString name = service->name();
		
		_catalogNames.append(name);
		
		if(_activeCatalogNames.contains(name))
		{
			int errCode = 0;
			catalog = KParts::ComponentFactory::createInstanceFromService<KatapultCatalog>
				(service, 0, 0, QStringList(), &errCode);
			if(catalog != 0)
			{
				KConfigGroup group(kapp->config(), QString("Catalogs/%1").arg(name));
				catalog->readSettings(&group);
				catalog->initialize();
				_activeCatalogs.insert(name, catalog);
			}
		}
	}
}

void KatapultSettings::loadDisplayPlugins()
{
	if(_display != 0)
	{
		delete _display;
		_display = 0;
	}
	
	_displayNames.clear();
	
	KTrader::OfferList offers = KTrader::self()->query("Katapult/Display");
	KTrader::OfferList::ConstIterator it;
	for(it = offers.begin(); it != offers.end(); ++it)
	{
		KService::Ptr service = *it;
		
		_displayNames.append(service->name());
		if(service->name() == _displayName)
		{
			int errCode = 0;
			_display = KParts::ComponentFactory::createInstanceFromService<KatapultDisplay>
				(service, 0, 0, QStringList(), &errCode);
		}
	}
	if(_display != 0)
	{
		KConfigGroup group(kapp->config(), QString("Displays/%1").arg(_displayName));
		_display->readSettings(&group);
	}
}

KatapultCatalog * KatapultSettings::catalog(QString catalogName) const
{
	return _activeCatalogs.find(catalogName);
}

#include "katapultsettings.moc"

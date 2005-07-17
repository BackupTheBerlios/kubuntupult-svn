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

#ifndef _KATAPULT_H_
#define _KATAPULT_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <ksystemtray.h>
#include <kglobalaccel.h>
#include <kactioncollection.h>

#include <qstring.h>
#include <qptrlist.h>
#include <qevent.h>
#include <qtimer.h>
#include <qdict.h>
#include <qvaluelist.h>

#include <match.h>

#include "katapultdisplay.h"
#include "katapultcatalog.h"
#include "katapultaction.h"
#include "status.h"

class KatapultSettings;

class Katapult : public KSystemTray
{
	Q_OBJECT
public:
	Katapult();
	~Katapult();
    
	void setQuery(QString);

public slots:
	void showLauncher();
	void hideLauncher();
	void completeQuery();
	void clearQuery();
	void clearOrBack();
	void showShortcutsDialog();
	void showGlobalShortcutsDialog();
	void showAboutDialog();
	void execute();
	void previous();
	void next();
	void selectAction();
	
	void loadCatalogPlugins();
	void initDisplay();
	
	virtual void keyReleased(QKeyEvent *);
	
protected:
	virtual void mousePressEvent(QMouseEvent *);
	
private:
	void initAccel(QWidget *);
	void selectMatch(unsigned int);
	void autoSelectAction();
	
	bool executing, _autoSelectAction;
	Selecting selecting;
	unsigned int selected;
	bool multi;
	
	KatapultDisplay *display;
	KatapultSettings *settings;
	QDict<KatapultCatalog> catalogs;
	
	KGlobalAccel *globalAccel;
	KActionCollection *actions;
	
	QValueList<Match> matches;
	Match item, action, indirectItem;
	
	QString _query;
	
	QTimer *hideTimer;
	QTimer *clearTimer;
};

#endif // _KATAPULT_H_

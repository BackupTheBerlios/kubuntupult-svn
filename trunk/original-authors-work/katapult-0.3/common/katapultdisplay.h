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
#ifndef KATAPULTDISPLAY_H
#define KATAPULTDISPLAY_H

#include <qwidget.h>
#include <qstring.h>
#include <qevent.h>
#include <qvaluelist.h>

#include "katapultitem.h"
#include "katapultaction.h"
#include "match.h"
#include "status.h"

class KConfigBase;

/**
@author Joe Ferris
*/
class KatapultDisplay : public QWidget
{
	Q_OBJECT

public:
	KatapultDisplay(const char *, WFlags);
	virtual ~KatapultDisplay();
	
	void setQuery(QString);
	void setItems(const QValueList<Match> &);
	void setActions(const QValueList<Match> &);
	void setIndirectItems(const QValueList<Match> &);
	void setSelecting(Selecting);
	void setStatus(int);
	void setMulti(bool);
	void setSelected(int);

	virtual void readSettings(KConfigBase *);
	virtual void writeSettings(KConfigBase *);
	virtual QWidget * configure();
	
signals:
	void keyReleased(QKeyEvent *);
	void focusOut();
	
protected:
	virtual void keyReleaseEvent(QKeyEvent *);
	virtual void focusOutEvent(QFocusEvent *);
	
	virtual int maxItemsAtOnce() const;
	
	QString query() const;
	int status() const;
	Selecting selecting() const;
	const QValueList<Match> & items() const;
	const QValueList<Match> & actions() const;
	const QValueList<Match> & indirectItems() const;
	bool multi() const;
	int selected() const;
	int firstItem() const;
	
private:
	QString _query;
	QValueList<Match> _items;
	QValueList<Match> _actions;
	QValueList<Match> _indirectItems;
	bool _multi;
	int _status, _selected, _firstItem;
	Selecting _selecting;
};

#endif

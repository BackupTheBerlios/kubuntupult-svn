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
#ifndef KATAPULTCATALOG_H
#define KATAPULTCATALOG_H

#include <qobject.h>

class Match;
class KConfigBase;
class KatapultItem;

/**
@author Joe Ferris
*/
class KatapultCatalog : public QObject {
	Q_OBJECT
public:
	virtual ~KatapultCatalog();
	
	virtual void initialize();
	virtual void readSettings(KConfigBase *);
	virtual void writeSettings(KConfigBase *);
	virtual QWidget * configure();

public slots:
	virtual void beginQuery(const QString &);
	virtual void continueQuery(const QString &);
	virtual void endQuery();
	
signals:
	void statusChanged(Status);
	void matchFound(Match);
	void matchChanged(const KatapultItem *, int);
	void matchRemoved(const KatapultItem *);
	
protected:
	Match queryItem(const KatapultItem *, QString) const;
	
};

#endif

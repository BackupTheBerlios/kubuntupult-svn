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

#include <qstringlist.h>
#include <qstring.h>

#include "cachedcatalog.h"
#include "katapultitem.h"
#include "katapultaction.h"
#include "match.h"
#include "status.h"

CachedCatalog::CachedCatalog()
{
	query = QString::null;
	status = 0;
}

const KatapultItem * CachedCatalog::findExact(QString text) const
{
	text = text.lower();
	KatapultItem *item;
	for(KatapultItem::List::ConstIterator it = cache.begin(); it != cache.end(); ++it) {
		item = *it;
		if(item->text().lower() == text)
			return item;
	}
	return 0;
}

void CachedCatalog::beginQuery(const QString & query)
{
	results.clear();
	this->query = query;
	KatapultItem::Ptr item;
	for(KatapultItem::List::Iterator it = cache.begin(); it != cache.end(); ++it) {
		item = *it;
		Match match = queryItem(item, query());
		if(!match.isNull())
			results.append(item);
	}
}

void CachedCatalog::continueQuery(const QString & add)
{
}

void CachedCatalog::endQuery()
{
	results.clear();
	this->query = QString::null;
}

unsigned int CachedCatalog::minQueryLen() const
{
	return 3;
}

void CachedCatalog::queryChanged()
{
	int newStatus = 0;
	if(query() == "")
	{
		results.clear();
	} else {
		if(query().length() >= minQueryLen())
		{
			if(status() & S_Active)
			{
				KatapultItem::Ptr item;
				for(KatapultItem::List::Iterator it = results.begin(); it != results.end(); ) {
					item = *it;
					++it;
					Match match = queryItem(item, query());
					if(match.isNull())
						results.remove(item);
				}
			} else {
				results.clear();
				
				KatapultItem::Ptr item;
				for(KatapultItem::List::Iterator it = cache.begin(); it != cache.end(); ++it) {
					item = *it;
					Match match = queryItem(item, query());
					if(!match.isNull())
						results.append(item);
				}
			}
			
			newStatus |= S_Active;
			if(results.count() > 0)
			{
				newStatus |= S_HasResults;
				if(results.count() > 1)
					newStatus |= S_Multiple;
			} else
				newStatus |= S_NoResults;
		}
	}
	setStatus(newStatus);
}

void CachedCatalog::addItem(KatapultItem *item)
{
	if(findExact(item->text())) {
//		qDebug("Ignored duplicate item: %s", item->text().ascii());
		delete item;
	} else
		cache.append(item);
}

void CachedCatalog::addMatches(QValueList<Match> & matches, unsigned int max, const KatapultAction *action)
{
	KatapultItem::Ptr item;
	for(KatapultItem::List::Iterator it = results.begin(); it != results.end(); ++it) {
		item = *it;
		if(action == 0 || action->accepts(item))
			addMatch(matches, queryItem(item, query()), max);
	}
}

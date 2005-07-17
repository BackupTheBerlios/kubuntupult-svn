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


#include "actioncatalog.h"

#include "katapultaction.h"
#include "status.h"

static ActionCatalog * actionCatalogInstance = 0;

ActionCatalog::ActionCatalog()
 : KatapultCatalog()
{
}

void ActionCatalog::clear()
{
	actions.clear();
}

void ActionCatalog::addAction(KatapultAction * action)
{
	actions.append(action);
}

void ActionCatalog::addMatches(QValueList<Match> & matches, unsigned int max, KatapultAction *)
{
	QString test = query().lower();
	KatapultAction::Ptr action;
	for(KatapultAction::List::Iterator it = results.begin(); it != results.end(); ++it) {
		action = *it;
		if(test.isEmpty()) {
			addMatch(matches, Match(action, 1, 0), max);
		} else {
			Match match = queryItem(action, test);
			addMatch(matches, match, max);
		}
	}
}

void ActionCatalog::queryChanged()
{
	int newStatus = 0;
	QString test = query().lower();
	
	if(status() & S_Active && !test.isEmpty()) {
		KatapultAction::Ptr action;
		for(KatapultAction::List::Iterator it = results.begin(); it != results.end(); ) {
			action = *it;
			++it;
			Match match = queryItem(action, test);
			if(match.isNull())
				results.remove(action);
		}
	} else {
		results.clear();
		KatapultAction::Ptr action;
		for(KatapultAction::List::Iterator it = actions.begin(); it != actions.end(); ++it) {
			action = *it;
			if(_accepts.isNull() || action->accepts(_accepts.item())) {
				if(test.isEmpty()) {
					results.append(action);
				} else {
					Match match = queryItem(action, test);
					if(!match.isNull())
						results.append(action);
				}
			}
		}
	}
	
	if(results.count() > 0) {
		newStatus |= S_HasResults;
		if(results.count() > 1) {
			newStatus |= S_Multiple;
		}
	} else {
		newStatus |= S_NoResults;
	}
	newStatus |= S_Active;
	setStatus(newStatus);
}

ActionCatalog * ActionCatalog::self()
{
	if(actionCatalogInstance == 0)
		actionCatalogInstance = new ActionCatalog();
	return actionCatalogInstance;
}

void ActionCatalog::setAccepts(Match match)
{
	if(status() & S_Active && !match.isNull()) {
		KatapultAction::Ptr action;
		for(KatapultAction::List::Iterator it = results.begin(); it != results.end(); ) {
			action = *it;
			++it;
			if(!action->accepts(match.item()))
				results.remove(action);
		}
	}
	this->_accepts = match;
	queryChanged();
}

KatapultAction * ActionCatalog::defaultAction(const KatapultItem *item)
{
	KatapultAction::Ptr action, bestAction;
	for(KatapultAction::List::Iterator it = actions.begin(); it != actions.end(); ++it) {
		action = *it;
		int rank = action->accepts(item);
		if(rank == 100)
			return action;
		else if(rank > 0)
			bestAction = action;
	}
	return bestAction;
}

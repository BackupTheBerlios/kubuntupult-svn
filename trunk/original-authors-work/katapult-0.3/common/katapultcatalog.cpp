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

#include "katapultcatalog.h"

#include <qstringlist.h>

#include "katapultitem.h"
#include "match.h"

KatapultCatalog::~KatapultCatalog()
	{}

void KatapultCatalog::initialize()
	{}

void KatapultCatalog::readSettings(KConfigBase *)
	{}

void KatapultCatalog::writeSettings(KConfigBase *)
	{}

QWidget * KatapultCatalog::configure()
	{	return 0;	}
	
void KatapultCatalog::beginQuery(const QString &)
	{}
	
void KatapultCatalog::continueQuery(const QString &)
	{}
	
void KatapultCatalog::endQuery()
	{}

Match KatapultCatalog::queryItem(const KatapultItem *item, QString query) const
{
	int wordNo = 0;
	int _rank = 0;
	unsigned int _matched = 0;
	QString text = item->text().lower();
	QStringList queryWords = QStringList::split(" ", query.lower());
	int wordMax = queryWords.count()-1;
	QStringList words = QStringList::split(" ", text);
	QStringList::Iterator wit = words.begin();
	for(QStringList::Iterator qit = queryWords.begin(); qit != queryWords.end(); ++qit) {
		QString queryWord = *qit;
		bool didMatch = FALSE;
		for(; wit != words.end(); ++wit) {
			QString word = *wit;
			if(word.startsWith(queryWord)) {
				if(_matched != 0)
					_matched++;
				if(wordNo == wordMax) {
					_matched += queryWord.length();
				} else {
					_matched += word.length();
				}
				didMatch = TRUE;
				break;
			}
			if(wordNo == 0) {
				if(_matched != 0)
					_matched++;
				_matched += word.length();
			}
		}
		if(didMatch == FALSE) {
			return Match();
		}
		wordNo++;
	}
	
	if(_matched > text.length())
		return Match();

	_rank = 100*query.length()/text.length();
	
	if(_rank == 0)
		return Match();
	else
		return Match(item, _rank, _matched);
}

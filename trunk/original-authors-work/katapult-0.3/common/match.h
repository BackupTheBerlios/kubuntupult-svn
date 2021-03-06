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
#ifndef MATCH_H
#define MATCH_H

#include "katapultitem.h"

/**
@author Joe Ferris
*/
class Match  {
public:
	Match();
	Match(const KatapultItem *, int, unsigned int);
	Match(const Match &);
	
	Match & operator= (const Match &);
	
	int rank() const;
	const KatapultItem * item() const;
	bool isNull() const;
	unsigned int matched() const;
	
	Match setRank(int) const;
	Match setItem(const KatapultItem *) const;
	Match setMatched(int) const;

private:
	int _rank;
	unsigned int _matched;
	KatapultItem::ConstPtr _item;

};

#endif

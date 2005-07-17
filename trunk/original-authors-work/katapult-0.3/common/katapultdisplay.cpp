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

#include "katapultdisplay.h"

KatapultDisplay::KatapultDisplay(const char *name, WFlags f)
	: QWidget(0, name, f)
{
	_query = "";
	_status = 0;
	_selecting = SelectItem;
	_multi = FALSE;
	_selected = 0;
	_firstItem = 0;
}

KatapultDisplay::~KatapultDisplay()
{
}

void KatapultDisplay::focusOutEvent(QFocusEvent *)
{
	emit focusOut();
}

void KatapultDisplay::keyReleaseEvent(QKeyEvent *e)
{
	emit keyReleased(e);
}

void KatapultDisplay::setMulti(bool _multi)
{
	this->_multi = _multi;
}

bool KatapultDisplay::multi() const
{
	return _multi;
}

int KatapultDisplay::maxItemsAtOnce() const
{
	return 10;
}

void KatapultDisplay::setSelected(int _selected)
{
	this->_selected = _selected;
	if(_selected < _firstItem) {
		_firstItem = _selected;
	} else if(_selected > _firstItem + maxItemsAtOnce() - 1) {
		_firstItem = _selected - maxItemsAtOnce() + 1;
	}
}

int KatapultDisplay::selected() const
{
	return _selected;
}

int KatapultDisplay::firstItem() const
{
	return _firstItem;
}

void KatapultDisplay::setQuery(QString _query)
{
	this->_query = _query;
}

void KatapultDisplay::setSelecting(Selecting _selecting)
{
	this->_selecting = _selecting;
}

Selecting KatapultDisplay::selecting() const
{
	return _selecting;
}

void KatapultDisplay::setItems(const QValueList<Match> & _items)
{
	this->_items = _items;
}

void KatapultDisplay::setActions(const QValueList<Match> & _actions)
{
	this->_actions = _actions;
}

void KatapultDisplay::setIndirectItems(const QValueList<Match> & _items)
{
	_indirectItems = _items;
}

void KatapultDisplay::setStatus(int _status)
{
	this->_status = _status;
}

QString KatapultDisplay::query() const
{
	return _query;
}

const QValueList<Match> & KatapultDisplay::items() const
{
	return _items;
}

const QValueList<Match> & KatapultDisplay::actions() const
{
	return _actions;
}

const QValueList<Match> & KatapultDisplay::indirectItems() const
{
	return _indirectItems;
}

int KatapultDisplay::status() const
{
	return _status;
}

void KatapultDisplay::readSettings(KConfigBase *)
{
}

void KatapultDisplay::writeSettings(KConfigBase *)
{
}

QWidget * KatapultDisplay::configure()
{
	return 0;
}


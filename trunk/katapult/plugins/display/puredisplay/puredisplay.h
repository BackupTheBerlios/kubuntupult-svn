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
#ifndef PUREDISPLAY_H
#define PUREDISPLAY_H

#include <qevent.h>
#include <qpixmap.h>
#include <qtimer.h>
#include <qimage.h>

#include <katapultdisplay.h>

class Katapult;
class QFont;

/**
@author Joe Ferris
*/
class PureDisplay : public KatapultDisplay
{
	Q_OBJECT
public:
	PureDisplay(QObject *, const char *, const QStringList&);
	virtual ~PureDisplay();
	
public slots:
	void continueFade();
	virtual void hide();

	virtual void readSettings(KConfigBase *);
	virtual void writeSettings(KConfigBase *);
	virtual QWidget * configure();
	
	void setFont(const QString &);
	void setMinFontSize(int);
	void setMaxFontSize(int);
	void setFadeOut(int);
	
protected:
	virtual void showEvent(QShowEvent *);
	virtual void paintEvent(QPaintEvent *);
	
	QPixmap getDisplay();
	void drawText(QPixmap &, int, int, QString, int) const;
    
private:
	QPixmap *bgSngl, *bgDbl, *singlebg, *doublebg;
	QRect desktopSize;
	QImage *fadeImg;
	QTimer *fadeTimer;
	QString fontFace;
	int minFontSize, maxFontSize;
	int alpha;
	bool fadeOut;
	int fadeTime, fadeStep;
};

#endif

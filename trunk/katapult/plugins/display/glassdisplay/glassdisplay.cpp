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

#include <kglobal.h>
#include <kglobalsettings.h>
#include <kiconloader.h>
#include <kwin.h>
#include <kimageeffect.h>
#include <kgenericfactory.h>
#include <kconfig.h>
#include <kfontcombo.h>
#include <klocale.h>

#include <qpainter.h>
#include <qapplication.h>
#include <qimage.h>
#include <qbitmap.h>
#include <qslider.h>
#include <qspinbox.h>

#include <status.h>
 
#include "glassdisplay.h"
#include "settings.h"
#include "qembed_images.h"

K_EXPORT_COMPONENT_FACTORY( katapult_glassdisplay,
                            KGenericFactory<GlassDisplay>( "katapult_glassdisplay" ) )

#define WIDTH 295
#define HEIGHT 189
#define PADDING 6
#define ICONSIZE 128

#define LEFTMARGIN 1
#define TOPMARGIN 1
#define RIGHTMARGIN 8
#define BOTTOMMARGIN 8

#define LEFTOFFSET (LEFTMARGIN+PADDING)
#define TOPOFFSET (TOPMARGIN+PADDING)
#define RIGHTOFFSET (RIGHTMARGIN+PADDING)
#define BOTTOMOFFSET (BOTTOMMARGIN+PADDING)

#define FADEINTERVAL 20

GlassDisplay::GlassDisplay(QObject *, const char *name, const QStringList&)
	: KatapultDisplay(name, WType_TopLevel | WStyle_Customize | WStyle_NoBorder | WStyle_StaysOnTop | WNoAutoErase | WDestructiveClose)
{
	KWin::setType(winId(), NET::Dock);
	setBackgroundMode(NoBackground);
	setFocusPolicy(QWidget::StrongFocus);
	
	singlebg = new QPixmap(qembed_findImage("singlebg"));
	doublebg = new QPixmap(qembed_findImage("doublebg"));
	bg = 0;
	fadeImg = 0;
	
	alpha = 0;
	fadeTimer = new QTimer(this);
	connect(fadeTimer, SIGNAL(timeout()), this, SLOT(continueFade()));
	
	QRect desktopSize = qApp->desktop()->availableGeometry();
	move((desktopSize.width() - WIDTH)/2, (desktopSize.height() - HEIGHT)/2);
	resize(WIDTH, HEIGHT);
	
	fadeTime = 250;
	fadeStep = 100/(250/FADEINTERVAL);
}

GlassDisplay::~GlassDisplay()
{
	if(singlebg != 0)
		delete singlebg;
	if(doublebg != 0)
		delete doublebg;
	if(bg != 0)
		delete bg;
	if(fadeImg != 0)
		delete fadeImg;
}

void GlassDisplay::continueFade()
{
	if(fadeOut)
	{
		if(fadeStep == 0)
			alpha = 0;
		else
			alpha -= fadeStep;
		if(alpha <= 0)
		{
			alpha = 0;
			fadeTimer->stop();
			hide();
		}
	} else {
		if(fadeStep == 0)
			alpha = 100;
		else
			alpha += fadeStep;
		if(alpha > 100)
		{
			alpha = 100;
			fadeTimer->stop();
			if(fadeImg != 0)
			{
				delete fadeImg;
				fadeImg = 0;
			}
		}
	}
	update();
}

void GlassDisplay::showEvent(QShowEvent *)
{
	if(bg != 0)
		delete bg;
	bg = new QPixmap(QPixmap::grabWindow(qt_xrootwin(), x(), y(), width(), height()));
	fadeOut = false;
	alpha = 0;
	fadeTimer->start(FADEINTERVAL, FALSE);
	if(fadeImg != 0)
		delete fadeImg;
	fadeImg = new QImage(getDisplay().convertToImage());
}

void GlassDisplay::hide()
{
	if(alpha == 0)
	{
		if(fadeImg != 0)
		{
			delete fadeImg;
			fadeImg = 0;
		}
		KatapultDisplay::hide();
	} else {
		if(fadeImg != 0)
			delete fadeImg;
		fadeImg = new QImage(getDisplay().convertToImage());
		fadeOut = TRUE;
		if(!fadeTimer->isActive())
			fadeTimer->start(FADEINTERVAL, FALSE);
	}
}

void GlassDisplay::drawText(QPixmap & pixmap, int x, int width, QString text, int hilight) const
{
	int fontSize = maxFontSize;
	QFont font(fontFace, fontSize);
	QFontMetrics metrics(font);
	
	while(fontSize > minFontSize && metrics.width(text) > width) {
		fontSize--;
		font.setPointSize(fontSize);
		metrics = QFontMetrics(font);
	}

	while(hilight > 1 && metrics.width(text) > width) {
		text = text.remove(0, 1);
		hilight--;
	}
	
	int useChars = text.length();
	
	while(metrics.width(text, useChars) > width) {
		useChars--;
	}
	text = text.left(useChars);
	
	QString hilighted = text.left(hilight);
	QString remaining = text.right(text.length() - hilighted.length());
	
	x += (width-metrics.width(text))/2;
	
	QPainter painter(&pixmap);
	painter.setFont(font);
	
	painter.setPen(QColor(16, 48, 254));
	painter.drawText(x, HEIGHT-BOTTOMOFFSET, hilighted);
	painter.setPen(QColor(255, 255, 255));
	painter.drawText(x+metrics.width(hilighted), HEIGHT-BOTTOMOFFSET, remaining);
}

QPixmap GlassDisplay::getDisplay()
{
	QPixmap pixmap(*bg);
	QPainter painter(&pixmap);
	
	if(status() & S_HasResults)
	{
		// show best match
		painter.drawPixmap(0, 0, *doublebg);
		
		QFontMetrics metrics = painter.fontMetrics();
		QRect bounds;
		QPixmap icon;
		
		int itemSpace = (WIDTH-LEFTOFFSET-RIGHTOFFSET-PADDING)/2;
		
		const KatapultItem *_item = item();
		if(_item != 0)
		{
			icon = _item->icon(ICONSIZE);
			painter.drawPixmap(LEFTOFFSET+(itemSpace-ICONSIZE)/2, TOPOFFSET, icon);
			drawText(pixmap, LEFTOFFSET, itemSpace, _item->text(), selected());
		}
			
		const KatapultAction *_action = action();
		if(_action != 0)
		{
			int x = LEFTOFFSET+itemSpace+PADDING+PADDING;
			icon = _action->icon(ICONSIZE);
			painter.drawPixmap(x+(itemSpace-ICONSIZE)/2, TOPOFFSET, icon);
			drawText(pixmap, x, itemSpace, _action->text(), 0);
		}
	} else {
		// show splash or error
		painter.drawPixmap(0, 0, *singlebg);
		
		QString label;
		QPixmap icon;
		
		if(status() & S_Active)
		{
			icon = KGlobal::iconLoader()->loadIcon("unknown", KIcon::NoGroup, 128);
			if(query().isEmpty())
				label = i18n("No items matched.");
			else
				label = query();
		} else {
			icon = KGlobal::iconLoader()->loadIcon("katapult", KIcon::NoGroup, 128);
			if(query().isEmpty())
				label = "Katapult";
			else {
				label = query();
				painter.setPen(QColor(16, 48, 254));
			}
		}
		
		painter.drawPixmap(LEFTOFFSET+(WIDTH-LEFTOFFSET-RIGHTOFFSET-128)/2, TOPOFFSET, icon);
		
		drawText(pixmap, LEFTOFFSET, WIDTH-LEFTOFFSET-RIGHTOFFSET, label, 0);
		
/*		painter.drawText(LEFTOFFSET, HEIGHT-BOTTOMOFFSET-30, WIDTH-LEFTOFFSET-RIGHTOFFSET, 30,
			Qt::AlignHCenter | Qt::AlignBottom | Qt::SingleLine, label);*/
	}
	
	painter.end();
	
	return pixmap;
}

void GlassDisplay::paintEvent(QPaintEvent *)
{
	if(alpha == 0)
	{
		bitBlt(this, 0, 0, bg);
	} else if(fadeImg != 0) {
		QImage buffer = bg->convertToImage();
		KImageEffect::blend(*fadeImg, buffer, (float)alpha/100);
		bitBlt(this, 0, 0, &buffer);
	} else {
		QPixmap pixmap = getDisplay();
		bitBlt(this, 0, 0, &pixmap);
	}
}

void GlassDisplay::readSettings(KConfigBase *config)
{
	fadeTime = config->readUnsignedNumEntry("FadeTime", 250);
	fadeStep = fadeTime/FADEINTERVAL;
	QFont defaultFont = KGlobalSettings::generalFont();
	fontFace = config->readEntry("FontFace", defaultFont.family());
	minFontSize = config->readUnsignedNumEntry("MinFontSize", 7);
	maxFontSize = config->readUnsignedNumEntry("MaxFontSize", 14);
}

void GlassDisplay::writeSettings(KConfigBase *config)
{
	config->writeEntry("FadeTime", fadeTime);
	config->writeEntry("FontFace", fontFace);
	config->writeEntry("MinFontSize", minFontSize);
	config->writeEntry("MaxFontSize", maxFontSize);
}

QWidget * GlassDisplay::configure()
{
	GlassDisplaySettings *settings = new GlassDisplaySettings();
	
	settings->fadeTime->setValue(fadeTime);
	connect(settings->fadeTime, SIGNAL(valueChanged(int)), this, SLOT(setFadeOut(int)));
	
	settings->displayFont->setCurrentFont(fontFace);
	connect(settings->displayFont, SIGNAL(textChanged(const QString &)), this, SLOT(setFont(const QString &)));
	
	settings->minFontSize->setValue(minFontSize);
	connect(settings->minFontSize, SIGNAL(valueChanged(int)), this, SLOT(setMinFontSize(int)));
	
	settings->maxFontSize->setValue(maxFontSize);
	connect(settings->maxFontSize, SIGNAL(valueChanged(int)), this, SLOT(setMaxFontSize(int)));
	
	return settings;
}

void GlassDisplay::setFont(const QString &font)
{
	fontFace = font;
}

void GlassDisplay::setMinFontSize(int size)
{
	minFontSize = size;
}

void GlassDisplay::setMaxFontSize(int size)
{
	maxFontSize = size;
}

void GlassDisplay::setFadeOut(int fadeTime)
{
	this->fadeTime = fadeTime;
	fadeStep = fadeTime/FADEINTERVAL;
	if(fadeStep == 0)
		fadeStep = 100;
	else
		fadeStep = 100/fadeStep;
}

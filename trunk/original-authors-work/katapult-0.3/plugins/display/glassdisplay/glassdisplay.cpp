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
#include <match.h>
 
#include "glassdisplay.h"
#include "settings.h"
#include "qembed_images.h"

K_EXPORT_COMPONENT_FACTORY( katapult_glassdisplay,
                            KGenericFactory<GlassDisplay>( "katapult_glassdisplay" ) )

#define BLOCKSIZE 14
#define TILESIZE 5
#define PADDING 3
#define MAXICONSIZE 128
#define MAXTEXTHEIGHT 28
#define SHADOW 8
#define PANEOVERLAP 4
#define MAXITEMS 7

#define PANEWIDTH (MAXICONSIZE+PADDING*2+SHADOW)
#define MINPANEHEIGHT 30

#define WIDTH (PANEWIDTH*2+PANEOVERLAP)
#define HEIGHT (MAXITEMS*(MINPANEHEIGHT-PANEOVERLAP)+PANEOVERLAP)

#define LEFTMARGIN 0
#define TOPMARGIN 0
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
// 	KatapultDisplay::hide();
}

int GlassDisplay::maxItemsAtOnce() const
{
	return MAXITEMS;
}

int GlassDisplay::getPaneHeight(IconSize size) const
{
	int height;
	switch(size) {
	case TinyIcon:
	case SmallIcon:
		height = (int) size + PADDING*2 + SHADOW;
		if(height < MINPANEHEIGHT)
			return MINPANEHEIGHT;
		else
			return height;
	case NormalIcon:
		return (int) size + PADDING*3 + MAXTEXTHEIGHT + SHADOW;
		break;
	case LargeIcon:
	default:
		return (MINPANEHEIGHT-PANEOVERLAP)*MAXITEMS+PANEOVERLAP;
	}
}

void GlassDisplay::drawText(QPixmap & pixmap, int x, int y, int width, int height, QString text, int hilight, bool centerVert) const
{
	int fontSize = maxFontSize;
	int addSelectChars = 0;
	
	QFont font(fontFace, fontSize);
	QFontMetrics metrics(font);
	
	while(fontSize > minFontSize && (metrics.width(text) > width || metrics.height() > height)) {
		fontSize--;
		font.setPointSize(fontSize);
		metrics = QFontMetrics(font);
	}
	
	y -= metrics.descent();
	
	if(metrics.width(text) > width) {
		int elipsesWidth = metrics.width("...");
		addSelectChars += 3;
		while(hilight > 1 && metrics.width(text)+elipsesWidth > width) {
			text = text.remove(0, 1);
			hilight--;
		}
		
		text = QString("...").append(text);
		
		if(metrics.width(text) > width) {
			int useChars = text.length();
		
			while(useChars > 0 && metrics.width(text, useChars)+elipsesWidth > width) {
				useChars--;
			}
			text = text.left(useChars);
			text.append("...");
		}
	}
	
	if(hilight != 0)
		hilight += addSelectChars;
	QString hilighted = text.left(hilight);
	QString remaining = text.right(text.length() - hilighted.length());
	
	if(centerVert)
		y -= (height-metrics.height())/2;
	else
		x += (width-metrics.width(text))/2;
	
	QPainter painter(&pixmap);
	painter.setFont(font);
	
	painter.setPen(QColor(16, 48, 254));
	painter.drawText(x, y, hilighted);
	painter.setPen(QColor(255, 255, 255));
	painter.drawText(x+metrics.width(hilighted), y, remaining);
}

void GlassDisplay::drawItem(QPixmap & pixmap, int x, int y, IconSize size, const Match & match, bool doubleWidth, bool drawLogo) const
{
	QPainter painter(&pixmap);
	
	int width;
	if(doubleWidth)
		width = PANEWIDTH*2-PANEOVERLAP;
	else
		width = PANEWIDTH;
	
	
	int height = getPaneHeight(size);
	int rightStart = x+width-BLOCKSIZE;
	int bottomStart = y+height-BLOCKSIZE;
	
	// draw corners
	painter.drawImage(x, y, qembed_findImage("nw_corner"));
	painter.drawImage(rightStart, y, qembed_findImage("ne_corner"));
	painter.drawImage(x, bottomStart, qembed_findImage("sw_corner"));
	painter.drawImage(rightStart, bottomStart, qembed_findImage("se_corner"));
	
	// horizontal tiles
	int tileWidth = width-BLOCKSIZE*2;
	if(tileWidth > 0) {
		painter.drawTiledPixmap(x+BLOCKSIZE, y, tileWidth, BLOCKSIZE, qembed_findImage("n_side"));
		painter.drawTiledPixmap(x+BLOCKSIZE, bottomStart, tileWidth, BLOCKSIZE, qembed_findImage("s_side"));
	}
	
	// vertical tiles
	int tileHeight = height-BLOCKSIZE*2;
	if(tileHeight > 0) {
		painter.drawTiledPixmap(x, y+BLOCKSIZE, BLOCKSIZE, tileHeight, qembed_findImage("w_side"));
		painter.drawTiledPixmap(rightStart, y+BLOCKSIZE, BLOCKSIZE, tileHeight, qembed_findImage("e_side"));
		
		// fill
		if(tileWidth > 0)
			painter.drawTiledPixmap(x+BLOCKSIZE, y+BLOCKSIZE, tileWidth, tileHeight, qembed_findImage("fill"));
	}
	
	QPixmap icon;
	QString text;
	
	if(match.isNull() || drawLogo) {
		if(drawLogo) {
			icon = KGlobal::iconLoader()->loadIcon("katapult", KIcon::NoGroup, (int) size);
			text = "Katapult";
		} else {
			icon = KGlobal::iconLoader()->loadIcon("unknown", KIcon::NoGroup, (int) size);
			text = query();
		}
	} else {
		icon = match.item()->icon((int) size);
		text = match.item()->text();
	}
	
	if((int) size < 64) {
		painter.drawPixmap(x+PADDING*3, y+PADDING+(height-PADDING*2-SHADOW-(int) size)/2, icon);
		drawText(pixmap, x + PADDING*5 + (int) size, y+height-PADDING-SHADOW, width-PADDING*8-SHADOW-(int) size, height-PADDING*2-SHADOW, text, match.matched(), TRUE);
	} else {
		painter.drawPixmap(x+PADDING+(width-PADDING*2-SHADOW-(int) size)/2, y+PADDING, icon);
		drawText(pixmap, x + PADDING, y+height-PADDING-SHADOW, width-PADDING*2-SHADOW, height-PADDING*3-SHADOW-(int) size, text, match.matched(), FALSE);
	}
}

void GlassDisplay::drawItems(QPixmap & pixmap, int x, const QValueList<Match> & matches)
{
	int matchCount = matches.count();
	if(matchCount > 0) {
		if(multi() && matchCount > 1) {
			if(matchCount > MAXITEMS)
				matchCount = MAXITEMS;
			QValueList<IconSize> sizes;
			sizes << LargeIcon << NormalIcon << SmallIcon << TinyIcon;
			IconSize size = TinyIcon;
			int itemHeight = MINPANEHEIGHT;
			for(QValueListIterator<IconSize> it = sizes.begin(); it != sizes.end(); ++it) {
				size = *it;
				itemHeight = getPaneHeight(size);
				if((itemHeight-PANEOVERLAP)*matchCount+PANEOVERLAP <= HEIGHT)
					break;
			}
			
			int y = 0, itemNo = 0, hilight = selected() - firstItem();
			Match match;
			for(QValueListConstIterator<Match> it = matches.at(firstItem()); it != matches.end() && itemNo < MAXITEMS; ++it) {
				match = *it;
				if(itemNo == hilight)
					match = match.setMatched(match.item()->text().length());
				else
					match = match.setMatched(0);
				drawItem(pixmap, x, y, size, match, FALSE);
				y += itemHeight-PANEOVERLAP;
				itemNo++;
			}
		} else {
			drawItem(pixmap, x, 0, LargeIcon, matches.first());
		}
	} else {
		drawItem(pixmap, x, 0, LargeIcon, Match());
	}
}

QPixmap GlassDisplay::getDisplay()
{
	QPixmap pixmap(*bg);
	
	if(status() & S_Active) {
		if(items().count() > 0) {
			drawItems(pixmap, 0, items());
			if(actions().count() > 0)
				drawItems(pixmap, PANEWIDTH-PANEOVERLAP, actions());
			else
				drawItem(pixmap, PANEWIDTH-PANEOVERLAP, 0, LargeIcon, Match(), FALSE, FALSE);
		} else if(actions().count() > 0 && ! actions().first().isNull()) {
			drawItem(pixmap, 0, 0, LargeIcon, Match(), FALSE, (status()&S_NoResults)?FALSE:TRUE);
			drawItems(pixmap, PANEWIDTH-PANEOVERLAP, actions());
		} else {
			drawItem(pixmap, 0, 0, LargeIcon, Match(), TRUE);
		}
	} else {
		drawItem(pixmap, 0, 0, LargeIcon, Match(), TRUE, TRUE);
	}

/*	if(items().count() > 0) {
		drawItem(pixmap, 0, 0, LargeIcon, items().first());
	} else {
		drawItem(pixmap, 0, 0, LargeIcon, Match(), TRUE);
	}*/
	
/*	if(status() & S_HasResults)
	{
		drawItem(pixmap, 0, 0, LargeIcon, item(), selected());
		drawItem(pixmap, PANEWIDTH-PANEOVERLAP, 0, TinyIcon, action(), 0);
	} else {
		drawItem(pixmap, 0, 0, LargeIcon, 0, 0);
	}*/
	
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

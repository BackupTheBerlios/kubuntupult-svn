#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file '/home/doros/src/local/kde/katapult/plugins/display/glassdisplay/settings.ui'
**
** Created: Tue Mar 1 21:18:39 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "settings.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qslider.h>
#include <qbuttongroup.h>
#include <kfontcombo.h>
#include <qspinbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a GlassDisplaySettings as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
GlassDisplaySettings::GlassDisplaySettings( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "GlassDisplaySettings" );
    GlassDisplaySettingsLayout = new QVBoxLayout( this, 11, 6, "GlassDisplaySettingsLayout"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    GlassDisplaySettingsLayout->addWidget( textLabel1 );

    fadeTime = new QSlider( this, "fadeTime" );
    fadeTime->setMaxValue( 2000 );
    fadeTime->setLineStep( 100 );
    fadeTime->setPageStep( 250 );
    fadeTime->setOrientation( QSlider::Horizontal );
    fadeTime->setTickmarks( QSlider::NoMarks );
    fadeTime->setTickInterval( 1000 );
    GlassDisplaySettingsLayout->addWidget( fadeTime );

    autoFontSize = new QButtonGroup( this, "autoFontSize" );
    autoFontSize->setCheckable( FALSE );
    autoFontSize->setColumnLayout(0, Qt::Vertical );
    autoFontSize->layout()->setSpacing( 6 );
    autoFontSize->layout()->setMargin( 11 );
    autoFontSizeLayout = new QVBoxLayout( autoFontSize->layout() );
    autoFontSizeLayout->setAlignment( Qt::AlignTop );

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    textLabel2 = new QLabel( autoFontSize, "textLabel2" );
    layout6->addWidget( textLabel2 );
    spacer2 = new QSpacerItem( 91, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout6->addItem( spacer2 );

    displayFont = new KFontCombo( autoFontSize, "displayFont" );
    layout6->addWidget( displayFont );
    autoFontSizeLayout->addLayout( layout6 );

    layout7 = new QHBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1_2 = new QLabel( autoFontSize, "textLabel1_2" );
    layout7->addWidget( textLabel1_2 );
    spacer3 = new QSpacerItem( 181, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout7->addItem( spacer3 );

    minFontSize = new QSpinBox( autoFontSize, "minFontSize" );
    layout7->addWidget( minFontSize );
    autoFontSizeLayout->addLayout( layout7 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    textLabel1_2_2 = new QLabel( autoFontSize, "textLabel1_2_2" );
    layout8->addWidget( textLabel1_2_2 );
    spacer4 = new QSpacerItem( 191, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout8->addItem( spacer4 );

    maxFontSize = new QSpinBox( autoFontSize, "maxFontSize" );
    layout8->addWidget( maxFontSize );
    autoFontSizeLayout->addLayout( layout8 );
    GlassDisplaySettingsLayout->addWidget( autoFontSize );
    spacer1 = new QSpacerItem( 20, 160, QSizePolicy::Minimum, QSizePolicy::Expanding );
    GlassDisplaySettingsLayout->addItem( spacer1 );
    languageChange();
    resize( QSize(411, 385).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
GlassDisplaySettings::~GlassDisplaySettings()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void GlassDisplaySettings::languageChange()
{
    setCaption( tr2i18n( "Settings" ) );
    textLabel1->setText( tr2i18n( "Length of fade-in/fade-out:" ) );
    autoFontSize->setTitle( tr2i18n( "Display Font" ) );
    textLabel2->setText( tr2i18n( "Font face:" ) );
    textLabel1_2->setText( tr2i18n( "Minimum font size:" ) );
    textLabel1_2_2->setText( tr2i18n( "Maximum font size:" ) );
}

#include "settings.moc"

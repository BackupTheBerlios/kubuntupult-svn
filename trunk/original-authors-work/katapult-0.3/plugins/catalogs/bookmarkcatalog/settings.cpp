#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file '/home/doros/src/local/kde/katapult/plugins/catalogs/bookmarkcatalog/settings.ui'
**
** Created: Tue Mar 1 21:18:11 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "settings.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <knuminput.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <kurlrequester.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a BookmarkCatalogSettings as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
BookmarkCatalogSettings::BookmarkCatalogSettings( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "BookmarkCatalogSettings" );
    BookmarkCatalogSettingsLayout = new QVBoxLayout( this, 11, 6, "BookmarkCatalogSettingsLayout"); 

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    minQueryLen = new KIntSpinBox( this, "minQueryLen" );
    minQueryLen->setMaxValue( 10 );
    minQueryLen->setMinValue( 1 );
    layout1->addWidget( minQueryLen );
    BookmarkCatalogSettingsLayout->addLayout( layout1 );

    mozEnabled = new QButtonGroup( this, "mozEnabled" );
    mozEnabled->setCheckable( TRUE );
    mozEnabled->setColumnLayout(0, Qt::Vertical );
    mozEnabled->layout()->setSpacing( 6 );
    mozEnabled->layout()->setMargin( 11 );
    mozEnabledLayout = new QVBoxLayout( mozEnabled->layout() );
    mozEnabledLayout->setAlignment( Qt::AlignTop );

    mozAuto = new QRadioButton( mozEnabled, "mozAuto" );
    mozEnabledLayout->addWidget( mozAuto );

    mozManual = new QRadioButton( mozEnabled, "mozManual" );
    mozEnabledLayout->addWidget( mozManual );

    mozFile = new KURLRequester( mozEnabled, "mozFile" );
    mozEnabledLayout->addWidget( mozFile );
    BookmarkCatalogSettingsLayout->addWidget( mozEnabled );
    spacer1 = new QSpacerItem( 20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding );
    BookmarkCatalogSettingsLayout->addItem( spacer1 );
    languageChange();
    resize( QSize(401, 280).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
BookmarkCatalogSettings::~BookmarkCatalogSettings()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void BookmarkCatalogSettings::languageChange()
{
    setCaption( tr2i18n( "Settings" ) );
    textLabel1->setText( tr2i18n( "Number of characters before searching:" ) );
    QWhatsThis::add( minQueryLen, tr2i18n( "Katapult will not search for programs until you have typed at least this many characters in the Katapult launcher." ) );
    mozEnabled->setTitle( tr2i18n( "Import Mozilla bookmarks" ) );
    mozAuto->setText( tr2i18n( "Automatically detect bookmark file" ) );
    mozManual->setText( tr2i18n( "Use the following file:" ) );
}

#include "settings.moc"

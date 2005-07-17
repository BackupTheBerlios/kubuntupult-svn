#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file '/home/doros/src/local/kde/katapult/plugins/catalogs/documentcatalog/settings.ui'
**
** Created: Tue Mar 1 21:18:30 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "settings.h"

#include <qvariant.h>
#include <qlabel.h>
#include <knuminput.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a DocumentCatalogSettings as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
DocumentCatalogSettings::DocumentCatalogSettings( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "DocumentCatalogSettings" );
    DocumentCatalogSettingsLayout = new QVBoxLayout( this, 11, 6, "DocumentCatalogSettingsLayout"); 

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    minQueryLen = new KIntSpinBox( this, "minQueryLen" );
    minQueryLen->setMaxValue( 10 );
    minQueryLen->setMinValue( 1 );
    layout1->addWidget( minQueryLen );
    DocumentCatalogSettingsLayout->addLayout( layout1 );
    spacer1 = new QSpacerItem( 20, 370, QSizePolicy::Minimum, QSizePolicy::Expanding );
    DocumentCatalogSettingsLayout->addItem( spacer1 );
    languageChange();
    resize( QSize(308, 519).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DocumentCatalogSettings::~DocumentCatalogSettings()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DocumentCatalogSettings::languageChange()
{
    setCaption( tr2i18n( "Settings" ) );
    textLabel1->setText( tr2i18n( "Number of characters before searching:" ) );
    QWhatsThis::add( minQueryLen, tr2i18n( "Katapult will not search for programs until you have typed at least this many characters in the Katapult launcher." ) );
}

#include "settings.moc"

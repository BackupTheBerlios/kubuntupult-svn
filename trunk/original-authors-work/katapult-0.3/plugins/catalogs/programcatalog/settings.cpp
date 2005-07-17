#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file '/home/doros/src/local/kde/katapult/plugins/catalogs/programcatalog/settings.ui'
**
** Created: Tue Mar 1 21:17:53 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "settings.h"

#include <qvariant.h>
#include <qlabel.h>
#include <knuminput.h>
#include <qcheckbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ProgramCatalogSettings as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ProgramCatalogSettings::ProgramCatalogSettings( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ProgramCatalogSettings" );
    ProgramCatalogSettingsLayout = new QVBoxLayout( this, 11, 6, "ProgramCatalogSettingsLayout"); 

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    minQueryLen = new KIntSpinBox( this, "minQueryLen" );
    minQueryLen->setMaxValue( 10 );
    minQueryLen->setMinValue( 1 );
    layout1->addWidget( minQueryLen );
    ProgramCatalogSettingsLayout->addLayout( layout1 );

    ignoreIconless = new QCheckBox( this, "ignoreIconless" );
    ProgramCatalogSettingsLayout->addWidget( ignoreIconless );

    ignoreTerminal = new QCheckBox( this, "ignoreTerminal" );
    ProgramCatalogSettingsLayout->addWidget( ignoreTerminal );

    useExecName = new QCheckBox( this, "useExecName" );
    ProgramCatalogSettingsLayout->addWidget( useExecName );
    spacer1 = new QSpacerItem( 20, 370, QSizePolicy::Minimum, QSizePolicy::Expanding );
    ProgramCatalogSettingsLayout->addItem( spacer1 );
    languageChange();
    resize( QSize(308, 519).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProgramCatalogSettings::~ProgramCatalogSettings()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProgramCatalogSettings::languageChange()
{
    setCaption( tr2i18n( "Settings" ) );
    textLabel1->setText( tr2i18n( "Number of characters before searching:" ) );
    QWhatsThis::add( minQueryLen, tr2i18n( "Katapult will not search for programs until you have typed at least this many characters in the Katapult launcher." ) );
    ignoreIconless->setText( tr2i18n( "Ignore applications without icons" ) );
    ignoreTerminal->setText( tr2i18n( "Ignore terminal applications" ) );
    useExecName->setText( tr2i18n( "Catalog applications by executable name" ) );
}

#include "settings.moc"

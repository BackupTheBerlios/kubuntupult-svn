#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file '/home/doros/src/local/kde/katapult/katapult/confcatalogs.ui'
**
** Created: Tue Mar 1 21:19:00 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "confcatalogs.h"

#include <qvariant.h>
#include <kactionselector.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ConfCatalogs as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ConfCatalogs::ConfCatalogs( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ConfCatalogs" );
    ConfCatalogsLayout = new QVBoxLayout( this, 11, 6, "ConfCatalogsLayout"); 

    catalogs = new KActionSelector( this, "catalogs" );
    catalogs->setSelectedInsertionPolicy( KActionSelector::Sorted );
    catalogs->setShowUpDownButtons( FALSE );
    ConfCatalogsLayout->addWidget( catalogs );
    languageChange();
    resize( QSize(300, 211).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ConfCatalogs::~ConfCatalogs()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ConfCatalogs::languageChange()
{
    setCaption( tr2i18n( "Catalogs" ) );
}

#include "confcatalogs.moc"

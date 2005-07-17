#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file '/home/doros/src/local/kde/katapult/katapult/confdisplay.ui'
**
** Created: Tue Mar 1 21:19:02 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "confdisplay.h"

#include <qvariant.h>
#include <kcombobox.h>
#include <qframe.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ConfDisplay as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ConfDisplay::ConfDisplay( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ConfDisplay" );
    ConfDisplayLayout = new QVBoxLayout( this, 11, 6, "ConfDisplayLayout"); 

    displayName = new KComboBox( FALSE, this, "displayName" );
    displayName->setDuplicatesEnabled( FALSE );
    ConfDisplayLayout->addWidget( displayName );

    displaySettings = new QFrame( this, "displaySettings" );
    displaySettings->setFrameShape( QFrame::StyledPanel );
    displaySettings->setFrameShadow( QFrame::Raised );
    ConfDisplayLayout->addWidget( displaySettings );
    spacer1 = new QSpacerItem( 20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding );
    ConfDisplayLayout->addItem( spacer1 );
    languageChange();
    resize( QSize(299, 216).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ConfDisplay::~ConfDisplay()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ConfDisplay::languageChange()
{
    setCaption( tr2i18n( "Display" ) );
}

#include "confdisplay.moc"

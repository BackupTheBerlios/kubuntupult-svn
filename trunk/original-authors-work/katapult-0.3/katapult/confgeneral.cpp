#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file '/home/doros/src/local/kde/katapult/katapult/confgeneral.ui'
**
** Created: Sun Mar 6 13:42:10 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "confgeneral.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qbuttongroup.h>
#include <qlabel.h>
#include <qslider.h>
#include <qcheckbox.h>
#include <qradiobutton.h>
#include <qspinbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ConfGeneral as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ConfGeneral::ConfGeneral( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ConfGeneral" );
    ConfGeneralLayout = new QHBoxLayout( this, 0, 6, "ConfGeneralLayout"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    buttonGroup2 = new QButtonGroup( this, "buttonGroup2" );
    buttonGroup2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)3, 0, 0, buttonGroup2->sizePolicy().hasHeightForWidth() ) );
    buttonGroup2->setColumnLayout(0, Qt::Vertical );
    buttonGroup2->layout()->setSpacing( 6 );
    buttonGroup2->layout()->setMargin( 11 );
    buttonGroup2Layout = new QVBoxLayout( buttonGroup2->layout() );
    buttonGroup2Layout->setAlignment( Qt::AlignTop );

    HideDelayLabel = new QLabel( buttonGroup2, "HideDelayLabel" );
    buttonGroup2Layout->addWidget( HideDelayLabel );

    hideDelay = new QSlider( buttonGroup2, "hideDelay" );
    hideDelay->setMaxValue( 5000 );
    hideDelay->setLineStep( 100 );
    hideDelay->setPageStep( 1000 );
    hideDelay->setOrientation( QSlider::Horizontal );
    hideDelay->setTickmarks( QSlider::Below );
    hideDelay->setTickInterval( 1000 );
    buttonGroup2Layout->addWidget( hideDelay );

    autoExec = new QCheckBox( buttonGroup2, "autoExec" );
    buttonGroup2Layout->addWidget( autoExec );
    layout3->addWidget( buttonGroup2 );

    noResultOptions = new QButtonGroup( this, "noResultOptions" );
    noResultOptions->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)1, 0, 0, noResultOptions->sizePolicy().hasHeightForWidth() ) );
    noResultOptions->setProperty( "selectedId", -1 );
    noResultOptions->setColumnLayout(0, Qt::Vertical );
    noResultOptions->layout()->setSpacing( 6 );
    noResultOptions->layout()->setMargin( 11 );
    noResultOptionsLayout = new QVBoxLayout( noResultOptions->layout() );
    noResultOptionsLayout->setAlignment( Qt::AlignTop );

    textLabel1 = new QLabel( noResultOptions, "textLabel1" );
    noResultOptionsLayout->addWidget( textLabel1 );

    nrClearQuery = new QRadioButton( noResultOptions, "nrClearQuery" );
    noResultOptionsLayout->addWidget( nrClearQuery );

    nrHideDisplay = new QRadioButton( noResultOptions, "nrHideDisplay" );
    noResultOptionsLayout->addWidget( nrHideDisplay );

    nrDoNothing = new QRadioButton( noResultOptions, "nrDoNothing" );
    noResultOptionsLayout->addWidget( nrDoNothing );

    textLabel2 = new QLabel( noResultOptions, "textLabel2" );
    noResultOptionsLayout->addWidget( textLabel2 );

    noResultsDelay = new QSlider( noResultOptions, "noResultsDelay" );
    noResultsDelay->setMaxValue( 5000 );
    noResultsDelay->setLineStep( 100 );
    noResultsDelay->setPageStep( 1000 );
    noResultsDelay->setOrientation( QSlider::Horizontal );
    noResultsDelay->setTickmarks( QSlider::Below );
    noResultsDelay->setTickInterval( 1000 );
    noResultOptionsLayout->addWidget( noResultsDelay );
    layout3->addWidget( noResultOptions );

    buttonGroup3 = new QButtonGroup( this, "buttonGroup3" );
    buttonGroup3->setColumnLayout(0, Qt::Vertical );
    buttonGroup3->layout()->setSpacing( 6 );
    buttonGroup3->layout()->setMargin( 11 );
    buttonGroup3Layout = new QVBoxLayout( buttonGroup3->layout() );
    buttonGroup3Layout->setAlignment( Qt::AlignTop );

    layout2 = new QHBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1_2 = new QLabel( buttonGroup3, "textLabel1_2" );
    layout2->addWidget( textLabel1_2 );

    maxResults = new QSpinBox( buttonGroup3, "maxResults" );
    layout2->addWidget( maxResults );
    buttonGroup3Layout->addLayout( layout2 );
    layout3->addWidget( buttonGroup3 );
    spacer3_2 = new QSpacerItem( 20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout3->addItem( spacer3_2 );
    ConfGeneralLayout->addLayout( layout3 );
    spacer3 = new QSpacerItem( 160, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ConfGeneralLayout->addItem( spacer3 );
    languageChange();
    resize( QSize(449, 455).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ConfGeneral::~ConfGeneral()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ConfGeneral::languageChange()
{
    setCaption( tr2i18n( "General Settings" ) );
    buttonGroup2->setTitle( tr2i18n( "Executing Actions" ) );
    HideDelayLabel->setText( tr2i18n( "Delay before hiding launcher:" ) );
    QToolTip::add( HideDelayLabel, tr2i18n( "How long Katapult waits before hiding the launcher" ) );
    QWhatsThis::add( HideDelayLabel, tr2i18n( "After an action is performed or no results were found, the Katapult launcher will be hidden.\n"
"\n"
"This sets how long Katapult will wait before hiding the launcher." ) );
    autoExec->setText( tr2i18n( "Automatically perform default action" ) );
    QToolTip::add( autoExec, tr2i18n( "Whether to wait for confirmation or automatically execute actions" ) );
    QWhatsThis::add( autoExec, tr2i18n( "If enabled, Katapult will automatically perform the default action once all items but one have been eliminated. This avoids the extra keystroke after there is only one possibility." ) );
    noResultOptions->setTitle( tr2i18n( "No Results" ) );
    textLabel1->setText( tr2i18n( "When there are no results:" ) );
    nrClearQuery->setText( tr2i18n( "Clear the query after a delay" ) );
    nrHideDisplay->setText( tr2i18n( "Hide the display after a delay" ) );
    nrDoNothing->setText( tr2i18n( "Do nothing" ) );
    textLabel2->setText( tr2i18n( "Delay before clearing or hiding:" ) );
    buttonGroup3->setTitle( tr2i18n( "Results" ) );
    textLabel1_2->setText( tr2i18n( "Maximum number of results:" ) );
}

#include "confgeneral.moc"

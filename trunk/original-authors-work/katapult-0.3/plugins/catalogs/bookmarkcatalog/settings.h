/****************************************************************************
** Form interface generated from reading ui file '/home/doros/src/local/kde/katapult/plugins/catalogs/bookmarkcatalog/settings.ui'
**
** Created: Tue Mar 1 21:18:01 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef BOOKMARKCATALOGSETTINGS_H
#define BOOKMARKCATALOGSETTINGS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class KIntSpinBox;
class QButtonGroup;
class QRadioButton;
class KURLRequester;

class BookmarkCatalogSettings : public QWidget
{
    Q_OBJECT

public:
    BookmarkCatalogSettings( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~BookmarkCatalogSettings();

    QLabel* textLabel1;
    KIntSpinBox* minQueryLen;
    QButtonGroup* mozEnabled;
    QRadioButton* mozAuto;
    QRadioButton* mozManual;
    KURLRequester* mozFile;

protected:
    QVBoxLayout* BookmarkCatalogSettingsLayout;
    QSpacerItem* spacer1;
    QHBoxLayout* layout1;
    QVBoxLayout* mozEnabledLayout;

protected slots:
    virtual void languageChange();

};

#endif // BOOKMARKCATALOGSETTINGS_H

/****************************************************************************
** Form interface generated from reading ui file '/home/doros/src/local/kde/katapult/plugins/catalogs/documentcatalog/settings.ui'
**
** Created: Tue Mar 1 21:18:21 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DOCUMENTCATALOGSETTINGS_H
#define DOCUMENTCATALOGSETTINGS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class KIntSpinBox;

class DocumentCatalogSettings : public QWidget
{
    Q_OBJECT

public:
    DocumentCatalogSettings( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~DocumentCatalogSettings();

    QLabel* textLabel1;
    KIntSpinBox* minQueryLen;

protected:
    QVBoxLayout* DocumentCatalogSettingsLayout;
    QSpacerItem* spacer1;
    QHBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // DOCUMENTCATALOGSETTINGS_H

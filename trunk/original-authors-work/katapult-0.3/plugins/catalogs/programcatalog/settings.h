/****************************************************************************
** Form interface generated from reading ui file '/home/doros/src/local/kde/katapult/plugins/catalogs/programcatalog/settings.ui'
**
** Created: Tue Mar 1 21:17:46 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PROGRAMCATALOGSETTINGS_H
#define PROGRAMCATALOGSETTINGS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class KIntSpinBox;
class QCheckBox;

class ProgramCatalogSettings : public QWidget
{
    Q_OBJECT

public:
    ProgramCatalogSettings( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ProgramCatalogSettings();

    QLabel* textLabel1;
    KIntSpinBox* minQueryLen;
    QCheckBox* ignoreIconless;
    QCheckBox* ignoreTerminal;
    QCheckBox* useExecName;

protected:
    QVBoxLayout* ProgramCatalogSettingsLayout;
    QSpacerItem* spacer1;
    QHBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // PROGRAMCATALOGSETTINGS_H

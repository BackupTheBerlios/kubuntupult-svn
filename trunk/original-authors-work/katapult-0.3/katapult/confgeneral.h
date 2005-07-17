/****************************************************************************
** Form interface generated from reading ui file '/home/doros/src/local/kde/katapult/katapult/confgeneral.ui'
**
** Created: Sun Mar 6 13:42:07 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONFGENERAL_H
#define CONFGENERAL_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QButtonGroup;
class QLabel;
class QSlider;
class QCheckBox;
class QRadioButton;
class QSpinBox;

class ConfGeneral : public QWidget
{
    Q_OBJECT

public:
    ConfGeneral( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ConfGeneral();

    QButtonGroup* buttonGroup2;
    QLabel* HideDelayLabel;
    QSlider* hideDelay;
    QCheckBox* autoExec;
    QButtonGroup* noResultOptions;
    QLabel* textLabel1;
    QRadioButton* nrClearQuery;
    QRadioButton* nrHideDisplay;
    QRadioButton* nrDoNothing;
    QLabel* textLabel2;
    QSlider* noResultsDelay;
    QButtonGroup* buttonGroup3;
    QLabel* textLabel1_2;
    QSpinBox* maxResults;

protected:
    QHBoxLayout* ConfGeneralLayout;
    QSpacerItem* spacer3;
    QVBoxLayout* layout3;
    QSpacerItem* spacer3_2;
    QVBoxLayout* buttonGroup2Layout;
    QVBoxLayout* noResultOptionsLayout;
    QVBoxLayout* buttonGroup3Layout;
    QHBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // CONFGENERAL_H

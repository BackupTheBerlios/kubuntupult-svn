/****************************************************************************
** Form interface generated from reading ui file '/home/doros/src/local/kde/katapult/plugins/display/glassdisplay/settings.ui'
**
** Created: Tue Mar 1 21:18:36 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef GLASSDISPLAYSETTINGS_H
#define GLASSDISPLAYSETTINGS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QSlider;
class QButtonGroup;
class KFontCombo;
class QSpinBox;

class GlassDisplaySettings : public QWidget
{
    Q_OBJECT

public:
    GlassDisplaySettings( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~GlassDisplaySettings();

    QLabel* textLabel1;
    QSlider* fadeTime;
    QButtonGroup* autoFontSize;
    QLabel* textLabel2;
    KFontCombo* displayFont;
    QLabel* textLabel1_2;
    QSpinBox* minFontSize;
    QLabel* textLabel1_2_2;
    QSpinBox* maxFontSize;

protected:
    QVBoxLayout* GlassDisplaySettingsLayout;
    QSpacerItem* spacer1;
    QVBoxLayout* autoFontSizeLayout;
    QHBoxLayout* layout6;
    QSpacerItem* spacer2;
    QHBoxLayout* layout7;
    QSpacerItem* spacer3;
    QHBoxLayout* layout8;
    QSpacerItem* spacer4;

protected slots:
    virtual void languageChange();

};

#endif // GLASSDISPLAYSETTINGS_H

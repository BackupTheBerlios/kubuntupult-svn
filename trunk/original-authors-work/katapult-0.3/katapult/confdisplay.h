/****************************************************************************
** Form interface generated from reading ui file '/home/doros/src/local/kde/katapult/katapult/confdisplay.ui'
**
** Created: Tue Mar 1 21:18:54 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONFDISPLAY_H
#define CONFDISPLAY_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class KComboBox;
class QFrame;

class ConfDisplay : public QWidget
{
    Q_OBJECT

public:
    ConfDisplay( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ConfDisplay();

    KComboBox* displayName;
    QFrame* displaySettings;

protected:
    QVBoxLayout* ConfDisplayLayout;
    QSpacerItem* spacer1;

protected slots:
    virtual void languageChange();

};

#endif // CONFDISPLAY_H

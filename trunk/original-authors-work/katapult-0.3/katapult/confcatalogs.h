/****************************************************************************
** Form interface generated from reading ui file '/home/doros/src/local/kde/katapult/katapult/confcatalogs.ui'
**
** Created: Tue Mar 1 21:18:54 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONFCATALOGS_H
#define CONFCATALOGS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class KActionSelector;

class ConfCatalogs : public QWidget
{
    Q_OBJECT

public:
    ConfCatalogs( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ConfCatalogs();

    KActionSelector* catalogs;

protected:
    QVBoxLayout* ConfCatalogsLayout;

protected slots:
    virtual void languageChange();

};

#endif // CONFCATALOGS_H

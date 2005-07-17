/****************************************************************************
** KatapultDisplay meta object code from reading C++ file 'katapultdisplay.h'
**
** Created: Tue Mar 1 21:17:30 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "katapultdisplay.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *KatapultDisplay::className() const
{
    return "KatapultDisplay";
}

QMetaObject *KatapultDisplay::metaObj = 0;
static QMetaObjectCleanUp cleanUp_KatapultDisplay( "KatapultDisplay", &KatapultDisplay::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString KatapultDisplay::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "KatapultDisplay", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString KatapultDisplay::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "KatapultDisplay", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* KatapultDisplay::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QKeyEvent", QUParameter::In }
    };
    static const QUMethod signal_0 = {"keyReleased", 1, param_signal_0 };
    static const QUMethod signal_1 = {"focusOut", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "keyReleased(QKeyEvent*)", &signal_0, QMetaData::Public },
	{ "focusOut()", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"KatapultDisplay", parentObject,
	0, 0,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_KatapultDisplay.setMetaObject( metaObj );
    return metaObj;
}

void* KatapultDisplay::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "KatapultDisplay" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL keyReleased
void KatapultDisplay::keyReleased( QKeyEvent* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL focusOut
void KatapultDisplay::focusOut()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool KatapultDisplay::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool KatapultDisplay::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: keyReleased((QKeyEvent*)static_QUType_ptr.get(_o+1)); break;
    case 1: focusOut(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool KatapultDisplay::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool KatapultDisplay::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

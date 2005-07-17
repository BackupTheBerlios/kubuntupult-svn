/****************************************************************************
** KatapultAction meta object code from reading C++ file 'katapultaction.h'
**
** Created: Fri May 13 17:09:06 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.4   edited Jan 21 18:14 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "katapultaction.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *KatapultAction::className() const
{
    return "KatapultAction";
}

QMetaObject *KatapultAction::metaObj = 0;
static QMetaObjectCleanUp cleanUp_KatapultAction( "KatapultAction", &KatapultAction::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString KatapultAction::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "KatapultAction", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString KatapultAction::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "KatapultAction", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* KatapultAction::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = KatapultItem::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"KatapultAction", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_KatapultAction.setMetaObject( metaObj );
    return metaObj;
}

void* KatapultAction::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "KatapultAction" ) )
	return this;
    return KatapultItem::qt_cast( clname );
}

bool KatapultAction::qt_invoke( int _id, QUObject* _o )
{
    return KatapultItem::qt_invoke(_id,_o);
}

bool KatapultAction::qt_emit( int _id, QUObject* _o )
{
    return KatapultItem::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool KatapultAction::qt_property( int id, int f, QVariant* v)
{
    return KatapultItem::qt_property( id, f, v);
}

bool KatapultAction::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

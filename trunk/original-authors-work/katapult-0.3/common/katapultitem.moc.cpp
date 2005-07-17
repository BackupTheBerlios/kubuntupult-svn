/****************************************************************************
** KatapultItem meta object code from reading C++ file 'katapultitem.h'
**
** Created: Fri May 13 17:09:03 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.4   edited Jan 21 18:14 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "katapultitem.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *KatapultItem::className() const
{
    return "KatapultItem";
}

QMetaObject *KatapultItem::metaObj = 0;
static QMetaObjectCleanUp cleanUp_KatapultItem( "KatapultItem", &KatapultItem::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString KatapultItem::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "KatapultItem", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString KatapultItem::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "KatapultItem", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* KatapultItem::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"KatapultItem", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_KatapultItem.setMetaObject( metaObj );
    return metaObj;
}

void* KatapultItem::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "KatapultItem" ) )
	return this;
    if ( !qstrcmp( clname, "KShared" ) )
	return (KShared*)this;
    return QObject::qt_cast( clname );
}

bool KatapultItem::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool KatapultItem::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool KatapultItem::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool KatapultItem::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

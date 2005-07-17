/****************************************************************************
** CachedCatalog meta object code from reading C++ file 'cachedcatalog.h'
**
** Created: Fri May 13 17:09:08 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.4   edited Jan 21 18:14 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "cachedcatalog.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CachedCatalog::className() const
{
    return "CachedCatalog";
}

QMetaObject *CachedCatalog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CachedCatalog( "CachedCatalog", &CachedCatalog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CachedCatalog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CachedCatalog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CachedCatalog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CachedCatalog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CachedCatalog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = KatapultCatalog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"beginQuery", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"continueQuery", 1, param_slot_1 };
    static const QUMethod slot_2 = {"endQuery", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "beginQuery(const QString&)", &slot_0, QMetaData::Public },
	{ "continueQuery(const QString&)", &slot_1, QMetaData::Public },
	{ "endQuery()", &slot_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CachedCatalog", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CachedCatalog.setMetaObject( metaObj );
    return metaObj;
}

void* CachedCatalog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CachedCatalog" ) )
	return this;
    return KatapultCatalog::qt_cast( clname );
}

bool CachedCatalog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: beginQuery((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: continueQuery((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: endQuery(); break;
    default:
	return KatapultCatalog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CachedCatalog::qt_emit( int _id, QUObject* _o )
{
    return KatapultCatalog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CachedCatalog::qt_property( int id, int f, QVariant* v)
{
    return KatapultCatalog::qt_property( id, f, v);
}

bool CachedCatalog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

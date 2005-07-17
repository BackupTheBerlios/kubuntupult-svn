/****************************************************************************
** DocumentCatalog meta object code from reading C++ file 'documentcatalog.h'
**
** Created: Sat Mar 5 01:54:16 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "documentcatalog.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *DocumentCatalog::className() const
{
    return "DocumentCatalog";
}

QMetaObject *DocumentCatalog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_DocumentCatalog( "DocumentCatalog", &DocumentCatalog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString DocumentCatalog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DocumentCatalog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString DocumentCatalog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DocumentCatalog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* DocumentCatalog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = KatapultCatalog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"minQueryLenChanged", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "minQueryLenChanged(int)", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"DocumentCatalog", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_DocumentCatalog.setMetaObject( metaObj );
    return metaObj;
}

void* DocumentCatalog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "DocumentCatalog" ) )
	return this;
    return KatapultCatalog::qt_cast( clname );
}

bool DocumentCatalog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: minQueryLenChanged((int)static_QUType_int.get(_o+1)); break;
    default:
	return KatapultCatalog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool DocumentCatalog::qt_emit( int _id, QUObject* _o )
{
    return KatapultCatalog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool DocumentCatalog::qt_property( int id, int f, QVariant* v)
{
    return KatapultCatalog::qt_property( id, f, v);
}

bool DocumentCatalog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

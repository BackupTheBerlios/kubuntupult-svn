/****************************************************************************
** BookmarkCatalog meta object code from reading C++ file 'bookmarkcatalog.h'
**
** Created: Tue Mar 1 21:18:16 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "bookmarkcatalog.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *BookmarkCatalog::className() const
{
    return "BookmarkCatalog";
}

QMetaObject *BookmarkCatalog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_BookmarkCatalog( "BookmarkCatalog", &BookmarkCatalog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString BookmarkCatalog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "BookmarkCatalog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString BookmarkCatalog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "BookmarkCatalog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* BookmarkCatalog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CachedCatalog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"minQueryLenChanged", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"toggleMozEnabled", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"toggleMozAuto", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"changeMozFile", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"searchMozDir", 2, param_slot_4 };
    static const QMetaData slot_tbl[] = {
	{ "minQueryLenChanged(int)", &slot_0, QMetaData::Public },
	{ "toggleMozEnabled(bool)", &slot_1, QMetaData::Public },
	{ "toggleMozAuto(bool)", &slot_2, QMetaData::Public },
	{ "changeMozFile(const QString&)", &slot_3, QMetaData::Public },
	{ "searchMozDir(QString)", &slot_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"BookmarkCatalog", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_BookmarkCatalog.setMetaObject( metaObj );
    return metaObj;
}

void* BookmarkCatalog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "BookmarkCatalog" ) )
	return this;
    return CachedCatalog::qt_cast( clname );
}

bool BookmarkCatalog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: minQueryLenChanged((int)static_QUType_int.get(_o+1)); break;
    case 1: toggleMozEnabled((bool)static_QUType_bool.get(_o+1)); break;
    case 2: toggleMozAuto((bool)static_QUType_bool.get(_o+1)); break;
    case 3: changeMozFile((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: static_QUType_QString.set(_o,searchMozDir((QString)static_QUType_QString.get(_o+1))); break;
    default:
	return CachedCatalog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool BookmarkCatalog::qt_emit( int _id, QUObject* _o )
{
    return CachedCatalog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool BookmarkCatalog::qt_property( int id, int f, QVariant* v)
{
    return CachedCatalog::qt_property( id, f, v);
}

bool BookmarkCatalog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

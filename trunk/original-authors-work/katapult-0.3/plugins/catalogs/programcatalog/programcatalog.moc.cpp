/****************************************************************************
** ProgramCatalog meta object code from reading C++ file 'programcatalog.h'
**
** Created: Tue Mar 1 21:17:56 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "programcatalog.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *ProgramCatalog::className() const
{
    return "ProgramCatalog";
}

QMetaObject *ProgramCatalog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ProgramCatalog( "ProgramCatalog", &ProgramCatalog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ProgramCatalog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ProgramCatalog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ProgramCatalog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ProgramCatalog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ProgramCatalog::staticMetaObject()
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
    static const QUMethod slot_1 = {"toggleIgnoreIconless", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"toggleUseExecName", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"toggleIgnoreTerminal", 1, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "minQueryLenChanged(int)", &slot_0, QMetaData::Public },
	{ "toggleIgnoreIconless(bool)", &slot_1, QMetaData::Public },
	{ "toggleUseExecName(bool)", &slot_2, QMetaData::Public },
	{ "toggleIgnoreTerminal(bool)", &slot_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"ProgramCatalog", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ProgramCatalog.setMetaObject( metaObj );
    return metaObj;
}

void* ProgramCatalog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ProgramCatalog" ) )
	return this;
    return CachedCatalog::qt_cast( clname );
}

bool ProgramCatalog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: minQueryLenChanged((int)static_QUType_int.get(_o+1)); break;
    case 1: toggleIgnoreIconless((bool)static_QUType_bool.get(_o+1)); break;
    case 2: toggleUseExecName((bool)static_QUType_bool.get(_o+1)); break;
    case 3: toggleIgnoreTerminal((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return CachedCatalog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool ProgramCatalog::qt_emit( int _id, QUObject* _o )
{
    return CachedCatalog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool ProgramCatalog::qt_property( int id, int f, QVariant* v)
{
    return CachedCatalog::qt_property( id, f, v);
}

bool ProgramCatalog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

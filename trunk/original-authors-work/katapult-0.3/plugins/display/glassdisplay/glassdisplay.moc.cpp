/****************************************************************************
** GlassDisplay meta object code from reading C++ file 'glassdisplay.h'
**
** Created: Tue Mar 1 21:18:42 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "glassdisplay.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *GlassDisplay::className() const
{
    return "GlassDisplay";
}

QMetaObject *GlassDisplay::metaObj = 0;
static QMetaObjectCleanUp cleanUp_GlassDisplay( "GlassDisplay", &GlassDisplay::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString GlassDisplay::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "GlassDisplay", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString GlassDisplay::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "GlassDisplay", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* GlassDisplay::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = KatapultDisplay::staticMetaObject();
    static const QUMethod slot_0 = {"continueFade", 0, 0 };
    static const QUMethod slot_1 = {"hide", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "KConfigBase", QUParameter::In }
    };
    static const QUMethod slot_2 = {"readSettings", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "KConfigBase", QUParameter::In }
    };
    static const QUMethod slot_3 = {"writeSettings", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::Out }
    };
    static const QUMethod slot_4 = {"configure", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"setFont", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"setMinFontSize", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"setMaxFontSize", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"setFadeOut", 1, param_slot_8 };
    static const QMetaData slot_tbl[] = {
	{ "continueFade()", &slot_0, QMetaData::Public },
	{ "hide()", &slot_1, QMetaData::Public },
	{ "readSettings(KConfigBase*)", &slot_2, QMetaData::Public },
	{ "writeSettings(KConfigBase*)", &slot_3, QMetaData::Public },
	{ "configure()", &slot_4, QMetaData::Public },
	{ "setFont(const QString&)", &slot_5, QMetaData::Public },
	{ "setMinFontSize(int)", &slot_6, QMetaData::Public },
	{ "setMaxFontSize(int)", &slot_7, QMetaData::Public },
	{ "setFadeOut(int)", &slot_8, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"GlassDisplay", parentObject,
	slot_tbl, 9,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_GlassDisplay.setMetaObject( metaObj );
    return metaObj;
}

void* GlassDisplay::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "GlassDisplay" ) )
	return this;
    return KatapultDisplay::qt_cast( clname );
}

bool GlassDisplay::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: continueFade(); break;
    case 1: hide(); break;
    case 2: readSettings((KConfigBase*)static_QUType_ptr.get(_o+1)); break;
    case 3: writeSettings((KConfigBase*)static_QUType_ptr.get(_o+1)); break;
    case 4: static_QUType_ptr.set(_o,configure()); break;
    case 5: setFont((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: setMinFontSize((int)static_QUType_int.get(_o+1)); break;
    case 7: setMaxFontSize((int)static_QUType_int.get(_o+1)); break;
    case 8: setFadeOut((int)static_QUType_int.get(_o+1)); break;
    default:
	return KatapultDisplay::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool GlassDisplay::qt_emit( int _id, QUObject* _o )
{
    return KatapultDisplay::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool GlassDisplay::qt_property( int id, int f, QVariant* v)
{
    return KatapultDisplay::qt_property( id, f, v);
}

bool GlassDisplay::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

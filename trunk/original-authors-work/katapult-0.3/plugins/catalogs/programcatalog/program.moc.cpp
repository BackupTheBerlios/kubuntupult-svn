/****************************************************************************
** Program meta object code from reading C++ file 'program.h'
**
** Created: Tue Mar 1 21:17:58 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "program.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Program::className() const
{
    return "Program";
}

QMetaObject *Program::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Program( "Program", &Program::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Program::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Program", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Program::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Program", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Program::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = KatapultItem::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"Program", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Program.setMetaObject( metaObj );
    return metaObj;
}

void* Program::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Program" ) )
	return this;
    return KatapultItem::qt_cast( clname );
}

bool Program::qt_invoke( int _id, QUObject* _o )
{
    return KatapultItem::qt_invoke(_id,_o);
}

bool Program::qt_emit( int _id, QUObject* _o )
{
    return KatapultItem::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Program::qt_property( int id, int f, QVariant* v)
{
    return KatapultItem::qt_property( id, f, v);
}

bool Program::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

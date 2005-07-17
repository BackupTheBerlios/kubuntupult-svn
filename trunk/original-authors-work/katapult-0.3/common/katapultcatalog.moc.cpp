/****************************************************************************
** KatapultCatalog meta object code from reading C++ file 'katapultcatalog.h'
**
** Created: Fri May 13 17:09:04 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.4   edited Jan 21 18:14 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "katapultcatalog.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *KatapultCatalog::className() const
{
    return "KatapultCatalog";
}

QMetaObject *KatapultCatalog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_KatapultCatalog( "KatapultCatalog", &KatapultCatalog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString KatapultCatalog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "KatapultCatalog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString KatapultCatalog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "KatapultCatalog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* KatapultCatalog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
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
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "Status", QUParameter::In }
    };
    static const QUMethod signal_0 = {"statusChanged", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "Match", QUParameter::In }
    };
    static const QUMethod signal_1 = {"matchFound", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "KatapultItem", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"matchChanged", 2, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "KatapultItem", QUParameter::In }
    };
    static const QUMethod signal_3 = {"matchRemoved", 1, param_signal_3 };
    static const QMetaData signal_tbl[] = {
	{ "statusChanged(Status)", &signal_0, QMetaData::Public },
	{ "matchFound(Match)", &signal_1, QMetaData::Public },
	{ "matchChanged(const KatapultItem*,int)", &signal_2, QMetaData::Public },
	{ "matchRemoved(const KatapultItem*)", &signal_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"KatapultCatalog", parentObject,
	slot_tbl, 3,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_KatapultCatalog.setMetaObject( metaObj );
    return metaObj;
}

void* KatapultCatalog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "KatapultCatalog" ) )
	return this;
    return QObject::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL statusChanged
void KatapultCatalog::statusChanged( Status t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL matchFound
void KatapultCatalog::matchFound( Match t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL matchChanged
void KatapultCatalog::matchChanged( const KatapultItem* t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL matchRemoved
void KatapultCatalog::matchRemoved( const KatapultItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool KatapultCatalog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: beginQuery((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: continueQuery((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: endQuery(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool KatapultCatalog::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: statusChanged((Status)(*((Status*)static_QUType_ptr.get(_o+1)))); break;
    case 1: matchFound((Match)(*((Match*)static_QUType_ptr.get(_o+1)))); break;
    case 2: matchChanged((const KatapultItem*)static_QUType_ptr.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 3: matchRemoved((const KatapultItem*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool KatapultCatalog::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool KatapultCatalog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

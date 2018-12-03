#include "dbus_receiver.h"
#include <QDebug>
#include <QDBusVariant>

DBusReceiver::DBusReceiver(const QString &pathName,
						   const QString &objName,
						   const QString &receiverName,
						   QWidget *parent) :
	QLineEdit(parent),
    m_pathName(pathName + receiverName),
    m_objName(objName + receiverName),
    m_receiverName(receiverName)
{
	setupDBus();
}

void DBusReceiver::setupDBus()
{
//    qRegisterMetaType<qPosition_pair>("qPosition_pair");
//    qDBusRegisterMetaType<qPosition_pair>();

//    qRegisterMetaType<qPosition>("qPosition");
    qDBusRegisterMetaType<qPositionPairElm>();
    qDBusRegisterMetaType<qPositionMapElm>();
    qDBusRegisterMetaType<qPosition>();

    qDBusRegisterMetaType<qValuesToReturn>();

    if (!QDBusConnection::sessionBus().registerService("org.agl.naviapi"))
        qDebug() << m_pathName << "registerService() failed";

    if (!QDBusConnection::sessionBus().registerObject("/org/genivi/navigationcore", this))
        qDebug() << m_objName << "registerObject() failed";

    new MapMatchedPositionAdaptor(this);

}

void setupApi(){

}

// Method
qPosition DBusReceiver::GetPosition(const qValuesToReturn &valuesToReturn){
    qDebug() << valuesToReturn;
    qPosition result;
    qPositionMapElm resultMapElm;
    qPositionPairElm Pair_1,Pair_2;

    Pair_1.key = 160;
    Pair_1.value = qvariant_cast<QDBusVariant>(35.5879);
    Pair_2.key = 161;
    Pair_2.value = qvariant_cast<QDBusVariant>(139.731);
    resultMapElm.insert(160,Pair_1);
    resultMapElm.insert(161,Pair_2);
    result.append(resultMapElm);
    return result;
}

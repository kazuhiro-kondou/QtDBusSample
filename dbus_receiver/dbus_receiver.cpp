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
    qDBusRegisterMetaType<qPositionPairElm>();
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
    qPositionPairElm Pair_1,Pair_2;

    Pair_1.key = 160;
    Pair_1.value = QDBusVariant(35.5879);
    Pair_2.key = 161;
    Pair_2.value = QDBusVariant(139.731);
    result.insert(160,Pair_1);
    result.insert(161,Pair_2);
    return result;
}

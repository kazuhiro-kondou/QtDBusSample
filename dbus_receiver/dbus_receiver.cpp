#include "dbus_receiver.h"
#include <QDebug>

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
qPosition GetPosition(const qValuesToReturn &valuesToReturn){
    qDebug() << valuesToReturn;
    qPosition result;
    QMap<int32_t,QPair<uint8_t,double>> map;
    QPair<uint8_t,double> buff_1,buff_2;
//    qPosition_pair buff_1,buff_2;
//    buff_1.key=160;
//    buff_1.value=35.5879;
//    buff_2.key=161;
//    buff_2.value=139.731;
    buff_1.first=160;
    buff_1.second=35.5879;
    buff_2.first=161;
    buff_2.second=139.731;
    map.insert(160,buff_1);
    map.insert(161,buff_2);
    result.append(map);
    return result;
}

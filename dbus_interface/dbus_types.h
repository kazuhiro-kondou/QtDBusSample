#ifndef DBUS_TYPES_H
#define DBUS_TYPES_H
#include <QtDBus>

#include <QMetaType>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QVariant>
#include <QPair>

// for org.genivi.navigationcore.MapMatchedPosition
//struct qPosition_pair{
//    uint8_t key;
//    double value;
//};
//Q_DECLARE_METATYPE(qPosition_pair)

//inline QDBusArgument &operator <<(QDBusArgument &argument, const qPosition_pair &qposition_pair)
//{
//    argument.beginStructure();
//    argument << qposition_pair.key;
//    argument << qposition_pair.value;
//    argument.endStructure();
//    return argument;
//}

//inline const QDBusArgument &operator >>(const QDBusArgument &argument, qPosition_pair &qposition_pair)
//{
//    argument.beginStructure();
//    argument >> qposition_pair.key;
//    argument >> qposition_pair.value;
//    argument.endStructure();
//    return argument;
//}

//typedef QMap<int32_t,qPosition_pair> qPosition;
typedef QList<QMap<int32_t,QPair<uint8_t,double>>> qPosition;
Q_DECLARE_METATYPE(qPosition)

//QDBusArgument &operator <<(QDBusArgument &argument, const qPosition &qposition)
//{
//    argument.beginMap( QVariant::Int, qMetaTypeId<qPosition_pair>() );
//    foreach (const int32_t i, qposition.keys()){
//        argument.beginMapEntry();
////        argument << i << qposition[i];
//        argument << i;
//        argument.beginStructure();
//        argument << qposition[i].key;
//        argument << qposition[i].value;
//        argument.endStructure();
//        argument.endMapEntry();
//    }
//    argument.endMap();

//    return argument;
//}

//const QDBusArgument &operator >>(const QDBusArgument &argument, qPosition &qposition)
//{
//    argument.beginMap();
//    qposition.clear();

//    while ( !argument.atEnd() ) {
//        int32_t key;
//        qPosition_pair val;

//        argument.beginMapEntry();
////        argument >> key >> val;
//        argument >> key;
//        argument.beginStructure();
//        argument >> val.key;
//        argument >> val.value;
//        argument.endStructure();
//        argument.endMapEntry();

//        qposition.insert(key,val);
//    }
//    return argument;
//}
typedef QList<int32_t> qValuesToReturn;
Q_DECLARE_METATYPE(qValuesToReturn)

#endif

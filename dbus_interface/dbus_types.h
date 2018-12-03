#ifndef DBUS_TYPES_H
#define DBUS_TYPES_H
#include <QtDBus>

#include <QMetaType>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QVariant>
#include <QPair>
#include <QDBusVariant>

// for org.genivi.navigationcore.MapMatchedPosition
struct qPositionPairElm{
    uint8_t key;
    QDBusVariant value;
};
Q_DECLARE_METATYPE(qPositionPairElm)

inline QDBusArgument &operator <<(QDBusArgument &argument, const qPositionPairElm &qpositionpairelm)
{
    argument.beginStructure();
    argument << qpositionpairelm.key << qpositionpairelm.value;
    argument.endStructure();
    return argument;
}

inline const QDBusArgument &operator >>(const QDBusArgument &argument, qPositionPairElm &qpositionpairelm)
{
    argument.beginStructure();
    argument >> qpositionpairelm.key;
    argument >> qpositionpairelm.value;
    argument.endStructure();
    return argument;
}

//typedef QMap<int32_t,qPosition_pair> qPosition;
typedef QMap<int32_t,qPositionPairElm> qPositionMapElm;
Q_DECLARE_METATYPE(qPositionMapElm)

//inline QDBusArgument &operator <<(QDBusArgument &argument, const qPositionMapElm &qpositionmapelm)
//{
//    argument.beginMap( QVariant::Int, qMetaTypeId<qPositionPairElm>() );
//    for ( qPositionMapElm::Iterator i = qpositionmapelm.begin(); i != qpositionmapelm.end(); ++i ) {
//        argument.beginMapEntry();
//        argument << i.key() << i.value();
//        argument.endMapEntry();
//    }
//    argument.endMap();
//    return argument;
//}

//inline const QDBusArgument &operator >>(const QDBusArgument &argument, qPositionMapElm &qpositionmapelm)
//{
//    argument.beginMap();
//    qpositionmapelm.clear();
//    while ( !argument.atEnd() ) {
//        int key;
//        qPositionPairElm value;
//        argument.beginMapEntry();
//        argument >> key >> value;
//        argument.endMapEntry();
//        qpositionmapelm.insert(key,value);
//    }
//    argument.endMap();
//    return argument;
//}


typedef QList<qPositionMapElm> qPosition;
Q_DECLARE_METATYPE(qPosition)

//inline QDBusArgument &operator <<(QDBusArgument &argument, const qPosition &qposition)
//{
//    argument.beginArray(qMetaTypeId<qPositionMapElm>);
//    for (int i = 0;i < qposition.size(); ++i){
//        argument << qposition[i];
//    }
//    argument.endArray();
//    return argument;
//}

//inline const QDBusArgument &operator >>(const QDBusArgument &argument, qPosition &qposition)
//{
//    qposition.clear();
//    argument.beginArray();
//    while ( !argument.atEnd() ) {
//        qPositionMapElm map;
//        argument >> map;
//        qposition.append(map);
//    }
//    argument.endArray();
//    return argument;
//}

typedef QList<int> qValuesToReturn;
Q_DECLARE_METATYPE(qValuesToReturn)

#endif

#ifndef DBUS_RECEIVER_H
#define DBUS_RECEIVER_H

#include <QLineEdit>
#include <QtDBus/QDBusConnection>
#include <QtCore/QObject>
#include <QtDBus/QtDBus>

#include "./../dbus_interface/org.genivi.navigationcore.mapmatchedposition_adaptor.h"
#include "./../dbus_interface/org.genivi.navigationcore.mapmatchedposition_interface.h"

class DBusReceiver : public QLineEdit
{
	Q_OBJECT

    QString	m_pathName;
    QString	m_objName;
	QString m_receiverName;

public:
	DBusReceiver(const QString &pathName,
				 const QString &objName,
				 const QString &receiverName,
				 QWidget *parent = 0);

public slots:
//    QList<Position> GetPosition(const QList<int32_t> &valuesToReturn);
//    QMap<int32_t,Position_pair> GetPosition(const QList<int32_t> &valuesToReturn);
    qPosition GetPosition(const qValuesToReturn &valuesToReturn);
private:
	void setupDBus();
    void setupApi();

};

#endif // DBUS_RECEIVER_H


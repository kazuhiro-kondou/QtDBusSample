#include <QApplication>
#include "dbus_receiver.h"

int main(int argc, char *argv[])
{
    // for dbusIF
    QString pathBase = "org.agl.";
    QString objBase = "/org/agl/";
    QString	receiverName = "naviapi";

	QApplication	app(argc, argv);

    DBusReceiver	receiver(pathBase, objBase, receiverName);

	receiver.show();

	return	app.exec();
}

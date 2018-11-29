TEMPLATE = app
TARGET = dbus_receiver
INCLUDEPATH += .
QT += widgets dbus

HEADERS += dbus_receiver.h 

SOURCES += dbus_receiver.cpp \
           main.cpp
LIBS += $$OUT_PWD/../dbus_interface/libdbus_interface.a
INCLUDEPATH += $$OUT_PWD/../dbus_interface




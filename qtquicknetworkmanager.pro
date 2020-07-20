TEMPLATE = lib
TARGET = qtquicknetworkmanager
QT += qml quick network dbus
CONFIG += plugin c++11 pkg-config

PKGCONFIG += glib-2.0 gtk+-2.0 gio-unix-2.0# libnm
DESTDIR = ./bin/QtQuick/NetworkManager

MOC_DIR = tmp
RCC_DIR = tmp
OBJECTS_DIR = tmp

INCLUDEPATH += /usr/include/KF5/NetworkManagerQt/

#TARGET = $$qtLibraryTarget($$TARGET)
#uri = QtQuick.NetworkManager

# Input
SOURCES += \
        qtquicknetworkmanager_plugin.cpp \
        networkmanager.cpp

HEADERS += \
        qtquicknetworkmanager_plugin.h \
        networkmanager.h

#DISTFILES = qmldir \
#    index.qml

OTHER_FILES += \
            run.sh \
            $$DESTDIR/qmldir \
            index.qml \
            .gitignore



#!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
#    copy_qmldir.target = $$OUT_PWD/qmldir
#    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
#    copy_qmldir.commands = $(COPY_FILE) "$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)" "$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)"
#    QMAKE_EXTRA_TARGETS += copy_qmldir
#    PRE_TARGETDEPS += $$copy_qmldir.target
#}

#qmldir.files = qmldir
#unix {
#    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \., /)
#    qmldir.path = $$installPath
#    target.path = $$installPath
#    INSTALLS += target qmldir
#}

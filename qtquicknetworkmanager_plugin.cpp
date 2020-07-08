#include "qtquicknetworkmanager_plugin.h"

#include "networkmanager.h"

#include <qqml.h>

void QtquicknetworkmanagerPlugin::registerTypes(const char *uri)
{
    // @uri QtQuick.NetworkManager
    qmlRegisterType<NetworkManager>(uri, 1, 0, "NetworkManager");
}


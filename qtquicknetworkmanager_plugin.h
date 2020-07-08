#ifndef QTQUICKNETWORKMANAGER_PLUGIN_H
#define QTQUICKNETWORKMANAGER_PLUGIN_H

#include <QQmlExtensionPlugin>

class QtquicknetworkmanagerPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // QTQUICKNETWORKMANAGER_PLUGIN_H

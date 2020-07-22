#include "networkmanagerprivate.h"

NetworkManagerPrivate *NetworkManagerPrivate::getInstance()
{
    qDebug()<<"NetworkManagerPrivate::getInstance";

    static NetworkManagerPrivate* nmp = new NetworkManagerPrivate();
    return nmp;
}

void NetworkManagerPrivate::run()
{
    qDebug()<<"NetworkManagerPrivate::run";
    while(true) {
        wifi_access_points.clear();
        updateWifiAccessPoints();
        qDebug()<<"NetworkManagerPrivate::run::count="<<wifi_access_points.count();
        qDebug()<<"NetworkManagerPrivate::run::count="<<_wifi_count;
        if(wifi_access_points.count() != _wifi_count) {
            _wifi_count = wifi_access_points.count();
            emit wifiCountChanged(_wifi_count);
        }
        QThread::sleep(5);
    }
}

NetworkManagerPrivate::NetworkManagerPrivate():_wifi_count(0)
{
    qDebug()<<"NetworkManagerPrivate::NetworkManagerPrivate::SINGLETON";
    start();
}

void NetworkManagerPrivate::updateWifiAccessPoints()
{
    qDebug()<<"NetworkManagerPrivate::updateWifiAccessPoints";

    QDBusInterface network_manager("org.freedesktop.NetworkManager",
                                   "/org/freedesktop/NetworkManager",
                                   "org.freedesktop.NetworkManager",
                                   QDBusConnection::systemBus());
    if(!network_manager.isValid()) {
        qFatal("Failed to connect to system bus");
        return;
    }
    QDBusMessage message = network_manager.call("GetDevices");
    QDBusArgument args = message.arguments().at(0).value<QDBusArgument>();
    QList<QDBusObjectPath> paths_list = qdbus_cast<QList<QDBusObjectPath> >(args);
    foreach(QDBusObjectPath path, paths_list) {
        QDBusInterface device("org.freedesktop.NetworkManager",
                              path.path(),
                              "org.freedesktop.NetworkManager.Device",
                              QDBusConnection::systemBus());
        if(device.property("DeviceType").toInt() != 2) {
            continue;
        }
        QDBusInterface wifi_device("org.freedesktop.NetworkManager",
                                   path.path(),
                                   "org.freedesktop.NetworkManager.Device.Wireless",
                                   QDBusConnection::systemBus());
        QMap<QString, QVariant> arg_list;
        QDBusMessage message = wifi_device.call("RequestScan", arg_list);
        QThread::sleep(3);
        message = wifi_device.call("GetAllAccessPoints");
        QDBusArgument access_points_list_arg = message.arguments().at(0).value<QDBusArgument>();
        QList<QDBusObjectPath> access_points_path_list = qdbus_cast<QList<QDBusObjectPath>>(access_points_list_arg);
        foreach(QDBusObjectPath path, access_points_path_list) {
            QDBusInterface access_point_interface("org.freedesktop.NetworkManager",
                                                  path.path(),
                                                  "org.freedesktop.NetworkManager.AccessPoint",
                                                  QDBusConnection::systemBus());
            if(!access_point_interface.isValid()) {
                qFatal("Unable to get the details of WiFi Access Points");
            }
            qDebug()<<access_point_interface.property("Ssid").toString()
                   <<access_point_interface.property("Strength").toInt();

            WifiAccessPoint pt;
            pt.ssid = access_point_interface.property("Ssid").toString();
            pt.strength = access_point_interface.property("Strength").toInt();
            wifi_access_points.append(pt);
        }
    }
}

#ifndef NETWORKMANAGERPRIVATE_H
#define NETWORKMANAGERPRIVATE_H

#include<QThread>
#include<QtDBus>
#include<QList>
#include <QString>

typedef struct {
    QString ssid;
    int strength;
}WifiAccessPoint;

class NetworkManagerPrivate : public QThread
{
    Q_OBJECT
public:
    static NetworkManagerPrivate *getInstance();
    void run();
    QList<WifiAccessPoint> wifi_access_points;
signals:
    void wifiCountChanged(int count);
private:
    NetworkManagerPrivate();
    NetworkManagerPrivate(NetworkManagerPrivate &);
    void updateWifiAccessPoints();
    int _wifi_count;

};

#endif // NETWORKMANAGERPRIVATE_H

#include "wifiaccesspointsmodel.h"

WifiAccessPointsModel::WifiAccessPointsModel(QObject *parent)
    :QAbstractListModel(parent), _count(0)
{
    nm = NetworkManagerPrivate::getInstance();
    connect(nm, SIGNAL(wifiCountChanged(int)),
            this, SLOT(updateWifiCount(int)));
}

void WifiAccessPointsModel::updateWifiCount(int count)
{
    qDebug()<<"WifiAccessPointsModel::updateWifiCount::count="<<count;
    _count = count;
    emit dataChanged(0, _count);
}

QHash<int, QByteArray> WifiAccessPointsModel::roleNames() const
{
    QHash<int, QByteArray> _roles;
    _roles[0] = "SSID";
    _roles[1] = "strength";
    return _roles;
}

int WifiAccessPointsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return _count;
}

QVariant WifiAccessPointsModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(index)
    Q_UNUSED(role)
//    if(!index.isValid()) {
//        return QVariant();
//    }

    return "MALCOLM"; //nm->wifi_access_points.at(index.row()).ssid;
}

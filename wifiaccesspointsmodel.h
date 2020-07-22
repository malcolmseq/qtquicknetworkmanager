#ifndef WIFIACCESSPOINTSMODEL_H
#define WIFIACCESSPOINTSMODEL_H

#include<QAbstractListModel>
#include <QDebug>
#include "networkmanagerprivate.h"

class WifiAccessPointsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    WifiAccessPointsModel(QObject *parent = nullptr);
public slots:
    void updateWifiCount(int count);
protected:
    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    NetworkManagerPrivate *nm;
    int _count;
};

#endif // WIFIACCESSPOINTSMODEL_H

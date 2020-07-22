#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QQuickItem>
#include <QDebug>

#include "networkmanagerprivate.h"

class NetworkManager : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(NetworkManager)

public:
    explicit NetworkManager(QQuickItem *parent = nullptr);
    ~NetworkManager() override;
private:
    NetworkManagerPrivate *nm;
};

#endif // NETWORKMANAGER_H

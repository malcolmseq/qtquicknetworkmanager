#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QQuickItem>

class NetworkManager : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(NetworkManager)

public:
    explicit NetworkManager(QQuickItem *parent = nullptr);
    ~NetworkManager() override;
};

#endif // NETWORKMANAGER_H

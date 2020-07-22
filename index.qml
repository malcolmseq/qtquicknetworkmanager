import QtQuick 2.0
import QtQuick.NetworkManager 1.0

Item {
    height:480
    width: 800;

    NetworkManager{
        id: networkManager;
    }
    WifiAccessPointsModel{
        id: wifiAccessPointsModel;
    }
    ListView{
        anchors.fill: parent;
        model: wifiAccessPointsModel
        delegate: Row{
            spacing: 15;
            Text{
                text: SSID
            }
            Text{
                text: strength
            }
        }
    }
}

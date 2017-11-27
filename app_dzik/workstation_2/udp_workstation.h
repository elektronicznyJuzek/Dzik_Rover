#ifndef UDP_ROBOT_H
#define UDP_ROBOT_H

#include <QObject>
#include <QMainWindow>
#include <QUdpSocket>
#include <QMap>
#include <QDebug>

# define PORT 4950

static const QDataStream::Version kDSVersion = QDataStream::Qt_5_5;

class UDP_WorkStation : public QObject
{
    Q_OBJECT
private:
    QUdpSocket *socket;
    QHostAddress PiAddress = QHostAddress("192.168.0.102"); // Raspberry address
    QMap <QString,double> meas;

public:
    explicit UDP_WorkStation(QObject *parent = 0);
    void send_data_to_ROBOT(QMap<int,bool> map_of_keys);

signals:

public slots:
    void read_data_from_Robot();

};

#endif // UDP_ROBOT_H

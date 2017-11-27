#include "udp_workstation.h"

UDP_WorkStation::UDP_WorkStation(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(PORT, QUdpSocket::ShareAddress);
    connect(socket,SIGNAL(readyRead()),this,SLOT(read_data_from_Robot()),Qt::QueuedConnection);
}

void UDP_WorkStation::send_data_to_ROBOT(QMap<int,bool> map_of_keys)
{
    QByteArray buf;
    QDataStream bds(&buf, QIODevice::WriteOnly);
    bds.setVersion(kDSVersion);
    bds << map_of_keys;
    socket->writeDatagram(buf,PiAddress,PORT);
    qDebug() << map_of_keys;
}

void UDP_WorkStation::read_data_from_Robot()
{
    QByteArray datagram;
    QHostAddress sender;
    quint16 senderPort;

    if(socket->hasPendingDatagrams())
    {
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(),datagram.size(), &sender, &senderPort);
        QDataStream byte_stream(&datagram, QIODevice::ReadOnly);
        byte_stream >> meas;
    }

    //qDebug() << sender;
}

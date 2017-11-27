#include "Robot.h"
#include <wiringPi.h>
#include <wiringPiSPI.h>

Robot::Robot(QObject *parent) : QObject(parent)
{
    wiringPiSetup();
    motor_init();
    socket = new QUdpSocket(this);
    socket->bind(PORT, QUdpSocket::ShareAddress);
    connect(socket,SIGNAL(readyRead()),this,SLOT(read_data_from_WorkStation()),Qt::QueuedConnection);
}

void Robot::read_data_from_WorkStation()
{
    while(socket->hasPendingDatagrams())
    {
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        QDataStream byte_stream(&datagram, QIODevice::ReadOnly);
        byte_stream >> control_map;
        robot_control();
        qDebug() << control_map;
    }
}

void Robot::send_data_to_WorkStation(QMap<QString,double> m_map)
{
    QByteArray buf;
    QDataStream bds(&buf, QIODevice::WriteOnly);
    bds << m_map;
    socket->writeDatagram(buf,WAddress,PORT);
}

void Robot::robot_control()
{   
         if(control_map[Qt::Key_Up])    drive_forward();
    else if(control_map[Qt::Key_Down])  drive_back();
    else if(control_map[Qt::Key_Left])  turn_left_inplace();
    else if(control_map[Qt::Key_Right]) turn_right_inplace();
    else if(!control_map[Qt::Key_Up] || !control_map[Qt::Key_Down] || !control_map[Qt::Key_Left] || !control_map[Qt::Key_Right]) stop();
}

void Robot::robot_speed(bool x)
{
     
}

void Robot::motor_init()
{
    pinMode(MOTOR_I_D9, OUTPUT);
    pinMode(MOTOR_I_D4, OUTPUT);
    pinMode(MOTOR_II_D8, OUTPUT);
    pinMode(MOTOR_II_D7, OUTPUT);
    pinMode(MOTOR_III_D8, OUTPUT);
    pinMode(MOTOR_III_D7, OUTPUT);
    pinMode(MOTOR_IV_D9, OUTPUT);
    pinMode(MOTOR_IV_D4, OUTPUT);
    stop();
}


void Robot::drive_forward()
{
    digitalWrite(MOTOR_I_D9, HIGH);
    digitalWrite(MOTOR_I_D4, LOW);
    digitalWrite(MOTOR_II_D8, LOW);
    digitalWrite(MOTOR_II_D7, HIGH);
    digitalWrite(MOTOR_III_D8, HIGH);
    digitalWrite(MOTOR_III_D7, LOW);
    digitalWrite(MOTOR_IV_D9, LOW);
    digitalWrite(MOTOR_IV_D4, HIGH);
}

void Robot::drive_back()
{
    digitalWrite(MOTOR_I_D9, LOW);
    digitalWrite(MOTOR_I_D4, HIGH);
    digitalWrite(MOTOR_II_D8, HIGH);
    digitalWrite(MOTOR_II_D7, LOW);
    digitalWrite(MOTOR_III_D8, LOW);
    digitalWrite(MOTOR_III_D7, HIGH);
    digitalWrite(MOTOR_IV_D9, HIGH);
    digitalWrite(MOTOR_IV_D4, LOW);
}

void Robot::turn_left_forward()
{
    digitalWrite(MOTOR_I_D9, HIGH);
    digitalWrite(MOTOR_I_D4, LOW);
    digitalWrite(MOTOR_II_D8, LOW);
    digitalWrite(MOTOR_II_D7, HIGH);
    digitalWrite(MOTOR_III_D8, HIGH);
    digitalWrite(MOTOR_III_D7, LOW);
    digitalWrite(MOTOR_IV_D9, LOW);
    digitalWrite(MOTOR_IV_D4, HIGH);
}

void Robot::turn_right_forward()
{
    digitalWrite(MOTOR_I_D9, HIGH);
    digitalWrite(MOTOR_I_D4, LOW);
    digitalWrite(MOTOR_II_D8, LOW);
    digitalWrite(MOTOR_II_D7, HIGH);
    digitalWrite(MOTOR_III_D8, HIGH);
    digitalWrite(MOTOR_III_D7, LOW);
    digitalWrite(MOTOR_IV_D9, LOW);
    digitalWrite(MOTOR_IV_D4, HIGH);
}
    
void Robot::turn_left_back()
{
    digitalWrite(MOTOR_I_D9, LOW);
    digitalWrite(MOTOR_I_D4, HIGH);
    digitalWrite(MOTOR_II_D8, HIGH);
    digitalWrite(MOTOR_II_D7, LOW);
    digitalWrite(MOTOR_III_D8, LOW);
    digitalWrite(MOTOR_III_D7, HIGH);
    digitalWrite(MOTOR_IV_D9, HIGH);
    digitalWrite(MOTOR_IV_D4, LOW);
}

void Robot::turn_right_back()
{
    digitalWrite(MOTOR_I_D9, LOW);
    digitalWrite(MOTOR_I_D4, HIGH);
    digitalWrite(MOTOR_II_D8, HIGH);
    digitalWrite(MOTOR_II_D7, LOW);
    digitalWrite(MOTOR_III_D8, LOW);
    digitalWrite(MOTOR_III_D7, HIGH);
    digitalWrite(MOTOR_IV_D9, HIGH);
    digitalWrite(MOTOR_IV_D4, LOW);
}

void Robot::turn_left_inplace()
{
    digitalWrite(MOTOR_I_D9, HIGH);
    digitalWrite(MOTOR_I_D4, LOW);
    digitalWrite(MOTOR_II_D8, LOW);
    digitalWrite(MOTOR_II_D7, HIGH);
    digitalWrite(MOTOR_III_D8, LOW);
    digitalWrite(MOTOR_III_D7, HIGH);
    digitalWrite(MOTOR_IV_D9, HIGH);
    digitalWrite(MOTOR_IV_D4, LOW);
}

void Robot::turn_right_inplace()
{
    digitalWrite(MOTOR_I_D9, LOW);
    digitalWrite(MOTOR_I_D4, HIGH);
    digitalWrite(MOTOR_II_D8, HIGH);
    digitalWrite(MOTOR_II_D7, LOW);
    digitalWrite(MOTOR_III_D8, HIGH);
    digitalWrite(MOTOR_III_D7, LOW);
    digitalWrite(MOTOR_IV_D9, LOW);
    digitalWrite(MOTOR_IV_D4, HIGH);
}

void Robot::stop()
{
    digitalWrite(MOTOR_I_D9, LOW);
    digitalWrite(MOTOR_I_D4, LOW);
    digitalWrite(MOTOR_II_D8, LOW);
    digitalWrite(MOTOR_II_D7, LOW);
    digitalWrite(MOTOR_III_D8, LOW);
    digitalWrite(MOTOR_III_D7, LOW);
    digitalWrite(MOTOR_IV_D9, LOW);
    digitalWrite(MOTOR_IV_D4, LOW);
}
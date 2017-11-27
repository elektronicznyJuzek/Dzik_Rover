#ifndef ROBOT_H
#define ROBOT_H

/*****************\
*                 *
*  ###        ### *
*  #1#=@@@@@@=#3# *              
*  ### @@@@@@ ### *                 
*      @@@@@@     *                   
*  ### @@@@@@ ### *                      
*  #2#=@@@@@@=#4# *                  
*  ###        ### *                  
*                 *          
\*****************/  

#define MOTOR_I_D9 7
#define MOTOR_I_D4 3
#define MOTOR_II_D8 0
#define MOTOR_II_D7 2
#define MOTOR_III_D8 24
#define MOTOR_III_D7 23
#define MOTOR_IV_D9 25
#define MOTOR_IV_D4 22

#define PORT 4950

#include <QObject>
#include <QUdpSocket>
#include <QMap>
#include <QDebug>

class Robot : public QObject
{
    Q_OBJECT
private:
    QUdpSocket *socket;
    QHostAddress WAddress = QHostAddress("192.168.0.102");
    QMap<int,bool> control_map;
    QMap<QString,double> meas_map;
    QByteArray datagram;
    QHostAddress sender;
    quint16 senderPort;
    unsigned char buffer[2];
public:
    explicit Robot(QObject *parent = 0);
    void send_data_to_WorkStation(QMap<QString,double>);
    void robot_control();
    void robot_speed(bool);
    void motor_init();
    void drive_forward();
    void drive_back();
    void turn_left_forward();
    void turn_right_forward();
    void turn_left_back();
    void turn_right_back();
    void turn_left_inplace();
    void turn_right_inplace();
    void stop();

signals:

public slots:
     void read_data_from_WorkStation();
};

#endif // UDP_ROBOT_H
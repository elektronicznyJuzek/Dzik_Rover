#include <QDebug>
#include <QTimer>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "udp_workstation.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);
    startTimer(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *)
{
        UDP_WorkStation client;
        client.send_data_to_ROBOT(keys);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
   keys[event->key()] = true; QWidget::keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
   keys[event->key()] = false; QWidget::keyReleaseEvent(event);
}


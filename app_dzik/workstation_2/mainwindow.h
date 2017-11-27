#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <QMap>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

private:
    Ui::MainWindow *ui;
    QMap<int,bool> keys{
        {Qt::Key_Up,false},
        {Qt::Key_Down,false},
        {Qt::Key_Left,false},
        {Qt::Key_Right,false},
        {Qt::Key_Space,false},
        {Qt::Key_Shift,false}
    };
    QKeyEvent *event;
};

#endif // MAINWINDOW_H

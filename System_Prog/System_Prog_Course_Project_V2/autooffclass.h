#ifndef AUTOOFFCLASS_H
#define AUTOOFFCLASS_H

#include <QWidget>
#include <QMainWindow>
#include "mainwindowclass.h"
#include "mythread.h"
#include "timeroffclass.h"
#include <QProcess>

#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QMouseEvent>
#include <QMessageBox>
#include <QPixmap>
#include <QPushButton>
#include <QBoxLayout>


namespace Ui {
class AutoOffClass;
}

class AutoOffClass : public QWidget
{
    Q_OBJECT

public:
    explicit AutoOffClass(QWidget *parent = nullptr);
    ~AutoOffClass();

protected:
    //void paintEvent(QPaintEvent *event) override;
    virtual void mousePressEvent(QMouseEvent * pe) override;
    virtual void mouseMoveEvent(QMouseEvent *me) override;

signals:
    void endLesson(int64_t n);
    void finished();
    void timerStart();
    void errorOff();
    void startErrorOffTimer();

private:
    void workOffTime();


private slots:
    void offPC();
    void startThread(int64_t n);
    void endLessonTime();
    void threeMinutesWarning();
    void setNextValue();
    void setErrorOffNextValue();
    void errorOffMessage();
    void timerWork();
    void errorOffTimerWork();

private:
    Ui::AutoOffClass *ui;
    MainWindowClass mc;
    QPoint oldPos;
    MyThread *thread;
    TimerOffClass *timerOff;
    QTimer *pcOfftimer;
    QTimer *errorOffTimer;
    QProcess *shutdownProcess;
    int value;
    int errorValue;
};

#endif // AUTOOFFCLASS_H

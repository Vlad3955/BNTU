//#ifndef AUTOOFFCLOCK_H
//#define AUTOOFFCLOCK_H

//#include <QWidget>
//#include "mainwindowclass.h"
//#include "mythread.h"
//#include "timeroffclass.h"

//class AutoOffClock : public QWidget
//{
//    Q_OBJECT

//public:
//    AutoOffClock(QWidget *parent = nullptr);
//    ~AutoOffClock();

//protected:
//    void paintEvent(QPaintEvent *event) override;
//    virtual void mousePressEvent(QMouseEvent * pe) override;
//    virtual void mouseMoveEvent(QMouseEvent *me) override;

//signals:
//    void endLesson();

//private:
//    void workOffTime();

//private slots:
//    void offPC();
//    void startThread();
//    void endLessonTime();

//private:
//    MainWindowClass mc;
//    QPoint oldPos;
//    MyThread *thread;
//    TimerOffClass *timerOff;
//};
//#endif // AUTOOFFCLOCK_H



// VARIANT II
//==========================================================
//==========================================================

//#ifndef AUTOOFFCLOCK_H
//#define AUTOOFFCLOCK_H

//#include <QWidget>
//#include "mainwindowclass.h"
//#include "mythread.h"
//#include "timeroffclass.h"

//class AutoOffClock : public QWidget
//{
//    Q_OBJECT

//public:
//    AutoOffClock(QWidget *parent = nullptr);
//    ~AutoOffClock();

//protected:
//    void paintEvent(QPaintEvent *event) override;
//    virtual void mousePressEvent(QMouseEvent * pe) override;
//    virtual void mouseMoveEvent(QMouseEvent *me) override;

//signals:
//    void endLesson(int64_t n);

//private:
//    void workOffTime();

//private slots:
//    void offPC();
//    void startThread(int64_t n);
//    void endLessonTime();
//    void threeMinutesWarning();

//private:
//    MainWindowClass mc;
//    QPoint oldPos;
//    MyThread *thread;
//    TimerOffClass *timerOff;
//};
//#endif // AUTOOFFCLOCK_H


// VARIANT III
//==========================================================
//==========================================================


#ifndef AUTOOFFCLOCK_H
#define AUTOOFFCLOCK_H

#include <QWidget>
#include "mainwindowclass.h"
#include "mythread.h"
#include "timeroffclass.h"
#include <QProcess>

class AutoOffClock : public QWidget
{
    Q_OBJECT

public:
    AutoOffClock(QWidget *parent = nullptr);
    ~AutoOffClock();

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
#endif // AUTOOFFCLOCK_H
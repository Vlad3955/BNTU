//#include "timeroffclass.h"
//#include <QDebug>

//TimerOffClass::TimerOffClass(int n, QObject *parent)
//    : QObject{parent}
//{
//    value = n;
//    timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(setNextValue()));
//    //endLessonTime();
//}

//void TimerOffClass::timerWork()
//{
//    timer->start(1000);
//    qDebug() << "work";
//}

//void TimerOffClass::setNextValue()
//{
//    --value;
//    if (value == 0)
//    {
//        emit finished();
//        timer->stop();
//    }
//    qDebug() << value;
//}

////void TimerOffClass::endLessonTime()
////{
////    bool t = true;
////    while (t)
////    {
////        if (QTime::currentTime().hour() == 16 && QTime::currentTime().minute() == 39)
////        {
////            t = false;
////        }
////    }
////}


// VARIANT II
//==========================================================
//==========================================================

//#include "timeroffclass.h"
//#include <QDebug>

//TimerOffClass::TimerOffClass(QObject *parent)
//    : QObject{parent}
//{
//    timer = new QTimer(this);
//    connect(this, SIGNAL(timerStart()), this, SLOT(timerWork()));
//    connect(timer, SIGNAL(timeout()), this, SLOT(setNextValue()));
//}

//void TimerOffClass::timerWork()
//{
//    timer->start(1000);
//    qDebug() << "work";
//}

//void TimerOffClass::setValue(int64_t n)
//{
//    value = n;
//    qDebug() << n;
//    emit timerStart();
//}

//void TimerOffClass::setNextValue()
//{
//    --value;
//    if (value == 2450)
//    {
//        emit threeMenutesSignal();
//    }
//    if (value == 0)
//    {
//        emit finished();
//        timer->stop();
//    }
//    qDebug() << value;
//}



// VARIANT III
//==========================================================
//==========================================================


#include "timeroffclass.h"
#include <QDebug>

TimerOffClass::TimerOffClass(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    connect(this, SIGNAL(timerStart()), this, SLOT(timerWork()));
    connect(timer, SIGNAL(timeout()), this, SLOT(setNextValue()));
}

void TimerOffClass::timerWork()
{
    timer->start(1000);
    qDebug() << "work";
}

void TimerOffClass::setValue(int64_t n)
{
    value = n;
    qDebug() << n;
    emit timerStart();
}

void TimerOffClass::setNextValue()
{
    --value;
    if (value == 0)
    {
        timer->stop();
        emit threeMenutesSignal();
        emit finished();
    }
    qDebug() << value;
}

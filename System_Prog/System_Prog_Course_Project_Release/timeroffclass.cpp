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

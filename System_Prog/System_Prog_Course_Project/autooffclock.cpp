//#include "autooffclock.h"
//#include "qapplication.h"

//#include <QPainter>
//#include <QTime>
//#include <QTimer>
//#include <QMouseEvent>
//#include <QMessageBox>

//AutoOffClock::AutoOffClock(QWidget *parent)
//    : QWidget(parent)
//{
//    QTimer *timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, QOverload<>::of(&AutoOffClock::update));
//    timer->start(1000);
//    setWindowTitle(tr("Analog Clock"));
//    resize(200, 200);

//    thread = new MyThread();
//    timerOff = new TimerOffClass(30, this);
//    timerOff->moveToThread(thread);
//    connect(timerOff, SIGNAL(finished()), thread, SLOT(quit()));
//    connect(thread, SIGNAL(finished()), this, SLOT(offPC()));
//    connect(this, SIGNAL(endLesson()), this, SLOT(startThread()));
//    endLessonTime();

//}

//AutoOffClock::~AutoOffClock()
//{

//}

//void AutoOffClock::paintEvent(QPaintEvent *event)
//{
//    workOffTime();

//    Q_UNUSED(event)
//    static const QPoint hourHand[3] = {
//        QPoint(7, 8),
//        QPoint(-7, 8),
//        QPoint(0, -40)
//    };
//    static const QPoint minuteHand[3] = {
//        QPoint(7, 8),
//        QPoint(-7, 8),
//        QPoint(0, -70)
//    };

//    QColor hourColor(127, 0, 127);
//    QColor minuteColor(0, 127, 127, 191);

//    int side = qMin(width(), height());

//    QPainter painter(this);

//    painter.setRenderHint(QPainter::Antialiasing);

//    painter.translate(width() / 2, height() / 2);

//    painter.scale(side / 200.0, side / 200.0);

//    painter.setPen(Qt::NoPen);

//    painter.setBrush(hourColor);

//    QTime time = QTime::currentTime();

//    painter.save();

//    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
//    painter.drawConvexPolygon(hourHand, 3);
//    painter.restore();

//    painter.setPen(hourColor);

//    for (int i = 0; i < 12; ++i) {
//        painter.drawLine(88, 0, 96, 0);
//        painter.rotate(30.0);
//    }

//    painter.setPen(Qt::NoPen);

//    painter.setBrush(minuteColor);

//    painter.save();
//    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
//    painter.drawConvexPolygon(minuteHand, 3);
//    painter.restore();

//    painter.setPen(minuteColor);

//    for (int j = 0; j < 60; ++j) {
//        if ((j % 5) != 0)
//            painter.drawLine(92, 0, 96, 0);
//        painter.rotate(6.0);
//    }
//}

//void AutoOffClock::mousePressEvent(QMouseEvent *pe)
//{
//    if (pe->button() == Qt::LeftButton)
//    {
//        oldPos = pe->pos();
//        mc.show();
//    }
//}

//void AutoOffClock::mouseMoveEvent(QMouseEvent *me)
//{
//    QPoint delta = me->pos() - oldPos;
//    move(pos() + delta);
//}

//void AutoOffClock::workOffTime()
//{
//    QMessageBox msgBox;

//    if (QTime::currentTime().hour() > 18 || (QTime::currentTime().hour() == 18 && QTime::currentTime().minute() >= 40) || QTime::currentTime().hour() <= 7)
//    {
//        if (QTime::currentTime().hour() == 7 && QTime::currentTime().minute() >= 35)
//        {
//            return;
//        }
//        qDebug() << QTime::currentTime();
//        msgBox.setText("Приложение будет закрыто");
//        msgBox.setDefaultButton(QMessageBox::Ok);
//        msgBox.exec();
//        qApp->exit();
//    }
//}

//void AutoOffClock::offPC()
//{
//    QMessageBox msgBox;
//    qDebug() << QTime::currentTime();
//    msgBox.setText("Ты говняшка!");
//    msgBox.setDefaultButton(QMessageBox::Ok);
//    msgBox.exec();
//}

//void AutoOffClock::startThread()
//{

//    thread->start();
//    timerOff->timerWork();
//}

//void AutoOffClock::endLessonTime()
//{
//    if (QTime::currentTime().hour() == 12 && QTime::currentTime().minute() == 36)
//    {
//        emit endLesson();

//    }
//}



// VARIANT II
//==========================================================
//==========================================================

//#include "autooffclock.h"
//#include "qapplication.h"

//#include <QPainter>
//#include <QTime>
//#include <QTimer>
//#include <QMouseEvent>
//#include <QMessageBox>

//AutoOffClock::AutoOffClock(QWidget *parent)
//    : QWidget(parent)
//{
//    QTimer *timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, QOverload<>::of(&AutoOffClock::update));
//    timer->start(1000);
//    setWindowTitle(tr("Analog Clock"));
//    resize(200, 200);

//    thread = new MyThread();
//    timerOff = new TimerOffClass(this);
//    timerOff->moveToThread(thread);
//    connect(timerOff, SIGNAL(finished()), thread, SLOT(quit()));
//    connect(thread, SIGNAL(finished()), this, SLOT(offPC()));
//    connect(this, SIGNAL(endLesson(int64_t)), this, SLOT(startThread(int64_t)));
//    connect(timerOff, SIGNAL(threeMenutesSignal()), this, SLOT(threeMinutesWarning()));
//    endLessonTime();

//}

//AutoOffClock::~AutoOffClock()
//{

//}

//void AutoOffClock::paintEvent(QPaintEvent *event)
//{
//    workOffTime();

//    Q_UNUSED(event)
//    static const QPoint hourHand[3] = {
//        QPoint(7, 8),
//        QPoint(-7, 8),
//        QPoint(0, -40)
//    };
//    static const QPoint minuteHand[3] = {
//        QPoint(7, 8),
//        QPoint(-7, 8),
//        QPoint(0, -70)
//    };

//    QColor hourColor(127, 0, 127);
//    QColor minuteColor(0, 127, 127, 191);

//    int side = qMin(width(), height());

//    QPainter painter(this);

//    painter.setRenderHint(QPainter::Antialiasing);

//    painter.translate(width() / 2, height() / 2);

//    painter.scale(side / 200.0, side / 200.0);

//    painter.setPen(Qt::NoPen);

//    painter.setBrush(hourColor);

//    QTime time = QTime::currentTime();

//    painter.save();

//    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
//    painter.drawConvexPolygon(hourHand, 3);
//    painter.restore();

//    painter.setPen(hourColor);

//    for (int i = 0; i < 12; ++i) {
//        painter.drawLine(88, 0, 96, 0);
//        painter.rotate(30.0);
//    }

//    painter.setPen(Qt::NoPen);

//    painter.setBrush(minuteColor);

//    painter.save();
//    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
//    painter.drawConvexPolygon(minuteHand, 3);
//    painter.restore();

//    painter.setPen(minuteColor);

//    for (int j = 0; j < 60; ++j) {
//        if ((j % 5) != 0)
//            painter.drawLine(92, 0, 96, 0);
//        painter.rotate(6.0);
//    }
//}

//void AutoOffClock::mousePressEvent(QMouseEvent *pe)
//{
//    if (pe->button() == Qt::LeftButton)
//    {
//        oldPos = pe->pos();
//        mc.show();
//    }
//}

//void AutoOffClock::mouseMoveEvent(QMouseEvent *me)
//{
//    QPoint delta = me->pos() - oldPos;
//    move(pos() + delta);
//}

//void AutoOffClock::workOffTime()
//{
//    QMessageBox msgBox;

//    if (QTime::currentTime().hour() >= 18 || (QTime::currentTime().hour() == 18 && QTime::currentTime().minute() >= 40) || QTime::currentTime().hour() <= 7)
//    {
//        if (QTime::currentTime().hour() == 7 && QTime::currentTime().minute() >= 35)
//        {
//            return;
//        }
//        msgBox.setText("Компьютер включен в нервбочее время. Программа будет закрыта");
//        msgBox.setDefaultButton(QMessageBox::Ok);
//        msgBox.exec();
//        qApp->exit();
//    }
//}

//void AutoOffClock::offPC()
//{
//    QMessageBox msgBox;
//    qDebug() << QTime::currentTime();
//    msgBox.setText("Ты говняшка!");
//    msgBox.setDefaultButton(QMessageBox::Ok);
//    msgBox.exec();
//}

//void AutoOffClock::startThread(int64_t n)
//{

//    thread->start();
//    timerOff->setValue(n);
//}

//void AutoOffClock::endLessonTime()
//{
//    int hour = QTime::currentTime().hour();
//    int minutes = QTime::currentTime().minute();

//    if (hour < 10 || (hour == 10 && minutes <= 20))
//    {
//        QTime alarmTime = QTime(10, 23, 0, 0);
//        QTime res = QTime::currentTime();;
//        emit endLesson(res.msecsTo(alarmTime) / 1000);
//    }
//    else if (hour < 11 || (hour == 11 && minutes <= 55))
//    {
//        QTime alarmTime = QTime(11, 58, 0, 0);
//        QTime res = QTime::currentTime();;
//        emit endLesson(res.msecsTo(alarmTime) / 1000);
//    }
//    else if (hour < 13 || (hour == 13 && minutes <= 45))
//    {
//        QTime alarmTime = QTime(13, 48, 0, 0);
//        QTime res = QTime::currentTime();;
//        emit endLesson(res.msecsTo(alarmTime) / 1000);
//    }
//    else if (hour < 15 || (hour == 15 && minutes <= 20))
//    {
//        QTime alarmTime = QTime(15, 23, 0, 0);
//        QTime res = QTime::currentTime();;
//        emit endLesson(res.msecsTo(alarmTime) / 1000);
//    }
//    else if (hour < 17 || (hour == 17 && minutes <= 10))
//    {
//        QTime alarmTime = QTime(17, 13, 0, 0);
//        QTime res = QTime::currentTime();;
//        emit endLesson(res.msecsTo(alarmTime) / 1000);
//    }
//}

//void AutoOffClock::threeMinutesWarning()
//{
//    QMessageBox::warning(nullptr, "Предупреждение", "Сделай выкл");
//}


// VARIANT III
//==========================================================
//==========================================================


#include "autooffclock.h"
#include "qapplication.h"

#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QMouseEvent>
#include <QMessageBox>
#include <QPixmap>

AutoOffClock::AutoOffClock(QWidget *parent)
    : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&AutoOffClock::update));
    timer->start(1000);
    setWindowTitle(tr("PC Off"));
    resize(250, 200);

    workOffTime();
    //setAttribute(Qt::WA_TranslucentBackground);

    shutdownProcess = new QProcess(this);
    pcOfftimer = new QTimer(this);
    errorOffTimer = new QTimer(this);
    value = 170;
    errorValue = 20;
    thread = new MyThread();
    timerOff = new TimerOffClass(this);
    timerOff->moveToThread(thread);

    connect(timerOff, SIGNAL(finished()), thread, SLOT(quit()));
    connect(this, SIGNAL(endLesson(int64_t)), this, SLOT(startThread(int64_t)));
    connect(timerOff, SIGNAL(threeMenutesSignal()), this, SLOT(timerWork()));
    connect(pcOfftimer, SIGNAL(timeout()), this, SLOT(setNextValue()));
    connect(timerOff, SIGNAL(threeMenutesSignal()), this, SLOT(threeMinutesWarning()));
    connect(this, SIGNAL(finished()), this, SLOT(offPC()));
    endLessonTime();

    connect(this, SIGNAL(startErrorOffTimer()), this, SLOT(errorOffTimerWork()));
    connect(errorOffTimer, SIGNAL(timeout()), this, SLOT(setErrorOffNextValue()));
    connect(this, SIGNAL(errorOff()), this, SLOT(errorOffMessage()));
    endLessonTime();

}

AutoOffClock::~AutoOffClock()
{

}

//void AutoOffClock::paintEvent(QPaintEvent *event)
//{
//    workOffTime();

//    Q_UNUSED(event)
//    static const QPoint hourHand[3] = {
//        QPoint(7, 8),
//        QPoint(-7, 8),
//        QPoint(0, -40)
//    };
//    static const QPoint minuteHand[3] = {
//        QPoint(7, 8),
//        QPoint(-7, 8),
//        QPoint(0, -70)
//    };

//    QColor hourColor(127, 0, 127);
//    QColor minuteColor(0, 127, 127, 191);

//    int side = qMin(width(), height());

//    QPainter painter(this);

//    painter.setRenderHint(QPainter::Antialiasing);

//    painter.translate(width() / 2, height() / 2);

//    painter.scale(side / 200.0, side / 200.0);

//    painter.setPen(Qt::NoPen);

//    painter.setBrush(hourColor);

//    QTime time = QTime::currentTime();

//    painter.save();

//    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
//    painter.drawConvexPolygon(hourHand, 3);
//    painter.restore();

//    painter.setPen(hourColor);

//    for (int i = 0; i < 12; ++i) {
//        painter.drawLine(88, 0, 96, 0);
//        painter.rotate(30.0);
//    }

//    painter.setPen(Qt::NoPen);

//    painter.setBrush(minuteColor);

//    painter.save();
//    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
//    painter.drawConvexPolygon(minuteHand, 3);
//    painter.restore();

//    painter.setPen(minuteColor);

//    for (int j = 0; j < 60; ++j) {
//        if ((j % 5) != 0)
//            painter.drawLine(92, 0, 96, 0);
//        painter.rotate(6.0);
//    }
//}

void AutoOffClock::mousePressEvent(QMouseEvent *pe)
{
    if (pe->button() == Qt::LeftButton)
    {
        oldPos = pe->pos();
        mc.show();
    }
}

void AutoOffClock::mouseMoveEvent(QMouseEvent *me)
{
    QPoint delta = me->pos() - oldPos;
    move(pos() + delta);
}

void AutoOffClock::workOffTime()
{
    QMessageBox msgBox;

    if (QTime::currentTime().hour() >= 18 || (QTime::currentTime().hour() == 18 && QTime::currentTime().minute() >= 40) || QTime::currentTime().hour() <= 7)
    {
        if (QTime::currentTime().hour() == 7 && QTime::currentTime().minute() >= 35)
        {
            return;
        }
        msgBox.setText("Компьютер включен в нервбочее время. Программа будет закрыта");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        qApp->exit();
    }
}

void AutoOffClock::timerWork()
{
    pcOfftimer->start(1000);
    qDebug() << "pcOfftimer";
}

void AutoOffClock::errorOffTimerWork()
{
    errorOffTimer->start(1000);
    qDebug() << "errorOfftimer";
}

void AutoOffClock::offPC()
{
    emit startErrorOffTimer();
    QStringList arguments = QStringList() << "-s" << "-t" << "10";
    shutdownProcess->start("shutdown", arguments);

}

void AutoOffClock::startThread(int64_t n)
{
    thread->start();
    timerOff->setValue(n);
}

void AutoOffClock::endLessonTime()
{
    int hour = QTime::currentTime().hour();
    int minutes = QTime::currentTime().minute();

    if (hour < 10 || (hour == 10 && minutes <= 20))
    {
        QTime alarmTime = QTime(10, 20, 0, 0);
        QTime res = QTime::currentTime();;
        emit endLesson(res.msecsTo(alarmTime) / 1000);
    }
    else if (hour < 11 || (hour == 11 && minutes <= 55))
    {
        QTime alarmTime = QTime(11, 55, 0, 0);
        QTime res = QTime::currentTime();;
        emit endLesson(res.msecsTo(alarmTime) / 1000);
    }
    else if (hour < 13 || (hour == 13 && minutes <= 45))
    {
        QTime alarmTime = QTime(13, 45, 0, 0);
        QTime res = QTime::currentTime();;
        emit endLesson(res.msecsTo(alarmTime) / 1000);
    }
    else if (hour < 15 || (hour == 15 && minutes <= 20))
    {
        QTime alarmTime = QTime(15, 20, 0, 0);
        QTime res = QTime::currentTime();;
        emit endLesson(res.msecsTo(alarmTime) / 1000);
    }
    else if (hour < 17 || (hour == 17 && minutes <= 10))
    {
        QTime alarmTime = QTime(17, 10, 0, 0);
        QTime res = QTime::currentTime();;
        emit endLesson(res.msecsTo(alarmTime) / 1000);
    }
}

void AutoOffClock::threeMinutesWarning()
{
    QMessageBox::warning(nullptr, "Предупреждение", "Пора заканчивать."
                                  "\nВыключите пожалуйста компьютер.\n"
                                  "Автоматическое выключение компьютера\n"
                                  "через 3 минуты.");
}

void AutoOffClock::setNextValue()
{
    --value;

    if (value == 0)
    {
        pcOfftimer->stop();
        emit finished();
    }
    qDebug() << value;
}

void AutoOffClock::setErrorOffNextValue()
{
    --errorValue;

    if (errorValue == 0)
    {
        errorOffTimer->stop();
        emit errorOff();
    }
}

void AutoOffClock::errorOffMessage()
{
    QMessageBox::critical(nullptr, "Error", "Невозможно выключить компьютер!");
}

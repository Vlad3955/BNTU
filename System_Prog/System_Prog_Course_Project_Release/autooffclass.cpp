#include "autooffclass.h"
#include "ui_autooffclass.h"

AutoOffClass::AutoOffClass(QWidget *parent) :
    QWidget(parent, Qt::FramelessWindowHint | Qt::Window),
    ui(new Ui::AutoOffClass)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->label->setAttribute(Qt::WA_TranslucentBackground);
    ui->label->setPixmap(QPixmap(":/pic/alarm-clock-128.png"));

    QPushButton* pcmdQuit = new QPushButton("X");
    pcmdQuit->setFixedSize(16, 16);
    connect(pcmdQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
    QVBoxLayout* pvbx = new QVBoxLayout;
    pvbx->addWidget(pcmdQuit);
    pvbx->addStretch(1);
    ui->label->setLayout(pvbx);

    msgBox = new QMessageBox(this);
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
    connect(this, SIGNAL(workOffTimeSignal()), this, SLOT(workOffTime()));
    connect(this, SIGNAL(startErrorOffTimer()), this, SLOT(errorOffTimerWork()));
    connect(errorOffTimer, SIGNAL(timeout()), this, SLOT(setErrorOffNextValue()));
    connect(this, SIGNAL(errorOff()), this, SLOT(errorOffMessage()));

    endLessonTime();
}

AutoOffClass::~AutoOffClass()
{
    delete ui;
}


void AutoOffClass::mousePressEvent(QMouseEvent *pe)
{
    if (pe->button() == Qt::LeftButton)
    {
        oldPos = pe->pos();
        mc.show();
    }
}

void AutoOffClass::mouseMoveEvent(QMouseEvent *me)
{
    QPoint delta = me->pos() - oldPos;
    move(pos() + delta);
}

void AutoOffClass::workOffTime()
{
    msgBox->setText("Компьютер включен в нервбочее время. Программа будет закрыта");
    msgBox->setDefaultButton(QMessageBox::Ok);
    msgBox->exec();
    exit(0);
}

void AutoOffClass::timerWork()
{
    pcOfftimer->start(1000);
    qDebug() << "pcOfftimer";
}

void AutoOffClass::errorOffTimerWork()
{
    errorOffTimer->start(1000);
    qDebug() << "errorOfftimer";
}

void AutoOffClass::offPC()
{
    emit startErrorOffTimer();
    QStringList arguments = QStringList() << "-s" << "-t" << "10";
    shutdownProcess->start("shutdown", arguments);

}

void AutoOffClass::startThread(int64_t n)
{
    thread->start();
    timerOff->setValue(n);
}

void AutoOffClass::endLessonTime()
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
    else if (QTime::currentTime().hour() >= 18 || (QTime::currentTime().hour() == 18 && QTime::currentTime().minute() >= 40) || QTime::currentTime().hour() <= 7)
    {
        if (QTime::currentTime().hour() == 7 && QTime::currentTime().minute() >= 35)
        {
            return;
        }
        emit workOffTimeSignal();
    }
}

void AutoOffClass::threeMinutesWarning()
{
    QMessageBox::warning(nullptr, "Предупреждение", "Пора заканчивать."
                                  "\nВыключите пожалуйста компьютер.\n"
                                  "Автоматическое выключение компьютера\n"
                                  "через 3 минуты.");
}

void AutoOffClass::setNextValue()
{
    --value;

    if (value == 0)
    {
        pcOfftimer->stop();
        emit finished();
    }
    qDebug() << value;
}

void AutoOffClass::setErrorOffNextValue()
{
    --errorValue;

    if (errorValue == 0)
    {
        errorOffTimer->stop();
        emit errorOff();
    }
}

void AutoOffClass::errorOffMessage()
{
    QMessageBox::critical(nullptr, "Error", "Невозможно выключить компьютер!");
}

#include "mainwindowclass.h"
#include "ui_mainwindowclass.h"

#include <QTime>
#include <QTimer>


MainWindowClass::MainWindowClass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
    setWindowTitle(tr("PC Off"));
    setFixedHeight(162);
    setFixedWidth(279);
    displayTimeOff();
}

MainWindowClass::~MainWindowClass()
{
    delete ui;
}

void MainWindowClass::displayTimeOff()
{
    lessonHour1 = 10, LessonMinutes1 = 20;
    lessonHour2 =11, LessonMinutes2 = 55,
    lessonHour3 = 13, LessonMinutes3 = 45,
    lessonHour4 = 15, LessonMinutes4 = 20,
    lessonHour5 = 17, LessonMinutes5 = 10;
    int hour = QTime::currentTime().hour();
    int minutes = QTime::currentTime().minute();
    QString lesson;

    if (hour < 10 || (hour == 10 && minutes <= 20))
    {
        lesson = QString::number(lessonHour1) + ":" + (QString::number(LessonMinutes1 + 3));
        ui->l_time->setText(lesson);
    }
    else if (hour < 11 || (hour == 11 && minutes <= 55))
    {
        lesson = QString::number(lessonHour2) + ":" + (QString::number(LessonMinutes2 + 3));
        ui->l_time->setText(lesson);
    }
    else if (hour < 13 || (hour == 13 && minutes <= 45))
    {
        lesson = QString::number(lessonHour3) + ":" + (QString::number(LessonMinutes3 + 3));
        ui->l_time->setText(lesson);
    }
    else if (hour < 15 || (hour == 15 && minutes <= 20))
    {
        lesson = QString::number(lessonHour4) + ":" + (QString::number(LessonMinutes4 + 3));
        ui->l_time->setText(lesson);
    }
    else if (hour < 17 || (hour == 17 && minutes <= 10))
    {
        lesson = QString::number(lessonHour5) + ":" + (QString::number(LessonMinutes5 + 3));
        ui->l_time->setText(lesson);
    }
    else
    {
        ui->l_time->setText("До завтра!");
    }
}

void MainWindowClass::mousePressEvent(QMouseEvent *pe)
{
    if (pe->button() == Qt::LeftButton)
    {
        oldPos = pe->pos();
        this->close();
    }
}

void MainWindowClass::mouseMoveEvent(QMouseEvent *me)
{
    QPoint delta = me->pos() - oldPos;
    move(pos() + delta);
}

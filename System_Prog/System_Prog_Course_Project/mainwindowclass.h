#ifndef MAINWINDOWCLASS_H
#define MAINWINDOWCLASS_H

#include <QWidget>
#include <QString>
#include <QMouseEvent>

namespace Ui {
class MainWindowClass;
}

class MainWindowClass : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindowClass(QWidget *parent = nullptr);
    ~MainWindowClass();
    void displayTimeOff();

protected:
    virtual void mousePressEvent(QMouseEvent * pe) override;
    virtual void mouseMoveEvent(QMouseEvent *me) override;

private:
    Ui::MainWindowClass *ui;
    QPoint oldPos;
    int lessonHour1, LessonMinutes1,
    lessonHour2, LessonMinutes2,
    lessonHour3, LessonMinutes3,
    lessonHour4, LessonMinutes4,
    lessonHour5, LessonMinutes5;
};

#endif // MAINWINDOWCLASS_H

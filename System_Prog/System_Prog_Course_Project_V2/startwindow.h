#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QLabel>
#include <QObject>
#include <QMouseEvent>

class StartWindow : public QLabel
{
    Q_OBJECT
public:
    StartWindow(QWidget* pwgt = 0);

protected:
    virtual void mousePressEvent(QMouseEvent * pe) override;
    virtual void mouseMoveEvent(QMouseEvent *me) override;

private:
    QPoint oldPos;

};

#endif // STARTWINDOW_H

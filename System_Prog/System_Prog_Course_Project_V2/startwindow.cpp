#include "startwindow.h"

StartWindow::StartWindow(QWidget *pwgt)
    : QLabel(pwgt, Qt::FramelessWindowHint | Qt::Window)
{

}

void StartWindow::mousePressEvent(QMouseEvent *pe)
{
    if (pe->button() == Qt::LeftButton)
    {
        oldPos = pe->pos();
    }
}

void StartWindow::mouseMoveEvent(QMouseEvent *me)
{
    QPoint delta = me->pos() - oldPos;
    move(pos() + delta);
}

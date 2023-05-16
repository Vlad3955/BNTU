#include "mythread.h"
#include "qdebug.h"

MyThread::MyThread()
{
    qDebug() << "MyThread";
}

void MyThread::run()
{
    exec();
}

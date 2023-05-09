#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QObject>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    void run() override;
};

#endif // MYTHREAD_H

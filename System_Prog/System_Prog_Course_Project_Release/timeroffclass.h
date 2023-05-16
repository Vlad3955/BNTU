#ifndef TIMEROFFCLASS_H
#define TIMEROFFCLASS_H

#include <QObject>
#include <QTimer>
#include <QTime>

class TimerOffClass : public QObject
{
    Q_OBJECT
public:
    explicit TimerOffClass(QObject *parent = nullptr);

signals:
    void finished();
    void timerStart();
    void threeMenutesSignal();

public slots:
    void timerWork();
    void setValue(int64_t n);

private slots:
    void setNextValue();



private:
    QTimer *timer;
    int value;
};


#endif // TIMEROFFCLASS_H

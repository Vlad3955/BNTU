#include "autooffclock.h"
#include "autooffclass.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //AutoOffClock w;
    AutoOffClass w;
    w.show();
    return a.exec();
}

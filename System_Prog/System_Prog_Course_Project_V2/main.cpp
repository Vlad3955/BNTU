#include "autooffclass.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AutoOffClass w;
    w.show();
    return a.exec();
}

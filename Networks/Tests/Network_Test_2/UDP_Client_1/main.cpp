#include "udp_client.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UDP_Client w;
    w.show();
    return a.exec();
}

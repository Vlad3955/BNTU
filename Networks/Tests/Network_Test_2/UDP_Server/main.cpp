#include <QCoreApplication>
#include "udp_server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TCP_Server tcp_s;
    return a.exec();
}

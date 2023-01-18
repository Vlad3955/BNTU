#include "tcp_server.h"
#include <QDebug>

TCP_Server::TCP_Server()
{
    if (this->listen(QHostAddress::Any, 11111))
    {
        qDebug() << "start";
    }
    else
    {
        qDebug() << "error";
    }
    nextBlockSize = 0;
}

void TCP_Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &TCP_Server::slot_ready_read);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    qDebug() << "client connected" << socketDescriptor;
}

void TCP_Server::slot_ready_read()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);
    if (in.status() == QDataStream::Ok)
    {
        qDebug() << "read...";
//        QString str;
//        in >> str;
//        qDebug() << str;
//        send_to_client(str);
        for (;;)
        {
            if (nextBlockSize == 0)
            {
                if (socket->bytesAvailable() < 2)
                {
                    break;
                }
                in >> nextBlockSize;
            }
            if (socket->bytesAvailable() < nextBlockSize)
            {
                break;
            }
            QString str;
            in >> str;
            nextBlockSize = 0;
            send_to_client(str);
            break;
        }
    }
    else
    {
        qDebug() << "DataStream error";
    }
}

void TCP_Server::send_to_client(QString str)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << quint16(0) << str;
    out.device()->seek(0);
    out << quint16(Data.size() - sizeof(quint16));
    //socket->write(Data);
    for (int i = 0; i < Sockets.size(); ++i)
    {
        Sockets[i]->write(Data);
    }
}

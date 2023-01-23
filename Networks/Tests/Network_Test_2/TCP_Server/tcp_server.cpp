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
    connect(socket, &QTcpSocket::readyRead, this, &TCP_Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    qDebug() << "client connected" << socketDescriptor;
}

void TCP_Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);
    if (in.status() == QDataStream::Ok)
    {
        qDebug() << "read...";
        for (;;)
        {
            if (nextBlockSize == 0)
            {
                qDebug() << "nextBlockSize == 0";
                if (socket->bytesAvailable() < 2)
                {
                    qDebug() << "Data < 2, break.";
                    break;
                }
                in >> nextBlockSize;
                qDebug() << "nextBlockSize = " << nextBlockSize;
            }
            if (socket->bytesAvailable() < nextBlockSize)
            {
                 qDebug() << "Do not full, break.";
                break;
            }
            QString str;
            QTime time;
            in >> time >> str;
            nextBlockSize = 0;
            qDebug() << str;
            SendToClient(str);
            break;
        }
    }
    else
    {
        qDebug() << "DataStream error";
    }
}

void TCP_Server::SendToClient(QString str)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << quint16(0) << QTime::currentTime() << str;
    out.device()->seek(0);
    out << quint16(Data.size() - sizeof(quint16));
    for (int i = 0; i < Sockets.size(); ++i)
    {
        Sockets[i]->write(Data);
    }
}

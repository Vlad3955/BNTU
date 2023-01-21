#ifndef TCP_SERVER_H
#define TCP_SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QDataStream>
#include <QTime>


class TCP_Server : public QTcpServer
{
    Q_OBJECT

public:
    TCP_Server();
    QTcpSocket *socket;

private:
    QVector<QTcpSocket*> Sockets;
    QByteArray Data;
    quint16 nextBlockSize;
    void SendToClient(QString str);

public slots:
    void incomingConnection(qintptr socketDescriptor) override;
    void slotReadyRead();
};

#endif // TCP_SERVER_H

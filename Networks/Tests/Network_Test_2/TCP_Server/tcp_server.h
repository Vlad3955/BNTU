#ifndef TCP_SERVER_H
#define TCP_SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>


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
    void send_to_client(QString str);

public slots:
    void incomingConnection(qintptr socketDescriptor) override;
    void slot_ready_read();
};

#endif // TCP_SERVER_H

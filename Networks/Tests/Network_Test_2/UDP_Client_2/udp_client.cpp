#include "udp_client.h"
#include "ui_udp_client.h"

UDP_Client::UDP_Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UDP_Client)
{
    ui->setupUi(this);

    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 11112);
    connect (socket, SIGNAL(readyRead()),this, SLOT(reading_data()));
}

UDP_Client::~UDP_Client()
{
    delete ui;
}

void UDP_Client::reading_data()
{
    QHostAddress sender;
    quint16 sender_port;

    while (socket->hasPendingDatagrams())
    {
         QByteArray datagram;
         datagram.resize(socket->pendingDatagramSize());
         socket->readDatagram(datagram.data(),datagram.size(),&sender,&sender_port);
         ui->textEdit->append("<font color=red>" + QString(datagram) + "</font");
         qDebug() << datagram.data() << "IP: " + sender.toString() << "Port: " + QString("%1").arg(sender_port);
    }
}


void UDP_Client::on_pushButton_clicked()
{
    socket->writeDatagram(ui->lineEdit->text().toUtf8(), QHostAddress::LocalHost, 11111);
    ui->textEdit->append("You: <font color=cyan>" + ui->lineEdit->text() + "</font");
    ui->lineEdit->clear();
}


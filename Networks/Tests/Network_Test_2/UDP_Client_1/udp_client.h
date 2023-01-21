#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class UDP_Client; }
QT_END_NAMESPACE

class UDP_Client : public QMainWindow
{
    Q_OBJECT

public:
    UDP_Client(QWidget *parent = nullptr);
    ~UDP_Client();

public slots:
    void reading_data();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UDP_Client *ui;
    QUdpSocket *socket;
};
#endif // UDP_CLIENT_H

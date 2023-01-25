#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMultiMap>
#include <QStandardItemModel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    struct Aeroflot {
        QString dest;
        QString flight_num = 0;
        Aeroflot(QString d, QString fn) : dest(d), flight_num(fn) {}
    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_add_clicked();

    void on_pb_del_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QMultiMap<QString, Aeroflot*> aerofl;
    QStandardItemModel *model;
    QStandardItemModel *modelSearch;
};
#endif // MAINWINDOW_H

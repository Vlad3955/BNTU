#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMultiMap>
#include <QStandardItemModel>
#include <QMenuBar>
#include <QMenu>
#include <QFileDialog>
#include <QFile>
#include <QEvent>
#include <QKeyEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    // Struct for filling the multimap
    struct Aeroflot {
        QString dest;
        QString flight_num = 0;
        Aeroflot(QString d, QString fn) : dest(d), flight_num(fn) {}
    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
     void keyPressEvent(QKeyEvent *event) override;

private slots:
    void on_pb_add_clicked();

    void on_pb_del_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pb_open_clicked();

    void on_pb_save_clicked();

private:
    Ui::MainWindow *ui;
    QMultiMap<QString, Aeroflot*> aerofl;
    QStandardItemModel *model;
    QStandardItemModel *modelSearch;
    QString pathSave;
    QString path;
};
#endif // MAINWINDOW_H

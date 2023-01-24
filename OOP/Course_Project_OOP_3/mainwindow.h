#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMultiMap>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "qmultimapmodel.h"
#include "aeroflot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_add_clicked();

    void on_pb_del_clicked();

private:
    Ui::MainWindow *ui;
    QMultiMap<QString, Aeroflot*> aerofl;
    QStandardItemModel *model;
    QItemSelectionModel *selectionModel;
    QMultiMapModel qmmmod;
};
#endif // MAINWINDOW_H

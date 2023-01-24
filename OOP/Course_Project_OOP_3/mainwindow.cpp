#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    aerofl.clear();
    aerofl.insert("Airbus A320", new Aeroflot("London", "1234"));
    aerofl.insert("Airbus A320", new Aeroflot("Helsinki", "3509"));
    aerofl.insert("Boeing 737 MAX", new Aeroflot("Paris", "5398"));


//    model = new QStandardItemModel(0, 0, this);
//    selectionModel = new QItemSelectionModel(model, this);
//    for (auto it = aerofl.begin(); it != aerofl.end(); ++ it)
//    {
//        QStandardItem *item_col_1 = new QStandardItem(it.key());
//        QStandardItem *item_col_2 = new QStandardItem(it.value()->dest);
//        QStandardItem *item_col_3 = new QStandardItem(it.value()->flight_num);
//        model->appendRow(QList<QStandardItem*>() << item_col_1 << item_col_2 << item_col_3);
//    }
//    ui->tableView_2->setModel(model);
//    ui->tableView_2->setSelectionModel(selectionModel);

    //qmmmod = new QMultiMapModel(this);
    qmmmod.setMultiMap(&aerofl);

    ui->tableView_2->setModel(&qmmmod);
    //ui->tableView_2->setSelectionModel(selectionModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_add_clicked()
{
    int const row_count = model->rowCount();
    model->insertRow(row_count);
    model->setData(model->index(row_count, 3), Qt::DisplayRole);
}


void MainWindow::on_pb_del_clicked()
{
    if(!ui->tableView->selectionModel()->selectedIndexes().isEmpty())
    {
        QModelIndexList indexList = ui->tableView->selectionModel()->selectedIndexes();

        model->removeRow(indexList.last().row());
    }



}


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


    model = new QStandardItemModel(0, 0, this);
    for (auto it = aerofl.begin(); it != aerofl.end(); ++ it)
    {
        QStandardItem *item_col_1 = new QStandardItem(it.key());
        QStandardItem *item_col_2 = new QStandardItem(it.value()->dest);
        QStandardItem *item_col_3 = new QStandardItem(it.value()->flight_num);
        model->appendRow(QList<QStandardItem*>() << item_col_1 << item_col_2 << item_col_3);
    }
    ui->tableView_2->setModel(model);
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
    // Variant I
    if(!ui->tableView_2->selectionModel()->selectedIndexes().isEmpty())
    {
        QModelIndexList indexList = ui->tableView_2->selectionModel()->selectedIndexes();

        model->removeRow(indexList.last().row());
    }
    else
    {
        return;
    }

    // Variant II
//    if(!ui->tableView_2->selectionModel()->selectedIndexes().isEmpty())
//    {
//        QModelIndexList indexList = ui->tableView_2->selectionModel()->selectedRows();

//        model->removeRows(indexList.last().row(), 1);
//    }
//    else
//    {
//        return;
//    }
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->tableView_2->model()->sort(0, Qt::AscendingOrder);
}


void MainWindow::on_pushButton_6_clicked()
{
    QString str = ui->lineEdit->text();
    modelSearch = new QStandardItemModel(this);
    for (int index = 0; index < model->columnCount(); ++index)
    {
        QList<QStandardItem*> items = model->findItems(str,Qt::MatchExactly, index);
        int count = items.count();
        if (count > 0)
        {

            for (int k = 0; k < count; ++k)
            {
                QModelIndex modelIndex = model->indexFromItem(items[k]);

                QModelIndex index1 = model->index(modelIndex.row(), 0);
                QModelIndex index2 = model->index(modelIndex.row(), 1);
                QModelIndex index3 = model->index(modelIndex.row(), 2);
                QStandardItem *item_col_1 = new QStandardItem(index1.data(Qt::DisplayRole).toString());
                QStandardItem *item_col_2 = new QStandardItem(index2.data(Qt::DisplayRole).toString());
                QStandardItem *item_col_3 = new QStandardItem(index3.data(Qt::DisplayRole).toString());
                modelSearch->appendRow(QList<QStandardItem*>() << item_col_1 << item_col_2 << item_col_3);
                //modelSearch->appendRow(QList<QStandardItem*>() << item_col_1);
                qDebug() << "Column = " << index << "Row = " << modelIndex.row();
            }
        }
    }
    ui->tableView->setModel(modelSearch);
}


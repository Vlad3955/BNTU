#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Filling the multimap, used if the table is empty and there is no boot file

//    aerofl.clear();
//    aerofl.insert("Airbus A320", new Aeroflot("London", "1234"));
//    aerofl.insert("Airbus A320", new Aeroflot("Helsinki", "3509"));
//    aerofl.insert("Boeing 737 MAX", new Aeroflot("Paris", "5398"));


    model = new QStandardItemModel(0, 0, this);
    model->setHorizontalHeaderItem(0, new QStandardItem("Тип самолёта"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Направление"));
    model->setHorizontalHeaderItem(2, new QStandardItem("Номер"));

    // Displaying a Multimap in a view

//    for (auto it = aerofl.begin(); it != aerofl.end(); ++ it)
//    {
//        QStandardItem *item_col_1 = new QStandardItem(it.key());
//        QStandardItem *item_col_2 = new QStandardItem(it.value()->dest);
//        QStandardItem *item_col_3 = new QStandardItem(it.value()->flight_num);
//        model->appendRow(QList<QStandardItem*>() << item_col_1 << item_col_2 << item_col_3);
//    }

    ui->tableView_2->setModel(model);

    modelSearch = new QStandardItemModel(this);
    modelSearch->setHorizontalHeaderItem(0, new QStandardItem("Тип самолёта"));
    modelSearch->setHorizontalHeaderItem(1, new QStandardItem("Направление"));
    modelSearch->setHorizontalHeaderItem(2, new QStandardItem("Номер"));

    QMenu *file_menu = menuBar()->addMenu("Файл");
    file_menu->addAction("Открыть       CTRL+O", this, SLOT(on_pb_open_clicked()));
    file_menu->addSeparator();
    file_menu->addAction("Сохранить как... CTRL+S", this, SLOT(on_pb_save_clicked()));

    QMenu *tools_menu = menuBar()->addMenu("Инструменты");
    tools_menu->addAction("Добавить", this, SLOT(on_pb_add_clicked()));
    tools_menu->addSeparator();
    tools_menu->addAction("Удалить", this, SLOT(on_pb_del_clicked()));

    ui->tableView->setModel(modelSearch);
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

// Sort button
void MainWindow::on_pushButton_5_clicked()
{
    ui->tableView_2->model()->sort(0, Qt::AscendingOrder);
}

// Search button
void MainWindow::on_pushButton_6_clicked()
{
    QString str = ui->lineEdit->text();
    //ui->lineEdit->clear();


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
                qDebug() << "Column = " << index << "Row = " << modelIndex.row();
            }
        }
    }
}


void MainWindow::on_pb_open_clicked()
{
    // Variant .csv

//    path = QFileDialog::getOpenFileName();
//    if (path.isEmpty())
//    {
//        return;
//    }
//    QFile file(path);
//    if (file.open(QIODevice::ReadOnly))
//    {
//        int lineindex = 0;                     // file line counter
//        QTextStream in(&file);                 // read to text stream

//        while (!in.atEnd()) {

//            // read one line from textstream(separated by "\n")
//            QString fileLine = in.readLine();

//            // parse the read line into separate pieces(tokens) with "," as the delimiter
//            QStringList lineToken = fileLine.split(";", Qt::SkipEmptyParts);

//            // load parsed data to model accordingly
//            for (int j = 0; j < lineToken.size(); j++) {
//                QString value = lineToken.at(j);
//                QStandardItem *item = new QStandardItem(value);
//                model->setItem(lineindex, j, item);
//            }

//            lineindex++;
//        }

//        file.close();
//    }

//==================================================================================
//==================================================================================

    // Variant .txt

    path = QFileDialog::getOpenFileName();
    if (path.isEmpty())
    {
        return;
    }
    QFile file(path);
    if (file.open(QIODevice::ReadOnly))
    {
        int lineindex = 0;                     // file line counter
        QTextStream in(&file);                 // read to text stream

        while (!in.atEnd()) {

            // read one line from textstream(separated by "\n")
            QString fileLine = in.readLine();

            // parse the read line into separate pieces(tokens) with "," as the delimiter
            QStringList lineToken = fileLine.split(" ", Qt::SkipEmptyParts);

            // load parsed data to model accordingly
            for (int j = 0; j < lineToken.size(); j++) {
                QString value = lineToken.at(j);
                QStandardItem *item = new QStandardItem(value);
                model->setItem(lineindex, j, item);
            }

            lineindex++;
        }

        file.close();
    }
}


void MainWindow::on_pb_save_clicked()
{
    QString textData;
    int rows = model->rowCount();
    int columns = model->columnCount();

//==================================================================================
//==================================================================================

      // Variant .txt

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {

             textData += model->data(model->index(i,j)).toString();
             textData += " ";      // for .csv file format
        }
        textData += "\n";             // (optional: for new line segmentation)
    }

    pathSave = QFileDialog::getSaveFileName();
    if (pathSave.isEmpty())
    {
        return;
    }
    QFile txtFile(pathSave);
    if (txtFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&txtFile);
        out << textData;

        txtFile.close();
    }

//==================================================================================
//==================================================================================

    // Variant .csv I

//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < columns; j++)
//        {

//             textData += model->data(model->index(i,j)).toString();
//             textData += " ";      // for .csv file format
//        }
//        textData += "\n";             // (optional: for new line segmentation)
//    }

//    pathSave = QFileDialog::getSaveFileName();
//    if (pathSave.isEmpty())
//    {
//        return;
//    }
//    QFile csvFile(pathSave);
//    if (csvFile.open(QIODevice::WriteOnly))
//    {
//        QTextStream out(&csvFile);
//        out << textData;

//        csvFile.close();
//    }

//==================================================================================
//==================================================================================

      // Variant .cvs II with table horizontal header

//    QString filters("CSV files (*.csv);;All files (*.*)");
//    QString defaultFilter("CSV files (*.csv)");
//    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
//                       filters, &defaultFilter);
//    QFile file(fileName);

//    QAbstractItemModel *model =  ui->tableView_2->model();
//    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
//        QTextStream data(&file);
//        QStringList strList;
//        for (int i = 0; i < model->columnCount(); i++) {
////            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
////                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
////            else
//                strList.append("");
//        }
//        data << strList.join(";") << "\n";
//        for (int i = 0; i < model->rowCount(); i++) {
//            strList.clear();
//            for (int j = 0; j < model->columnCount(); j++) {

//                if (model->data(model->index(i, j)).toString().length() > 0)
//                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
//                else
//                    strList.append("");
//            }
//            data << strList.join(";") + "\n";
//        }
//        file.close();
//    }

//==================================================================================
//==================================================================================

    // Variant .cvs III without table horizontal header

//    QString filters("CSV files (*.csv);;All files (*.*)");
//    QString defaultFilter("CSV files (*.csv)");
//    pathSave = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
//                       filters, &defaultFilter);
//    QFile file(pathSave);

//    QAbstractItemModel *model =  ui->tableView_2->model();
//    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
//        QTextStream data(&file);
//        QStringList strList;
//        //data << strList.join(";") << "\n";
//        for (int i = 0; i < model->rowCount(); i++)
//        {
//            strList.clear();
//            for (int j = 0; j < model->columnCount(); j++) {

//                if (model->data(model->index(i, j)).toString().length() > 0)
//                    strList.append(model->data(model->index(i, j)).toString());
//                else
//                    strList.append("");
//            }
//            data << strList.join(";") + "\n";
//        }
//        file.close();
//    }
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_O:
        if (event->modifiers() & Qt::ControlModifier)
        {
            this->on_pb_open_clicked();
        }
        break;
    case Qt::Key_S:
        if (event->modifiers() & Qt::ControlModifier)
        {
            this->on_pb_save_clicked();
        }
        break;
    case Qt::Key_Q:
        if (event->modifiers() & Qt::ControlModifier)
        {
            exit(0);
        }
        break;
    default:
        break;
    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    ui->listView->setModel(model);
    model->appendRow(new QStandardItem(QIcon(":/Icons/c++.png"),"c++"));
    model->appendRow(new QStandardItem(QIcon(":/Icons/Python.png"), "Python"));
    model->appendRow(new QStandardItem(QIcon(":/Icons/java.png"), "Java"));
    model->appendRow(new QStandardItem(QIcon(":/Icons/C#"), "C#"));
    model->appendRow(new QStandardItem(QIcon(":/Icons/PHP.png"), "PHP"));
    model->appendRow(new QStandardItem(QIcon(":/Icons/JavaScript.png"), "JavaScript"));

    ui->listView->setViewMode(QListView::IconMode);
    ui->listView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString newItem = ui->lineEdit->text();
    model->appendRow(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_FileIcon)),newItem));
}


void MainWindow::on_deleteButton_clicked()
{
    int row = ui->listView->currentIndex().row();
    model->removeRow(row);
}

void MainWindow::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    {
        ui->listView->setViewMode(QListView::IconMode);
    }
    else
    {
        ui->listView->setViewMode(QListView::ListMode);
    }
}

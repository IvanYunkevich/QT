#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double side1 = ui->lineEdit->text().toDouble();
    double side2 = ui->lineEdit_2->text().toDouble();
    double angle = ui->lineEdit_3->text().toDouble();

    if (ui->radioButton_g->isChecked())
    {
        angle = (angle * (M_PI/180));
    }
    double side3 = qSqrt(side1*side1+side2*side2-2*side1*side2*qCos(angle));
    QString answer = QString::number(side3);
    ui->lineEdit_4->setText(answer);
}


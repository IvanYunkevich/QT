#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "weather.h"
#include "parse.h"

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

void MainWindow::on_ButtonChoose_clicked()
{
    filePath = QFileDialog::getOpenFileName(this,"Открыть файл с HTML-кодом");
    ui->labelFilePath->setText(filePath);
}

void MainWindow::on_ButtonDisplay_clicked()
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray r = file.readAll();
        QString text(r);
        Weather weather(text);
        ui->textBrowser->setText(weather.parse());
        ParseCurrents currents(text);
        ui->lineEdit_usd->setText(currents.parseCur("USD"));
        ui->lineEdit_eur->setText(currents.parseCur("EUR"));
    }
}

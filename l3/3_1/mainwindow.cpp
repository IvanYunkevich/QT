#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QTextStream"
#include "QVBoxLayout"
#include "QLabel"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Текстовый редактор");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QString filename = QFileDialog::getOpenFileName();
    if(filename.length())
    {
        QFile file(filename);
        if(file.open(QFile::ReadOnly | QFile::ExistingOnly))
        {
            QTextStream stream(&file);
            ui->plainTextEdit->setPlainText(stream.readAll());
            file.close();
        }
    }
}

void MainWindow::on_action_2_triggered()
{
    QString fileName = QFileDialog::getSaveFileName();
    if(fileName.length())
    {
        QFile file(fileName);
        if(file.open(QFile::WriteOnly | QFile::NewOnly))
        {
            QTextStream stream(&file);
            stream << ui->plainTextEdit->toPlainText();
            file.close();
        }
    }
}

void MainWindow::on_action_3_triggered()
{
    QWidget* pWindow = new QWidget();
    QDialog* d = new QDialog(pWindow);
    d->setMinimumWidth(200);
    d->setMinimumHeight(100);
    d->setWindowTitle("Справка");
    QVBoxLayout *vlayout = new QVBoxLayout;
    QLabel *label = new QLabel("Version 1.0");
    vlayout->addWidget(label);
    d->setLayout(vlayout);
    d->show();
}

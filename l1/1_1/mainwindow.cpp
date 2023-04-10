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
    double a = ui->lineEdit->text().toDouble();
    double b = ui->lineEdit_2->text().toDouble();
    double c = ui->lineEdit_3->text().toDouble();
    double d = b*b - 4*a*c;
    QString answer;
    if (a == 0) {
        if (b != 0){
            double x = c*(-1)/b;
            answer = QStringLiteral("x = %1").arg(x);
        }
        else {
            answer = "Корней нет";
        }
    }
    else {
        if (d < 0) {
            answer = "Корней нет";
        }
        else if (d > 0) {
            double x1 = (b*(-1)+pow(d,0.5))/(2*a);
            double x2 = (b*(-1)-pow(d,0.5))/(2*a);
            answer = QStringLiteral("x1 = %1\nx2 = %2").arg(x1).arg(x2);
        }
        else{
            double x = b*(-1)/(2 * a);
            answer = QStringLiteral("x = %1").arg(x);
        }
    }
    ui->textEdit->setText(answer);
}


#include "comb.h"
#include "ui_comb.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
        
    ui->label->setText(tr("Открыть новый документ"));
    ui->label_2->setText(tr("Сохранить как..."));
    ui->label_3->setText(tr("Создать новый документ"));
    ui->label_4->setText(tr("Выход"));
        
    ui->radioButton->setChecked(true);
    ui->radioButton_4->setChecked(true);
    ui->radioButton_6->setChecked(true);
    ui->radioButton_8->setChecked(true);

    qTranslator.load(":/new/laguages/QtLanguage_ru.qm");
    qApp->installTranslator(&qTranslator);
    ui->retranslateUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setLanguage(int i)
{
   if(i)
   {
       qTranslator.load(":/new/laguages/QtLanguage_en.qm");
       qApp->installTranslator(&qTranslator);
       ui->retranslateUi(this);
   }else
   {
       qTranslator.load(":/new/laguages/QtLanguage_ru.qm");
       qApp->installTranslator(&qTranslator);
       ui->retranslateUi(this);
   }
}

bool Dialog::getCheckOpen()
{
    return ui->radioButton->isChecked();
}

bool Dialog::getCheckSave()
{
    return ui->radioButton_4->isChecked();
}

bool Dialog::getCheckNew()
{
    return ui->radioButton_6->isChecked();
}

bool Dialog::getCheckQuit()
{
    return ui->radioButton_8->isChecked();
}

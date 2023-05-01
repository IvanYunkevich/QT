#include "aboutprogram.h"
#include "ui_aboutprogram.h"
#include <QIcon>

aboutProgram::aboutProgram(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::aboutProgram)
{
    ui->setupUi(this);

    setDefaultLanguage();
}

aboutProgram::~aboutProgram()
{
    delete ui;
}

void aboutProgram::setDefaultLanguage()
{
    this->setWindowTitle(tr("О программе"));

    ui->label_info->setText(tr("Блокнот"));
}

void aboutProgram::setLanguage(Language::CodeLanguage code)
{
    if(Language::CodeLanguage::en == code)
    {
        qtranslator.load(":/language/qm/QtLanguage_en.qm");
        qApp->installTranslator(&qtranslator);
        ui->retranslateUi(this);
    }else
    {
        qtranslator.load(":/language/qm/QtLanguage_ru.qm");
        qApp->installTranslator(&qtranslator);
        ui->retranslateUi(this);
    }
}

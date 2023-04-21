#ifndef COMB_H
#define COMB_H

#include <QDialog>
#include <QTranslator>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    bool getCheckOpen();
    bool getCheckSave();
    bool getCheckNew();
    bool getCheckQuit();

    void setLanguage(int);

private:
    Ui::Dialog *ui;
    QTranslator qTranslator;
};

#endif // COMB_H

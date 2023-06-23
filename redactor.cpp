// Файл с описанием методов в классе Redactor

#include "redactor.h"
#include "ui_redactor.h"
#include "Forms/RedactDialog/redactdialog.h"

// [1]    Описание конструктора.
Redactor::Redactor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Redactor)
{
    ui->setupUi(this);
}
// [1]    Конец описания конструктора.

// [2]    Описание деструктора.
Redactor::~Redactor()
{
    delete ui;
}
// [2]    Конец описания деструктора.

// [3]    Описание функции on_pushButton_clicked.
void Redactor::on_pushButton_clicked()
{
    RedactDialog dialog;
    dialog.exec();
}
// [3]    Конец описания on_pushButton_clicked.

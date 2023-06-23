// Файл с описанием методов в классе RedactDialog

#include "redactdialog.h"
#include "ui_redactdialog.h"
#include "../../Parser/xmlparser.h"

// [1]    Описание конструктора.
RedactDialog::RedactDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RedactDialog)
{
    ui->setupUi(this);

    tree = parser.read();
    model = new TreeModel(tree);
    ui->treeView->setModel(model);
}
// [1]    Конец описания конструктора.

// [2]    Описание деструктора.
RedactDialog::~RedactDialog()
{
    delete ui;
    delete tree;
    delete model;
}
// [2]    Конец описания деструктора.

// [3]    Описание функции on_buttonBox_clicked.
//            button - указатель на кнопку
void RedactDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if (button->text() == "Save")
    {
        parser.write(tree);
        accept();
    }
    if (button->text() == "Close")
    {
        reject();
    }
}
// [3]    Конец описания on_buttonBox_clicked.


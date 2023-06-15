#include "redactdialog.h"
#include "ui_redactdialog.h"
#include "../../Parser/xmlparser.h"

RedactDialog::RedactDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RedactDialog)
{
    ui->setupUi(this);

    tree = parser.read();
    model = new TreeModel(tree);
    ui->treeView->setModel(model);
}

RedactDialog::~RedactDialog()
{
    delete ui;
    delete tree;
    delete model;
}

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


#include "redactor.h"
#include "ui_redactor.h"
#include "Forms/RedactDialog/redactdialog.h"

void SetApModel(TreeNode *node, QList <QModelIndex> deep_levels, QStandardItemModel *model);

Redactor::Redactor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Redactor)
{
    ui->setupUi(this);
}

Redactor::~Redactor()
{
    delete ui;
}


void Redactor::on_pushButton_clicked()
{
    RedactDialog dialog;
    dialog.show();
}


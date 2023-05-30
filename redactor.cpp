#include "redactor.h"
#include "ui_redactor.h"

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


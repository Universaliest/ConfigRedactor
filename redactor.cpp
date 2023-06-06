#include "redactor.h"
#include "ui_redactor.h"
#include "Parser/xmlparser.h"

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
   XmlParser().read();
}


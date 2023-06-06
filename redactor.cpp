#include "redactor.h"
#include "ui_redactor.h"
#include "Parser/xmlparser.h"
#include "Tree/tree.h"

Redactor::Redactor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Redactor)
{
    ui->setupUi(this);
    Tree *tree = XmlParser().read();
    //Вот здесь
}

Redactor::~Redactor()
{
    delete ui;
}

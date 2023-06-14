#include "redactor.h"
#include "ui_redactor.h"
#include "Parser/xmlparser.h"
#include "Tree/tree.h"
#include <Models/treemodel.h>
#include <QStandardItemModel>

void SetApModel(TreeNode *node, QList <QModelIndex> deep_levels, QStandardItemModel *model);

Redactor::Redactor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Redactor)
{
    ui->setupUi(this);


    tree = XmlParser().read();
    model = new TreeModel(tree);
//    //Вот здесь
//    model = new QStandardItemModel(1, 3);

//    QList<QModelIndex> deep_levels = {
//        model -> index(0, 0),
//        model -> index(0, 1),
//        model -> index(0, 2)
//    };

//    SetApModel(tree->root(), deep_levels, model);
    ui->treeView->setModel(model);
}

Redactor::~Redactor()
{
    delete ui;
    delete tree;
    delete model;
}


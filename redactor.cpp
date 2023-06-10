#include "redactor.h"
#include "ui_redactor.h"
#include "Parser/xmlparser.h"
#include "Tree/tree.h"
#include <QStandardItemModel>

void SetApModel(TreeNode *node, QList <QModelIndex> deep_levels, QStandardItemModel *model);

Redactor::Redactor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Redactor)
{
    ui->setupUi(this);
    tree = XmlParser().read();
    //Вот здесь
    model = new QStandardItemModel(1, 3);

    QList<QModelIndex> deep_levels = {
        model -> index(0, 0),
        model -> index(0, 1),
        model -> index(0, 2)
    };

    SetApModel(tree->root(), deep_levels, model);
    ui->treeView->setModel(model);
}

Redactor::~Redactor()
{
    delete ui;
    delete tree;
    delete model;
}


// deep_level - индекс?
void SetApModel(TreeNode *node, QList <QModelIndex> deep_levels, QStandardItemModel *model){
    model -> setData(deep_levels[0], node->dataPtr()->name());
    model -> setData(deep_levels[1], node->dataPtr()->description());
    model -> setData(deep_levels[2], node->dataPtr()->value());

    // 0 -> false, иначе -> true
    if (node->childrenCount()){
        model ->insertRows(0, node->childrenCount(), deep_levels[0]);
        model ->insertColumns(0, 3, deep_levels[0]);

        for(int i = 0; i < node->childrenCount(); i++){
            QList<QModelIndex> new_deep_levels = {
                model -> index(i, 0, deep_levels[0]),
                model -> index(i, 1, deep_levels[0]),
                model -> index(i, 2, deep_levels[0])
            };
            SetApModel(node->childAt(i), new_deep_levels, model);
        }
    }
};

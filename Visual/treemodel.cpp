#include "treemodel.h"


TreeModel::TreeModel(const Tree *tree, QObject *parent)
{
    _tree = new Tree(*tree);
}

TreeModel::~TreeModel()
{
    delete _tree;
}


#include "treemodel.h"
#include <Tree/treenode.h>
#include <Tree/tree.h>

#include <QDebug>

TreeModel::TreeModel()
{

}

TreeModel::TreeModel(Tree *tree)
{
    _tree = tree;

    // Дебагер =)
    // qDebug() << getItem(QModelIndex());
}

TreeModel::~TreeModel()
{

}

TreeNode *TreeModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()){
        TreeNode *item = static_cast<TreeNode*>(index.internalPointer());
        if (item)
            return item;
    }
    return _tree->root();
}


QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();

    TreeNode *parentItem = getItem(parent);
    if (!parentItem)
        return QModelIndex();

    TreeNode *childItem = parentItem ->childAt(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}



QModelIndex TreeModel::parent(const QModelIndex &index) const
{

}



int TreeModel::rowCount(const QModelIndex &parent) const
{

}



int TreeModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return Data::NumberOfValues;
}



QVariant TreeModel::data(const QModelIndex &index, int role) const
{

}



Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{

}



bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{


}


bool TreeModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    return false;
}




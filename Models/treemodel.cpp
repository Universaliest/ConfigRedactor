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
    // qDebug() << flags(QModelIndex());
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
    if (!index.isValid())
        return QModelIndex();

    TreeNode *childItem = getItem(index);
    TreeNode *parentItem = childItem ? childItem->parent() : nullptr;

    if (parentItem == _tree->root() || !parentItem)
        return QModelIndex();

    return createIndex(parentItem->childNumber(), 0, parentItem);
}



int TreeModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() > 0)
        return 0;

    TreeNode *parentItem = getItem(parent);

    return parentItem ? parentItem->childrenCount() : 0;
}



int TreeModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return Data::NumberOfValues;
}



QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    TreeNode *item = getItem(index);

    switch (index.column())
    {
        case 0:  return QVariant(item->dataPtr()->name());
        case 1:  return QVariant(item->dataPtr()->description());
        case 2:  return QVariant(item->dataPtr()->value());
        default: return QVariant();
    }
}



Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    Qt::ItemFlags flags = Qt::ItemIsEnabled;
    if (index.column() == 2 && getItem(index)->dataPtr()->value() != "")
        flags |= Qt::ItemIsEditable | Qt::ItemIsSelectable;
    return flags;
}



bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    // 3 - хочу с тобой написать и разобраться
    Q_UNUSED(index);
    Q_UNUSED(value);
    Q_UNUSED(role);
    return false; // заглушка
}


bool TreeModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    Q_UNUSED(section);
    Q_UNUSED(orientation);
    Q_UNUSED(value);
    Q_UNUSED(role);
    return false;
}

void TreeModel::setTree(Tree *tree)
{
    _tree = tree;
}





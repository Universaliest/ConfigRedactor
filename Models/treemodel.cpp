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

    // 1 - Как определить место ребенка для определенного родителя?
    // --------------------------------------------------------------------------------
    //    int TreeItem::childNumber() const
    //    {
    //        if (parentItem)
    //            return parentItem->childItems.indexOf(const_cast<TreeItem*>(this));
    //        return 0;
    //    }
    // где childItems - это List детей
    // return createIndex(parentItem->childNumber(), 0, parentItem);
    // --------------------------------------------------------------------------------
    // return createIndex(, 0, parentItem);
    return QModelIndex();   //Заглушка =)
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

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    TreeNode *item = getItem(index);

    // 2 - Как нам вернуть список данных?
    // return item->dataPtr(index.column());
}



Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}



bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    // 3 - хочу с тобой написать и разобраться
    return false; // заглушка
}


bool TreeModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    return false;
}

void TreeModel::setupModelData(const QStringList lines, TreeNode *parent)
{

}




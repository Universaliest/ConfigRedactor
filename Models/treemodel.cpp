#include "treemodel.h"
#include <Tree/treenode.h>

TreeModel::TreeModel()
{

}

TreeModel::TreeModel(TreeNode *tree, Data *data)
{
    _tree = tree;
    _data = data;
}



QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    // Если все данные известны
    if(hasIndex(row, column, parent)){
        return QModelIndex();
    }

    // Если не найдено родителя
    if(!parent.isValid()){
        return createIndex(row, column, const_cast<TreeNode*>(&_tree[row]));
    }

    // С этим местом небольшие проблемы, не понимаю прикола и кода
    // В коде из инета, что ты скинул, присутствует ссылка, но у нас она вызывает ошибку
    // ----------------------------------------------------------------------------------
    //    NodeInfo* parentInfo = static_cast<NodeInfo*>(parent.internalPointer());
    //    return createIndex(row, column, &parentInfo->children[row]);
    // ----------------------------------------------------------------------------------

    TreeNode* treeInfo = static_cast<TreeNode*>(parent.internalPointer());
    return createIndex(row, column, treeInfo ->childAt(row));
}


QModelIndex TreeModel::parent(const QModelIndex &child) const
{

}


int TreeModel::rowCount(const QModelIndex &parent) const
{

}


int TreeModel::columnCount(const QModelIndex &parent) const
{

}


QVariant TreeModel::data(const QModelIndex &index, int role) const
{

}

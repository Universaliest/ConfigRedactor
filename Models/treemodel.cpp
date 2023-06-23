// Файл с описанием методов в классе TreeModel.

#include "treemodel.h"
#include <Tree/treenode.h>
#include <Tree/tree.h>

#include <QDebug>

// [1]    Описание конструкторов.
TreeModel::TreeModel()
{

}

TreeModel::TreeModel(Tree *tree)
{
    _tree = tree;
}

TreeModel::~TreeModel()
{

}
// [1]    Конец описания конструкторов

// [2]    Описание функции getItem.
//            index - ссылка на существующий индекс, по которому возвращается структура.
TreeNode *TreeModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()){
        TreeNode *item = static_cast<TreeNode*>(index.internalPointer());
        if (item)
            return item;
    }
    return _tree->root();
}
// [2]    Конец описания getItem.

// [3]    Описание функции index.
//            row, column - строка и столбец нового индекса
//            parent - родитель нового индекса
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
//[3]    Конец описания index.

//[4]    Описание parent.
//            index - ссылка на существующий индекс, по которому возвращается его родитель.
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
//[4]    Конец описаения parent.

//[5]    Описание методов rowCount и columnCount.
//           parent - ссылка на существующий индекс, по которому определяется количество столбцов и строк.
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
//[5]    Конец описания rowCount и columnCount.

//[6]    Описание метода data.
//            index - ссылка на существующий индекс, по которому определяется элемент
//            role - роль (флаги), которая принадлежит индексу (редактируемвя, выделенная и тд.)
QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
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
//[6]    Конец описания data

//[7]    Описание метода headerData.
//            section - столбец
//            orientation - расположение элемента
//            role - роль (флаги), которая принадлежит индексу (редактируемвя, выделенная и тд.)
QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        switch (section)
        {
        case 0: return QVariant("Название");
        case 1: return QVariant("Описание");
        case 2: return QVariant("Значение");
        }
    return QVariant();
}
//[7]    Конец описания headerData.

//[8]    Описание метода flags.
//            index - ссылка на существующий индекс, по которому определяется элемент
Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    Qt::ItemFlags flags = Qt::ItemIsEnabled;
    if (index.column() == 2 && getItem(index)->dataPtr()->value() != "")
        flags |= Qt::ItemIsEditable | Qt::ItemIsSelectable;
    return flags;
}
//[8]    Конец описания flags.

//[9]    Описание метода setData.
//            index - ссылка на существующий индекс, по которому определяется элемент
//            value - ссылка на существующее значение определенного индекса
//            role - роль (флаги), которая принадлежит индексу (редактируемвя, выделенная и тд.)
bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    if (value == "")
        return false;

    getItem(index)->dataPtr()->setValue(value.toString());
    emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});
    return true;
}
//[9]    Конец описания setData.

//[10]    Описание методов setTree.
//            tree - указатель на дерево
void TreeModel::setTree(Tree *tree)
{
    _tree = tree;
}
//[10]    Конец описания setTree.




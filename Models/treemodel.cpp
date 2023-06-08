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

    // Если индекс не допустим?
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


// Под вопросом
//int TreeModel::findRow(const TreeNode *nodeInfo) const
//{

//}


QModelIndex TreeModel::parent(const QModelIndex &child) const
{
    // Если индекс не допустим?
    if(!child.isValid()){
        return QModelIndex();
    }

    TreeNode* childInfo = static_cast<TreeNode*>(child.internalPointer());
    TreeNode* parentInfo = childInfo ->parent();
    if(parentInfo != 0){    // Если родитель запрашивается не у корневого элемента
        // Это действие у меня находится под вопросом
        // return createIndex(findRow(parentInfo), /* столбец, по которому происходит ветвление, хз что это*/, parentInfo);
    }
    else {
        return QModelIndex();
    }
}


int TreeModel::rowCount(const QModelIndex &parent) const
{
    // На сайте тут такая охинея, не уверена, нужно ли нам это
    // ----------------------------------------------------------------------------------------------
    //    int FilesystemModel::rowCount(const QModelIndex &parent) const
    //    {
    //        if (!parent.isValid()) {
    //            return _nodes.size(); // _nodes - это список корневых узлов
    //        }
    //        const NodeInfo* parentInfo = static_cast<const NodeInfo*>(parent.internalPointer());
    //        return parentInfo->children.size(); // children - это список дочерних узлов
    //    }
    // ----------------------------------------------------------------------------------------------

}


QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    // С датой очень сложно, хотела бы разобрать это с тобой
    // ----------------------------------------------------------------------------------------------
    //    QVariant FilesystemModel::data(const QModelIndex &index, int role) const
    //    {
    //        if (!index.isValid()) {
    //            return QVariant();
    //        }

    //        const NodeInfo* nodeInfo = static_cast<NodeInfo*>(index.internalPointer());
    //        const QFileInfo& fileInfo = nodeInfo->fileInfo;

    //        switch (index.column()) {
    //        case NameColumn:
    //            return nameData(fileInfo, role);
    //        case ModificationDateColumn:
    //            if (role == Qt::DisplayRole) {
    //                return fileInfo.lastModified();
    //            }
    //            break;
    //        case SizeColumn:
    //            if (role == Qt::DisplayRole) {
    //                return fileInfo.isDir()? QVariant(): fileInfo.size();
    //            }
    //            break;
    //        default:
    //            break;
    //        }
    //        return QVariant();
    //    }

    //    QVariant FilesystemModel::nameData(const QFileInfo &fileInfo, int role) const
    //    {
    //        switch (role) {
    //        case Qt::EditRole:
    //            return fileInfo.fileName();
    //        case Qt::DisplayRole:
    //            if (fileInfo.isRoot()) {
    //                return fileInfo.absoluteFilePath();
    //            }
    //            else if (fileInfo.isDir()){
    //                return fileInfo.fileName();
    //            }
    //            else {
    //                return fileInfo.completeBaseName();
    //            }
    //        default:
    //            return QVariant();
    //        }
    //        Q_UNREACHABLE();
    //    }
    // ----------------------------------------------------------------------------------------------
}


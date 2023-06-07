#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <Tree/tree.h>
#include <Tree/data.h>

#include <QAbstractItemModel>
#include <QModelIndex>

class TreeModel: public QAbstractItemModel
{
public:
    //Конструктор и диструктор
    TreeModel();
    TreeModel(TreeNode *tree, Data *data);
    ~TreeModel();

    //Пересформированные методы модели
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
private:
    // Атрибуты
    TreeNode *_tree;
    Data *_data;
};

#endif // TREEMODEL_H

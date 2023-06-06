#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include "Tree/tree.h"

class TreeModel : public QAbstractItemModel
{
public:
    explicit TreeModel(const Tree *tree, QObject *parent = nullptr);
    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
private:
    Tree *_tree;
};

#endif // TREEMODEL_H

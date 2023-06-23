/// КЛАСС TreeModel
// Атрибуты класса:
//    -    _tree - указатель на дерево
// Функции класса:
//    +    index - функция для создания нового индекса на основе существующего.
//    +    parent - определение родительского индекса от входящего.
//    +    rowCount, columnCount - определение строк и столбцов соответственно на определённом индексе.
//    +    data - заполнение индексов указателями на данные.
//    +    headerData - заполнение названий столбцов.
//    +    flags - определение флагов каждого индекса.
//    +    setData - изменение данных в стркутуре по индексу.
//    +    setTree - задать дерево, по которому строится модель.
//    
//    -    getItem - получение элемента по его индексу.
#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <Tree/tree.h>
#include <Tree/data.h>

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVector>

class TreeModel: public QAbstractItemModel
{
    Q_OBJECT
public:
    //Конструкторы и деструктор
    TreeModel();
    TreeModel(Tree *tree);
    ~TreeModel();

    //Пересформированные методы модели
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    void setTree(Tree *tree);
private:
    Tree *_tree;
    TreeNode *getItem(const QModelIndex &index) const;
};

#endif // TREEMODEL_H

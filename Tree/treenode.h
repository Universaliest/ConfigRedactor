/// КЛАСС TreeNode
/// Атрибуты класса:
///     -   _data               -   Указатель на данные узла;
///     -   _parent             -   Указатель на родителя узла;
///     -   _children           -   Список указателей на дочерние узлы;
///     -   _childNumber        -   Номер дочернего элемента в списке родителя;
///     -   _childrenCount      -   Количество элементов в списке дочерних узлов;
/// Методы класса:
///     +   dataPtr         }
///     +   childrenCount   }   -   геттеры класса
///     +   parent          }
///     +   childNumber     }
///     +   childAt             -   Возврат дочернего узла по номеру в списке;
///     +   setParent           -   Сеттер родителя
///     +   appendChild         -   Добавление дочернего узла дерева в соотыетствующий список;

#ifndef QTREENODE_H
#define QTREENODE_H

#include "data.h"
#include <QList>

class TreeNode
{
public:
    TreeNode();
    TreeNode(TreeNode *parent, QList<TreeNode*> children, Data *data);
    ~TreeNode();

    Data* dataPtr();
    int childrenCount();
    TreeNode* parent();
    int childNumber();

    TreeNode* childAt(int index);

    void setParent(TreeNode *parent);
    void appendChild(TreeNode *child);


private:
    Data *_data;
    TreeNode *_parent = nullptr;
    QList<TreeNode*> _children;
    int _childNumber = -1;
    int _childrenCount = 0;
};

#endif // QTREENODE_H

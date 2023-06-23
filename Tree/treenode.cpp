// Файл с описанием методов в классе treenode

#include "treenode.h"
#include <QVariant>

// [1]    Описание конструкторов.
TreeNode::TreeNode()
{
    _data = new Data();
}

TreeNode::TreeNode(TreeNode *parent, QList<TreeNode*> children, Data *data)
{
    _parent = parent;
    _children = children;
    _data = new Data(*data);
}
// [1]    Конец описания конструкторов.

// [2]    Описание деструктора.
TreeNode::~TreeNode()
{
    if (_childrenCount)
    {
        for (int i = 0; i < _childrenCount; i++)
            delete _children[i];
    }
    delete _data;
}
// [2]    Конец описания деструктора.

// [3]    Описание геттеров класса.
Data *TreeNode::dataPtr()
{
    return _data;
}

int TreeNode::childrenCount()
{
    return _childrenCount;
}

TreeNode *TreeNode::parent()
{
    return _parent;
}

int TreeNode::childNumber()
{
    return _childNumber;
}
// [3]    Конец описания геттеров класса.

// [4]    Описание функции childAt.
//            index - ссылка на существующий индекс, по которому возвращается его ребенок
TreeNode* TreeNode::childAt(int index)
{
    return _children[index];
}
// [4]    Конец описания childAt.

// [5]    Описание сеттеров класса.
void TreeNode::setParent(TreeNode *parent)
{
    _parent = parent;
}

void TreeNode::appendChild(TreeNode *child)
{
    child->_childNumber = _childrenCount;
    _children.append(child);
    _childrenCount++;
}
// [5]    Конец описания сеттеров класса.

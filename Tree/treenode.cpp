#include "treenode.h"
#include <QVariant>

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

TreeNode::~TreeNode()
{
    if (_childrenCount)
    {
        for (int i = 0; i < _childrenCount; i++)
            delete _children[i];
    }
    delete _data;
}

Data *TreeNode::dataPtr()
{
    return _data;
}

int TreeNode::childrenCount()
{
    return _childrenCount;
}

TreeNode* TreeNode::childAt(int index)
{
    return _children[index];
}


TreeNode *TreeNode::parent()
{
    return _parent;
}

QVariant TreeNode::getValue(int column)
{
    if (column < 0 || column > Data::NumberOfValues)
        return QVariant();
    else
    {
        switch (column)
        {
        case 0:  return QVariant(_data->name());
        case 1:  return QVariant(_data->description());
        case 2:  return QVariant(_data->value());
        default: return QVariant();
        }
    }
}

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

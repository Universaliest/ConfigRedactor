#include "treenode.h"

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

void TreeNode::setParent(TreeNode *parent)
{
    _parent = parent;
}

void TreeNode::appendChild(TreeNode *child)
{
    _children.append(child);
    _childrenCount++;
}

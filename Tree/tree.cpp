#include "tree.h"

Tree::Tree(TreeNode *root)
{
    if (root->parent() == nullptr)
        _root = root;
    else
        throw "У корня не может быть родителей!";
}

Tree::~Tree()
{
    delete _root;
}

TreeNode *Tree::root()
{
    return _root;
}

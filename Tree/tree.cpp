// Файл с описанием методов в классе tree.

#include "tree.h"

// [1]    Описание конструктора.
Tree::Tree(TreeNode *root)
{
    if (root->parent() == nullptr)
        _root = root;
    else
        throw "У корня не может быть родителей!";
}
// [1]    Конец описания конструктора.

// [2]    Описание деструктора.
Tree::~Tree()
{
    delete _root;
}
// [2]    Конец описания деструктора.

// [3]    Описание функции root.
TreeNode *Tree::root()
{
    return _root;
}
// [3]    Конец описания root.

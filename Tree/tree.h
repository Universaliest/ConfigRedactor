/// КЛАСС tree
// Атрибуты класса:
//    -    _root - указатель на корневой элемент дерева
// Функции класса:
//    +    root - функция на определения root (корневой элемент дерева)

#ifndef TREE_H
#define TREE_H

#include "treenode.h"

class Tree
{
public:
    Tree(TreeNode *root);
    ~Tree();

    TreeNode* root();
private:
    TreeNode *_root;
};
#endif // TREE_H

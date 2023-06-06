#ifndef MODEL_H
#define MODEL_H

#include <QAbstractItemModel>
#include <Tree/treenode.h>
#include <Tree/tree.h>

// Прости, что так мало всего.. Мне очень тяжело самостоятельно что то делать..

class Model: QAbstractItemModel
{
public:
    Model();
    // + Конструктор хз как написать, не понимаю, что нужно..
    ~Model();

    void Index(TreeNode *node); //Немного не понимаю, что нужно использовать.. тоже Node?
    void SetData(TreeNode *node);
private:
    Tree *tree;
};

#endif // MODEL_H

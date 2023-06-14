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
    TreeNode* childAt(int index);
    TreeNode* parent();
    int childNumber();
    QString getNameOfNode();

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

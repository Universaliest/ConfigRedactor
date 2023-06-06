#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QDomNode>
#include "../Tree/tree.h"

class XmlParser
{
public:
    XmlParser();
    ~XmlParser();
    Tree *read();
private:
    TreeNode* deepDive(QDomNode &parent, TreeNode *tree_parent);
    Tree *_tree;

};

#endif // XMLPARSER_H

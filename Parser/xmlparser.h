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
    void write(Tree *tree);
private:
    TreeNode* fromDomToTree(QDomNode &dom_parent, TreeNode *tree_parent);
    void redactValuesInDom(QDomNode &dom_parent, TreeNode *tree_parent);

    QDomDocument _xmlDoc;
    Tree *_tree;

};

#endif // XMLPARSER_H

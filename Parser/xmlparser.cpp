#include "xmlparser.h"
#include <QFile>
#include <QtXML/QDomDocument>
#include <QtXml/QDomElement>
#include <QtXml/QDomNodeList>
#include <QCoreApplication>
#include <QDebug>
#include <QList>

XmlParser::XmlParser()
{

}

XmlParser::~XmlParser()
{
    delete _tree;
}

Tree &XmlParser::read()
{
    QFile XMLFile("D:/Qt Projects/ConfigRedactor/Parser/settings.xml");
    if (!XMLFile.open(QIODevice::ReadOnly))
    {
        throw "Файл не открывается!";
    }

    QDomDocument XMLDom;
    XMLDom.setContent(&XMLFile);
    XMLFile.close();

    QDomNode root = XMLDom.documentElement().childNodes().at(0);

    _tree = new Tree(deepDive(root, nullptr));

    return *_tree;

}

int deep_level = 0;
Data *data;

TreeNode* XmlParser::deepDive(QDomNode &parent, TreeNode *tree_parent)
{
    QString name = parent.attributes().namedItem("displayed_name").nodeValue();
    QString description = parent.attributes().namedItem("description").nodeValue();
    QString value = parent.attributes().namedItem("value").nodeValue();

    data = new Data(name, description, value);
    TreeNode *node = new TreeNode(tree_parent, {}, data);
    delete data;

    if (parent.hasChildNodes())
    {
        QDomNodeList child_list = parent.childNodes();
        for (int child_index = 0; child_index < child_list.count(); child_index++)
        {
            QDomNode child = QDomNode(child_list.at(child_index));
            deep_level++;
            node->appendChild(deepDive(child, node));
            deep_level--;
        }
    }
    return node;
}

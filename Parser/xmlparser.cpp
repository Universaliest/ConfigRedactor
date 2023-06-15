#include "xmlparser.h"
#include "pathoffile.h"
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

}

Tree *XmlParser::read()
{
    QFile xml_file(PATHOFFILE);
    if (!xml_file.open(QIODevice::ReadOnly))
    {
        throw "Файл не открывается!";
    }
    _xmlDoc.setContent(&xml_file);
    xml_file.close();

    QDomNode _root = _xmlDoc.documentElement().cloneNode();

    _tree = new Tree(fromDomToTree(_root, nullptr));

    return _tree;

}

void XmlParser::write(Tree *tree)
{

    QDomNode _root = _xmlDoc.documentElement();
    redactValuesInDom(_root, tree->root());

    QFile file(PATHOFFILE);

    if (!file.open(QIODevice::WriteOnly))
    {
        throw "a";
    }

    QTextStream stream(&file);

    stream << _xmlDoc;

    file.close();

}

int deep_level = 0;
Data *data;

TreeNode* XmlParser::fromDomToTree(QDomNode &dom_parent, TreeNode *tree_parent)
{
    QString name = dom_parent.attributes().namedItem("displayed_name").nodeValue();
    QString description = dom_parent.attributes().namedItem("description").nodeValue();
    QString value = dom_parent.attributes().namedItem("value").nodeValue();

    data = new Data(name, description, value);
    TreeNode *node = new TreeNode(tree_parent, {}, data);
    delete data;

    if (dom_parent.hasChildNodes())
    {
        QDomNodeList child_list = dom_parent.childNodes();
        for (int child_index = 0; child_index < child_list.count(); child_index++)
        {
            QDomNode child = QDomNode(child_list.at(child_index));
            deep_level++;
            node->appendChild(fromDomToTree(child, node));
            deep_level--;
        }
    }
    return node;
}

void XmlParser::redactValuesInDom(QDomNode &dom_parent, TreeNode *tree_parent)
{
    if (dom_parent.attributes().contains("value"))
        dom_parent.attributes().namedItem("value").setNodeValue(tree_parent->dataPtr()->value());

    if (dom_parent.hasChildNodes())
    {
        QDomNodeList child_list = dom_parent.childNodes();
        for (int child_index = 0; child_index < child_list.count(); child_index++)
        {
            QDomNode node = dom_parent.childNodes().at(child_index);
            redactValuesInDom(node, tree_parent->childAt(child_index));
        }
    }
}

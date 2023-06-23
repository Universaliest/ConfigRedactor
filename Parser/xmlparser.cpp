///     Файл описания процедур класса XmlParser

#include "xmlparser.h"
#include "pathoffile.h"
#include <QFile>
#include <QtXML/QDomDocument>
#include <QtXml/QDomElement>
#include <QtXml/QDomNodeList>
#include <QCoreApplication>
#include <QDebug>
#include <QException>
#include <QList>

//  [1] Конструктор и деструктор
XmlParser::XmlParser()
{

}

XmlParser::~XmlParser()
{

}

//  [1]

//  [2] Описание функции read
Tree *XmlParser::read()
{
    QFile xml_file(PATHOFFILE);
    if (!xml_file.open(QIODevice::ReadOnly))
    {
        qDebug() <<  "File not found!";
        return NULL;
    }
    _xmlDoc.setContent(&xml_file);
    xml_file.close();

    QDomNode _root = _xmlDoc.documentElement().cloneNode();

    _tree = new Tree(fromDomToTree(_root, nullptr));

    return _tree;

}
//  [2]

//  [3] Описание функции write.
//          *tree   -   указатель на дерево
void XmlParser::write(Tree *tree)
{

    QDomNode _root = _xmlDoc.documentElement();
    redactValuesInDom(_root, tree->root());

    QFile file(PATHOFFILE);

    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() <<  "File not found!";
        return;
    }

    QTextStream stream(&file);

    stream << _xmlDoc;

    file.close();

}

//  [3]

//  Указатель на данные (временная переменная)
Data *data;

//  [4] Описание функции fromDomToTree.
//          dom_parent  -   Родитель DOM-структуры
//          tree_parent -   указатель на родительский узел дерева
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
            node->appendChild(fromDomToTree(child, node));
        }
    }
    return node;
}
//  [4]

//  [5] Описание функции redactValuesInDom.
//          dom_parent  -   ссылка на родитель DOM-структуры
//          tree_parent -   указатель на родительский узел дерева
void XmlParser::x(QDomNode &dom_parent, TreeNode *tree_parent)
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
// [5]

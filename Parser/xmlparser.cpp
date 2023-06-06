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

void XmlParser::read()
{
    QFile XMLFile("D:/Qt Projects/ConfigRedactor/Parser/settings.xml");
    if (!XMLFile.open(QIODevice::ReadWrite))
    {
        qDebug() << "[ERROR]\tXML file not open. Error:" << XMLFile.error();
        qDebug() << XMLFile.fileName();
        return;
    }

    QDomDocument XMLDom;
    XMLDom.setContent(&XMLFile);
    XMLFile.close();

    QDomNode root = XMLDom.documentElement();
    deep_dive(root);

}

int deep_level = 0;

void XmlParser::deep_dive(QDomNode &root)
{
    QString name = root.attributes().namedItem("displayed_name").nodeValue();
    QString description = root.attributes().namedItem("description").nodeValue();
    QString value = root.attributes().namedItem("value").nodeValue();


    qDebug() << deep_level << name << "\t" << description << '\t' << value;

    if (root.hasChildNodes())
    {
        QDomNodeList child_list = root.childNodes();
        for (int child_index = 0; child_index < child_list.count(); child_index++)
        {
            QDomNode child = QDomNode(child_list.at(child_index));
            deep_level++;
            deep_dive(child);
            deep_level--;
        }
    }

}

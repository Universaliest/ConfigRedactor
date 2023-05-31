#include "xmlparser.h"
#include <QFile>
#include <QtXML/QDomDocument>
#include <QtXml/QDomElement>
#include <QtXml/QDomNodeList>
#include <QCoreApplication>
#include <QDebug>
#include <QList>

XMLParser::XMLParser()
{

}

void XMLParser::read()
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
    QList<QDomNode> item_buffer;
    item_buffer.append(root);
    while (!item_buffer.isEmpty())
    {
        QDomNode item = item_buffer.last();
        item_buffer.pop_back();
        if (!item.hasChildNodes())
        {
            QDomNamedNodeMap item_attributes = item.attributes();
            for (int i = 0; i < item_attributes.count(); i++)
            {
                item = item_attributes.item(i);
                qDebug() << item.nodeName() << '=' << item.nodeValue();
            }
        }
        else
        {
            QDomNodeList list = item.childNodes();
            for (int i = list.count(); i > 0; i--)
                item_buffer.append(list.at(i));
        }
    }
//    for (int i = 0; i < items.count(); i++)
//    {
//        qDebug() << '\t' << items.at(i).nodeName();
//        QDomNodeList second_items = items.at(1).childNodes();
//        for (int j = 0; j < second_items.count(); j++)
//        {
//            qDebug() << "\t\t" << second_items.at(j).nodeName();
//            for (int aaaa = 0; aaaa < second_items.at(j).attributes().count(); aaaa++)
//            {
//                qDebug() << "\t\t\t" << second_items.at(j).attributes().item(aaaa).nodeName() << '=' << second_items.at(j).attributes().item(aaaa).nodeValue();
//            }
//        }
//    }
}

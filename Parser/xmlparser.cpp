#include "xmlparser.h"
#include <QFile>
#include <QtXML/QDomDocument>
#include <QtXml/QDomElement>
#include <QtXml/QDomNodeList>
#include <QCoreApplication>
#include <QDebug>

XMLParser::XMLParser()
{

}

void XMLParser::read()
{
    QFile XMLFile(QCoreApplication::applicationDirPath()+"/Parser/settings.xml");
    if (!XMLFile.open(QIODevice::ReadWrite))
    {
        qDebug() << "[ERROR]\tXML file not open. Error:" << XMLFile.error();
        return;
    }

    QDomDocument XMLDom;
    XMLDom.setContent(&XMLFile);
    XMLFile.close();

    QDomElement root = XMLDom.documentElement();
    QDomNodeList items = root.childNodes();

    qDebug() << "[INFO]\tTotal child nodes: " << items.count();
}

#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QDomNode>

class XmlParser
{
public:
    XmlParser();
    void read();
private:
    void deepDive(QDomNode &root);

};

#endif // XMLPARSER_H

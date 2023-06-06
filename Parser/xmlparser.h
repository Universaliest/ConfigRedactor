#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QDomNode>

class XmlParser
{
public:
    XmlParser();
    void read();
private:
    void deep_dive(QDomNode &root);
};

#endif // XMLPARSER_H

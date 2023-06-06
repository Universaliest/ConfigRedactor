#ifndef DATA_H
#define DATA_H

#include <QString>

class Data
{
public:
    Data();
    Data(QString name, QString description, QString value);
    void setName(QString name);
    void setDescription(QString description);
    void setValue(QString value);
    QString name();
    QString description();
    QString value();
private:
    QString _name;
    QString _description;
    QString _value;
};

#endif // DATA_H

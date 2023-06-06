#include "data.h"

Data::Data()
{

}

Data::Data(QString name, QString description, QString value)
{
    _name = name;
    _description = description;
    _value = value;
}

void Data::setName(QString name)
{
    _name = name;
}

void Data::setDescription(QString description)
{
    _description = description;
}

void Data::setValue(QString value)
{
    _value = value;
}

QString Data::name()
{
    return _name;
}

QString Data::description()
{
    return _description;
}

QString Data::value()
{
    return _value;
}

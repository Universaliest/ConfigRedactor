// Описание методов класса Data

#include "data.h"

//  [1] Конструкторы
Data::Data()
{

}

Data::Data(QString name, QString description, QString value)
{
    _name = name;
    _description = description;
    _value = value;
}
//  [1]

//  [2] Описание сеттеров
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
//  [2]

//  [3] Описание геттеров
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
//  [3]

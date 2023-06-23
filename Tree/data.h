/// КЛАСС Data
/// Атрибуты класса:
///     -   _name           -   название настройки;
///     -   _description    -   описание настройки;
///     -   _value          -   значение настройки;
/// Методы класса:
///     +   setName         }
///     +   setDescription  } - сеттеры класса;
///     +   setValue        }
///
///     +   name            }
///     +   description     } - геттеры класса;
///     +   value           }
#ifndef DATA_H
#define DATA_H

#include <QString>

class Data
{
public:
    static const int NumberOfValues = 3;
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

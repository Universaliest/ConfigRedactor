#ifndef REDACTOR_H
#define REDACTOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Redactor; }
QT_END_NAMESPACE

class Redactor : public QMainWindow
{
    Q_OBJECT

public:
    Redactor(QWidget *parent = nullptr);
    ~Redactor();

private:
    Ui::Redactor *ui;
};
#endif // REDACTOR_H

#ifndef REDACTOR_H
#define REDACTOR_H

#include <QMainWindow>
#include <Tree/tree.h>
#include <QStandardItemModel>

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
    Tree *tree;
    QStandardItemModel *model;
};
#endif // REDACTOR_H

#ifndef REDACTOR_H
#define REDACTOR_H

#include <QMainWindow>
#include <Tree/tree.h>
#include <QStandardItemModel>
#include <Models/treemodel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Redactor; }
QT_END_NAMESPACE

class Redactor : public QMainWindow
{
    Q_OBJECT

public:
    Redactor(QWidget *parent = nullptr);
    ~Redactor();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Redactor *ui;
};
#endif // REDACTOR_H

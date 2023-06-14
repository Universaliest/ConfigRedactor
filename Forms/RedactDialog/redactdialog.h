#ifndef REDACTDIALOG_H
#define REDACTDIALOG_H

#include <QDialog>
#include "../../Models/treemodel.h"
#include "../../Tree/tree.h"
namespace Ui {
class RedactDialog;
}

class RedactDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RedactDialog(QWidget *parent = nullptr);
    ~RedactDialog();

private:
    Ui::RedactDialog *ui;
    Tree *tree;
    TreeModel *model;
};

#endif // REDACTDIALOG_H

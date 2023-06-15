#ifndef REDACTDIALOG_H
#define REDACTDIALOG_H

#include <QAbstractButton>
#include <QDialog>
#include "../../Models/treemodel.h"
#include "../../Tree/tree.h"
#include "../../Parser/xmlparser.h"

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

    XmlParser parser;
    Tree *tree;
    TreeModel *model;

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
};

#endif // REDACTDIALOG_H

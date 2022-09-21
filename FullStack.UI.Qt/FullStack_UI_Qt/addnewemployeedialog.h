#ifndef ADDNEWEMPLOYEEDIALOG_H
#define ADDNEWEMPLOYEEDIALOG_H

#include "employee.h"

#include <QDialog>

namespace Ui
{
class AddNewEmployeeDialog;
}

class AddNewEmployeeDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddNewEmployeeDialog(QWidget *parent = nullptr);
    virtual ~AddNewEmployeeDialog();
    Employee employee() const;
private slots:
    void on_addButton_clicked();
    void on_cancelButton_clicked();
private:
    Ui::AddNewEmployeeDialog *ui;
};

#endif // ADDNEWEMPLOYEEDIALOG_H

#include "addnewemployeedialog.h"
#include "ui_addnewemployeedialog.h"

AddNewEmployeeDialog::AddNewEmployeeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddNewEmployeeDialog)
{
    ui->setupUi(this);
}

AddNewEmployeeDialog::~AddNewEmployeeDialog()
{
    delete ui;
}

Employee AddNewEmployeeDialog::employee() const
{
    Employee e;
    e.Name = ui->txtName->text();
    e.Email = ui->txtEmail->text();
    e.Phone = ui->txtPhone->text();
    e.Salary = ui->txtSalary->text().toDouble();
    e.Department = ui->txtDepartment->text();
    return e;
}

void AddNewEmployeeDialog::on_addButton_clicked()
{
    accept();
}

void AddNewEmployeeDialog::on_cancelButton_clicked()
{
    reject();
}

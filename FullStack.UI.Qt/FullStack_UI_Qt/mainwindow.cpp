#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employeeservice.h"
#include "addnewemployeedialog.h"
#include "deleteemployeebutton.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonDocument>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_employeeService = new EmployeeService(this);
    connect(m_employeeService, &EmployeeService::getEmployeesFinished, this, &MainWindow::getEmployeesFinished);
    connect(m_employeeService, &EmployeeService::getEmployeeFinished, this, &MainWindow::getEmployeeFinished);
    connect(m_employeeService, &EmployeeService::postEmployeeFinished, this, &MainWindow::postEmployeeFinished);
    connect(m_employeeService, &EmployeeService::putEmployeeFinished, this, &MainWindow::putEmployeeFinished);
    connect(m_employeeService, &EmployeeService::deleteEmployeeFinished, this, &MainWindow::deleteEmployeeFinished);
    m_employeeService->getEmployees();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addNewEmployeeButton_clicked()
{
    AddNewEmployeeDialog d(this);
    if (d.exec() == QDialog::Accepted)
    {
        m_employeeService->postEmployee(d.employee().toDTO());
    }
}

void MainWindow::getEmployeesFinished(const QByteArray &data)
{
    for (const QJsonValue &employeeMap : QJsonDocument::fromJson(data).array())
    {
        Employee employee = Employee::fromVariantMap(employeeMap.toObject().toVariantMap());
        insertEmployeeInTable(employee);
    }
}

void MainWindow::getEmployeeFinished(const QByteArray &data)
{
    (void) data;
    // Employee employee = Employee::fromVariantMap(QJsonDocument::fromJson(data).object().toVariantMap());
    // nothing to do here
}

void MainWindow::postEmployeeFinished(const QByteArray &data)
{
    Employee employee = Employee::fromVariantMap(QJsonDocument::fromJson(data).object().toVariantMap());
    insertEmployeeInTable(employee);
}

void MainWindow::putEmployeeFinished(const QByteArray &data)
{
    (void) data;
    // todo...
    //Employee employee = Employee::fromVariantMap(QJsonDocument::fromJson(data).object().toVariantMap());

    // todo...
    // ...
    // "id" and "employee.id" must be equal
    //m_employeeService->putEmployee(id, employee);
}

void MainWindow::deleteEmployeeFinished(const QByteArray &data)
{
    Employee employee = Employee::fromVariantMap(QJsonDocument::fromJson(data).object().toVariantMap());
    qDebug() << "employee with id" << employee.Id << "has been deleted";
}

void MainWindow::insertEmployeeInTable(const Employee &employee)
{
    const int row = ui->employeeTableWidget->rowCount();
    ui->employeeTableWidget->insertRow(row);
    ui->employeeTableWidget->setItem(row, Id, new QTableWidgetItem(QString::number(employee.Id)));
    ui->employeeTableWidget->setItem(row, Name, new QTableWidgetItem(employee.Name));
    ui->employeeTableWidget->setItem(row, Email, new QTableWidgetItem(employee.Email));
    ui->employeeTableWidget->setItem(row, Phone, new QTableWidgetItem(employee.Phone));
    ui->employeeTableWidget->setItem(row, Salary, new QTableWidgetItem(QString::number(employee.Salary)));
    ui->employeeTableWidget->setItem(row, Department, new QTableWidgetItem(employee.Department));
    DeleteEmployeeButton *deleteButton = new DeleteEmployeeButton(row, this);
    ui->employeeTableWidget->setCellWidget(row, Delete, deleteButton);
    connect(deleteButton, &DeleteEmployeeButton::deleteClicked, this, [&](int deleteRow)
    {
        if (QMessageBox::question(this, "Delete", "Are you sure?") == QMessageBox::Yes)
        {
            m_employeeService->deleteEmployee(ui->employeeTableWidget->item(deleteRow, Id)->text().toInt());
            ui->employeeTableWidget->removeRow(deleteRow);
        }
    });
}

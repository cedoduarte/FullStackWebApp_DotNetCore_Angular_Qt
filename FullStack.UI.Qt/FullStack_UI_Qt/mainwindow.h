#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "employee.h"

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class EmployeeService;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    enum EmployeeTableEnum
    {
        Id,
        Name,
        Email,
        Phone,
        Salary,
        Department,
        Delete
    };

    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
private slots:
    void on_addNewEmployeeButton_clicked();

    void getEmployeesFinished(const QByteArray &data);
    void getEmployeeFinished(const QByteArray &data);
    void postEmployeeFinished(const QByteArray &data);
    void putEmployeeFinished(const QByteArray &data);
    void deleteEmployeeFinished(const QByteArray &data);
private:
    void insertEmployeeInTable(const Employee &employee);

    Ui::MainWindow *ui;
    EmployeeService *m_employeeService;
};

#endif // MAINWINDOW_H

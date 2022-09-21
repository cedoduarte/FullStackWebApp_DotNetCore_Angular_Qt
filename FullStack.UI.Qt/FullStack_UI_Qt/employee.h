#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "employeedto.h"

#include <QString>
#include <QByteArray>
#include <QVariantMap>

struct Employee
{
    int Id;
    QString Name;
    QString Email;
    QString Phone;
    double Salary;
    QString Department;

    EmployeeDTO toDTO() const;
    QByteArray toJson() const;
    static Employee fromVariantMap(const QVariantMap &map);
};

#endif // EMPLOYEE_H

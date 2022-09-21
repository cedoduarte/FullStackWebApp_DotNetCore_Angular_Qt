#ifndef EMPLOYEEDTO_H
#define EMPLOYEEDTO_H

#include <QString>

struct EmployeeDTO
{
    QString Name;
    QString Email;
    QString Phone;
    double Salary;
    QString Department;

    QByteArray toJson() const;
    static EmployeeDTO fromVariantMap(const QVariantMap &map);
};

#endif // EMPLOYEEDTO_H

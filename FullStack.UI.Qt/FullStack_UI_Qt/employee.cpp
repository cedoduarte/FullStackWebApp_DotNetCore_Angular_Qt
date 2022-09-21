#include "employee.h"
#include "QNetLib/qflexiblejsonobject.h"

#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>

EmployeeDTO Employee::toDTO() const
{
    return {
        Name,
        Email,
        Phone,
        Salary,
        Department
    };
}

QByteArray Employee::toJson() const
{
    QJsonObject object;
    object["Id"] = Id;
    object["Name"] = Name;
    object["Email"] = Email;
    object["Phone"] = Phone;
    object["Salary"] = Salary;
    object["Department"] = Department;
    QJsonDocument doc;
    doc.setObject(object);
    return doc.toJson(QJsonDocument::Compact);
}

Employee Employee::fromVariantMap(const QVariantMap &map)
{
    return {
        QFlexibleJsonObject::value(map, "Id").toInt(),
        QFlexibleJsonObject::value(map, "Name").toString(),
        QFlexibleJsonObject::value(map, "Email").toString(),
        QFlexibleJsonObject::value(map, "Phone").toString(),
        QFlexibleJsonObject::value(map, "Salary").toDouble(),
        QFlexibleJsonObject::value(map, "Department").toString()
    };
}

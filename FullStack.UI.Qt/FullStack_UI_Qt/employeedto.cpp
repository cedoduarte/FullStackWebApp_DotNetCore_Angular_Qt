#include "employeedto.h"
#include "QNetLib/qflexiblejsonobject.h"

#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>

QByteArray EmployeeDTO::toJson() const
{
    QJsonObject object;
    object["Name"] = Name;
    object["Email"] = Email;
    object["Phone"] = Phone;
    object["Salary"] = Salary;
    object["Department"] = Department;
    QJsonDocument doc;
    doc.setObject(object);
    return doc.toJson(QJsonDocument::Compact);
}

EmployeeDTO EmployeeDTO::fromVariantMap(const QVariantMap &map)
{
    return {
        QFlexibleJsonObject::value(map, "Name").toString(),
        QFlexibleJsonObject::value(map, "Email").toString(),
        QFlexibleJsonObject::value(map, "Phone").toString(),
        QFlexibleJsonObject::value(map, "Salary").toDouble(),
        QFlexibleJsonObject::value(map, "Department").toString()
    };
}

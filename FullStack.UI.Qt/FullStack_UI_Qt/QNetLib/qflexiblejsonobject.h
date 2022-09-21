#ifndef QFLEXIBLEJSONOBJECT_H
#define QFLEXIBLEJSONOBJECT_H

#include <QJsonValue>
#include <QJsonObject>
#include <QVariantMap>

class QFlexibleJsonObject
{
public:
    static QJsonValue value(const QJsonObject &object, const QString &key);
    static QVariant value(const QVariantMap &map, const QString &key);
    QFlexibleJsonObject() = delete;
};

#endif // QFLEXIBLEJSONOBJECT_H

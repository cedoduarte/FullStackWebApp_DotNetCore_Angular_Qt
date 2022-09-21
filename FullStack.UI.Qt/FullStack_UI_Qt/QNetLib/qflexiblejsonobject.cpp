#include "qflexiblejsonobject.h"

QJsonValue QFlexibleJsonObject::value(const QJsonObject &object, const QString &key)
{
    for (const QString &currentKey : object.keys())
    {
        if (currentKey.toLower() == key.toLower())
        {
            return object.value(currentKey);
        }
    }
    return QJsonValue();
}

QVariant QFlexibleJsonObject::value(const QVariantMap &map, const QString &key)
{
    for (const QString &currentKey : map.keys())
    {
        if (currentKey.toLower() == key.toLower())
        {
            return map.value(currentKey);
        }
    }
    return QVariant();
}

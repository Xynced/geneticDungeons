#include "encounter.h"

Encounter::Encounter()
{

}

QJsonObject Encounter::toJson() const
{
    QJsonObject result = Room::toJson();
    result.insert("type", "Encounter");
    return result;
}

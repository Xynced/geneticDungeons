#include "encounter.h"

Encounter::Encounter()
{

}

QJsonObject Encounter::toJson() const
{
    QJsonObject encounter = Room::toJson();
    encounter.insert("type", "Encounter");
    return encounter;
}

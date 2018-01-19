#include "combat.h"

Combat::Combat(const QList<MobParty *> &mobs)
{
    m_mobs = mobs;
}

QJsonObject Combat::toJson() const
{
    QJsonObject combat = Room::toJson();
    combat.insert("type", "Combat");
    combat.insert("enemies", mobsToJson());
    return combat;
}

QJsonObject Combat::mobsToJson() const
{
    QJsonArray mobsArray;
    foreach(MobParty * mobParty, m_mobs) {
        mobsArray.append(mobParty->toJson());
    }
    return mobsArray;
}

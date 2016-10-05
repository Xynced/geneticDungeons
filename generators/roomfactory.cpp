#include "roomfactory.h"

Combat * RoomFactory::generateCombat(QByteArray seed)
{
    Q_UNUSED(seed);
    return (new Combat());
}

Combat * RoomFactory::generateCombat()
{
    return (new Combat());
}

Encounter * RoomFactory::generateEncounter(QByteArray seed)
{
    Q_UNUSED(seed);
    return (new Encounter());
}

Encounter * RoomFactory::generateEncounter()
{
    return (new Encounter());
}

MobPartyFactory * RoomFactory::mobPartyFactory() const
{
    return m_mobPartyFactory;
}

void RoomFactory::setMobPartyFactory(MobPartyFactory *mobPartyFactory)
{
    m_mobPartyFactory = mobPartyFactory;
}

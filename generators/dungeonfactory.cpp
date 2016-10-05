#include "dungeonfactory.h"

Dungeon * DungeonFactory::generateDungeon(QByteArray seed)
{
    Q_UNUSED(seed);
    return (new Dungeon());
}

Dungeon * DungeonFactory::generateDungeon()
{
    return (new Dungeon());
}

RoomFactory * DungeonFactory::roomFactory() const
{
    return m_roomFactory;
}

void DungeonFactory::setRoomFactory(RoomFactory *roomFactory)
{
    m_roomFactory = roomFactory;
}

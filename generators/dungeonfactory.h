#ifndef DUNGEONFACTORY_H
#define DUNGEONFACTORY_H

#include "world/dungeon.h"

#include "generators/roomfactory.h"

class DungeonFactory
{
public:
    explicit DungeonFactory() {}

    virtual Dungeon * generateDungeon(QByteArray seed);
    virtual Dungeon * generateDungeon();

    RoomFactory * roomFactory() const;
    void setRoomFactory(RoomFactory *roomFactory);

private:
    RoomFactory *m_roomFactory;
};

#endif // DUNGEONFACTORY_H

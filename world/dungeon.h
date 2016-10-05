#ifndef DUNGEON_H
#define DUNGEON_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "world/room.h"
#include "characters/party.h"

#include "utils/seedable.h"

class Dungeon : public Seedable
{
public:
    Dungeon();
    virtual ~Dungeon();

    virtual bool start(Party *party);

    QList<Room *> rooms() const;
    void setRooms(const QList<Room *> &rooms);
    void addRooms(const QList<Room *> &rooms);
    void addRooms(Room *room);

    Party * party() const;

    QString toString() {return ""; /*TO DO!!!*/}

private:
    QList<Room *> m_rooms;
    Party *m_party;
};

#endif // DUNGEON_H

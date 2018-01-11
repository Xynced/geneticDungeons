#include "dungeon.h"

Dungeon::Dungeon()
{

}

Dungeon::~Dungeon()
{
    qDeleteAll(m_rooms);
}

bool Dungeon::start(Party *party)
{
    m_party = party;

    for (Room * room : m_rooms) {
        if (room->start(m_party)) {
            room->reward(m_party);
        } else {
            return false;
        }
    }

    return true;
}

QList<Room *> Dungeon::rooms() const
{
    return m_rooms;
}

void Dungeon::setRooms(const QList<Room *> &rooms)
{
    m_rooms = rooms;
}

void Dungeon::addRooms(const QList<Room *> &rooms)
{
    m_rooms.append(rooms);
}

void Dungeon::addRooms(Room *room)
{
    m_rooms.append(room);
}

Party * Dungeon::party() const
{
    return m_party;
}

QJsonObject Dungeon::toJson() const
{
    QJsonObject dungeon;
    QJsonArray rooms;
    foreach(Room * room, m_rooms) {
        rooms.append(room->toJson());
    }
    dungeon.insert("rooms", rooms);
    return dungeon;
}

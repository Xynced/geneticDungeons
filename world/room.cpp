#include "room.h"

Room::Room() {}

bool Room::start(Party *party)
{
    Q_UNUSED(party);
    return true;
}

void Room::reward(Party *party)
{
    Q_UNUSED(party);
}

RoomModifier Room::roomModifier() const
{
    return m_roomModifier;
}

void Room::setRoomModifier(const RoomModifier &roomModifier)
{
    m_roomModifier = roomModifier;
}

QJsonObject Room::toJson() const
{
    QJsonObject room;
    room.insert("modifier", roomModifier.toString());
    return room;
}

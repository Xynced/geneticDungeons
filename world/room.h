#ifndef ROOM_H
#define ROOM_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "characters/party.h"

#include "world/roommodifier.h"

#include "utils/seedable.h"

class Room : public Seedable
{
public:
    Room();
    virtual ~Room(){}

    virtual bool start(Party *party);
    // use for reward party exp, points and other staff
    virtual void reward(Party *party);

    RoomModifier roomModifier() const;
    void setRoomModifier(const RoomModifier &roomModifier);

private:
    RoomModifier m_roomModifier;
};

#endif // ROOM_H

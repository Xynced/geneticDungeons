#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <QtCore/QObject>

#include "world/room.h"

class Encounter : public Room
{
public:
    Encounter();

    virtual bool start(Party *party) {return Room::start(party);}
    // use for reward party exp, points and other staff
    virtual void reward(Party *party) {Room::reward(party);}

    virtual QJsonObject toJson() const;
};

#endif // ENCOUNTER_H

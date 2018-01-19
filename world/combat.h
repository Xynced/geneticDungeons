#ifndef COMBAT_H
#define COMBAT_H

#include <QtCore/QObject>
#include <QtCore/QJsonArray>

#include "world/room.h"
#include "characters/mobparty.h"


class Combat : public Room
{
public:
    Combat(const QList<MobParty *> &mobs = QList<MobParty *>());

    virtual bool start(Party *party) {return Room::start(party);}
    virtual void reward(Party *party) {Room::reward(party);}

    virtual QJsonObject toJson() const;

private:
    // Every different mob party will be enemy for each other
    QList<MobParty *> m_mobs;

    QJsonArray mobsToJson() const;
};

#endif // COMBAT_H

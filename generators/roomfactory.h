#ifndef ROOMFACTORY_H
#define ROOMFACTORY_H

#include "world/combat.h"
#include "world/encounter.h"

#include "generators/mobpartyfactory.h"

class RoomFactory
{
public:
    explicit RoomFactory() {}

    virtual Combat * generateCombat(QByteArray seed);
    virtual Combat * generateCombat();
    virtual Encounter * generateEncounter(QByteArray seed);
    virtual Encounter * generateEncounter();

    MobPartyFactory * mobPartyFactory() const;
    void setMobPartyFactory(MobPartyFactory *mobPartyFactory);

private:
    MobPartyFactory *m_mobPartyFactory;
};

#endif // ROOMFACTORY_H

#ifndef GENETIC_H
#define GENETIC_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QFile>
#include <QtGlobal>

#include "characters/party.h"
#include "world/dungeon.h"

#include "generators/partyfactory.h"
#include "generators/dungeonfactory.h"

class Genetic
{
public:
    Genetic(PartyFactory * partyFactory, DungeonFactory * dungeonFactory,
            uint parties = 0, uint generations = 0,
            double mutationChance = 0.05, uint topSave = 0);

    void start(QFile * outFile, uint parties = 0, uint generations = 0,
               double mutationChance = 0.05, uint topSave = 0);

private:
    PartyFactory * m_partyFactory ;
    DungeonFactory * m_dungeonFactory;
    uint m_parties;
    uint m_generations;
    double m_mutationChance;
    uint m_topSave;
    bool m_isOutOpen;

    inline void write(const QString &string, QFile *outFile);
};

#endif // GENETIC_H

#include "genetic.h"

Genetic::Genetic(PartyFactory * partyFactory, DungeonFactory * dungeonFactory,
                 uint parties, uint generations, double mutationChance, uint topSave) :
    m_partyFactory(partyFactory),
    m_dungeonFactory(dungeonFactory),
    m_parties(parties),
    m_generations(generations),
    m_mutationChance(mutationChance),
    m_topSave(topSave)
{}

bool partyLessThen(Party *p1, Party *p2) {
    return p1->depth() < p2->depth();
}

void Genetic::start(QFile *outFile, uint parties, uint generations, double mutationChance, uint topSave)
{
    m_parties = parties;
    m_generations = generations;
    m_isOutOpen = false;
    m_mutationChance = mutationChance;
    m_topSave = topSave;

    if (m_parties == 0 || m_generations == 0 || m_topSave >= m_parties)
        return;

    m_isOutOpen = outFile->open(QIODevice::WriteOnly);

    QList<Party *> partiesList;
    QList<Party *> newParties;

    for (uint generation = 0; generation < m_generations; ++generation) {
        write(QString("Start generation #%1").arg(generation), outFile);

        partiesList.clear();
        if (generation == 0) {
            for (uint i = 0; i < m_parties; ++i) {
                write(QString("Party #i").arg(i), outFile);
                Party * party = m_partyFactory->generateParty();
                write(party->toString(), outFile);
                partiesList.append(party);
            }
        } else {
            for (uint i = 0; i < m_parties; ++i) {
                write(QString("Party #i").arg(i), outFile);
                Party * party = newParties.at(i);
                write(party->toString(), outFile);
                partiesList.append(party);
            }
            newParties.clear();
        }

        uint aliveParties = m_parties;
        while (aliveParties != 0) {
            Dungeon * dungeon = m_dungeonFactory->generateDungeon();
            write(dungeon->toString(), outFile);

            for (uint i = 0; i < m_parties; ++i) {
                Party * party = partiesList.at(i);
                if (party->active()) {
                    Dungeon * dungeonCopy = m_dungeonFactory->generateDungeon(dungeon->seed());
                    if (!dungeonCopy->start(party)) {
                        aliveParties--;
                        party->setActive(false);
                    }
                }
            }
        }

        qSort(partiesList.begin(), partiesList.end(), partyLessThen);

        for (uint i = 0; i < topSave; ++i) {
            newParties.append(m_partyFactory->generateParty(partiesList.at(i)->seed()));
        }

        QList<Party *> clones;
        for (uint i = 0; i < m_parties; ++i) {
            clones.append(m_partyFactory->generateParty(partiesList.at(i)->seed()));
            clones.append(m_partyFactory->generateParty(partiesList.at(i)->seed()));
        }

        for (uint i = topSave; i < m_parties; ++i) {
            Party * parent1 = clones.takeAt(qrand() % clones.length());
            Party * parent2 = clones.takeAt(qrand() % clones.length());
            Party * newParty = new Party(parent1, parent2);
            newParties.append(newParty);
            for (int j = 0; j < newParty->characters().length(); ++j) {
                if (qrand() % 100 < m_mutationChance * 100) {
                    newParty->characters().at(j)->mutate();
                }
            }
            delete parent1;
            delete parent2;
        }

        qDeleteAll(clones);
    }

    for (uint i = 0; i < m_parties; ++i) {
        write(QString("Last parties").arg(i), outFile);
        Party * party = partiesList.at(i);
        write(party->toString(), outFile);
    }
}


void Genetic::write(const QString &string, QFile *outFile)
{
    if (m_isOutOpen) {
        outFile->write(string.toLocal8Bit());
        outFile->write(QString(QChar::LineSeparator).toLocal8Bit());
    }
}

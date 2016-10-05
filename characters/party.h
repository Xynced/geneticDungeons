#ifndef PARTY_H
#define PARTY_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "characters/character.h"

#include "utils/seedable.h"

class Party : public Seedable
{
public:
    Party(const QList<Character *> &characters = QList<Character *>());
    Party(Party *parent1, Party *parent2);
    virtual ~Party();

    QList<Character *> characters() const;
    void addCharacter(Character *character);
    void addCharacter(const QList<Character *> &characters);

    double depth() const;
    void setDepth(double depth);

    bool active() const;
    void setActive(bool active);

    QString toString() {return ""; /*TO DO!!!*/}

private:
    QList<Character *> m_characters;
    double m_depth;
    bool m_active;
};

#endif // PARTY_H

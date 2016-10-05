#ifndef MOBPARTY_H
#define MOBPARTY_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "characters/character.h"

#include "utils/seedable.h"

class MobParty : public Seedable
{
public:
    MobParty(const QList<Character *> &characters = QList<Character *>());
    MobParty(const MobParty &mobParty);

    QList<Character *> characters() const;
    void addCharacter(Character *character);
    void addCharacter(const QList<Character *> &characters);

    bool active() const;
    void setActive(bool active);

private:
    QList<Character *> m_characters;
    bool m_active;
};

#endif // MOBPARTY_H

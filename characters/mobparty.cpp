#include "mobparty.h"

MobParty::MobParty(const QList<Character *> &characters) :
    m_characters(characters),
    m_active(true)
{

}

MobParty::MobParty(const MobParty &mobParty) :
    m_active(true)
{
    m_characters = mobParty.characters();
}

QList<Character *> MobParty::characters() const
{
    return m_characters;
}

void MobParty::addCharacter(Character *character)
{
    m_characters.append(character);
}

void MobParty::addCharacter(const QList<Character *> &characters)
{
    m_characters.append(characters);
}

bool MobParty::active() const
{
    return m_active;
}

void MobParty::setActive(bool active)
{
    m_active = active;
}

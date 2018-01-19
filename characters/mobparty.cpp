#include "mobparty.h"

#include <QtCore/QJsonArray>

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

QJsonObject MobParty::toJson() const
{
    QJsonObject mobParty;
    mobParty.insert("is_active", m_active);
    QJsonArray mobsArray;
    foreach(Character * character, m_characters) {
        mobsArray.append(character->toJson());
    }
    mobParty.insert("mobs", mobsArray);
    return mobParty;
}

#include "party.h"

Party::Party(const QList<Character *> &characters) :
    m_characters(characters),
    m_depth(0),
    m_active(true)
{}

Party::Party(Party *parent1, Party *parent2) :
    m_depth(0),
    m_active(true)
{
    Q_UNUSED(parent1);
    Q_UNUSED(parent2);
    //todo
}

Party::~Party()
{
    qDeleteAll(m_characters);
}

QList<Character *> Party::characters() const
{
    return m_characters;
}

void Party::addCharacter(Character *character)
{
    m_characters.append(character);
}

void Party::addCharacter(const QList<Character *> &characters)
{
    m_characters.append(characters);
}

double Party::depth() const
{
    return m_depth;
}

void Party::setDepth(double depth)
{
    m_depth = depth;
}

bool Party::active() const
{
    return m_active;
}

void Party::setActive(bool active)
{
    m_active = active;
}


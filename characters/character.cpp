#include "character.h"

Character::Character(AI *ai, Controller *controller, Dynasty *dynasty) :
    m_ai(ai),
    m_controller(controller),
    m_dynasty(dynasty),
    m_generation(0),
    m_active(true)
{
    m_controller->setCharacter(this);
}

void Character::action(QList<Character *> friends, QList<Character *> targets)
{
    m_ai->action(m_controller, friends, targets);
}

bool Character::isActive() const
{
    return m_active;
}

AI* Character::ai() const
{
    return m_ai;
}

void Character::setAI(AI *ai)
{
    m_ai = ai;
}

Controller* Character::controller() const
{
    return m_controller;
}

void Character::setController(Controller *controller)
{
    m_controller = controller;
}

Dynasty* Character::dynasty() const
{
    return m_dynasty;
}

void Character::setDynasty(Dynasty *dynasty)
{
    m_dynasty = dynasty;
}

uint Character::generation() const
{
    return m_generation;
}

void Character::setGeneration(const uint &generation)
{
    m_generation = generation;
}

QJsonObject Character::toJson() const
{
    QJsonObject character;
    return character;
}

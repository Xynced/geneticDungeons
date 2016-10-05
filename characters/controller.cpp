#include "controller.h"

Controller::Controller(){}

Character * Controller::character() const
{
    return m_character;
}

void Controller::setCharacter(Character *character)
{
    m_character = character;
}

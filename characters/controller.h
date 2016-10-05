#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "characters/character.h"

class Character;

class Controller
{
public:
    Controller();

    Character * character() const;
    void setCharacter(Character *character);

private:
    Character * m_character;
};

#endif // CONTROLLER_H

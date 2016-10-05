#ifndef AI_H
#define AI_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "characters/controller.h"
#include "characters/character.h"

class Character;
class Controller;

class AI
{
public:
    AI();

    virtual void action(Controller *controller, QList<Character *> friends, QList<Character *> targets);
};

#endif // AI_H

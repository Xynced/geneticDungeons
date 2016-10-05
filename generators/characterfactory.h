#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H

#include "characters/character.h"

class CharacterFactory
{
public:
    explicit CharacterFactory() {}
    virtual Character * generateCharacter(QByteArray seed);
    virtual Character * generateCharacter();

private:
};

#endif // CHARACTERFACTORY_H

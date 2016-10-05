#include "characterfactory.h"

Character * CharacterFactory::generateCharacter(QByteArray seed)
{
    Q_UNUSED(seed);
    return (new Character());
}

Character * CharacterFactory::generateCharacter()
{
    return (new Character());
}

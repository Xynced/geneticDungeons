#include "partyfactory.h"

Party * PartyFactory::generateParty(QByteArray seed)
{
    Q_UNUSED(seed);
    return (new Party());
}

Party * PartyFactory::generateParty()
{
    return (new Party());
}

CharacterFactory * PartyFactory::characterFactory() const
{
    return m_characterFactory;
}

void PartyFactory::setCharacterFactory(CharacterFactory *characterFactory)
{
    m_characterFactory = characterFactory;
}

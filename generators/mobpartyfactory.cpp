#include "mobpartyfactory.h"

MobParty * MobPartyFactory::generateParty(QByteArray seed)
{
    Q_UNUSED(seed);
    return (new MobParty());
}

MobParty * MobPartyFactory::generateParty()
{
    return (new MobParty());
}

CharacterFactory * MobPartyFactory::characterFactory() const
{
    return m_characterFactory;
}

void MobPartyFactory::setCharacterFactory(CharacterFactory *characterFactory)
{
    m_characterFactory = characterFactory;
}

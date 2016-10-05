#ifndef MOBPARTYFACTORY_H
#define MOBPARTYFACTORY_H

#include "characters/mobparty.h"
#include "generators/characterfactory.h"

class MobPartyFactory
{
public:
    explicit MobPartyFactory() {}
    virtual MobParty * generateParty(QByteArray seed);
    virtual MobParty * generateParty();

    CharacterFactory * characterFactory() const;
    void setCharacterFactory(CharacterFactory *characterFactory);

private:
    CharacterFactory *m_characterFactory;
};

#endif // MOBPARTYFACTORY_H

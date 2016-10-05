#ifndef PARTYFACTORY_H
#define PARTYFACTORY_H

#include "generators/characterfactory.h"
#include "characters/party.h"

class PartyFactory
{
public:
    explicit PartyFactory() {}
    virtual Party * generateParty(QByteArray seed);
    virtual Party * generateParty();

    CharacterFactory * characterFactory() const;
    void setCharacterFactory(CharacterFactory *characterFactory);

private:
    CharacterFactory *m_characterFactory;
};

#endif // PARTYFACTORY_H

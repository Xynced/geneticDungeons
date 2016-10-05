#include "seedable.h"

Seedable::Seedable() :
    m_seed(0)
{
}

QByteArray Seedable::seed() const
{
    return m_seed;
}

void Seedable::setSeed(const QByteArray &seed)
{
    m_seed = seed;
}

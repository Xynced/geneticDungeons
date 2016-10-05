#ifndef SEEDABLE_H
#define SEEDABLE_H

#include <QtCore/QObject>

class Seedable
{
public:
    Seedable();

    virtual QByteArray seed() const final;
    virtual void setSeed(const QByteArray &seed) final;

private:
    QByteArray m_seed;
};

#endif // SEEDABLE_H

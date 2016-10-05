#include "dynasty.h"

QList<Dynasty *> Dynasty::s_dynasties = QList<Dynasty *>();

Dynasty * Dynasty::parentDynasty(Dynasty *dynasty)
{
    if (!s_dynasties.isEmpty()) {
        foreach (Dynasty *registredDynasty, s_dynasties) {
            if (dynasty->equals(registredDynasty)) {
                return registredDynasty;
            }
        }
    }

    return Q_NULLPTR;
}

void Dynasty::setDynasty(Dynasty *dynasty)
{
    s_dynasties.append(dynasty);
}

Dynasty::Dynasty(ushort g1, ushort g2, ushort g3, ushort g4, ushort g5)
{
    m_genom << g1 << g2 << g3 << g4 << g5;
    setNameAndFeature();
}

Dynasty::Dynasty(const QList<ushort> &genom)
{
    m_genom = genom;
    setNameAndFeature();
}

Dynasty::Dynasty(Dynasty *parent1, Dynasty *parent2)
{
    for (int i = 0; i < 5; ++i) {
        ushort newAllel;
        int parent = qrand() % 2;
        newAllel = (parent) ? parent1->genom().at(i) : parent2->genom().at(i);
        m_genom << newAllel;
    }
    setNameAndFeature();
}

void Dynasty::setNameAndFeature()
{
    Dynasty *parentDynasty = Dynasty::parentDynasty(this);
    if (parentDynasty != Q_NULLPTR) {
        m_dynastyFeature = parentDynasty->dynastyFeature();
        m_name = parentDynasty->name();
    } else {
        m_dynastyFeature = DynastyFeature::getNewRandomFeature();
        generateNewName();
        Dynasty::setDynasty(this);
    }
}

QList<ushort> Dynasty::genom() const
{
    return m_genom;
}

void Dynasty::setGenom(const QList<ushort> &genom)
{
    m_genom = genom;
}

DynastyFeature * Dynasty::dynastyFeature() const
{
    return m_dynastyFeature;
}

void Dynasty::setDynastyFeature(DynastyFeature *dynastyFeature)
{
    m_dynastyFeature = dynastyFeature;
}

QString Dynasty::name() const
{
    return m_name;
}

void Dynasty::setName(const QString &name)
{
    m_name = name;
}

QString Dynasty::toString() const
{
    return QString("(%1, %2, %3, %4, %5)").arg(m_genom[0]).arg(m_genom[1]).arg(m_genom[2]).arg(m_genom[3]).arg(m_genom[4]);
}

void Dynasty::generateNewName()
{
    m_name = "";
    for (int i = 0; i < 5; ++i) {
        m_name += DynastyNames::getNamePart(i, m_genom.at(i));
    }
}

bool Dynasty::operator ==(const Dynasty &dynasty)
{
    return equals(dynasty);
}

bool Dynasty::equals(const Dynasty &dynasty)
{
    uint matches = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (dynasty.genom().at(i) == m_genom.at(i)) matches++;
    }
    return (matches >= 4) ? true : false;
}

bool Dynasty::equals(Dynasty *dyansty)
{
    return equals(*dyansty);
}

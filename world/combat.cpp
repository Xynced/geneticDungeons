#include "combat.h"

Combat::Combat(const QList<MobParty *> &mobs)
{
    m_mobs = mobs;
}

QString Combat::toString() const
{
    return QString("{Combat:%1:%2}").arg(m_roomModifier.toString()).arg(mobsToSting());
}

QString Combat::mobsToSting() const
{
    QString result;
    foreach(MobParty * mobParty, m_mobs) {
        result += QString("%1; ").arg(mobParty->toString());
    }
    result.chop(2);
    return result;
}

#ifndef DYNASTY_H
#define DYNASTY_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "characters/dynastyfeature.h"
#include "characters/dynastynames.h"

class Dynasty
{
public:
    static Dynasty *parentDynasty(Dynasty *dynasty);
    static void setDynasty(Dynasty *dynasty);

    Dynasty(ushort g1 = 0, ushort g2 = 0, ushort g3 = 0, ushort g4 = 0, ushort g5 = 0);
    Dynasty(const QList<ushort> &genom);
    Dynasty(Dynasty *parent1, Dynasty *parent2);

    void setNameAndFeature();

    QList<ushort> genom() const;
    void setGenom(const QList<ushort> &genom);

    DynastyFeature * dynastyFeature() const;
    void setDynastyFeature(DynastyFeature* dynastyFeature);

    QString name() const;
    void setName(const QString &name);

    QString toString() const;

    void generateNewName();

    bool operator==(const Dynasty &dynasty);
    bool equals(const Dynasty &dynasty);
    bool equals(Dynasty *dyansty);

private:
//    Q_GLOBAL_STATIC(QList<Dynasty *>, s_dynasties)
    static QList<Dynasty *> s_dynasties;

    QList<ushort> m_genom;
    DynastyFeature *m_dynastyFeature;
    QString m_name;

};

#endif // DYNASTY_H

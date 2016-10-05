#include "dynastynames.h"

DynastyNames * DynastyNames::m_instance = nullptr;

QString DynastyNames::getNamePart(int position, int value)
{
    if (m_instance == nullptr) m_instance = new DynastyNames();

    return m_instance->names.at(position).at(value);
}

DynastyNames::DynastyNames()
{
    QList<QString> first;
    first << "Wri" << "Xu" << "We" << "Dro" << "Ku" << "Ze" << "Thi" << "Sa" << "Ox" << "Ra";
    QList<QString> second;
    second << "to" << "p" << "t" << "s" << "'" << "bro" << "si" << "ro" << "oug" << "on";
    QList<QString> third;
    third << "op" << "an" << "ri" << "tri" << "ga" << "as" << "t" << "k" << "ka" << "shi";
    QList<QString> fourth;
    fourth  << "ia" << "can" << "c" << "y" << "a" << "ite" << "ea" << "qo" << "cha" << "to";
    QList<QString> fiveth;
    fiveth << "yn" << "an" << "ria" << "ra" << "en" << "or" << "th" << "el" << "us" << "al";

    names << first << second << third << fourth << fiveth;
}

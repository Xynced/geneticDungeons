#ifndef DYNASTYNAMES_H
#define DYNASTYNAMES_H

#include <QtCore/QObject>
#include <QtCore/QList>

class DynastyNames
{
public:
    static QString getNamePart(int position, int value);
    QList<QList<QString> > names;
private:
    static DynastyNames *m_instance;

    DynastyNames();
};

#endif // DYNASTYNAMES_H

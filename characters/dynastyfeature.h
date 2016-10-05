#ifndef DYNASTYFEATURE_H
#define DYNASTYFEATURE_H

#include <QtCore/QObject>

class DynastyFeature
{
public:
    DynastyFeature();

    static DynastyFeature * getNewRandomFeature() {return Q_NULLPTR;}
};

#endif // DYNASTYFEATURE_H

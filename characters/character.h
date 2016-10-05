#ifndef CHARACTER_H
#define CHARACTER_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "utils/seedable.h"

#include "characters/ai.h"
#include "characters/controller.h"
#include "characters/dynasty.h"

class Controller;
class AI;

class Character : public QObject, public Seedable
{
    Q_OBJECT
public:
    Character(AI *ai = 0, Controller *controller = 0, Dynasty* dynasty = 0);
    virtual ~Character() {}

    virtual Character * clone() {return new Character();}
    virtual Character * getChild(Character *, Character *) {return new Character();}
    virtual void mutate() {}

    virtual double getSpeed() {return 0.0;}

    virtual QString toString() {return QString();}
    virtual QString name() {return QString();}

    void action(QList<Character *> friends, QList<Character *> targets);

    bool isActive() const;

    AI* ai() const;
    void setAI(AI* ai);

    Controller* controller() const;
    void setController(Controller* controller);

    Dynasty* dynasty() const;
    void setDynasty(Dynasty* dynasty);

    uint generation() const;
    void setGeneration(const uint &generation);

private:
    AI* m_ai;
    Controller* m_controller;
    Dynasty* m_dynasty;

    uint m_generation;
    bool m_active;
};

#endif // CHARACTER_H

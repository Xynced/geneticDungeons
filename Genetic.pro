TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    characters/character.cpp \
    characters/controller.cpp \
    characters/ai.cpp \
    characters/party.cpp \
    characters/dynasty.cpp \
    characters/dynastyfeature.cpp \
    characters/dynastynames.cpp \
    world/dungeon.cpp \
    world/room.cpp \
    world/combat.cpp \
    world/encounter.cpp \
    items/item.cpp \
    items/inventory.cpp \
    items/equip.cpp \
    world/roommodifier.cpp \
    characters/mobparty.cpp \
    algorithms/genetic.cpp \
    generators/dungeonfactory.cpp \
    generators/roomfactory.cpp \
    generators/characterfactory.cpp \
    generators/partyfactory.cpp \
    generators/mobpartyfactory.cpp \
    utils/seedable.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    characters/character.h \
    characters/controller.h \
    characters/ai.h \
    characters/party.h \
    characters/dynasty.h \
    characters/dynastyfeature.h \
    characters/dynastynames.h \
    world/dungeon.h \
    world/room.h \
    world/combat.h \
    world/encounter.h \
    items/item.h \
    items/inventory.h \
    items/equip.h \
    world/roommodifier.h \
    characters/mobparty.h \
    algorithms/genetic.h \
    generators/dungeonfactory.h \
    generators/roomfactory.h \
    generators/characterfactory.h \
    generators/partyfactory.h \
    generators/mobpartyfactory.h \
    utils/seedable.h

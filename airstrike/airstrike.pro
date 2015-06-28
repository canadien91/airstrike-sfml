
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    Aircraft/Aircraft.h \
    Entity/Entity.h \
    Game/Game.h \
    ResourceHolder/ResourceHolder.hpp \
    ResourceHolder/ResourceHolder.inl \
    ResourceHolder/ResourceIdentifiers.h \


SOURCES += main.cpp \
    Aircraft/Aircraft.cpp \
    Entity/Entity.cpp \
    Game/Game.cpp \

TARGET = airstrike

LIBS += -L"/usr/lib/i386-linux-gnu"
LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += "/usr/include/SFML/"
DEPENDPATH += "/usr/include/SFML/"

QMAKE_CXXFLAGS += -std=c++11

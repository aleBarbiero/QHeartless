#-------------------------------------------------
#
# Project created by QtCreator 2019-08-10T09:31:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QHeartless
TEMPLATE = app
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        GUI/Battle.cpp \
        GUI/Index.cpp \
        GUI/Insert.cpp \
        GUI/Listino.cpp \
        GUI/Model.cpp \
        GUI/Myxml.cpp \
        GUI/RemoveL.cpp \
        Mymainwindow.cpp \
        characters/ArmedDefender.cpp \
        characters/Darksider.cpp \
        characters/Defender.cpp \
        characters/Heartless.cpp \
        characters/NeoShadow.cpp \
        characters/NovaShadow.cpp \
        container/Container.cpp \
        container/DeepPtr.cpp \
        main.cpp

HEADERS += \
        GUI/Battle.h \
        GUI/Index.h \
        GUI/Insert.h \
        GUI/Listino.h \
        GUI/Model.h \
        GUI/Myxml.h \
        GUI/RemoveL.h \
        Mymainwindow.h \
        characters/ArmedDefender.h \
        characters/Darksider.h \
        characters/Defender.h \
        characters/Heartless.h \
        characters/NeoShadow.h \
        characters/NovaShadow.h \
        container/Container.h \
        container/DeepPtr.h

FORMS += \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    GUI/style.qss \
    icon/logo.png \
    images/ArmedDefender.png \
    images/Darksider.png \
    images/Defender.png \
    images/Heartless.png \
    images/NeoShadow.png \
    images/NovaShadow.png \
    images/background.jpg \
    images/death.png \
    images/heart.png \
    images/title.png \
    qheartless.xml

RESOURCES += \
    source.qrc

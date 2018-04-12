#-------------------------------------------------
#
# Project created by QtCreator 2018-01-29T23:11:43
#
#-------------------------------------------------

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Zerk
TEMPLATE = app

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
    main.cpp \
    location.cpp \
    item.cpp \
    object.cpp \
    person.cpp \
    player.cpp \
    scene.cpp \
    character.cpp \
    parser.cpp \
    menu.cpp \
    gamewindow.cpp \
    talkdialog.cpp

HEADERS += \
    location.h \
    item.h \
    object.h \
    person.h \
    player.h \
    scene.h \
    character.h \
    parser.h \
    menu.h \
    gamewindow.h \
    talkdialog.h

FORMS += \
    menu.ui \
    gamewindow.ui \
    talkdialog.ui

OTHER_FILES +=

DISTFILES += \
    characters.xml \
    objects.xml \
    items.xml \
    locations.xml

RESOURCES += \
    resources.qrc


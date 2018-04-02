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

# Print to console, for debugging
CONFIG += console


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    location.cpp \
    item.cpp \
    object.cpp \
    person.cpp \
    player.cpp \
    scene.cpp \
    character.cpp \
    parser.cpp

HEADERS += \
    mainwindow.h \
    location.h \
    item.h \
    object.h \
    person.h \
    player.h \
    scene.h \
    character.h \
    parser.h

FORMS += \
    mainwindow.ui

OTHER_FILES +=

DISTFILES += \
    characters.xml \
    objects.xml \
    items.xml \
    locations.xml

Test {
    message(Running Build with Tests)
)
    QT += testlib
    TARGET = UnitTests

    # Remove main to prevent two main method errors
    SOURCES -= \
        main.cpp

    # Import Test Headers
    HEADERS += \
        tests/test_item.h \
        tests/test_location.h \
        tests/test_person.h \
        tests/test_object.h \
        tests/test_player.h \
        tests/test_scene.h \
        tests/test_character.h

    # Import Test Sources
    SOURCES += \
        tests/test_character.cpp \
        tests/test_item.cpp \
        tests/test_location.cpp \
        tests/test_person.cpp \
        tests/test_object.cpp \
        tests/test_player.cpp \
        tests/test_scene.cpp
}
else
{
    message(Running Normal Build)
}

RESOURCES += \
    resources.qrc


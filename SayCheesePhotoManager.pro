#-------------------------------------------------
#
# Project created by QtCreator 2014-09-19T17:21:18
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport network

TARGET = SayCheesePhotoManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    screenmanager.cpp \
    bundle.cpp \
    mainscreen.cpp \
    saycheesescreen.cpp \
    mainscreenview.cpp \
    settingsscreenview.cpp \
    settingsscreen.cpp \
    serverconfigurationscreenview.cpp \
    serverconfigurationscreen.cpp \
    qthemedimagebutton.cpp \
    qcircularindicator.cpp \
    qbusyindicator.cpp \
    selectphonetypescreenview.cpp \
    selectphonetypescreen.cpp \
    qcircularprogressbar.cpp \
    selectconnectiontypescreenview.cpp \
    selectconnectiontypescreen.cpp \
    qcustomplot.cpp \
    statisticsscreenview.cpp \
    statisticsscreen.cpp \
    settings.cpp \
    phototransferscreenview.cpp \
    phototransferscreen.cpp \
    net/command.cpp \
    mainmenu.cpp \
    aboutdialog.cpp \
    creditsdialog.cpp \
    licensedialog.cpp \
    net/phototransferservicebroadcastserver.cpp \
    net/phototransferserver.cpp \
    net/phototransferserverthread.cpp \
    net/phototransferservicebroadcasthelpers.cpp

HEADERS  += mainwindow.h \
    screen.h \
    transitiondirection.h \
    screenmanager.h \
    bundle.h \
    mainscreen.h \
    saycheesescreen.h \
    mainscreenview.h \
    saycheeseaction.h \
    settingsscreenview.h \
    settingsscreen.h \
    serverconfigurationscreenview.h \
    serverconfigurationscreen.h \
    qthemedimagebutton.h \
    qcircularindicator.h \
    qbusyindicator.h \
    selectphonetypescreenview.h \
    selectphonetypescreen.h \
    qcircularprogressbar.h \
    selectconnectiontypescreenview.h \
    selectconnectiontypescreen.h \
    qcustomplot.h \
    statisticsscreenview.h \
    statisticsscreen.h \
    settings.h \
    phototransferscreenview.h \
    phototransferscreen.h \
    saycheeseprotocol.h \
    net/command.h \
    mainmenu.h \
    aboutdialog.h \
    creditsdialog.h \
    licensedialog.h \
    net/phototransferservicebroadcastserver.h \
    net/phototransferserver.h \
    net/phototransferserverthread.h \
    net/phototransferservicebroadcasthelpers.h

RESOURCES += \
    resources.qrc

TRANSLATIONS += \
    saycheesepm_es.ts \
    saycheesepm_zh.ts

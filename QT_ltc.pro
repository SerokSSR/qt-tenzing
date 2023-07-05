QT       += core gui
QT+= widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    form.cpp \
    main.cpp \
    mainwindow.cpp \
    mypushbutton.cpp \
    widget.cpp \
    win.cpp \
    gamemap.cpp \
    role.cpp \
    widget1.cpp

HEADERS += \
    form.h \
    mainwindow.h \
    mypushbutton.h \
    pokemon.h \
    widget.h \
    win.h \
    const.h \
    gamemap.h \
    role.h \
    widget1.h

FORMS += \
    form.ui \
    mainwindow.ui \
    widget.ui \
    win.ui \
    widget1.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    mylarge.qrc \
    mysource.qrc \
    res.qrc \
    map.qrc \
    image.qrc

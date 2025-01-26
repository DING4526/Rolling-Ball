QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ball.cpp \
    board.cpp \
    bouncingboard.cpp \
    corewidget.cpp \
    destination.cpp \
    helpwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    portal_a.cpp \
    portal_b.cpp \
    recorddot.cpp \
    trap.cpp \
    vortex.cpp

HEADERS += \
    ball.h \
    board.h \
    bouncingboard.h \
    corewidget.h \
    destination.h \
    helpwidget.h \
    mainwindow.h \
    portal_a.h \
    portal_b.h \
    recorddot.h \
    trap.h \
    vortex.h

FORMS += \
    helpwidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image/my_image.qrc \
    image/myimage.qrc

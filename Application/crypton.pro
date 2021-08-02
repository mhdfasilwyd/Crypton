QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DESTDIR = $$PWD/build/
MOC_DIR = $$DESTDIR
RCC_DIR = $$DESTDIR
UI_DIR = $$DESTDIR
OBJECTS_DIR = $$DESTDIR

LIBS += -L"$$PWD/../CoinGecko/lib/lib_pc" -lcoingecko -lcpr

SOURCES += \
    ./src/main.cpp \
    ./src/mainwindow.cpp

HEADERS += \
    ./include/mainwindow.h \
    ../CoinGecko/include/

FORMS += \
    ./ui/mainwindow.ui

#RESOURCES += \
#    ./files/resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

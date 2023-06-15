QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += xml

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Forms/RedactDialog/redactdialog.cpp \
    Models/treemodel.cpp \
    Parser/xmlparser.cpp \
    Tree/data.cpp \
    Tree/tree.cpp \
    Tree/treenode.cpp \
    main.cpp \
    redactor.cpp

HEADERS += \
    Forms/RedactDialog/redactdialog.h \
    Models/treemodel.h \
    Parser/pathoffile.h \
    Parser/xmlparser.h \
    Tree/data.h \
    Tree/tree.h \
    Tree/treenode.h \
    redactor.h

FORMS += \
    Forms/RedactDialog/redactdialog.ui \
    redactor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

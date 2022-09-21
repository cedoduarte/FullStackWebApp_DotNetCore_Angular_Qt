QT += core gui network widgets

CONFIG += c++17

SOURCES += \
    QNetLib/qflexiblejsonobject.cpp \
    QNetLib/qnetrequest.cpp \
    addnewemployeedialog.cpp \
    deleteemployeebutton.cpp \
    employee.cpp \
    employeedto.cpp \
    employeeservice.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    QNetLib/qflexiblejsonobject.h \
    QNetLib/qnetrequest.h \
    addnewemployeedialog.h \
    deleteemployeebutton.h \
    employee.h \
    employeedto.h \
    employeeservice.h \
    mainwindow.h

FORMS += \
    addnewemployeedialog.ui \
    mainwindow.ui

LIBS += -L$$PWD/QNetLib/lib/openssl
LIBS += -lssl-1_1-x64
LIBS += -lcrypto-1_1-x64

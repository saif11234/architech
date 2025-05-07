# Ajout du chemin du projet
INCLUDEPATH += "C:/Users/moham/Downloads/projet-integration-non-termine/projet"
DEPENDPATH += "C:/Users/moham/Downloads/projet-integration-non-termine/projet"

QT += core gui widgets sql printsupport charts multimedia pdf pdfwidgets
QT       += quickwidgets
QT       += quick widgets quickcontrols2 location positioning
QT      +=  multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG -= console
QT += serialport
SOURCES += \
    arduino.cpp \
    clients.cpp \
    connection.cpp \
    dialogPDF_RESSOURCE.cpp \
    facilitehistorique.cpp \
    feedback.cpp \
    mailing.cpp \
    main.cpp \
    mainwindow.cpp \
    modifierprojetdialog.cpp \
    partenaire.cpp \
    projet.cpp \
    projetmodel.cpp \
    rendezvous.cpp \
    ressource.cpp \
    QrCode.cpp \
    dialog.cpp \
    employe.cpp \
    justemp.cpp \
    sms.cpp

HEADERS += \
    arduino.h \
    clients.h \
    connection.h \
    dialogPDF_RESSOURCE.h \
    facilitehistorique.h \
    feedback.h \
    mailing.h \
    mainwindow.h \
    modifierprojetdialog.h \
    partenaire.h \
    projet.h \
    projetmodel.h \
    rendezvous.h \
    ressource.h \
    employe.h \
    QrCode.h \
    dialog.h \
    justemp.h \
    sms.h

FORMS += \
    dialog.ui \
    dialogPDF_RESSOURCE.ui \
    mailing.ui \
    mainwindow.ui \
    justemp.ui \
    modifierprojetdialog.ui \
    sms.ui

RESOURCES += \
    res.qrc

STATECHARTS += \
    "liste des ressource En PDF.scxml"

# Règles pour le déploiement
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=


include(""C:\Users\ElHach\Downloads\projet\QXlsx\QXlsx.pri"")
QT += charts
QT += core network

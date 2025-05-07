/********************************************************************************
** Form generated from reading UI file 'dialogPDF_RESSOURCE.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPDF_RESSOURCE_H
#define UI_DIALOGPDF_RESSOURCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogRESSOURCE
{
public:
    QWidget *pdfContainer;
    QPushButton *Quitter;
    QPushButton *TelechargerListRessources;
    QFrame *frame;

    void setupUi(QDialog *DialogRESSOURCE)
    {
        if (DialogRESSOURCE->objectName().isEmpty())
            DialogRESSOURCE->setObjectName("DialogRESSOURCE");
        DialogRESSOURCE->resize(968, 649);
        DialogRESSOURCE->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 127);\n"
"background-color: rgb(255, 255, 255);"));
        pdfContainer = new QWidget(DialogRESSOURCE);
        pdfContainer->setObjectName("pdfContainer");
        pdfContainer->setGeometry(QRect(9, 9, 941, 571));
        pdfContainer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Quitter = new QPushButton(DialogRESSOURCE);
        Quitter->setObjectName("Quitter");
        Quitter->setGeometry(QRect(800, 590, 148, 41));
        Quitter->setStyleSheet(QString::fromUtf8("/* Style de base du bouton bleu */\n"
"QPushButton {\n"
"    background-color: #2196F3;  /* Bleu vif */\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 12px 24px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border-radius: 6px;\n"
"    min-width: 100px;\n"
"    \n"
"    /* Gradient bleu */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                              stop:0 #42A5F5, stop:1 #1976D2);\n"
"    \n"
"    /* Ombre port\303\251e */\n"
"    box-shadow: 0 2px 4px rgba(0,0,0,0.1);\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                              stop:0 #64B5F6, stop:1 #1E88E5);\n"
"    box-shadow: 0 4px 8px rgba(0,0,0,0.15);\n"
"}\n"
"\n"
"/* Effet quand press\303\251 */\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                              stop:0 #1976D2, stop:1 #0D47A1);\n"
"    padding-top: 13px;  /* Effet d'enfoncement */"
                        "\n"
"    padding-bottom: 11px;\n"
"}\n"
"\n"
"/* \303\211tat d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background: #BBDEFB;\n"
"    color: #757575;\n"
"    box-shadow: none;\n"
"}\n"
"\n"
"/* Style optionnel pour ic\303\264ne */\n"
"QPushButton::icon {\n"
"    margin-right: 8px;\n"
"}"));
        TelechargerListRessources = new QPushButton(DialogRESSOURCE);
        TelechargerListRessources->setObjectName("TelechargerListRessources");
        TelechargerListRessources->setGeometry(QRect(10, 590, 161, 41));
        TelechargerListRessources->setStyleSheet(QString::fromUtf8("/* Style de base du bouton bleu */\n"
"QPushButton {\n"
"    background-color: #2196F3;  /* Bleu vif */\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 12px 24px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border-radius: 6px;\n"
"    min-width: 100px;\n"
"    \n"
"    /* Gradient bleu */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                              stop:0 #42A5F5, stop:1 #1976D2);\n"
"    \n"
"    /* Ombre port\303\251e */\n"
"    box-shadow: 0 2px 4px rgba(0,0,0,0.1);\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                              stop:0 #64B5F6, stop:1 #1E88E5);\n"
"    box-shadow: 0 4px 8px rgba(0,0,0,0.15);\n"
"}\n"
"\n"
"/* Effet quand press\303\251 */\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                              stop:0 #1976D2, stop:1 #0D47A1);\n"
"    padding-top: 13px;  /* Effet d'enfoncement */"
                        "\n"
"    padding-bottom: 11px;\n"
"}\n"
"\n"
"/* \303\211tat d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background: #BBDEFB;\n"
"    color: #757575;\n"
"    box-shadow: none;\n"
"}\n"
"\n"
"/* Style optionnel pour ic\303\264ne */\n"
"QPushButton::icon {\n"
"    margin-right: 8px;\n"
"}"));
        frame = new QFrame(DialogRESSOURCE);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, -51, 1001, 701));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 127);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame->raise();
        pdfContainer->raise();
        Quitter->raise();
        TelechargerListRessources->raise();

        retranslateUi(DialogRESSOURCE);

        QMetaObject::connectSlotsByName(DialogRESSOURCE);
    } // setupUi

    void retranslateUi(QDialog *DialogRESSOURCE)
    {
        DialogRESSOURCE->setWindowTitle(QCoreApplication::translate("DialogRESSOURCE", "Liste des ressources", nullptr));
        Quitter->setText(QCoreApplication::translate("DialogRESSOURCE", "Quitter", nullptr));
        TelechargerListRessources->setText(QCoreApplication::translate("DialogRESSOURCE", "Telecharger", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogRESSOURCE: public Ui_DialogRESSOURCE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPDF_RESSOURCE_H

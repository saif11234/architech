/********************************************************************************
** Form generated from reading UI file 'sms.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMS_H
#define UI_SMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_sms
{
public:
    QTextEdit *messageTextEdit;
    QPushButton *sendButton;
    QLineEdit *phoneLineEdit;
    QLabel *label_6;

    void setupUi(QDialog *sms)
    {
        if (sms->objectName().isEmpty())
            sms->setObjectName("sms");
        sms->resize(400, 300);
        messageTextEdit = new QTextEdit(sms);
        messageTextEdit->setObjectName("messageTextEdit");
        messageTextEdit->setGeometry(QRect(70, 110, 251, 121));
        sendButton = new QPushButton(sms);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(240, 239, 111, 41));
        sendButton->setStyleSheet(QString::fromUtf8("#Rechercher {\n"
"    background-color: #FFDAB9; /* Couleur orange p\303\242le */\n"
"\n"
"    border-radius: 15px; /* Arrondi du bouton */\n"
"    padding: 6px; /* Espacement interne pour un meilleur aspect */\n"
"    color: black; /* Couleur du texte */\n"
"    font-weight: bold; /* Texte en gras pour une meilleure visibilit\303\251 */\n"
"}\n"
"\n"
"#Rechercher:hover {\n"
"    background-color: #FFB347; }\n"
""));
        phoneLineEdit = new QLineEdit(sms);
        phoneLineEdit->setObjectName("phoneLineEdit");
        phoneLineEdit->setGeometry(QRect(180, 50, 171, 31));
        label_6 = new QLabel(sms);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 50, 151, 31));

        retranslateUi(sms);

        QMetaObject::connectSlotsByName(sms);
    } // setupUi

    void retranslateUi(QDialog *sms)
    {
        sms->setWindowTitle(QCoreApplication::translate("sms", "Dialog", nullptr));
        sendButton->setText(QCoreApplication::translate("sms", "send", nullptr));
        label_6->setText(QCoreApplication::translate("sms", "Entrer le num\303\251ro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sms: public Ui_sms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMS_H

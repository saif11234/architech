/********************************************************************************
** Form generated from reading UI file 'mailing.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAILING_H
#define UI_MAILING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_mailing
{
public:
    QLineEdit *objet;
    QLineEdit *mail_3;
    QTextEdit *corps;
    QLabel *label_6;
    QPushButton *envoyer;
    QLabel *label_20;

    void setupUi(QDialog *mailing)
    {
        if (mailing->objectName().isEmpty())
            mailing->setObjectName("mailing");
        mailing->resize(400, 300);
        objet = new QLineEdit(mailing);
        objet->setObjectName("objet");
        objet->setGeometry(QRect(90, 100, 211, 16));
        mail_3 = new QLineEdit(mailing);
        mail_3->setObjectName("mail_3");
        mail_3->setGeometry(QRect(90, 80, 211, 16));
        corps = new QTextEdit(mailing);
        corps->setObjectName("corps");
        corps->setGeometry(QRect(93, 120, 211, 71));
        label_6 = new QLabel(mailing);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 80, 31, 16));
        envoyer = new QPushButton(mailing);
        envoyer->setObjectName("envoyer");
        envoyer->setGeometry(QRect(230, 201, 71, 20));
        envoyer->setStyleSheet(QString::fromUtf8("#Rechercher {\n"
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
        label_20 = new QLabel(mailing);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(60, 100, 31, 16));

        retranslateUi(mailing);

        QMetaObject::connectSlotsByName(mailing);
    } // setupUi

    void retranslateUi(QDialog *mailing)
    {
        mailing->setWindowTitle(QCoreApplication::translate("mailing", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("mailing", "mail", nullptr));
        envoyer->setText(QCoreApplication::translate("mailing", "envoyer", nullptr));
        label_20->setText(QCoreApplication::translate("mailing", "objet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mailing: public Ui_mailing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAILING_H

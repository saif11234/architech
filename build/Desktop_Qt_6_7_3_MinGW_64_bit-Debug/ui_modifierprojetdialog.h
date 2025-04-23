/********************************************************************************
** Form generated from reading UI file 'modifierprojetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIERPROJETDIALOG_H
#define UI_MODIFIERPROJETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ModifierProjetDialog
{
public:
    QFrame *frame_4;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLineEdit *lineEditBudget;
    QLineEdit *lineEditNom;
    QLabel *label_77;
    QLineEdit *lineEditDescription;
    QPushButton *buttonValider;
    QPushButton *buttonAnnuler;
    QLineEdit *lineEditDateDebut;
    QLineEdit *lineEditDateFin;
    QLabel *label_80;
    QLineEdit *lineEditCinClient;
    QLabel *label_33;
    QLabel *label_38;
    QComboBox *comboBox;
    QLineEdit *latitude;
    QLineEdit *longitude;

    void setupUi(QDialog *ModifierProjetDialog)
    {
        if (ModifierProjetDialog->objectName().isEmpty())
            ModifierProjetDialog->setObjectName("ModifierProjetDialog");
        ModifierProjetDialog->resize(641, 402);
        frame_4 = new QFrame(ModifierProjetDialog);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(0, 0, 641, 401));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 226, 226);"));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        label_34 = new QLabel(frame_4);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(30, 60, 58, 16));
        label_34->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        label_35 = new QLabel(frame_4);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(30, 140, 71, 31));
        label_35->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        label_36 = new QLabel(frame_4);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(30, 210, 71, 21));
        label_36->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        label_37 = new QLabel(frame_4);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(30, 180, 101, 21));
        label_37->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        lineEditBudget = new QLineEdit(frame_4);
        lineEditBudget->setObjectName("lineEditBudget");
        lineEditBudget->setGeometry(QRect(130, 150, 113, 21));
        lineEditBudget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEditNom = new QLineEdit(frame_4);
        lineEditNom->setObjectName("lineEditNom");
        lineEditNom->setGeometry(QRect(130, 60, 113, 21));
        lineEditNom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_77 = new QLabel(frame_4);
        label_77->setObjectName("label_77");
        label_77->setGeometry(QRect(250, 50, 111, 31));
        label_77->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        lineEditDescription = new QLineEdit(frame_4);
        lineEditDescription->setObjectName("lineEditDescription");
        lineEditDescription->setGeometry(QRect(250, 90, 211, 111));
        lineEditDescription->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        buttonValider = new QPushButton(frame_4);
        buttonValider->setObjectName("buttonValider");
        buttonValider->setGeometry(QRect(50, 320, 100, 32));
        buttonValider->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        buttonAnnuler = new QPushButton(frame_4);
        buttonAnnuler->setObjectName("buttonAnnuler");
        buttonAnnuler->setGeometry(QRect(340, 320, 100, 32));
        buttonAnnuler->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        lineEditDateDebut = new QLineEdit(frame_4);
        lineEditDateDebut->setObjectName("lineEditDateDebut");
        lineEditDateDebut->setGeometry(QRect(130, 180, 113, 21));
        lineEditDateDebut->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEditDateFin = new QLineEdit(frame_4);
        lineEditDateFin->setObjectName("lineEditDateFin");
        lineEditDateFin->setGeometry(QRect(130, 210, 113, 21));
        lineEditDateFin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_80 = new QLabel(frame_4);
        label_80->setObjectName("label_80");
        label_80->setGeometry(QRect(30, 90, 91, 16));
        label_80->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        lineEditCinClient = new QLineEdit(frame_4);
        lineEditCinClient->setObjectName("lineEditCinClient");
        lineEditCinClient->setGeometry(QRect(130, 90, 113, 21));
        lineEditCinClient->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_33 = new QLabel(frame_4);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(100, 10, 271, 41));
        label_33->setStyleSheet(QString::fromUtf8("font: 24pt \"Academy Engraved LET\";"));
        label_38 = new QLabel(frame_4);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(30, 270, 71, 21));
        label_38->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        comboBox = new QComboBox(frame_4);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(130, 270, 111, 22));
        latitude = new QLineEdit(frame_4);
        latitude->setObjectName("latitude");
        latitude->setGeometry(QRect(130, 240, 113, 21));
        latitude->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        longitude = new QLineEdit(frame_4);
        longitude->setObjectName("longitude");
        longitude->setGeometry(QRect(350, 240, 113, 21));
        longitude->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        retranslateUi(ModifierProjetDialog);

        QMetaObject::connectSlotsByName(ModifierProjetDialog);
    } // setupUi

    void retranslateUi(QDialog *ModifierProjetDialog)
    {
        ModifierProjetDialog->setWindowTitle(QCoreApplication::translate("ModifierProjetDialog", "ModifierProjetDialog", nullptr));
        label_34->setText(QCoreApplication::translate("ModifierProjetDialog", "Nom:", nullptr));
        label_35->setText(QCoreApplication::translate("ModifierProjetDialog", "budget:", nullptr));
        label_36->setText(QCoreApplication::translate("ModifierProjetDialog", "date fin:", nullptr));
        label_37->setText(QCoreApplication::translate("ModifierProjetDialog", "date debut:", nullptr));
        label_77->setText(QCoreApplication::translate("ModifierProjetDialog", "description:", nullptr));
        buttonValider->setText(QCoreApplication::translate("ModifierProjetDialog", "modifier", nullptr));
        buttonAnnuler->setText(QCoreApplication::translate("ModifierProjetDialog", "annuler", nullptr));
        label_80->setText(QCoreApplication::translate("ModifierProjetDialog", "cin_client:", nullptr));
        label_33->setText(QCoreApplication::translate("ModifierProjetDialog", "modifier un projet", nullptr));
        label_38->setText(QCoreApplication::translate("ModifierProjetDialog", "etat:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ModifierProjetDialog", "en cours", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ModifierProjetDialog", "termin\303\251", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("ModifierProjetDialog", "en attente", nullptr));

    } // retranslateUi

};

namespace Ui {
    class ModifierProjetDialog: public Ui_ModifierProjetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIERPROJETDIALOG_H

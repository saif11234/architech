/********************************************************************************
** Form generated from reading UI file 'empreinte.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPREINTE_H
#define UI_EMPREINTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_empreinte
{
public:
    QTabWidget *tabWidget;
    QWidget *bb;
    QPushButton *signup;
    QPushButton *annuler;
    QLineEdit *lineEdit_cin;
    QLineEdit *lineEdit_mdp;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *status;
    QWidget *qq;
    QLabel *label_4;
    QPushButton *annuler1;
    QPushButton *login;
    QLineEdit *lineEdit_cin2;
    QLabel *label_6;

    void setupUi(QDialog *empreinte)
    {
        if (empreinte->objectName().isEmpty())
            empreinte->setObjectName("empreinte");
        empreinte->resize(698, 440);
        tabWidget = new QTabWidget(empreinte);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 701, 441));
        bb = new QWidget();
        bb->setObjectName("bb");
        signup = new QPushButton(bb);
        signup->setObjectName("signup");
        signup->setGeometry(QRect(540, 370, 83, 29));
        annuler = new QPushButton(bb);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(150, 370, 83, 29));
        lineEdit_cin = new QLineEdit(bb);
        lineEdit_cin->setObjectName("lineEdit_cin");
        lineEdit_cin->setGeometry(QRect(330, 160, 251, 28));
        lineEdit_mdp = new QLineEdit(bb);
        lineEdit_mdp->setObjectName("lineEdit_mdp");
        lineEdit_mdp->setGeometry(QRect(330, 240, 251, 28));
        label = new QLabel(bb);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 160, 63, 20));
        label_2 = new QLabel(bb);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 250, 101, 20));
        label_3 = new QLabel(bb);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(350, 50, 181, 20));
        status = new QLabel(bb);
        status->setObjectName("status");
        status->setGeometry(QRect(240, 310, 221, 16));
        tabWidget->addTab(bb, QString());
        qq = new QWidget();
        qq->setObjectName("qq");
        label_4 = new QLabel(qq);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(300, 40, 181, 20));
        annuler1 = new QPushButton(qq);
        annuler1->setObjectName("annuler1");
        annuler1->setGeometry(QRect(100, 360, 83, 29));
        login = new QPushButton(qq);
        login->setObjectName("login");
        login->setGeometry(QRect(490, 360, 83, 29));
        lineEdit_cin2 = new QLineEdit(qq);
        lineEdit_cin2->setObjectName("lineEdit_cin2");
        lineEdit_cin2->setGeometry(QRect(270, 190, 251, 28));
        label_6 = new QLabel(qq);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(180, 190, 63, 20));
        tabWidget->addTab(qq, QString());

        retranslateUi(empreinte);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(empreinte);
    } // setupUi

    void retranslateUi(QDialog *empreinte)
    {
        empreinte->setWindowTitle(QCoreApplication::translate("empreinte", "ModifierProjetDialog", nullptr));
        signup->setText(QCoreApplication::translate("empreinte", "Sign up", nullptr));
        annuler->setText(QCoreApplication::translate("empreinte", "Annuler", nullptr));
        label->setText(QCoreApplication::translate("empreinte", "CIN", nullptr));
        label_2->setText(QCoreApplication::translate("empreinte", "Mot de passe", nullptr));
        label_3->setText(QCoreApplication::translate("empreinte", "Enregistrer une empreinte", nullptr));
        status->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(bb), QCoreApplication::translate("empreinte", "Sign up", nullptr));
        label_4->setText(QCoreApplication::translate("empreinte", "Entrer une empreinte", nullptr));
        annuler1->setText(QCoreApplication::translate("empreinte", "Annuler", nullptr));
        login->setText(QCoreApplication::translate("empreinte", "Login", nullptr));
        label_6->setText(QCoreApplication::translate("empreinte", "CIN", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(qq), QCoreApplication::translate("empreinte", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class empreinte: public Ui_empreinte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPREINTE_H

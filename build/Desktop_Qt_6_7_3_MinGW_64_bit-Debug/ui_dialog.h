/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
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
    QPushButton *login;
    QPushButton *Rest_Button;
    QPushButton *loginButton;
    QLineEdit *cin_login;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *mot_de_passe_login;
    QLabel *label_5;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(698, 440);
        tabWidget = new QTabWidget(Dialog);
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
        login = new QPushButton(qq);
        login->setObjectName("login");
        login->setGeometry(QRect(210, 290, 281, 29));
        Rest_Button = new QPushButton(qq);
        Rest_Button->setObjectName("Rest_Button");
        Rest_Button->setGeometry(QRect(210, 330, 282, 24));
        loginButton = new QPushButton(qq);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(210, 260, 282, 24));
        cin_login = new QLineEdit(qq);
        cin_login->setObjectName("cin_login");
        cin_login->setGeometry(QRect(210, 118, 282, 22));
        label_4 = new QLabel(qq);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(110, 146, 74, 22));
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_6 = new QLabel(qq);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(110, 231, 94, 23));
        mot_de_passe_login = new QLineEdit(qq);
        mot_de_passe_login->setObjectName("mot_de_passe_login");
        mot_de_passe_login->setGeometry(QRect(210, 146, 282, 22));
        label_5 = new QLabel(qq);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(110, 118, 23, 22));
        label_5->setStyleSheet(QString::fromUtf8(""));
        tabWidget->addTab(qq, QString());

        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "ModifierProjetDialog", nullptr));
        signup->setText(QCoreApplication::translate("Dialog", "Sign up", nullptr));
        annuler->setText(QCoreApplication::translate("Dialog", "Annuler", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "CIN", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Mot de passe", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Enregistrer une empreinte", nullptr));
        status->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(bb), QCoreApplication::translate("Dialog", "Sign up", nullptr));
        login->setText(QCoreApplication::translate("Dialog", "Login avec empreinte", nullptr));
        Rest_Button->setText(QCoreApplication::translate("Dialog", "Annuler", nullptr));
        loginButton->setText(QCoreApplication::translate("Dialog", "Login", nullptr));
        cin_login->setText(QString());
        label_4->setText(QCoreApplication::translate("Dialog", "Mot_de_passe", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog", "Face recognized...", nullptr));
        mot_de_passe_login->setText(QString());
        label_5->setText(QCoreApplication::translate("Dialog", "CIN ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(qq), QCoreApplication::translate("Dialog", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

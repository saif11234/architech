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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *mot_de_passe_login;
    QLabel *label;
    QPushButton *loginButton;
    QPushButton *Rest_Button;
    QLabel *label_3;
    QLineEdit *cin_login;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        formLayout = new QFormLayout(Dialog);
        formLayout->setObjectName("formLayout");
        label_4 = new QLabel(Dialog);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        mot_de_passe_login = new QLineEdit(Dialog);
        mot_de_passe_login->setObjectName("mot_de_passe_login");

        formLayout->setWidget(4, QFormLayout::FieldRole, mot_de_passe_login);

        label = new QLabel(Dialog);
        label->setObjectName("label");

        formLayout->setWidget(7, QFormLayout::LabelRole, label);

        loginButton = new QPushButton(Dialog);
        loginButton->setObjectName("loginButton");

        formLayout->setWidget(8, QFormLayout::FieldRole, loginButton);

        Rest_Button = new QPushButton(Dialog);
        Rest_Button->setObjectName("Rest_Button");

        formLayout->setWidget(9, QFormLayout::FieldRole, Rest_Button);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        cin_login = new QLineEdit(Dialog);
        cin_login->setObjectName("cin_login");

        formLayout->setWidget(3, QFormLayout::FieldRole, cin_login);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "Mot_de_passe", nullptr));
        mot_de_passe_login->setText(QString());
        label->setText(QCoreApplication::translate("Dialog", "Face recognized...", nullptr));
        loginButton->setText(QCoreApplication::translate("Dialog", "Login", nullptr));
        Rest_Button->setText(QCoreApplication::translate("Dialog", "Annuler", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "CIN ", nullptr));
        cin_login->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

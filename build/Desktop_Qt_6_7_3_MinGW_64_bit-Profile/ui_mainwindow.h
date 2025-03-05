/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *ajouter_2;
    QLabel *label_10;
    QFrame *frame_2;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *budget;
    QLineEdit *nom_projet;
    QDateEdit *date_debut;
    QDateEdit *date_fin;
    QLabel *label_17;
    QLineEdit *description;
    QLabel *label_18;
    QComboBox *etat;
    QPushButton *ajouter;
    QPushButton *annuler;
    QLineEdit *cin_client;
    QLabel *label_13;
    QWidget *list;
    QTableView *tableprojet;
    QWidget *tab_7;
    QWidget *tab_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 761, 491));
        ajouter_2 = new QWidget();
        ajouter_2->setObjectName("ajouter_2");
        label_10 = new QLabel(ajouter_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(297, 9, 251, 41));
        label_10->setStyleSheet(QString::fromUtf8("font: 24pt \"Academy Engraved LET\";"));
        frame_2 = new QFrame(ajouter_2);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(70, 80, 631, 371));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 226, 226);"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_11 = new QLabel(frame_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 80, 58, 16));
        label_11->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 130, 71, 31));
        label_12->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        label_14 = new QLabel(frame_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(30, 200, 71, 21));
        label_14->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        label_15 = new QLabel(frame_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(30, 170, 101, 21));
        label_15->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        budget = new QLineEdit(frame_2);
        budget->setObjectName("budget");
        budget->setGeometry(QRect(130, 140, 113, 21));
        budget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        nom_projet = new QLineEdit(frame_2);
        nom_projet->setObjectName("nom_projet");
        nom_projet->setGeometry(QRect(130, 80, 113, 21));
        nom_projet->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        date_debut = new QDateEdit(frame_2);
        date_debut->setObjectName("date_debut");
        date_debut->setGeometry(QRect(130, 170, 110, 22));
        date_debut->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        date_fin = new QDateEdit(frame_2);
        date_fin->setObjectName("date_fin");
        date_fin->setGeometry(QRect(130, 200, 110, 22));
        date_fin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_17 = new QLabel(frame_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(310, 45, 111, 31));
        label_17->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        description = new QLineEdit(frame_2);
        description->setObjectName("description");
        description->setGeometry(QRect(310, 80, 241, 111));
        description->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_18 = new QLabel(frame_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(230, 230, 171, 21));
        label_18->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        etat = new QComboBox(frame_2);
        etat->addItem(QString());
        etat->addItem(QString());
        etat->addItem(QString());
        etat->setObjectName("etat");
        etat->setGeometry(QRect(230, 260, 171, 32));
        etat->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        ajouter = new QPushButton(frame_2);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(130, 310, 100, 32));
        ajouter->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        annuler = new QPushButton(frame_2);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(370, 310, 100, 32));
        annuler->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        cin_client = new QLineEdit(frame_2);
        cin_client->setObjectName("cin_client");
        cin_client->setGeometry(QRect(130, 110, 113, 21));
        cin_client->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_13 = new QLabel(frame_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 110, 58, 16));
        label_13->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        tabWidget->addTab(ajouter_2, QString());
        list = new QWidget();
        list->setObjectName("list");
        tableprojet = new QTableView(list);
        tableprojet->setObjectName("tableprojet");
        tableprojet->setGeometry(QRect(85, 71, 571, 321));
        tableprojet->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        tabWidget->addTab(list, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        tabWidget->addTab(tab_8, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "ajouter un projet", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Nom:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "budget:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "date fin:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "date debut:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "description:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\303\251tat d'avancement:", nullptr));
        etat->setItemText(0, QCoreApplication::translate("MainWindow", "en cours", nullptr));
        etat->setItemText(1, QCoreApplication::translate("MainWindow", "termin\303\251", nullptr));
        etat->setItemText(2, QCoreApplication::translate("MainWindow", "annul\303\251", nullptr));

        ajouter->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        annuler->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "cin client:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ajouter_2), QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(list), QCoreApplication::translate("MainWindow", "list des projets", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("MainWindow", "map", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("MainWindow", "todolist", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

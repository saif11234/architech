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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *menu2;
    QPushButton *pushButton_3;
    QWidget *mainmenu;
    QGroupBox *groupBox;
    QTableWidget *table;
    QPushButton *supp;
    QPushButton *modifier;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_10;
    QLineEdit *id;
    QLineEdit *nom;
    QLineEdit *prenom;
    QLineEdit *date;
    QLineEdit *poste;
    QLineEdit *salaire;
    QPushButton *ajouter;
    QLineEdit *num;
    QLabel *label_21;
    QLineEdit *recherche;
    QLabel *label_3;
    QComboBox *tri;
    QPushButton *trier;
    QLabel *label_11;
    QPushButton *afficher;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1608, 637);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -20, 1641, 681));
        label->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)\n"
";\n"
""));
        menu2 = new QWidget(centralwidget);
        menu2->setObjectName("menu2");
        menu2->setGeometry(QRect(-10, 0, 231, 561));
        menu2->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 rgba(255, 105, 180, 255),      /* Deep rose at the top */\n"
"                                      stop:0.5 rgba(255, 182, 193, 255),    /* Soft rose pink in the middle */\n"
"                                      stop:1 rgba(250, 240, 245, 255));     /* Light lavender at the bottom */\n"
"    color: black;  /* Text color to contrast with the soft pink background */\n"
"}"));
        pushButton_3 = new QPushButton(menu2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 50, 201, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color:rgba(248, 248, 147, 255);"));
        mainmenu = new QWidget(centralwidget);
        mainmenu->setObjectName("mainmenu");
        mainmenu->setGeometry(QRect(230, 0, 1351, 561));
        groupBox = new QGroupBox(mainmenu);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(340, 120, 981, 321));
        groupBox->setStyleSheet(QString::fromUtf8("\n"
"/* GroupBox Title */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 5px 20px;\n"
"    background-color: rgba(70, 130, 180, 255);  /* Steel Blue */\n"
"    color: white;  /* White text for contrast */\n"
"    border-radius: 10px;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* GroupBox */\n"
"QGroupBox {\n"
"    background-color: rgba(176, 224, 230, 255);  /* Light sky blue */\n"
"    border: 2px solid rgba(70, 130, 180, 255);  /* Steel blue border */\n"
"    border-radius: 12px;\n"
"    margin-top: 15px;\n"
"    padding: 20px;\n"
"}\n"
"\n"
"/* LineEdit */\n"
"QLineEdit {\n"
"    background-color: rgba(240, 248, 255, 0.8);  /* Alice blue */\n"
"    border: 2px solid rgba(70, 130, 180, 255);  /* Steel blue border */\n"
"    border-radius: 8px;\n"
"    padding: 8px;\n"
"    color: #333;\n"
"    font-size: 16px;\n"
"    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;\n"
"}\n"
"\n"
"/* Focused LineEdit */\n"
""
                        "QLineEdit:focus {\n"
"    border: 2px solid rgba(100, 149, 237, 255);  /* Dodger blue on focus */\n"
"    background-color: rgba(240, 248, 255, 0.9);  /* Slightly lighter blue on focus */\n"
"    box-shadow: 0 0 8px rgba(100, 149, 237, 255);  /* Soft glow effect */\n"
"}\n"
"\n"
"/* QLabel */\n"
"QLabel {\n"
"    color: rgba(70, 130, 180, 255);  /* Steel blue for text */\n"
"    background-color: transparent;\n"
"    font-weight: normal;\n"
"    font-size: 16px;\n"
"    padding: 5px 10px;\n"
"    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;\n"
"}\n"
"\n"
"/* Hover Effect for QLabel */\n"
"QLabel:hover {\n"
"    color: rgba(100, 149, 237, 255);  /* Brighter blue on hover */\n"
"    text-decoration: underline;\n"
"}\n"
"\n"
"/* QPushButton */\n"
"QPushButton {\n"
"    background-color: rgba(100, 149, 237, 255);  /* Dodger blue */\n"
"    color: white;\n"
"    border: 2px solid rgba(100, 149, 237, 255);\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 16px;\n"
"    font-w"
                        "eight: bold;\n"
"    transition: background-color 0.3s, transform 0.2s;\n"
"}\n"
"\n"
"/* Hover Effect for QPushButton */\n"
"QPushButton:hover {\n"
"    background-color: rgba(70, 130, 180, 255);  /* Steel blue on hover */\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"/* Pressed Effect for QPushButton */\n"
"QPushButton:pressed {\n"
"    background-color: rgba(100, 149, 237, 180);  /* Slightly darker on press */\n"
"    transform: scale(0.98);\n"
"}"));
        table = new QTableWidget(groupBox);
        if (table->columnCount() < 7)
            table->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        table->setObjectName("table");
        table->setGeometry(QRect(60, 50, 871, 161));
        supp = new QPushButton(groupBox);
        supp->setObjectName("supp");
        supp->setGeometry(QRect(320, 240, 121, 41));
        supp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1E90FF;  /* Dodger blue background */\n"
"    border: 2px solid #4682B4;  /* Steel blue border */\n"
"    border-radius: 10px;  /* Rounded corners for a smooth look */\n"
"    padding: 10px 20px;\n"
"    font-size: 16px;\n"
"    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;  /* Modern sans-serif font */\n"
"    font-weight: 600;  /* Semi-bold font weight for emphasis */\n"
"    color: white;  /* White text to contrast with the blue background */\n"
"    text-transform: uppercase;  /* Uppercase letters for a clean look */\n"
"    transition: background-color 0.3s, transform 0.2s ease, box-shadow 0.3s;  /* Smooth transition effects */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4682B4;  /* Steel blue on hover */\n"
"    border: 2px solid #5F9EA0;  /* Light slate gray border on hover */\n"
"    box-shadow: 0px 4px 12px rgba(70, 130, 180, 0.4);  /* Subtle shadow effect */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #4169E"
                        "1;  /* Royal blue when pressed */\n"
"    border: 2px solid #5F9EA0;  /* Lighter border on press */\n"
"    transform: scale(0.98);  /* Slightly shrink the button when pressed */\n"
"    box-shadow: 0px 2px 6px rgba(70, 130, 180, 0.6);  /* Darker shadow when pressed */\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../trash-2.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        supp->setIcon(icon);
        modifier = new QPushButton(groupBox);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(460, 240, 121, 41));
        modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1E90FF;  /* Dodger blue background */\n"
"    border: 2px solid #4682B4;  /* Steel blue border */\n"
"    border-radius: 10px;  /* Rounded corners for a smooth look */\n"
"    padding: 10px 20px;\n"
"    font-size: 16px;\n"
"    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;  /* Modern sans-serif font */\n"
"    font-weight: 600;  /* Semi-bold font weight for emphasis */\n"
"    color: white;  /* White text to contrast with the blue background */\n"
"    text-transform: uppercase;  /* Uppercase letters for a clean look */\n"
"    transition: background-color 0.3s, transform 0.2s ease, box-shadow 0.3s;  /* Smooth transition effects */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4682B4;  /* Steel blue on hover */\n"
"    border: 2px solid #5F9EA0;  /* Light slate gray border on hover */\n"
"    box-shadow: 0px 4px 12px rgba(70, 130, 180, 0.4);  /* Subtle shadow effect */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #4169E"
                        "1;  /* Royal blue when pressed */\n"
"    border: 2px solid #5F9EA0;  /* Lighter border on press */\n"
"    transform: scale(0.98);  /* Slightly shrink the button when pressed */\n"
"    box-shadow: 0px 2px 6px rgba(70, 130, 180, 0.6);  /* Darker shadow when pressed */\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../Edit_icon-icons.com_71853.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        modifier->setIcon(icon1);
        groupBox_2 = new QGroupBox(mainmenu);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 120, 301, 431));
        groupBox_2->setStyleSheet(QString::fromUtf8("\n"
"/* GroupBox Title */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 5px 20px;\n"
"    background-color: rgba(70, 130, 180, 255);  /* Steel Blue */\n"
"    color: white;  /* White text for contrast */\n"
"    border-radius: 10px;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* GroupBox */\n"
"QGroupBox {\n"
"    background-color: rgba(176, 224, 230, 255);  /* Light sky blue */\n"
"    border: 2px solid rgba(70, 130, 180, 255);  /* Steel blue border */\n"
"    border-radius: 12px;\n"
"    margin-top: 15px;\n"
"    padding: 20px;\n"
"}\n"
"\n"
"/* LineEdit */\n"
"QLineEdit {\n"
"    background-color: rgba(240, 248, 255, 0.8);  /* Alice blue */\n"
"    border: 2px solid rgba(70, 130, 180, 255);  /* Steel blue border */\n"
"    border-radius: 8px;\n"
"    padding: 8px;\n"
"    color: #333;\n"
"    font-size: 16px;\n"
"    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;\n"
"}\n"
"\n"
"/* Focused LineEdit */\n"
""
                        "QLineEdit:focus {\n"
"    border: 2px solid rgba(100, 149, 237, 255);  /* Dodger blue on focus */\n"
"    background-color: rgba(240, 248, 255, 0.9);  /* Slightly lighter blue on focus */\n"
"    box-shadow: 0 0 8px rgba(100, 149, 237, 255);  /* Soft glow effect */\n"
"}\n"
"\n"
"/* QLabel */\n"
"QLabel {\n"
"    color: rgba(70, 130, 180, 255);  /* Steel blue for text */\n"
"    background-color: transparent;\n"
"    font-weight: normal;\n"
"    font-size: 16px;\n"
"    padding: 5px 10px;\n"
"    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;\n"
"}\n"
"\n"
"/* Hover Effect for QLabel */\n"
"QLabel:hover {\n"
"    color: rgba(100, 149, 237, 255);  /* Brighter blue on hover */\n"
"    text-decoration: underline;\n"
"}\n"
"\n"
"/* QPushButton */\n"
"QPushButton {\n"
"    background-color: rgba(100, 149, 237, 255);  /* Dodger blue */\n"
"    color: white;\n"
"    border: 2px solid rgba(100, 149, 237, 255);\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 16px;\n"
"    font-w"
                        "eight: bold;\n"
"    transition: background-color 0.3s, transform 0.2s;\n"
"}\n"
"\n"
"/* Hover Effect for QPushButton */\n"
"QPushButton:hover {\n"
"    background-color: rgba(70, 130, 180, 255);  /* Steel blue on hover */\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"/* Pressed Effect for QPushButton */\n"
"QPushButton:pressed {\n"
"    background-color: rgba(100, 149, 237, 180);  /* Slightly darker on press */\n"
"    transform: scale(0.98);\n"
"}"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 50, 61, 31));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 220, 71, 31));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 90, 61, 31));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 180, 91, 31));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 140, 71, 31));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 260, 71, 21));
        id = new QLineEdit(groupBox_2);
        id->setObjectName("id");
        id->setGeometry(QRect(100, 50, 191, 31));
        nom = new QLineEdit(groupBox_2);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(100, 90, 191, 31));
        prenom = new QLineEdit(groupBox_2);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(100, 140, 191, 31));
        date = new QLineEdit(groupBox_2);
        date->setObjectName("date");
        date->setGeometry(QRect(100, 180, 191, 31));
        poste = new QLineEdit(groupBox_2);
        poste->setObjectName("poste");
        poste->setGeometry(QRect(100, 220, 191, 31));
        salaire = new QLineEdit(groupBox_2);
        salaire->setObjectName("salaire");
        salaire->setGeometry(QRect(100, 260, 191, 31));
        ajouter = new QPushButton(groupBox_2);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(180, 350, 111, 41));
        ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1E90FF;  /* Dodger blue background */\n"
"    border: 2px solid #4682B4;  /* Steel blue border */\n"
"    border-radius: 10px;  /* Rounded corners for a smooth look */\n"
"    padding: 10px 20px;\n"
"    font-size: 16px;\n"
"    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;  /* Modern sans-serif font */\n"
"    font-weight: 600;  /* Semi-bold font weight for emphasis */\n"
"    color: white;  /* White text to contrast with the blue background */\n"
"    text-transform: uppercase;  /* Uppercase letters for a clean look */\n"
"    transition: background-color 0.3s, transform 0.2s ease, box-shadow 0.3s;  /* Smooth transition effects */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4682B4;  /* Steel blue on hover */\n"
"    border: 2px solid #5F9EA0;  /* Light slate gray border on hover */\n"
"    box-shadow: 0px 4px 12px rgba(70, 130, 180, 0.4);  /* Subtle shadow effect */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #4169E"
                        "1;  /* Royal blue when pressed */\n"
"    border: 2px solid #5F9EA0;  /* Lighter border on press */\n"
"    transform: scale(0.98);  /* Slightly shrink the button when pressed */\n"
"    box-shadow: 0px 2px 6px rgba(70, 130, 180, 0.6);  /* Darker shadow when pressed */\n"
"}\n"
""));
        num = new QLineEdit(groupBox_2);
        num->setObjectName("num");
        num->setGeometry(QRect(100, 300, 191, 31));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(20, 300, 91, 31));
        recherche = new QLineEdit(mainmenu);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(280, 40, 781, 31));
        QFont font1;
        recherche->setFont(font1);
        recherche->setStyleSheet(QString::fromUtf8("#edit {\n"
"    background-color: transparent;  /* Make the input field transparent */\n"
"    border: 2px solid rgba(248, 248, 147, 255);  /* Same yellow border to maintain consistency */\n"
"    border-radius: 8px;  /* Rounded corners for a smooth look */\n"
"    padding: 5px;  /* Padding to give space inside the input */\n"
"    color: black;  /* Text color to ensure visibility */\n"
"    font-size: 14px;  /* Adjust font size */\n"
"}\n"
"\n"
"#edit:focus {\n"
"    border: 2px solid rgba(255, 255, 147, 255);  /* Brighter border when the input is focused */\n"
"    background-color: rgba(255, 255, 255, 0.2);  /* Light translucent background on focus */\n"
"}\n"
""));
        label_3 = new QLabel(mainmenu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(300, 40, 25, 25));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../search.svg")));
        label_3->setScaledContents(true);
        tri = new QComboBox(mainmenu);
        tri->addItem(QString());
        tri->addItem(QString());
        tri->addItem(QString());
        tri->setObjectName("tri");
        tri->setGeometry(QRect(450, 80, 101, 31));
        tri->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #e6f0ff;  /* Light blue background */\n"
"    border: 2px solid #4682b4;  /* Steel blue border */\n"
"    border-radius: 8px;  /* Rounded corners for a softer look */\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;  /* Dark text for readability */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #1e90ff;  /* Brighter blue on hover */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border-left: 1px solid #4682b4;  /* Divider for the dropdown arrow */\n"
"    width: 25px;\n"
"    background-color: #b0c4de;  /* Light steel blue for the dropdown */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(\":/images/down-arrow.png\");  /* Optional: Add a custom arrow icon */\n"
"}\n"
""));
        tri->setIconSize(QSize(21, 27));
        trier = new QPushButton(mainmenu);
        trier->setObjectName("trier");
        trier->setGeometry(QRect(560, 80, 91, 41));
        trier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1E90FF;  /* Dodger blue background */\n"
"    border: 2px solid #4682B4;  /* Steel blue border */\n"
"    border-radius: 10px;  /* Rounded corners for a smooth look */\n"
"    padding: 10px 20px;\n"
"    font-size: 16px;\n"
"    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;  /* Modern sans-serif font */\n"
"    font-weight: 600;  /* Semi-bold font weight for emphasis */\n"
"    color: white;  /* White text to contrast with the blue background */\n"
"    text-transform: uppercase;  /* Uppercase letters for a clean look */\n"
"    transition: background-color 0.3s, transform 0.2s ease, box-shadow 0.3s;  /* Smooth transition effects */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4682B4;  /* Steel blue on hover */\n"
"    border: 2px solid #5F9EA0;  /* Light slate gray border on hover */\n"
"    box-shadow: 0px 4px 12px rgba(70, 130, 180, 0.4);  /* Subtle shadow effect */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #4169E"
                        "1;  /* Royal blue when pressed */\n"
"    border: 2px solid #5F9EA0;  /* Lighter border on press */\n"
"    transform: scale(0.98);  /* Slightly shrink the button when pressed */\n"
"    box-shadow: 0px 2px 6px rgba(70, 130, 180, 0.6);  /* Darker shadow when pressed */\n"
"}\n"
""));
        label_11 = new QLabel(mainmenu);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(520, 80, 31, 31));
        label_11->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #e6f7ff;  /* Light sky blue background */\n"
"    border: 2px solid #4682b4;  /* Steel blue border */\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"\n"
"/* Hover Effect for ComboBox */\n"
"QComboBox:hover {\n"
"    border: 2px solid #1e90ff;  /* Brighter blue on hover */\n"
"}\n"
"\n"
"/* ComboBox Dropdown */\n"
"QComboBox::drop-down {\n"
"    border-left: 1px solid #4682b4;  /* Divider for the dropdown arrow */\n"
"    width: 25px;\n"
"    background-color: #b0e0e6;  /* Powder blue */\n"
"}\n"
"\n"
"/* Optional Custom Arrow for ComboBox */\n"
"QComboBox::down-arrow {\n"
"    image: url(\":/images/down-arrow.png\");  /* Optional: Custom arrow icon */\n"
"}"));
        label_11->setPixmap(QPixmap(QString::fromUtf8("../../filter (1).svg")));
        label_11->setScaledContents(true);
        afficher = new QPushButton(mainmenu);
        afficher->setObjectName("afficher");
        afficher->setGeometry(QRect(390, 450, 131, 41));
        afficher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1E90FF;  /* Dodger blue background */\n"
"    border: 2px solid #4682B4;  /* Steel blue border */\n"
"    border-radius: 10px;  /* Rounded corners for a smooth look */\n"
"    padding: 10px 20px;\n"
"    font-size: 16px;\n"
"    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;  /* Modern sans-serif font */\n"
"    font-weight: 600;  /* Semi-bold font weight for emphasis */\n"
"    color: white;  /* White text to contrast with the blue background */\n"
"    text-transform: uppercase;  /* Uppercase letters for a clean look */\n"
"    transition: background-color 0.3s, transform 0.2s ease, box-shadow 0.3s;  /* Smooth transition effects */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4682B4;  /* Steel blue on hover */\n"
"    border: 2px solid #5F9EA0;  /* Light slate gray border on hover */\n"
"    box-shadow: 0px 4px 12px rgba(70, 130, 180, 0.4);  /* Subtle shadow effect */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #4169E"
                        "1;  /* Royal blue when pressed */\n"
"    border: 2px solid #5F9EA0;  /* Lighter border on press */\n"
"    transform: scale(0.98);  /* Slightly shrink the button when pressed */\n"
"    box-shadow: 0px 2px 6px rgba(70, 130, 180, 0.6);  /* Darker shadow when pressed */\n"
"}\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1608, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "gestion d'employ\303\251e", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "liste d'employ\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "id employ\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "dateemp", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "num_res", nullptr));
        supp->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "ajouter un employ\303\251e", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "poste", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "dateemp", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "salaire", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        num->setText(QString());
        label_21->setText(QCoreApplication::translate("MainWindow", "num_res", nullptr));
        recherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "chercher un employer", nullptr));
        label_3->setText(QString());
        tri->setItemText(0, QCoreApplication::translate("MainWindow", "id", nullptr));
        tri->setItemText(1, QCoreApplication::translate("MainWindow", "date", nullptr));
        tri->setItemText(2, QCoreApplication::translate("MainWindow", "salaire", nullptr));

        trier->setText(QCoreApplication::translate("MainWindow", "tri\303\251r", nullptr));
        label_11->setText(QString());
        afficher->setText(QCoreApplication::translate("MainWindow", "afficher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

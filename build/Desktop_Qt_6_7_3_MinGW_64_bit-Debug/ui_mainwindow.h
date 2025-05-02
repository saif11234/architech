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
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QPushButton *Employes;
    QPushButton *Clients;
    QPushButton *Projets;
    QPushButton *Partenaire;
    QPushButton *RendezVous;
    QLabel *label_13;
    QPushButton *Ressources;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page1_EMPLOYES;
    QLabel *label_2;
    QWidget *page3_PROJETS;
    QLabel *label_4;
    QLabel *label_7;
    QTabWidget *tabWidget_2;
    QWidget *ajouter_5;
    QFrame *frame_4;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLineEdit *budget_3;
    QLineEdit *nom_projet_3;
    QLabel *label_77;
    QLineEdit *description_3;
    QPushButton *AjouterProjet;
    QPushButton *AnnulerProjet;
    QLineEdit *date_debut_3;
    QLineEdit *date_fin_3;
    QLabel *label_80;
    QLineEdit *cin_client_3;
    QLabel *label_33;
    QLabel *label_38;
    QComboBox *etat_projet_3;
    QLineEdit *latitude;
    QLineEdit *longitude;
    QLabel *label_43;
    QLabel *label_44;
    QWidget *list_3;
    QTableView *tableViewProjets;
    QPushButton *ModifierProjet;
    QPushButton *SupprimerProjet;
    QLineEdit *rechercheprojet;
    QPushButton *downloadprojet;
    QWidget *map;
    QQuickWidget *quickWidget_MapView;
    QPushButton *recherche_pin;
    QLineEdit *id_pin;
    QLabel *label_39;
    QWidget *todolist;
    QTableView *done;
    QTableView *doing;
    QTableView *todo;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QPushButton *movetodoing;
    QPushButton *delete_2;
    QPushButton *movetodone;
    QPushButton *add;
    QLineEdit *task;
    QComboBox *id_employe;
    QWidget *statistique;
    QWidget *page4_PARTENAIRES;
    QLabel *label_8;
    QWidget *page5_RENDEZVOUS;
    QLabel *label_10;
    QWidget *page6_RESSOURCES;
    QLabel *label_12;
    QWidget *page2_CLIENTS;
    QLabel *label_3;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 788);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 231, 781));
        frame->setStyleSheet(QString::fromUtf8("/* Fond de la sidebar */\n"
"QFrame {\n"
"    background-color: #2c3e50;  /* Un fond sombre professionnel */\n"
"    border-right: 2px solid #34495e; /* Ajout d'une bordure droite */\n"
"    \n"
"}\n"
"/* Style des boutons de la sidebar */\n"
"QPushButton {\n"
"    background-color: transparent; /* Fond transparent */\n"
"    color: white;                 /* Texte en blanc */\n"
"    border: none;                 /* Pas de bordure */\n"
"    font-size: 18px;              /* Taille de police */\n"
"    padding: 5px;                 /* Espacement int\303\251rieur */\n"
"    text-align: left 5px;             /* Alignement du texte \303\240 gauche */\n"
"    border-radius: 5px;           /* Coins arrondis */\n"
"    min-width: 180px;             /* Largeur minimale */\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background-color: #16a085;    /* Couleur de fond au survol */\n"
"    font-weight: bold;            /* Texte en gras */\n"
"}\n"
"\n"
"/* Effet quand le bouton est press\303\251 */\n"
""
                        "QPushButton:pressed {\n"
"    background-color: #1abc9c;    /* Couleur de fond quand press\303\251 */\n"
"}\n"
"\n"
"/* Suppression du contour de focus */\n"
"QPushButton:focus {\n"
"    outline: none;                /* Enl\303\250ve le contour quand le bouton est activ\303\251 */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral des boutons */\n"
"QPushButton:!pressed {\n"
"    margin-bottom: 5px;           /* Espacement entre les boutons */\n"
"}\n"
"/* Optionnel : ajout d'un effet de survol global pour le frame */\n"
"QFrame:hover {\n"
"    background-color: #34495e;  /* Change la couleur de fond lors du survol de la sidebar */\n"
"}\n"
""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        Employes = new QPushButton(frame);
        Employes->setObjectName("Employes");
        Employes->setGeometry(QRect(0, 240, 231, 61));
        Clients = new QPushButton(frame);
        Clients->setObjectName("Clients");
        Clients->setGeometry(QRect(0, 300, 231, 61));
        Projets = new QPushButton(frame);
        Projets->setObjectName("Projets");
        Projets->setGeometry(QRect(0, 360, 231, 61));
        Partenaire = new QPushButton(frame);
        Partenaire->setObjectName("Partenaire");
        Partenaire->setGeometry(QRect(0, 420, 231, 71));
        RendezVous = new QPushButton(frame);
        RendezVous->setObjectName("RendezVous");
        RendezVous->setGeometry(QRect(0, 490, 231, 61));
        label_13 = new QLabel(frame);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 140, 201, 61));
        label_13->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral du label */\n"
"QLabel {\n"
"    background-color: transparent;  /* Fond transparent pour \303\251viter un arri\303\250re-plan g\303\252nant */\n"
"    color: #ecf0f1;  /* Texte de couleur claire pour un contraste avec un fond sombre */\n"
"    font-size: 24px;  /* Taille de la police plus grande pour un titre */\n"
"    font-family: \"Helvetica Neue\", sans-serif;  /* Police moderne et lisible */\n"
"    font-weight: bold;  /* Donner un poids au texte */\n"
"    text-align: center;  /* Centrer le texte */\n"
"    border: none;\n"
"    padding: 20px;\n"
"    border-radius: 10px;  /* Arrondir les bords du label */\n"
"    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);  /* Ajoute une ombre subtile pour l'effet 3D */\n"
"}\n"
"\n"
"/* Effet lors du survol */\n"
"QLabel:hover {\n"
"    color: #16a085;  /* Change la couleur du texte au survol */\n"
"    cursor: pointer;  /* Change le curseur pour un effet interactif */\n"
"}\n"
"\n"
"/* Optionnel: Effet de focus ou de s\303\251lection */\n"
""
                        "QLabel:focus {\n"
"    outline: none;\n"
"    border: 2px solid #1abc9c;  /* Bordure subtile pour l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"}\n"
""));
        Ressources = new QPushButton(frame);
        Ressources->setObjectName("Ressources");
        Ressources->setGeometry(QRect(0, 550, 231, 61));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 191, 101));
        label->setStyleSheet(QString::fromUtf8("image: url(:/logo.jpg);\n"
"QLabel {\n"
"    border: 2px solid #3498db;  /* Bordure bleue de 2px */\n"
"    border-radius: 8px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 10px;              /* Espacement int\303\251rieur */\n"
"    background-color: #f9f9f9;  /* Fond l\303\251g\303\250rement gris pour un look moderne */\n"
"    color: #2c3e50;             /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
"    text-align: center;         /* Centrer le texte */\n"
"    min-width: 120px;           /* Largeur minimale */\n"
"    min-height: 40px;           /* Hauteur minimale */\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QLabel:hover {\n"
"    background-color: #ecf0f1;  /* Changement de fond au survol */\n"
"    border-color: #2980b9;      /* Bordure plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Effet quand le label est \"press\303\251\" ou actif */\n"
""
                        "QLabel:pressed {\n"
"    background-color: #bdc3c7;  /* Fond plus sombre quand press\303\251 */\n"
"    border-color: #1c5980;      /* Bordure encore plus fonc\303\251e */\n"
"}"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(229, -1, 901, 781));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page1_EMPLOYES = new QWidget();
        page1_EMPLOYES->setObjectName("page1_EMPLOYES");
        label_2 = new QLabel(page1_EMPLOYES);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, -10, 911, 801));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/back.png")));
        stackedWidget->addWidget(page1_EMPLOYES);
        page3_PROJETS = new QWidget();
        page3_PROJETS->setObjectName("page3_PROJETS");
        label_4 = new QLabel(page3_PROJETS);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, -10, 911, 801));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/back.png")));
        label_7 = new QLabel(page3_PROJETS);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(670, 30, 171, 20));
        tabWidget_2 = new QTabWidget(page3_PROJETS);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(190, 280, 491, 411));
        tabWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        ajouter_5 = new QWidget();
        ajouter_5->setObjectName("ajouter_5");
        frame_4 = new QFrame(ajouter_5);
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
        label_35->setGeometry(QRect(30, 120, 71, 31));
        label_35->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        label_36 = new QLabel(frame_4);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(30, 190, 71, 21));
        label_36->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        label_37 = new QLabel(frame_4);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(30, 160, 101, 21));
        label_37->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        budget_3 = new QLineEdit(frame_4);
        budget_3->setObjectName("budget_3");
        budget_3->setGeometry(QRect(130, 130, 113, 21));
        budget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        nom_projet_3 = new QLineEdit(frame_4);
        nom_projet_3->setObjectName("nom_projet_3");
        nom_projet_3->setGeometry(QRect(130, 60, 113, 21));
        nom_projet_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_77 = new QLabel(frame_4);
        label_77->setObjectName("label_77");
        label_77->setGeometry(QRect(250, 50, 111, 31));
        label_77->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        description_3 = new QLineEdit(frame_4);
        description_3->setObjectName("description_3");
        description_3->setGeometry(QRect(250, 90, 211, 111));
        description_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        AjouterProjet = new QPushButton(frame_4);
        AjouterProjet->setObjectName("AjouterProjet");
        AjouterProjet->setGeometry(QRect(50, 320, 100, 32));
        AjouterProjet->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        AnnulerProjet = new QPushButton(frame_4);
        AnnulerProjet->setObjectName("AnnulerProjet");
        AnnulerProjet->setGeometry(QRect(340, 320, 100, 32));
        AnnulerProjet->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        date_debut_3 = new QLineEdit(frame_4);
        date_debut_3->setObjectName("date_debut_3");
        date_debut_3->setGeometry(QRect(130, 160, 113, 21));
        date_debut_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        date_fin_3 = new QLineEdit(frame_4);
        date_fin_3->setObjectName("date_fin_3");
        date_fin_3->setGeometry(QRect(130, 190, 113, 21));
        date_fin_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_80 = new QLabel(frame_4);
        label_80->setObjectName("label_80");
        label_80->setGeometry(QRect(30, 90, 91, 16));
        label_80->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        cin_client_3 = new QLineEdit(frame_4);
        cin_client_3->setObjectName("cin_client_3");
        cin_client_3->setGeometry(QRect(130, 90, 113, 21));
        cin_client_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_33 = new QLabel(frame_4);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(100, 10, 251, 41));
        label_33->setStyleSheet(QString::fromUtf8("font: 24pt \"Academy Engraved LET\";"));
        label_38 = new QLabel(frame_4);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(30, 250, 71, 21));
        label_38->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        etat_projet_3 = new QComboBox(frame_4);
        etat_projet_3->addItem(QString());
        etat_projet_3->addItem(QString());
        etat_projet_3->addItem(QString());
        etat_projet_3->setObjectName("etat_projet_3");
        etat_projet_3->setGeometry(QRect(130, 250, 111, 22));
        latitude = new QLineEdit(frame_4);
        latitude->setObjectName("latitude");
        latitude->setGeometry(QRect(130, 220, 113, 21));
        latitude->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        longitude = new QLineEdit(frame_4);
        longitude->setObjectName("longitude");
        longitude->setGeometry(QRect(360, 220, 113, 21));
        longitude->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_43 = new QLabel(frame_4);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(30, 220, 71, 21));
        label_43->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        label_44 = new QLabel(frame_4);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(260, 210, 91, 31));
        label_44->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        tabWidget_2->addTab(ajouter_5, QString());
        list_3 = new QWidget();
        list_3->setObjectName("list_3");
        tableViewProjets = new QTableView(list_3);
        tableViewProjets->setObjectName("tableViewProjets");
        tableViewProjets->setGeometry(QRect(0, 40, 481, 291));
        tableViewProjets->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 226, 226);\n"
"color: rgb(0, 0, 0);"));
        ModifierProjet = new QPushButton(list_3);
        ModifierProjet->setObjectName("ModifierProjet");
        ModifierProjet->setGeometry(QRect(350, 350, 75, 24));
        SupprimerProjet = new QPushButton(list_3);
        SupprimerProjet->setObjectName("SupprimerProjet");
        SupprimerProjet->setGeometry(QRect(70, 350, 75, 24));
        rechercheprojet = new QLineEdit(list_3);
        rechercheprojet->setObjectName("rechercheprojet");
        rechercheprojet->setGeometry(QRect(60, 10, 341, 22));
        downloadprojet = new QPushButton(list_3);
        downloadprojet->setObjectName("downloadprojet");
        downloadprojet->setGeometry(QRect(210, 350, 75, 24));
        tabWidget_2->addTab(list_3, QString());
        map = new QWidget();
        map->setObjectName("map");
        quickWidget_MapView = new QQuickWidget(map);
        quickWidget_MapView->setObjectName("quickWidget_MapView");
        quickWidget_MapView->setGeometry(QRect(9, 50, 471, 291));
        quickWidget_MapView->setResizeMode(QQuickWidget::ResizeMode::SizeRootObjectToView);
        recherche_pin = new QPushButton(map);
        recherche_pin->setObjectName("recherche_pin");
        recherche_pin->setGeometry(QRect(350, 10, 75, 24));
        id_pin = new QLineEdit(map);
        id_pin->setObjectName("id_pin");
        id_pin->setGeometry(QRect(200, 10, 141, 22));
        label_39 = new QLabel(map);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(0, 0, 191, 31));
        label_39->setStyleSheet(QString::fromUtf8("color:rgb(0,0,127);\n"
"font:14pt\"Ebrima\";"));
        tabWidget_2->addTab(map, QString());
        todolist = new QWidget();
        todolist->setObjectName("todolist");
        todolist->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 72, 72);"));
        done = new QTableView(todolist);
        done->setObjectName("done");
        done->setGeometry(QRect(330, 60, 141, 251));
        done->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 152, 63);\n"
"color: gb(4,4,4);"));
        doing = new QTableView(todolist);
        doing->setObjectName("doing");
        doing->setGeometry(QRect(170, 60, 141, 251));
        doing->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 131, 131);\n"
"color: rgb(4, 4, 4);"));
        todo = new QTableView(todolist);
        todo->setObjectName("todo");
        todo->setGeometry(QRect(10, 60, 141, 251));
        todo->setStyleSheet(QString::fromUtf8("background-color: rgb(86, 86, 86);\n"
"color: gb(4, 4, 4);"));
        label_40 = new QLabel(todolist);
        label_40->setObjectName("label_40");
        label_40->setGeometry(QRect(50, 40, 58, 16));
        label_40->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font:14pt\"Ebrima\";"));
        label_41 = new QLabel(todolist);
        label_41->setObjectName("label_41");
        label_41->setGeometry(QRect(210, 40, 58, 16));
        label_41->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font:14pt\"Ebrima\";"));
        label_42 = new QLabel(todolist);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(370, 40, 58, 16));
        label_42->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font:14pt\"Ebrima\";"));
        movetodoing = new QPushButton(todolist);
        movetodoing->setObjectName("movetodoing");
        movetodoing->setGeometry(QRect(30, 330, 91, 24));
        movetodoing->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(131, 131, 131);\n"
""));
        delete_2 = new QPushButton(todolist);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(354, 330, 81, 24));
        delete_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 1, 18);"));
        movetodone = new QPushButton(todolist);
        movetodone->setObjectName("movetodone");
        movetodone->setGeometry(QRect(200, 330, 81, 24));
        movetodone->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 152, 63);"));
        add = new QPushButton(todolist);
        add->setObjectName("add");
        add->setGeometry(QRect(220, 10, 75, 24));
        add->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);"));
        task = new QLineEdit(todolist);
        task->setObjectName("task");
        task->setGeometry(QRect(20, 10, 201, 21));
        task->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        id_employe = new QComboBox(todolist);
        id_employe->addItem(QString());
        id_employe->addItem(QString());
        id_employe->addItem(QString());
        id_employe->addItem(QString());
        id_employe->addItem(QString());
        id_employe->addItem(QString());
        id_employe->setObjectName("id_employe");
        id_employe->setGeometry(QRect(370, 0, 111, 22));
        tabWidget_2->addTab(todolist, QString());
        statistique = new QWidget();
        statistique->setObjectName("statistique");
        statistique->setMinimumSize(QSize(0, 0));
        tabWidget_2->addTab(statistique, QString());
        stackedWidget->addWidget(page3_PROJETS);
        page4_PARTENAIRES = new QWidget();
        page4_PARTENAIRES->setObjectName("page4_PARTENAIRES");
        label_8 = new QLabel(page4_PARTENAIRES);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, -10, 911, 801));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/back.png")));
        stackedWidget->addWidget(page4_PARTENAIRES);
        page5_RENDEZVOUS = new QWidget();
        page5_RENDEZVOUS->setObjectName("page5_RENDEZVOUS");
        label_10 = new QLabel(page5_RENDEZVOUS);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(0, -10, 911, 801));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/back.png")));
        stackedWidget->addWidget(page5_RENDEZVOUS);
        page6_RESSOURCES = new QWidget();
        page6_RESSOURCES->setObjectName("page6_RESSOURCES");
        label_12 = new QLabel(page6_RESSOURCES);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, -10, 911, 801));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/back.png")));
        stackedWidget->addWidget(page6_RESSOURCES);
        page2_CLIENTS = new QWidget();
        page2_CLIENTS->setObjectName("page2_CLIENTS");
        label_3 = new QLabel(page2_CLIENTS);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, -10, 911, 801));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/back.png")));
        stackedWidget->addWidget(page2_CLIENTS);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "integration", nullptr));
        Employes->setText(QCoreApplication::translate("MainWindow", "Gestion des employ\303\251s", nullptr));
        Clients->setText(QCoreApplication::translate("MainWindow", "Gestion des clients", nullptr));
        Projets->setText(QCoreApplication::translate("MainWindow", "Gestion des projets", nullptr));
        Partenaire->setText(QCoreApplication::translate("MainWindow", "Gestion des partenaires ", nullptr));
        RendezVous->setText(QCoreApplication::translate("MainWindow", "Gestion des rendez-vous", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        Ressources->setText(QCoreApplication::translate("MainWindow", "Gestion des ressources", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_4->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "SAIF DKHAILI PROJETS", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "Nom:", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "budget:", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "date fin:", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "date debut:", nullptr));
        label_77->setText(QCoreApplication::translate("MainWindow", "description:", nullptr));
        AjouterProjet->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        AnnulerProjet->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        label_80->setText(QCoreApplication::translate("MainWindow", "cin_client:", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "ajouter un projet", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "etat:", nullptr));
        etat_projet_3->setItemText(0, QCoreApplication::translate("MainWindow", "en cours", nullptr));
        etat_projet_3->setItemText(1, QCoreApplication::translate("MainWindow", "termin\303\251", nullptr));
        etat_projet_3->setItemText(2, QCoreApplication::translate("MainWindow", "en attente", nullptr));

        label_43->setText(QCoreApplication::translate("MainWindow", "latitude:", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "longitude:", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(ajouter_5), QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        ModifierProjet->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        SupprimerProjet->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        downloadprojet->setText(QCoreApplication::translate("MainWindow", "telecharger", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(list_3), QCoreApplication::translate("MainWindow", "list des projets", nullptr));
        recherche_pin->setText(QCoreApplication::translate("MainWindow", "rechercher", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "Entrer un id du projet:", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(map), QCoreApplication::translate("MainWindow", "map", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "TO DO", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "DOING", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "DONE", nullptr));
        movetodoing->setText(QCoreApplication::translate("MainWindow", "passer a doing", nullptr));
        delete_2->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        movetodone->setText(QCoreApplication::translate("MainWindow", "passer a done", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        id_employe->setItemText(0, QCoreApplication::translate("MainWindow", "choisir employe", nullptr));
        id_employe->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        id_employe->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        id_employe->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        id_employe->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        id_employe->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));

        tabWidget_2->setTabText(tabWidget_2->indexOf(todolist), QCoreApplication::translate("MainWindow", "todolist", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(statistique), QCoreApplication::translate("MainWindow", "statistique", nullptr));
        label_8->setText(QString());
        label_10->setText(QString());
        label_12->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

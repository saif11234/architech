/********************************************************************************
** Form generated from reading UI file 'justemp.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JUSTEMP_H
#define UI_JUSTEMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_justemp
{
public:
    QFrame *frame;
    QPushButton *Employes;
    QPushButton *Clients;
    QPushButton *Projets;
    QPushButton *Partenaire;
    QPushButton *RendezVous;
    QLabel *label_14;
    QPushButton *Ressources;
    QLabel *label_2;
    QLabel *roleLabel;
    QLabel *cinLabel;
    QPushButton *deconnexionButton;
    QLineEdit *rechercher;
    QLabel *label;
    QTableView *trierTableView;
    QStackedWidget *stackedWidget;
    QWidget *page1_EMPLOYES;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_15;
    QTableView *trierTableView_2;
    QLineEdit *rechercher_2;
    QTableView *employeTableView1;
    QPushButton *StatistiqueButton;
    QPushButton *ExporterPDFButton;
    QPushButton *TrierButton;
    QWidget *page3_PROJETS;
    QLabel *label_4;
    QLabel *label_7;
    QTabWidget *tabWidget_2;
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
    QWidget *page4_PARTENAIRES;
    QLabel *label_8;
    QTabWidget *employes_3;
    QWidget *tab_11;
    QGroupBox *groupBox_13;
    QLabel *label_63;
    QLabel *label_64;
    QLabel *label_65;
    QLabel *label_66;
    QLabel *label_67;
    QLineEdit *lineEdit_61;
    QLineEdit *lineEdit_62;
    QLineEdit *lineEdit_63;
    QLineEdit *lineEdit_64;
    QLineEdit *lineEdit_65;
    QPushButton *pushButton_31;
    QPushButton *pushButton_32;
    QWidget *tab_12;
    QTableWidget *tableWidget_6;
    QWidget *Modifier_6;
    QGroupBox *groupBox_14;
    QLabel *label_68;
    QLabel *label_69;
    QLabel *label_70;
    QLabel *label_71;
    QLabel *label_72;
    QLineEdit *lineEdit_66;
    QLineEdit *lineEdit_67;
    QLineEdit *lineEdit_68;
    QLineEdit *lineEdit_69;
    QLineEdit *lineEdit_70;
    QPushButton *pushButton_33;
    QPushButton *pushButton_34;
    QLabel *label_9;
    QWidget *page5_RENDEZVOUS;
    QLabel *label_10;
    QLabel *label_11;
    QTabWidget *tab_client_3;
    QWidget *tab_13;
    QGroupBox *groupBox_15;
    QLabel *label_78;
    QLabel *label_79;
    QLabel *label_80;
    QLabel *label_81;
    QLabel *label_82;
    QLineEdit *lineEdit_76;
    QLineEdit *lineEdit_77;
    QLineEdit *lineEdit_78;
    QLineEdit *lineEdit_79;
    QLineEdit *lineEdit_80;
    QPushButton *pushButton_37;
    QPushButton *pushButton_38;
    QWidget *tab_14;
    QTableWidget *tableWidget_7;
    QWidget *Modifier_7;
    QGroupBox *groupBox_16;
    QLabel *label_83;
    QLabel *label_84;
    QLabel *label_85;
    QLabel *label_86;
    QLabel *label_87;
    QLineEdit *lineEdit_81;
    QLineEdit *lineEdit_82;
    QLineEdit *lineEdit_83;
    QLineEdit *lineEdit_84;
    QLineEdit *lineEdit_85;
    QPushButton *pushButton_39;
    QPushButton *pushButton_40;
    QWidget *page6_RESSOURCES;
    QLabel *label_12;
    QLabel *label_18;
    QWidget *ListeRessource;
    QLineEdit *chercherRESSOURCE;
    QComboBox *trie_ressource;
    QPushButton *CherRessourceNom;
    QTableView *tableRessource;
    QPushButton *CherRessourceNom_2;
    QWidget *page2_CLIENTS;
    QLabel *label_6;
    QTabWidget *employes;
    QWidget *tab_7;
    QGroupBox *groupBox_9;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_46;
    QLabel *label_47;
    QLineEdit *NOM;
    QLineEdit *PRENOM;
    QLineEdit *TELEPHONE;
    QLineEdit *MAIL;
    QLineEdit *PAIMENT;
    QPushButton *pushButton_23;
    QPushButton *AjouterClient;
    QLabel *label_73;
    QLineEdit *CIN;
    QLabel *label_75;
    QLineEdit *ADRESSE;
    QWidget *tab_8;
    QTableView *tableView;
    QWidget *Modifier_4;
    QGroupBox *groupBox_10;
    QLabel *label_48;
    QLabel *label_49;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *label_52;
    QLineEdit *PRENOM2;
    QLineEdit *TELEPHONE2;
    QLineEdit *MAIL2;
    QLineEdit *PAIMENT2;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QLineEdit *NOM2;
    QLabel *label_74;
    QLineEdit *CIN2;
    QLabel *label_76;
    QLineEdit *ADRESSE2;
    QLabel *label_13;

    void setupUi(QDialog *justemp)
    {
        if (justemp->objectName().isEmpty())
            justemp->setObjectName("justemp");
        justemp->resize(1119, 651);
        frame = new QFrame(justemp);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, -30, 231, 731));
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
        Employes->setGeometry(QRect(0, 240, 190, 61));
        Clients = new QPushButton(frame);
        Clients->setObjectName("Clients");
        Clients->setGeometry(QRect(0, 300, 190, 61));
        Projets = new QPushButton(frame);
        Projets->setObjectName("Projets");
        Projets->setGeometry(QRect(0, 350, 190, 71));
        Partenaire = new QPushButton(frame);
        Partenaire->setObjectName("Partenaire");
        Partenaire->setGeometry(QRect(0, 420, 231, 71));
        RendezVous = new QPushButton(frame);
        RendezVous->setObjectName("RendezVous");
        RendezVous->setGeometry(QRect(0, 490, 231, 61));
        label_14 = new QLabel(frame);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(0, 180, 201, 61));
        label_14->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral du label */\n"
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
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 191, 101));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/logo.jpg);\n"
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
        roleLabel = new QLabel(frame);
        roleLabel->setObjectName("roleLabel");
        roleLabel->setGeometry(QRect(20, 150, 61, 21));
        cinLabel = new QLabel(frame);
        cinLabel->setObjectName("cinLabel");
        cinLabel->setGeometry(QRect(90, 150, 121, 21));
        deconnexionButton = new QPushButton(justemp);
        deconnexionButton->setObjectName("deconnexionButton");
        deconnexionButton->setGeometry(QRect(1030, 10, 80, 18));
        rechercher = new QLineEdit(justemp);
        rechercher->setObjectName("rechercher");
        rechercher->setGeometry(QRect(340, 90, 261, 31));
        label = new QLabel(justemp);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 90, 61, 21));
        trierTableView = new QTableView(justemp);
        trierTableView->setObjectName("trierTableView");
        trierTableView->setGeometry(QRect(250, 380, 471, 181));
        trierTableView->setStyleSheet(QString::fromUtf8("font: 300 italic 9pt \"Segoe UI\";\n"
""));
        stackedWidget = new QStackedWidget(justemp);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(230, 0, 901, 781));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page1_EMPLOYES = new QWidget();
        page1_EMPLOYES->setObjectName("page1_EMPLOYES");
        label_3 = new QLabel(page1_EMPLOYES);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, -10, 911, 801));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/back.png")));
        label_5 = new QLabel(page1_EMPLOYES);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(670, 30, 161, 20));
        label_15 = new QLabel(page1_EMPLOYES);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(260, 300, 61, 21));
        trierTableView_2 = new QTableView(page1_EMPLOYES);
        trierTableView_2->setObjectName("trierTableView_2");
        trierTableView_2->setGeometry(QRect(190, 550, 351, 181));
        trierTableView_2->setStyleSheet(QString::fromUtf8("font: 300 italic 9pt \"Segoe UI\";\n"
""));
        rechercher_2 = new QLineEdit(page1_EMPLOYES);
        rechercher_2->setObjectName("rechercher_2");
        rechercher_2->setGeometry(QRect(380, 300, 261, 31));
        employeTableView1 = new QTableView(page1_EMPLOYES);
        employeTableView1->setObjectName("employeTableView1");
        employeTableView1->setGeometry(QRect(190, 350, 351, 191));
        employeTableView1->setStyleSheet(QString::fromUtf8("font: 300 italic 9pt \"Segoe UI\";\n"
""));
        StatistiqueButton = new QPushButton(page1_EMPLOYES);
        StatistiqueButton->setObjectName("StatistiqueButton");
        StatistiqueButton->setGeometry(QRect(560, 360, 121, 41));
        ExporterPDFButton = new QPushButton(page1_EMPLOYES);
        ExporterPDFButton->setObjectName("ExporterPDFButton");
        ExporterPDFButton->setGeometry(QRect(560, 560, 121, 41));
        TrierButton = new QPushButton(page1_EMPLOYES);
        TrierButton->setObjectName("TrierButton");
        TrierButton->setGeometry(QRect(560, 460, 121, 41));
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
        tabWidget_2->setGeometry(QRect(200, 260, 491, 411));
        tabWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
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
        tabWidget_2->addTab(todolist, QString());
        stackedWidget->addWidget(page3_PROJETS);
        page4_PARTENAIRES = new QWidget();
        page4_PARTENAIRES->setObjectName("page4_PARTENAIRES");
        label_8 = new QLabel(page4_PARTENAIRES);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, -10, 911, 801));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/back.png")));
        employes_3 = new QTabWidget(page4_PARTENAIRES);
        employes_3->setObjectName("employes_3");
        employes_3->setGeometry(QRect(190, 280, 491, 441));
        employes_3->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral du QTabWidget */\n"
"QTabWidget {\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #007acc; /* Bordure bleue */\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 4px; /* Espacement int\303\251rieur */\n"
"}\n"
"\n"
"\n"
"\n"
"/* Style des onglets */\n"
"QTabBar::tab {\n"
"    background-color: rgba(240, 240, 240, 0.8); /* Fond gris clair avec transparence */\n"
"    color: #333333; /* Texte gris fonc\303\251 */\n"
"    padding: 8px 16px; /* Espacement int\303\251rieur */\n"
"    border: 1px solid #cccccc; /* Bordure l\303\251g\303\250re */\n"
"    border-bottom: none; /* Pas de bordure en bas */\n"
"    border-top-left-radius: 6px; /* Coin arrondi en haut \303\240 gauche */\n"
"    border-top-right-radius: 6px; /* Coin arrondi en haut \303\240 droite */\n"
"    margin-right: 4px; /* Espacement entre les onglets */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
""
                        "}\n"
"\n"
"/* Onglet s\303\251lectionn\303\251 */\n"
"QTabBar::tab:selected {\n"
"    background-color: rgba(0, 122, 204, 0.9); /* Fond bleu avec transparence */\n"
"    color: white; /* Texte blanc */\n"
"    border-color: #007acc; /* Bordure bleue */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"/* Effet hover sur les onglets */\n"
"QTabBar::tab:hover {\n"
"    background-color: rgba(224, 224, 224, 0.8); /* Fond gris plus clair au survol */\n"
"    color: #007acc; /* Texte bleu au survol */\n"
"}\n"
"\n"
"\n"
"\n"
"/* Style de la barre d'onglets */\n"
"QTabBar {\n"
"    background: transparent; /* Fond transparent */\n"
"    border: none; /* Pas de bordure */\n"
"    spacing: 4px; /* Espacement entre les onglets */\n"
"}\n"
"\n"
"/* Style du bouton de fermeture des onglets (si applicable) */\n"
"QTabBar::close-button {\n"
"    background: transparent; /* Fond transparent */\n"
"    padding: 4px; /* Espacement int\303\251rieur */\n"
"    border-radius: 2px; /* Coins l\303\251g\303\250rement ar"
                        "rondis */\n"
"}\n"
"\n"
"QTabBar::close-button:hover {\n"
"    background: rgba(255, 68, 68, 0.8); /* Fond rouge avec transparence au survol */\n"
"    color: white; /* Texte blanc */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les QLabel */\n"
"QLabel {\n"
"    font-size: 14px; /* Taille de police */\n"
"    color: white; /* Texte gris fonc\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    border: 2px solid #007acc; /* Bordure bleue */\n"
"    border-radius: 6px; /* Coins arrondis */\n"
" \n"
"    margin: 4px; /* Marge ext\303\251rieure */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
"font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"/* Effet hover pour QLabel */\n"
"QLabel:hover {\n"
"    background-color: rgba(240, 248, 255, 0.8); /* Fond bleu clair avec transparence au survol */\n"
"    border-color: #005fa3; /* Bordure plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style pour QLineEdit */\n"
"QLineEdit {\n"
"    font-size: 14px; /* Tai"
                        "lle de police */\n"
"    color: #333333; /* Texte gris fonc\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    border: 2px solid #007acc; /* Bordure bleue */\n"
"    border-radius: 6px; /* Coins arrondis */\n"
"  \n"
"    margin: 4px; /* Marge ext\303\251rieure */\n"
"   font-weight: bold; /* Texte en gras */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
"}\n"
"\n"
"/* Effet focus pour QLineEdit */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #005fa3; /* Bordure plus fonc\303\251e lors du focus */\n"
"    background-color: rgba(240, 248, 255, 0.8); /* Fond bleu clair avec transparence lors du focus */\n"
"}\n"
"\n"
"/* Style pour QPushButton */\n"
"QPushButton {\n"
"    font-size: 14px; /* Taille de police */\n"
"    color: white; /* Texte blanc */\n"
"    background-color: rgba(0, 122, 204, 0.8); /* Fond bleu avec transparence */\n"
"    border: 2px solid #007acc; /* Bordure bleue */\n"
"    border-radius: 6px; /* Coins arrondis */\n"
"    padding: 8px"
                        " 16px; /* Espacement int\303\251rieur */\n"
"    margin: 4px; /* Marge ext\303\251rieure */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"/* Effet hover pour QPushButton */\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 95, 163, 0.8); /* Fond bleu plus fonc\303\251 avec transparence au survol */\n"
"    border-color: #005fa3; /* Bordure plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Effet press\303\251 pour QPushButton */\n"
"QPushButton:pressed {\n"
"    background-color: rgba(0, 79, 140, 0.8); /* Fond bleu encore plus fonc\303\251 avec transparence lors du clic */\n"
"    border-color: #004f8c; /* Bordure encore plus fonc\303\251e lors du clic */\n"
"}\n"
"\n"
"/* Style pour QPushButton d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: rgba(204, 204, 204, 0.8); /* Fond gris avec transparence */\n"
"    border-color: #cccccc; /* Bordure grise */\n"
"    color: #666666; /* Texte gris "
                        "fonc\303\251 */\n"
"} "));
        tab_11 = new QWidget();
        tab_11->setObjectName("tab_11");
        groupBox_13 = new QGroupBox(tab_11);
        groupBox_13->setObjectName("groupBox_13");
        groupBox_13->setGeometry(QRect(10, 0, 461, 401));
        groupBox_13->setStyleSheet(QString::fromUtf8(""));
        label_63 = new QLabel(groupBox_13);
        label_63->setObjectName("label_63");
        label_63->setGeometry(QRect(40, 39, 131, 41));
        label_63->setStyleSheet(QString::fromUtf8(""));
        label_64 = new QLabel(groupBox_13);
        label_64->setObjectName("label_64");
        label_64->setGeometry(QRect(40, 89, 131, 41));
        label_64->setStyleSheet(QString::fromUtf8(""));
        label_65 = new QLabel(groupBox_13);
        label_65->setObjectName("label_65");
        label_65->setGeometry(QRect(40, 140, 131, 41));
        label_65->setStyleSheet(QString::fromUtf8(""));
        label_66 = new QLabel(groupBox_13);
        label_66->setObjectName("label_66");
        label_66->setGeometry(QRect(40, 190, 131, 41));
        label_66->setStyleSheet(QString::fromUtf8(""));
        label_67 = new QLabel(groupBox_13);
        label_67->setObjectName("label_67");
        label_67->setGeometry(QRect(40, 240, 131, 41));
        label_67->setStyleSheet(QString::fromUtf8(""));
        lineEdit_61 = new QLineEdit(groupBox_13);
        lineEdit_61->setObjectName("lineEdit_61");
        lineEdit_61->setGeometry(QRect(220, 45, 121, 31));
        lineEdit_62 = new QLineEdit(groupBox_13);
        lineEdit_62->setObjectName("lineEdit_62");
        lineEdit_62->setGeometry(QRect(220, 95, 121, 31));
        lineEdit_63 = new QLineEdit(groupBox_13);
        lineEdit_63->setObjectName("lineEdit_63");
        lineEdit_63->setGeometry(QRect(220, 145, 121, 31));
        lineEdit_64 = new QLineEdit(groupBox_13);
        lineEdit_64->setObjectName("lineEdit_64");
        lineEdit_64->setGeometry(QRect(220, 195, 121, 31));
        lineEdit_65 = new QLineEdit(groupBox_13);
        lineEdit_65->setObjectName("lineEdit_65");
        lineEdit_65->setGeometry(QRect(220, 245, 121, 31));
        pushButton_31 = new QPushButton(groupBox_13);
        pushButton_31->setObjectName("pushButton_31");
        pushButton_31->setGeometry(QRect(20, 350, 121, 41));
        pushButton_32 = new QPushButton(groupBox_13);
        pushButton_32->setObjectName("pushButton_32");
        pushButton_32->setGeometry(QRect(280, 350, 121, 41));
        employes_3->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName("tab_12");
        tableWidget_6 = new QTableWidget(tab_12);
        if (tableWidget_6->columnCount() < 6)
            tableWidget_6->setColumnCount(6);
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget_6->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font1;
        font1.setBold(true);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tableWidget_6->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidget_6->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        tableWidget_6->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        tableWidget_6->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        tableWidget_6->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget_6->setObjectName("tableWidget_6");
        tableWidget_6->setGeometry(QRect(-10, 0, 501, 381));
        tableWidget_6->setStyleSheet(QString::fromUtf8("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
"<ui version=\"4.0\">\n"
" <widget name=\"__qt_fake_top_level\">\n"
"  <widget class=\"QGroupBox\" name=\"groupBox_6\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>-10</x>\n"
"     <y>0</y>\n"
"     <width>501</width>\n"
"     <height>401</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"styleSheet\">\n"
"    <string notr=\"true\"/>\n"
"   </property>\n"
"   <property name=\"title\">\n"
"    <string/>\n"
"   </property>\n"
"   <widget class=\"QLabel\" name=\"label_28\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>40</x>\n"
"      <y>39</y>\n"
"      <width>131</width>\n"
"      <height>41</height>\n"
"     </rect>\n"
"    </property>\n"
"    <property name=\"styleSheet\">\n"
"     <string notr=\"true\"/>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string>Nom:</string>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLabel\" name=\"label_29\">\n"
"    <property name=\"geometry\""
                        ">\n"
"     <rect>\n"
"      <x>40</x>\n"
"      <y>89</y>\n"
"      <width>131</width>\n"
"      <height>41</height>\n"
"     </rect>\n"
"    </property>\n"
"    <property name=\"styleSheet\">\n"
"     <string notr=\"true\"/>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string>Pr\303\251nom :</string>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLabel\" name=\"label_30\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>40</x>\n"
"      <y>140</y>\n"
"      <width>131</width>\n"
"      <height>41</height>\n"
"     </rect>\n"
"    </property>\n"
"    <property name=\"styleSheet\">\n"
"     <string notr=\"true\"/>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string>T\303\251lephone :</string>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLabel\" name=\"label_31\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>40</x>\n"
"      <y>190</y>\n"
"      <width>131</width>\n"
"      <height>41</height>\n"
"     </rect"
                        ">\n"
"    </property>\n"
"    <property name=\"styleSheet\">\n"
"     <string notr=\"true\"/>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string>Email :</string>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLabel\" name=\"label_32\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>40</x>\n"
"      <y>240</y>\n"
"      <width>131</width>\n"
"      <height>41</height>\n"
"     </rect>\n"
"    </property>\n"
"    <property name=\"styleSheet\">\n"
"     <string notr=\"true\"/>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string>Paiment(dt):</string>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLineEdit\" name=\"lineEdit_26\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>220</x>\n"
"      <y>50</y>\n"
"      <width>113</width>\n"
"      <height>26</height>\n"
"     </rect>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string/>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLineE"
                        "dit\" name=\"lineEdit_27\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>220</x>\n"
"      <y>100</y>\n"
"      <width>113</width>\n"
"      <height>26</height>\n"
"     </rect>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLineEdit\" name=\"lineEdit_28\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>220</x>\n"
"      <y>150</y>\n"
"      <width>113</width>\n"
"      <height>26</height>\n"
"     </rect>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLineEdit\" name=\"lineEdit_29\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>220</x>\n"
"      <y>200</y>\n"
"      <width>113</width>\n"
"      <height>26</height>\n"
"     </rect>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLineEdit\" name=\"lineEdit_30\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>220</x>\n"
"      <y>250</y>\n"
"      <width>113</width>\n"
"      <height>26</height>\n"
"     </rect>\n"
"    </property>\n"
"   </wi"
                        "dget>\n"
"   <widget class=\"QPushButton\" name=\"pushButton_17\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>20</x>\n"
"      <y>320</y>\n"
"      <width>121</width>\n"
"      <height>41</height>\n"
"     </rect>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string>Quitter</string>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QPushButton\" name=\"pushButton_18\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>270</x>\n"
"      <y>320</y>\n"
"      <width>121</width>\n"
"      <height>41</height>\n"
"     </rect>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string>Modifier</string>\n"
"    </property>\n"
"   </widget>\n"
"  </widget>\n"
" </widget>\n"
" <resources/>\n"
"</ui>\n"
""));
        employes_3->addTab(tab_12, QString());
        Modifier_6 = new QWidget();
        Modifier_6->setObjectName("Modifier_6");
        groupBox_14 = new QGroupBox(Modifier_6);
        groupBox_14->setObjectName("groupBox_14");
        groupBox_14->setGeometry(QRect(10, 0, 461, 401));
        groupBox_14->setStyleSheet(QString::fromUtf8(""));
        label_68 = new QLabel(groupBox_14);
        label_68->setObjectName("label_68");
        label_68->setGeometry(QRect(40, 39, 131, 41));
        label_68->setStyleSheet(QString::fromUtf8(""));
        label_69 = new QLabel(groupBox_14);
        label_69->setObjectName("label_69");
        label_69->setGeometry(QRect(40, 89, 131, 41));
        label_69->setStyleSheet(QString::fromUtf8(""));
        label_70 = new QLabel(groupBox_14);
        label_70->setObjectName("label_70");
        label_70->setGeometry(QRect(40, 140, 131, 41));
        label_70->setStyleSheet(QString::fromUtf8(""));
        label_71 = new QLabel(groupBox_14);
        label_71->setObjectName("label_71");
        label_71->setGeometry(QRect(40, 190, 131, 41));
        label_71->setStyleSheet(QString::fromUtf8(""));
        label_72 = new QLabel(groupBox_14);
        label_72->setObjectName("label_72");
        label_72->setGeometry(QRect(40, 240, 131, 41));
        label_72->setStyleSheet(QString::fromUtf8(""));
        lineEdit_66 = new QLineEdit(groupBox_14);
        lineEdit_66->setObjectName("lineEdit_66");
        lineEdit_66->setGeometry(QRect(220, 45, 121, 31));
        lineEdit_67 = new QLineEdit(groupBox_14);
        lineEdit_67->setObjectName("lineEdit_67");
        lineEdit_67->setGeometry(QRect(220, 95, 121, 31));
        lineEdit_68 = new QLineEdit(groupBox_14);
        lineEdit_68->setObjectName("lineEdit_68");
        lineEdit_68->setGeometry(QRect(220, 145, 121, 31));
        lineEdit_69 = new QLineEdit(groupBox_14);
        lineEdit_69->setObjectName("lineEdit_69");
        lineEdit_69->setGeometry(QRect(220, 195, 121, 31));
        lineEdit_70 = new QLineEdit(groupBox_14);
        lineEdit_70->setObjectName("lineEdit_70");
        lineEdit_70->setGeometry(QRect(220, 245, 121, 31));
        pushButton_33 = new QPushButton(groupBox_14);
        pushButton_33->setObjectName("pushButton_33");
        pushButton_33->setGeometry(QRect(20, 350, 121, 41));
        pushButton_34 = new QPushButton(groupBox_14);
        pushButton_34->setObjectName("pushButton_34");
        pushButton_34->setGeometry(QRect(280, 350, 121, 41));
        employes_3->addTab(Modifier_6, QString());
        label_9 = new QLabel(page4_PARTENAIRES);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(670, 30, 201, 41));
        stackedWidget->addWidget(page4_PARTENAIRES);
        page5_RENDEZVOUS = new QWidget();
        page5_RENDEZVOUS->setObjectName("page5_RENDEZVOUS");
        label_10 = new QLabel(page5_RENDEZVOUS);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(0, -10, 911, 801));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/back.png")));
        label_11 = new QLabel(page5_RENDEZVOUS);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(670, 30, 201, 41));
        tab_client_3 = new QTabWidget(page5_RENDEZVOUS);
        tab_client_3->setObjectName("tab_client_3");
        tab_client_3->setGeometry(QRect(190, 280, 491, 441));
        tab_client_3->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral du QTabWidget */\n"
"QTabWidget {\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #007acc; /* Bordure bleue */\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 4px; /* Espacement int\303\251rieur */\n"
"}\n"
"\n"
"\n"
"\n"
"/* Style des onglets */\n"
"QTabBar::tab {\n"
"    background-color: rgba(240, 240, 240, 0.8); /* Fond gris clair avec transparence */\n"
"    color: #333333; /* Texte gris fonc\303\251 */\n"
"    padding: 8px 16px; /* Espacement int\303\251rieur */\n"
"    border: 1px solid #cccccc; /* Bordure l\303\251g\303\250re */\n"
"    border-bottom: none; /* Pas de bordure en bas */\n"
"    border-top-left-radius: 6px; /* Coin arrondi en haut \303\240 gauche */\n"
"    border-top-right-radius: 6px; /* Coin arrondi en haut \303\240 droite */\n"
"    margin-right: 4px; /* Espacement entre les onglets */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
""
                        "}\n"
"\n"
"/* Onglet s\303\251lectionn\303\251 */\n"
"QTabBar::tab:selected {\n"
"    background-color: rgba(0, 122, 204, 0.9); /* Fond bleu avec transparence */\n"
"    color: white; /* Texte blanc */\n"
"    border-color: #007acc; /* Bordure bleue */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"/* Effet hover sur les onglets */\n"
"QTabBar::tab:hover {\n"
"    background-color: rgba(224, 224, 224, 0.8); /* Fond gris plus clair au survol */\n"
"    color: #007acc; /* Texte bleu au survol */\n"
"}\n"
"\n"
"\n"
"\n"
"/* Style de la barre d'onglets */\n"
"QTabBar {\n"
"    background: transparent; /* Fond transparent */\n"
"    border: none; /* Pas de bordure */\n"
"    spacing: 4px; /* Espacement entre les onglets */\n"
"}\n"
"\n"
"/* Style du bouton de fermeture des onglets (si applicable) */\n"
"QTabBar::close-button {\n"
"    background: transparent; /* Fond transparent */\n"
"    padding: 4px; /* Espacement int\303\251rieur */\n"
"    border-radius: 2px; /* Coins l\303\251g\303\250rement ar"
                        "rondis */\n"
"}\n"
"\n"
"QTabBar::close-button:hover {\n"
"    background: rgba(255, 68, 68, 0.8); /* Fond rouge avec transparence au survol */\n"
"    color: white; /* Texte blanc */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les QLabel */\n"
"QLabel {\n"
"    font-size: 14px; /* Taille de police */\n"
"    color: white; /* Texte gris fonc\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    border: 2px solid #007acc; /* Bordure bleue */\n"
"    border-radius: 6px; /* Coins arrondis */\n"
" \n"
"    margin: 4px; /* Marge ext\303\251rieure */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
"font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"/* Effet hover pour QLabel */\n"
"QLabel:hover {\n"
"    background-color: rgba(240, 248, 255, 0.8); /* Fond bleu clair avec transparence au survol */\n"
"    border-color: #005fa3; /* Bordure plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style pour QLineEdit */\n"
"QLineEdit {\n"
"    font-size: 14px; /* Tai"
                        "lle de police */\n"
"    color: #333333; /* Texte gris fonc\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    border: 2px solid #007acc; /* Bordure bleue */\n"
"    border-radius: 6px; /* Coins arrondis */\n"
"  \n"
"    margin: 4px; /* Marge ext\303\251rieure */\n"
"   font-weight: bold; /* Texte en gras */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
"}\n"
"\n"
"/* Effet focus pour QLineEdit */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #005fa3; /* Bordure plus fonc\303\251e lors du focus */\n"
"    background-color: rgba(240, 248, 255, 0.8); /* Fond bleu clair avec transparence lors du focus */\n"
"}\n"
"\n"
"/* Style pour QPushButton */\n"
"QPushButton {\n"
"    font-size: 14px; /* Taille de police */\n"
"    color: white; /* Texte blanc */\n"
"    background-color: rgba(0, 122, 204, 0.8); /* Fond bleu avec transparence */\n"
"    border: 2px solid #007acc; /* Bordure bleue */\n"
"    border-radius: 6px; /* Coins arrondis */\n"
"    padding: 8px"
                        " 16px; /* Espacement int\303\251rieur */\n"
"    margin: 4px; /* Marge ext\303\251rieure */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"/* Effet hover pour QPushButton */\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 95, 163, 0.8); /* Fond bleu plus fonc\303\251 avec transparence au survol */\n"
"    border-color: #005fa3; /* Bordure plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Effet press\303\251 pour QPushButton */\n"
"QPushButton:pressed {\n"
"    background-color: rgba(0, 79, 140, 0.8); /* Fond bleu encore plus fonc\303\251 avec transparence lors du clic */\n"
"    border-color: #004f8c; /* Bordure encore plus fonc\303\251e lors du clic */\n"
"}\n"
"\n"
"/* Style pour QPushButton d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: rgba(204, 204, 204, 0.8); /* Fond gris avec transparence */\n"
"    border-color: #cccccc; /* Bordure grise */\n"
"    color: #666666; /* Texte gris "
                        "fonc\303\251 */\n"
"} "));
        tab_13 = new QWidget();
        tab_13->setObjectName("tab_13");
        groupBox_15 = new QGroupBox(tab_13);
        groupBox_15->setObjectName("groupBox_15");
        groupBox_15->setGeometry(QRect(10, 0, 461, 401));
        groupBox_15->setStyleSheet(QString::fromUtf8(""));
        label_78 = new QLabel(groupBox_15);
        label_78->setObjectName("label_78");
        label_78->setGeometry(QRect(40, 39, 131, 41));
        label_78->setStyleSheet(QString::fromUtf8(""));
        label_79 = new QLabel(groupBox_15);
        label_79->setObjectName("label_79");
        label_79->setGeometry(QRect(40, 89, 131, 41));
        label_79->setStyleSheet(QString::fromUtf8(""));
        label_80 = new QLabel(groupBox_15);
        label_80->setObjectName("label_80");
        label_80->setGeometry(QRect(40, 140, 131, 41));
        label_80->setStyleSheet(QString::fromUtf8(""));
        label_81 = new QLabel(groupBox_15);
        label_81->setObjectName("label_81");
        label_81->setGeometry(QRect(40, 190, 131, 41));
        label_81->setStyleSheet(QString::fromUtf8(""));
        label_82 = new QLabel(groupBox_15);
        label_82->setObjectName("label_82");
        label_82->setGeometry(QRect(40, 240, 131, 41));
        label_82->setStyleSheet(QString::fromUtf8(""));
        lineEdit_76 = new QLineEdit(groupBox_15);
        lineEdit_76->setObjectName("lineEdit_76");
        lineEdit_76->setGeometry(QRect(220, 45, 121, 31));
        lineEdit_77 = new QLineEdit(groupBox_15);
        lineEdit_77->setObjectName("lineEdit_77");
        lineEdit_77->setGeometry(QRect(220, 95, 121, 31));
        lineEdit_78 = new QLineEdit(groupBox_15);
        lineEdit_78->setObjectName("lineEdit_78");
        lineEdit_78->setGeometry(QRect(220, 145, 121, 31));
        lineEdit_79 = new QLineEdit(groupBox_15);
        lineEdit_79->setObjectName("lineEdit_79");
        lineEdit_79->setGeometry(QRect(220, 195, 121, 31));
        lineEdit_80 = new QLineEdit(groupBox_15);
        lineEdit_80->setObjectName("lineEdit_80");
        lineEdit_80->setGeometry(QRect(220, 245, 121, 31));
        pushButton_37 = new QPushButton(groupBox_15);
        pushButton_37->setObjectName("pushButton_37");
        pushButton_37->setGeometry(QRect(20, 350, 121, 41));
        pushButton_38 = new QPushButton(groupBox_15);
        pushButton_38->setObjectName("pushButton_38");
        pushButton_38->setGeometry(QRect(280, 350, 121, 41));
        tab_client_3->addTab(tab_13, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName("tab_14");
        tableWidget_7 = new QTableWidget(tab_14);
        if (tableWidget_7->columnCount() < 6)
            tableWidget_7->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidget_7->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font1);
        tableWidget_7->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font1);
        tableWidget_7->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font1);
        tableWidget_7->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font1);
        tableWidget_7->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font1);
        tableWidget_7->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        tableWidget_7->setObjectName("tableWidget_7");
        tableWidget_7->setGeometry(QRect(-10, 0, 501, 381));
        tableWidget_7->setStyleSheet(QString::fromUtf8("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
"<ui version=\"4.0\">\n"
" <widget name=\"__qt_fake_top_level\">\n"
"  <widget class=\"QGroupBox\" name=\"groupBox_6\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>-10</x>\n"
"     <y>0</y>\n"
"     <width>501</width>\n"
"     <height>401</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"styleSheet\">\n"
"    <string notr=\"true\"/>\n"
"   </property>\n"
"   <property name=\"title\">\n"
"    <string/>\n"
"   </property>\n"
"   <widget class=\"QLabel\" name=\"label_28\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>40</x>\n"
"      <y>39</y>\n"
"      <width>131</width>\n"
"      <height>41</height>\n"
"     </rect>\n"
"    </property>\n"
"    <property name=\"styleSheet\">\n"
"     <string notr=\"true\"/>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string>Nom:</string>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLabel\" name=\"label_29\">\n"
"    <property name=\"geometry\""
                        ">\n"
"     <rect>\n"
"      <x>40</x>\n"
"      <y>89</y>\n"
"      <width>131</width>\n"
"      <height>41</height>\n"
"     </rect>\n"
"    </property>\n"
"    <property name=\"styleSheet\">\n"
"     <string notr=\"true\"/>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string>Pr\303\251nom :</string>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLabel\" name=\"label_30\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>40</x>\n"
"      <y>140</y>\n"
"      <width>131</width>\n"
"      <height>41</height>\n"
"     </rect>\n"
"    </property>\n"
"    <property name=\"styleSheet\">\n"
"     <string notr=\"true\"/>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string>T\303\251lephone :</string>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLabel\" name=\"label_31\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>40</x>\n"
"      <y>190</y>\n"
"      <width>131</width>\n"
"      <height>41</height>\n"
"     </rect"
                        ">\n"
"    </property>\n"
"    <property name=\"styleSheet\">\n"
"     <string notr=\"true\"/>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string>Email :</string>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLabel\" name=\"label_32\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>40</x>\n"
"      <y>240</y>\n"
"      <width>131</width>\n"
"      <height>41</height>\n"
"     </rect>\n"
"    </property>\n"
"    <property name=\"styleSheet\">\n"
"     <string notr=\"true\"/>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string>Paiment(dt):</string>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLineEdit\" name=\"lineEdit_26\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>220</x>\n"
"      <y>50</y>\n"
"      <width>113</width>\n"
"      <height>26</height>\n"
"     </rect>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string/>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLineE"
                        "dit\" name=\"lineEdit_27\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>220</x>\n"
"      <y>100</y>\n"
"      <width>113</width>\n"
"      <height>26</height>\n"
"     </rect>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLineEdit\" name=\"lineEdit_28\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>220</x>\n"
"      <y>150</y>\n"
"      <width>113</width>\n"
"      <height>26</height>\n"
"     </rect>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLineEdit\" name=\"lineEdit_29\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>220</x>\n"
"      <y>200</y>\n"
"      <width>113</width>\n"
"      <height>26</height>\n"
"     </rect>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QLineEdit\" name=\"lineEdit_30\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>220</x>\n"
"      <y>250</y>\n"
"      <width>113</width>\n"
"      <height>26</height>\n"
"     </rect>\n"
"    </property>\n"
"   </wi"
                        "dget>\n"
"   <widget class=\"QPushButton\" name=\"pushButton_17\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>20</x>\n"
"      <y>320</y>\n"
"      <width>121</width>\n"
"      <height>41</height>\n"
"     </rect>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string>Quitter</string>\n"
"    </property>\n"
"   </widget>\n"
"   <widget class=\"QPushButton\" name=\"pushButton_18\">\n"
"    <property name=\"geometry\">\n"
"     <rect>\n"
"      <x>270</x>\n"
"      <y>320</y>\n"
"      <width>121</width>\n"
"      <height>41</height>\n"
"     </rect>\n"
"    </property>\n"
"    <property name=\"text\">\n"
"     <string>Modifier</string>\n"
"    </property>\n"
"   </widget>\n"
"  </widget>\n"
" </widget>\n"
" <resources/>\n"
"</ui>\n"
""));
        tab_client_3->addTab(tab_14, QString());
        Modifier_7 = new QWidget();
        Modifier_7->setObjectName("Modifier_7");
        groupBox_16 = new QGroupBox(Modifier_7);
        groupBox_16->setObjectName("groupBox_16");
        groupBox_16->setGeometry(QRect(10, 0, 461, 401));
        groupBox_16->setStyleSheet(QString::fromUtf8(""));
        label_83 = new QLabel(groupBox_16);
        label_83->setObjectName("label_83");
        label_83->setGeometry(QRect(40, 39, 131, 41));
        label_83->setStyleSheet(QString::fromUtf8(""));
        label_84 = new QLabel(groupBox_16);
        label_84->setObjectName("label_84");
        label_84->setGeometry(QRect(40, 89, 131, 41));
        label_84->setStyleSheet(QString::fromUtf8(""));
        label_85 = new QLabel(groupBox_16);
        label_85->setObjectName("label_85");
        label_85->setGeometry(QRect(40, 140, 131, 41));
        label_85->setStyleSheet(QString::fromUtf8(""));
        label_86 = new QLabel(groupBox_16);
        label_86->setObjectName("label_86");
        label_86->setGeometry(QRect(40, 190, 131, 41));
        label_86->setStyleSheet(QString::fromUtf8(""));
        label_87 = new QLabel(groupBox_16);
        label_87->setObjectName("label_87");
        label_87->setGeometry(QRect(40, 240, 131, 41));
        label_87->setStyleSheet(QString::fromUtf8(""));
        lineEdit_81 = new QLineEdit(groupBox_16);
        lineEdit_81->setObjectName("lineEdit_81");
        lineEdit_81->setGeometry(QRect(220, 45, 121, 31));
        lineEdit_82 = new QLineEdit(groupBox_16);
        lineEdit_82->setObjectName("lineEdit_82");
        lineEdit_82->setGeometry(QRect(220, 95, 121, 31));
        lineEdit_83 = new QLineEdit(groupBox_16);
        lineEdit_83->setObjectName("lineEdit_83");
        lineEdit_83->setGeometry(QRect(220, 145, 121, 31));
        lineEdit_84 = new QLineEdit(groupBox_16);
        lineEdit_84->setObjectName("lineEdit_84");
        lineEdit_84->setGeometry(QRect(220, 195, 121, 31));
        lineEdit_85 = new QLineEdit(groupBox_16);
        lineEdit_85->setObjectName("lineEdit_85");
        lineEdit_85->setGeometry(QRect(220, 245, 121, 31));
        pushButton_39 = new QPushButton(groupBox_16);
        pushButton_39->setObjectName("pushButton_39");
        pushButton_39->setGeometry(QRect(20, 350, 121, 41));
        pushButton_40 = new QPushButton(groupBox_16);
        pushButton_40->setObjectName("pushButton_40");
        pushButton_40->setGeometry(QRect(280, 350, 121, 41));
        tab_client_3->addTab(Modifier_7, QString());
        stackedWidget->addWidget(page5_RENDEZVOUS);
        page6_RESSOURCES = new QWidget();
        page6_RESSOURCES->setObjectName("page6_RESSOURCES");
        label_12 = new QLabel(page6_RESSOURCES);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, -10, 911, 801));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/back.png")));
        label_18 = new QLabel(page6_RESSOURCES);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(670, 29, 211, 51));
        ListeRessource = new QWidget(page6_RESSOURCES);
        ListeRessource->setObjectName("ListeRessource");
        ListeRessource->setGeometry(QRect(160, 260, 491, 401));
        chercherRESSOURCE = new QLineEdit(ListeRessource);
        chercherRESSOURCE->setObjectName("chercherRESSOURCE");
        chercherRESSOURCE->setGeometry(QRect(30, 20, 331, 41));
        trie_ressource = new QComboBox(ListeRessource);
        trie_ressource->setObjectName("trie_ressource");
        trie_ressource->setGeometry(QRect(30, 80, 171, 31));
        trie_ressource->setStyleSheet(QString::fromUtf8("QLineEdit, QDateEdit, QComboBox {\n"
"    border: 2px solid #3A7ECF;  /* Bordure bleue */\n"
"    border-radius: 5px;\n"
"    background-color: transparent; /* Fond transparent */\n"
"    color: white;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* Supprimer la fl\303\250che du QComboBox et l'ic\303\264ne du QDateEdit */\n"
"QComboBox::drop-down, QDateEdit::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"/QComboBox QAbstractItemView {\n"
"    background-color: #2D2D2D; /* M\303\252me fond que le formulaire */\n"
"    border: 1px solid #3A7ECF;\n"
"    /*selection-background-color: #3A7ECF;*/\n"
"selection-background-color: white;\n"
"}\n"
"\n"
"\n"
"/* Style des boutons haut/bas du QDateEdit */\n"
"QDateEdit::up-button, QDateEdit::down-button {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
""));
        CherRessourceNom = new QPushButton(ListeRessource);
        CherRessourceNom->setObjectName("CherRessourceNom");
        CherRessourceNom->setGeometry(QRect(370, 20, 111, 41));
        tableRessource = new QTableView(ListeRessource);
        tableRessource->setObjectName("tableRessource");
        tableRessource->setGeometry(QRect(30, 120, 491, 301));
        tableRessource->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral pour le tableau */\n"
"QTableView {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #e0e0e0; /* Bordure l\303\251g\303\250re */\n"
"    gridline-color: #e0e0e0; /* Couleur des lignes de la grille */\n"
"    font-family: Arial, sans-serif; /* Police */\n"
"    font-size: 10px; /* Taille de la police r\303\251duite */\n"
"    selection-background-color: transparent; /* D\303\251sactiver la couleur de fond de la s\303\251lection */\n"
"    selection-color: inherit; /* Conserver la couleur du texte d'origine */\n"
"}\n"
"\n"
"/* Style pour l'en-t\303\252te du tableau */\n"
"QHeaderView::section {\n"
"    background-color: #2196F3; /* Couleur de fond de l'en-t\303\252te (bleu) */\n"
"    color: white; /* Couleur du texte */\n"
"    padding: 0px; /* Espacement interne r\303\251duit */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    border: 1px solid #1E88E5; /* Bordure */\n"
"    font-size: 11px; /* Taille de la police r\303\251duite */\n"
"    text"
                        "-align: center; /* Alignement du texte au centre */\n"
"}\n"
"\n"
"/* D\303\251sactiver la s\303\251lection des en-t\303\252tes */\n"
"QHeaderView::section:selected {\n"
"    background-color: #2196F3; /* Conserver la couleur de fond de l'en-t\303\252te */\n"
"    color: white; /* Conserver la couleur du texte */\n"
"}\n"
"\n"
"/* Style pour les cellules du tableau */\n"
"QTableView::item {\n"
"    padding: 1px; /* Espacement interne r\303\251duit */\n"
"    border: 1px solid #e0e0e0; /* Bordure l\303\251g\303\250re */\n"
"    color: #333333; /* Couleur du texte */\n"
"    text-align: center; /* Alignement horizontal au centre */\n"
"    vertical-align: middle; /* Alignement vertical au centre */\n"
"}\n"
"\n"
"/* D\303\251sactiver la s\303\251lection des cellules */\n"
"QTableView::item:selected {\n"
"    background-color: transparent; /* Fond transparent pour les cellules s\303\251lectionn\303\251es */\n"
"    color: inherit; /* Conserver la couleur du texte d'origine */\n"
"}\n"
"\n"
"/* Style pour les bout"
                        "ons */\n"
"QPushButton {\n"
"    background-color: #2196F3; /* Couleur de fond (bleu) */\n"
"    color: white; /* Couleur du texte */\n"
"    padding: 3px 8px; /* Espacement interne r\303\251duit */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 3px; /* Coins arrondis r\303\251duits */\n"
"    font-size: 12px; /* Taille de la police r\303\251duite */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1E88E5; /* Couleur de fond au survol (bleu plus fonc\303\251) */\n"
"}\n"
"\n"
"/* Style pour les champs de saisie */\n"
"QLineEdit {\n"
"    padding: 2px; /* Espacement interne r\303\251duit */\n"
"    border: 1px solid #ccc; /* Bordure */\n"
"    border-radius: 3px; /* Coins arrondis r\303\251duits */\n"
"    font-size: 12px; /* Taille de la police r\303\251duite */\n"
"    background-color: #f9f9f9; /* Fond l\303\251g\303\250rement gris */\n"
"}\n"
"\n"
"/* Style pour les cases \303\240 cocher */\n"
"QCheckBox {\n"
"    spacing: 3px; /"
                        "* Espacement r\303\251duit entre la case et le texte */\n"
"    font-size: 12px; /* Taille de la police r\303\251duite */\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 14px; /* Largeur de la case r\303\251duite */\n"
"    height: 14px; /* Hauteur de la case r\303\251duite */\n"
"}\n"
"\n"
"/* Style pour les boutons radio */\n"
"QRadioButton {\n"
"    spacing: 3px; /* Espacement r\303\251duit entre le bouton et le texte */\n"
"    font-size: 12px; /* Taille de la police r\303\251duite */\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 14px; /* Largeur du bouton r\303\251duite */\n"
"    height: 14px; /* Hauteur du bouton r\303\251duite */\n"
"}\n"
"\n"
"/* Style pour les dates */\n"
"QDateEdit {\n"
"    padding: 3px; /* Espacement interne r\303\251duit */\n"
"    border: 1px solid #ccc; /* Bordure */\n"
"    border-radius: 3px; /* Coins arrondis r\303\251duits */\n"
"    font-size: 12px; /* Taille de la police r\303\251duite */\n"
"    background-color: #f9f9f9; /* Fond l\303\251g\303\250rement g"
                        "ris */\n"
"}\n"
"\n"
"/* Style pour les titres */\n"
"QLabel {\n"
"    font-size: 12px; /* Taille de la police r\303\251duite */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style pour les sous-titres */\n"
"QLabel#subtitle {\n"
"    font-size: 10px; /* Taille de la police r\303\251duite */\n"
"    color: #666666; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style pour les s\303\251parateurs */\n"
"QFrame#separator {\n"
"    background-color: #e0e0e0; /* Couleur de fond */\n"
"    border: none; /* Pas de bordure */\n"
"    height: 1px; /* Hauteur */\n"
"}\n"
"* Style pour l'en-t\303\252te du tableau */\n"
"QHeaderView::section {\n"
"    background-color: #2196F3; /* Couleur de fond de l'en-t\303\252te (bleu) */\n"
"    color: white; /* Couleur du texte */\n"
"    padding: 0px; /* Supprimer l'espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    border: none; /* Supprimer la bordure */\n"
"    font-size: 12px; /* Taille de la "
                        "police r\303\251duite */\n"
"    text-align: center; /* Alignement du texte au centre */\n"
"    margin: 0px; /* Supprimer les marges entre les sections */\n"
"}\n"
"\n"
"/* D\303\251sactiver la s\303\251lection des en-t\303\252tes */\n"
"QHeaderView::section:selected {\n"
"    background-color: #2196F3; /* Conserver la couleur de fond de l'en-t\303\252te */\n"
"    color: white; /* Conserver la couleur du texte */\n"
"}"));
        CherRessourceNom_2 = new QPushButton(ListeRessource);
        CherRessourceNom_2->setObjectName("CherRessourceNom_2");
        CherRessourceNom_2->setGeometry(QRect(210, 70, 281, 41));
        stackedWidget->addWidget(page6_RESSOURCES);
        page2_CLIENTS = new QWidget();
        page2_CLIENTS->setObjectName("page2_CLIENTS");
        label_6 = new QLabel(page2_CLIENTS);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, -10, 911, 801));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/back.png")));
        employes = new QTabWidget(page2_CLIENTS);
        employes->setObjectName("employes");
        employes->setGeometry(QRect(190, 280, 491, 441));
        employes->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral du QTabWidget */\n"
"QTabWidget {\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #007acc; /* Bordure bleue */\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 4px; /* Espacement int\303\251rieur */\n"
"}\n"
"\n"
"\n"
"\n"
"/* Style des onglets */\n"
"QTabBar::tab {\n"
"    background-color: rgba(240, 240, 240, 0.8); /* Fond gris clair avec transparence */\n"
"    color: #333333; /* Texte gris fonc\303\251 */\n"
"    padding: 8px 16px; /* Espacement int\303\251rieur */\n"
"    border: 1px solid #cccccc; /* Bordure l\303\251g\303\250re */\n"
"    border-bottom: none; /* Pas de bordure en bas */\n"
"    border-top-left-radius: 6px; /* Coin arrondi en haut \303\240 gauche */\n"
"    border-top-right-radius: 6px; /* Coin arrondi en haut \303\240 droite */\n"
"    margin-right: 4px; /* Espacement entre les onglets */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
""
                        "}\n"
"\n"
"/* Onglet s\303\251lectionn\303\251 */\n"
"QTabBar::tab:selected {\n"
"    background-color: rgba(0, 122, 204, 0.9); /* Fond bleu avec transparence */\n"
"    color: white; /* Texte blanc */\n"
"    border-color: #007acc; /* Bordure bleue */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"/* Effet hover sur les onglets */\n"
"QTabBar::tab:hover {\n"
"    background-color: rgba(224, 224, 224, 0.8); /* Fond gris plus clair au survol */\n"
"    color: #007acc; /* Texte bleu au survol */\n"
"}\n"
"\n"
"\n"
"\n"
"/* Style de la barre d'onglets */\n"
"QTabBar {\n"
"    background: transparent; /* Fond transparent */\n"
"    border: none; /* Pas de bordure */\n"
"    spacing: 4px; /* Espacement entre les onglets */\n"
"}\n"
"\n"
"/* Style du bouton de fermeture des onglets (si applicable) */\n"
"QTabBar::close-button {\n"
"    background: transparent; /* Fond transparent */\n"
"    padding: 4px; /* Espacement int\303\251rieur */\n"
"    border-radius: 2px; /* Coins l\303\251g\303\250rement ar"
                        "rondis */\n"
"}\n"
"\n"
"QTabBar::close-button:hover {\n"
"    background: rgba(255, 68, 68, 0.8); /* Fond rouge avec transparence au survol */\n"
"    color: white; /* Texte blanc */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les QLabel */\n"
"QLabel {\n"
"    font-size: 14px; /* Taille de police */\n"
"    color: white; /* Texte gris fonc\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    border: 2px solid #007acc; /* Bordure bleue */\n"
"    border-radius: 6px; /* Coins arrondis */\n"
" \n"
"    margin: 4px; /* Marge ext\303\251rieure */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
"font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"/* Effet hover pour QLabel */\n"
"QLabel:hover {\n"
"    background-color: rgba(240, 248, 255, 0.8); /* Fond bleu clair avec transparence au survol */\n"
"    border-color: #005fa3; /* Bordure plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Style pour QLineEdit */\n"
"QLineEdit {\n"
"    font-size: 14px; /* Tai"
                        "lle de police */\n"
"    color: #333333; /* Texte gris fonc\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    border: 2px solid #007acc; /* Bordure bleue */\n"
"    border-radius: 6px; /* Coins arrondis */\n"
"  \n"
"    margin: 4px; /* Marge ext\303\251rieure */\n"
"   font-weight: bold; /* Texte en gras */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
"}\n"
"\n"
"/* Effet focus pour QLineEdit */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #005fa3; /* Bordure plus fonc\303\251e lors du focus */\n"
"    background-color: rgba(240, 248, 255, 0.8); /* Fond bleu clair avec transparence lors du focus */\n"
"}\n"
"\n"
"/* Style pour QPushButton */\n"
"QPushButton {\n"
"    font-size: 14px; /* Taille de police */\n"
"    color: white; /* Texte blanc */\n"
"    background-color: rgba(0, 122, 204, 0.8); /* Fond bleu avec transparence */\n"
"    border: 2px solid #007acc; /* Bordure bleue */\n"
"    border-radius: 6px; /* Coins arrondis */\n"
"    padding: 8px"
                        " 16px; /* Espacement int\303\251rieur */\n"
"    margin: 4px; /* Marge ext\303\251rieure */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"/* Effet hover pour QPushButton */\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 95, 163, 0.8); /* Fond bleu plus fonc\303\251 avec transparence au survol */\n"
"    border-color: #005fa3; /* Bordure plus fonc\303\251e au survol */\n"
"}\n"
"\n"
"/* Effet press\303\251 pour QPushButton */\n"
"QPushButton:pressed {\n"
"    background-color: rgba(0, 79, 140, 0.8); /* Fond bleu encore plus fonc\303\251 avec transparence lors du clic */\n"
"    border-color: #004f8c; /* Bordure encore plus fonc\303\251e lors du clic */\n"
"}\n"
"\n"
"/* Style pour QPushButton d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: rgba(204, 204, 204, 0.8); /* Fond gris avec transparence */\n"
"    border-color: #cccccc; /* Bordure grise */\n"
"    color: #666666; /* Texte gris "
                        "fonc\303\251 */\n"
"} "));
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        groupBox_9 = new QGroupBox(tab_7);
        groupBox_9->setObjectName("groupBox_9");
        groupBox_9->setGeometry(QRect(10, 0, 461, 401));
        groupBox_9->setStyleSheet(QString::fromUtf8(""));
        label_43 = new QLabel(groupBox_9);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(40, 40, 131, 41));
        label_43->setStyleSheet(QString::fromUtf8(""));
        label_44 = new QLabel(groupBox_9);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(40, 80, 131, 41));
        label_44->setStyleSheet(QString::fromUtf8(""));
        label_45 = new QLabel(groupBox_9);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(40, 120, 131, 41));
        label_45->setStyleSheet(QString::fromUtf8(""));
        label_46 = new QLabel(groupBox_9);
        label_46->setObjectName("label_46");
        label_46->setGeometry(QRect(40, 160, 131, 41));
        label_46->setStyleSheet(QString::fromUtf8(""));
        label_47 = new QLabel(groupBox_9);
        label_47->setObjectName("label_47");
        label_47->setGeometry(QRect(40, 240, 131, 41));
        label_47->setStyleSheet(QString::fromUtf8(""));
        NOM = new QLineEdit(groupBox_9);
        NOM->setObjectName("NOM");
        NOM->setGeometry(QRect(220, 50, 121, 31));
        PRENOM = new QLineEdit(groupBox_9);
        PRENOM->setObjectName("PRENOM");
        PRENOM->setGeometry(QRect(220, 90, 121, 31));
        TELEPHONE = new QLineEdit(groupBox_9);
        TELEPHONE->setObjectName("TELEPHONE");
        TELEPHONE->setGeometry(QRect(220, 130, 121, 31));
        MAIL = new QLineEdit(groupBox_9);
        MAIL->setObjectName("MAIL");
        MAIL->setGeometry(QRect(220, 170, 121, 31));
        PAIMENT = new QLineEdit(groupBox_9);
        PAIMENT->setObjectName("PAIMENT");
        PAIMENT->setGeometry(QRect(220, 250, 121, 31));
        pushButton_23 = new QPushButton(groupBox_9);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(20, 350, 121, 41));
        AjouterClient = new QPushButton(groupBox_9);
        AjouterClient->setObjectName("AjouterClient");
        AjouterClient->setGeometry(QRect(280, 350, 121, 41));
        label_73 = new QLabel(groupBox_9);
        label_73->setObjectName("label_73");
        label_73->setGeometry(QRect(40, 0, 131, 41));
        label_73->setStyleSheet(QString::fromUtf8(""));
        CIN = new QLineEdit(groupBox_9);
        CIN->setObjectName("CIN");
        CIN->setGeometry(QRect(220, 10, 121, 31));
        label_75 = new QLabel(groupBox_9);
        label_75->setObjectName("label_75");
        label_75->setGeometry(QRect(40, 200, 131, 41));
        label_75->setStyleSheet(QString::fromUtf8(""));
        ADRESSE = new QLineEdit(groupBox_9);
        ADRESSE->setObjectName("ADRESSE");
        ADRESSE->setGeometry(QRect(220, 210, 121, 31));
        employes->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        tableView = new QTableView(tab_8);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 40, 471, 281));
        employes->addTab(tab_8, QString());
        Modifier_4 = new QWidget();
        Modifier_4->setObjectName("Modifier_4");
        groupBox_10 = new QGroupBox(Modifier_4);
        groupBox_10->setObjectName("groupBox_10");
        groupBox_10->setGeometry(QRect(10, 0, 461, 401));
        groupBox_10->setStyleSheet(QString::fromUtf8(""));
        label_48 = new QLabel(groupBox_10);
        label_48->setObjectName("label_48");
        label_48->setGeometry(QRect(40, 40, 131, 41));
        label_48->setStyleSheet(QString::fromUtf8(""));
        label_49 = new QLabel(groupBox_10);
        label_49->setObjectName("label_49");
        label_49->setGeometry(QRect(40, 80, 131, 41));
        label_49->setStyleSheet(QString::fromUtf8(""));
        label_50 = new QLabel(groupBox_10);
        label_50->setObjectName("label_50");
        label_50->setGeometry(QRect(40, 120, 131, 41));
        label_50->setStyleSheet(QString::fromUtf8(""));
        label_51 = new QLabel(groupBox_10);
        label_51->setObjectName("label_51");
        label_51->setGeometry(QRect(40, 160, 131, 41));
        label_51->setStyleSheet(QString::fromUtf8(""));
        label_52 = new QLabel(groupBox_10);
        label_52->setObjectName("label_52");
        label_52->setGeometry(QRect(40, 240, 131, 41));
        label_52->setStyleSheet(QString::fromUtf8(""));
        PRENOM2 = new QLineEdit(groupBox_10);
        PRENOM2->setObjectName("PRENOM2");
        PRENOM2->setGeometry(QRect(220, 90, 121, 31));
        TELEPHONE2 = new QLineEdit(groupBox_10);
        TELEPHONE2->setObjectName("TELEPHONE2");
        TELEPHONE2->setGeometry(QRect(220, 130, 121, 31));
        MAIL2 = new QLineEdit(groupBox_10);
        MAIL2->setObjectName("MAIL2");
        MAIL2->setGeometry(QRect(220, 170, 121, 31));
        PAIMENT2 = new QLineEdit(groupBox_10);
        PAIMENT2->setObjectName("PAIMENT2");
        PAIMENT2->setGeometry(QRect(220, 250, 121, 31));
        pushButton_25 = new QPushButton(groupBox_10);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setGeometry(QRect(20, 350, 121, 41));
        pushButton_26 = new QPushButton(groupBox_10);
        pushButton_26->setObjectName("pushButton_26");
        pushButton_26->setGeometry(QRect(280, 350, 121, 41));
        NOM2 = new QLineEdit(groupBox_10);
        NOM2->setObjectName("NOM2");
        NOM2->setGeometry(QRect(220, 50, 121, 31));
        label_74 = new QLabel(groupBox_10);
        label_74->setObjectName("label_74");
        label_74->setGeometry(QRect(40, 0, 131, 41));
        label_74->setStyleSheet(QString::fromUtf8(""));
        CIN2 = new QLineEdit(groupBox_10);
        CIN2->setObjectName("CIN2");
        CIN2->setGeometry(QRect(220, 10, 121, 31));
        label_76 = new QLabel(groupBox_10);
        label_76->setObjectName("label_76");
        label_76->setGeometry(QRect(40, 200, 131, 41));
        label_76->setStyleSheet(QString::fromUtf8(""));
        ADRESSE2 = new QLineEdit(groupBox_10);
        ADRESSE2->setObjectName("ADRESSE2");
        ADRESSE2->setGeometry(QRect(220, 210, 121, 31));
        employes->addTab(Modifier_4, QString());
        label_13 = new QLabel(page2_CLIENTS);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(670, 30, 151, 20));
        stackedWidget->addWidget(page2_CLIENTS);
        frame->raise();
        rechercher->raise();
        label->raise();
        trierTableView->raise();
        stackedWidget->raise();
        deconnexionButton->raise();

        retranslateUi(justemp);

        stackedWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);
        employes_3->setCurrentIndex(0);
        tab_client_3->setCurrentIndex(0);
        employes->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(justemp);
    } // setupUi

    void retranslateUi(QDialog *justemp)
    {
        justemp->setWindowTitle(QCoreApplication::translate("justemp", "Dialog", nullptr));
        Employes->setText(QCoreApplication::translate("justemp", "Gestion des employ\303\251s", nullptr));
        Clients->setText(QCoreApplication::translate("justemp", "Gestion des clients", nullptr));
        Projets->setText(QCoreApplication::translate("justemp", "Gestion des projets", nullptr));
        Partenaire->setText(QCoreApplication::translate("justemp", "Gestion des partenaires ", nullptr));
        RendezVous->setText(QCoreApplication::translate("justemp", "Gestion des rendez-vous", nullptr));
        label_14->setText(QCoreApplication::translate("justemp", "Dashboard", nullptr));
        Ressources->setText(QCoreApplication::translate("justemp", "Gestion des ressources", nullptr));
        label_2->setText(QString());
#if QT_CONFIG(tooltip)
        roleLabel->setToolTip(QCoreApplication::translate("justemp", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        roleLabel->setText(QString());
#if QT_CONFIG(tooltip)
        cinLabel->setToolTip(QCoreApplication::translate("justemp", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cinLabel->setText(QString());
        deconnexionButton->setText(QCoreApplication::translate("justemp", "Deconexion", nullptr));
        label->setText(QCoreApplication::translate("justemp", "rechercher", nullptr));
        label_3->setText(QString());
        label_5->setText(QCoreApplication::translate("justemp", "AZIZ HENI EMPLOYES", nullptr));
        label_15->setText(QCoreApplication::translate("justemp", "rechercher", nullptr));
        StatistiqueButton->setText(QCoreApplication::translate("justemp", "Statistique", nullptr));
        ExporterPDFButton->setText(QCoreApplication::translate("justemp", "PDF", nullptr));
        TrierButton->setText(QCoreApplication::translate("justemp", "Trier", nullptr));
        label_4->setText(QString());
        label_7->setText(QCoreApplication::translate("justemp", "SAIF DKHAILI PROJETS", nullptr));
        label_40->setText(QCoreApplication::translate("justemp", "TO DO", nullptr));
        label_41->setText(QCoreApplication::translate("justemp", "DOING", nullptr));
        label_42->setText(QCoreApplication::translate("justemp", "DONE", nullptr));
        movetodoing->setText(QCoreApplication::translate("justemp", "passer a doing", nullptr));
        delete_2->setText(QCoreApplication::translate("justemp", "supprimer", nullptr));
        movetodone->setText(QCoreApplication::translate("justemp", "passer a done", nullptr));
        add->setText(QCoreApplication::translate("justemp", "ajouter", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(todolist), QCoreApplication::translate("justemp", "todolist", nullptr));
        label_8->setText(QString());
        groupBox_13->setTitle(QString());
        label_63->setText(QCoreApplication::translate("justemp", "Nom:", nullptr));
        label_64->setText(QCoreApplication::translate("justemp", "Pr\303\251nom :", nullptr));
        label_65->setText(QCoreApplication::translate("justemp", "T\303\251lephone :", nullptr));
        label_66->setText(QCoreApplication::translate("justemp", "Email :", nullptr));
        label_67->setText(QCoreApplication::translate("justemp", "Paiment(dt):", nullptr));
        lineEdit_61->setText(QString());
        pushButton_31->setText(QCoreApplication::translate("justemp", "Quitter", nullptr));
        pushButton_32->setText(QCoreApplication::translate("justemp", "Ajouter", nullptr));
        employes_3->setTabText(employes_3->indexOf(tab_11), QCoreApplication::translate("justemp", "ajouter", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_6->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("justemp", "Id client", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_6->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("justemp", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_6->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("justemp", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_6->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("justemp", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_6->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("justemp", "Paiment", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_6->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("justemp", "Actions", nullptr));
        employes_3->setTabText(employes_3->indexOf(tab_12), QCoreApplication::translate("justemp", "lister", nullptr));
        groupBox_14->setTitle(QString());
        label_68->setText(QCoreApplication::translate("justemp", "Nom:", nullptr));
        label_69->setText(QCoreApplication::translate("justemp", "Pr\303\251nom :", nullptr));
        label_70->setText(QCoreApplication::translate("justemp", "T\303\251lephone :", nullptr));
        label_71->setText(QCoreApplication::translate("justemp", "Email :", nullptr));
        label_72->setText(QCoreApplication::translate("justemp", "Paiment(dt):", nullptr));
        lineEdit_66->setText(QString());
        pushButton_33->setText(QCoreApplication::translate("justemp", "Quitter", nullptr));
        pushButton_34->setText(QCoreApplication::translate("justemp", "Modifier", nullptr));
        employes_3->setTabText(employes_3->indexOf(Modifier_6), QCoreApplication::translate("justemp", "modifier", nullptr));
        label_9->setText(QCoreApplication::translate("justemp", "Yasmine jbeli PARTENAIRE", nullptr));
        label_10->setText(QString());
        label_11->setText(QCoreApplication::translate("justemp", "BARAA Mensi RENDEZ-VOUS", nullptr));
        groupBox_15->setTitle(QString());
        label_78->setText(QCoreApplication::translate("justemp", "Nom:", nullptr));
        label_79->setText(QCoreApplication::translate("justemp", "Pr\303\251nom :", nullptr));
        label_80->setText(QCoreApplication::translate("justemp", "T\303\251lephone :", nullptr));
        label_81->setText(QCoreApplication::translate("justemp", "Email :", nullptr));
        label_82->setText(QCoreApplication::translate("justemp", "Paiment(dt):", nullptr));
        lineEdit_76->setText(QString());
        pushButton_37->setText(QCoreApplication::translate("justemp", "Quitter", nullptr));
        pushButton_38->setText(QCoreApplication::translate("justemp", "Ajouter", nullptr));
        tab_client_3->setTabText(tab_client_3->indexOf(tab_13), QCoreApplication::translate("justemp", "ajouter", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_7->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("justemp", "Id client", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_7->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("justemp", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_7->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("justemp", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_7->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("justemp", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_7->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("justemp", "Paiment", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_7->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("justemp", "Actions", nullptr));
        tab_client_3->setTabText(tab_client_3->indexOf(tab_14), QCoreApplication::translate("justemp", "lister", nullptr));
        groupBox_16->setTitle(QString());
        label_83->setText(QCoreApplication::translate("justemp", "Nom:", nullptr));
        label_84->setText(QCoreApplication::translate("justemp", "Pr\303\251nom :", nullptr));
        label_85->setText(QCoreApplication::translate("justemp", "T\303\251lephone :", nullptr));
        label_86->setText(QCoreApplication::translate("justemp", "Email :", nullptr));
        label_87->setText(QCoreApplication::translate("justemp", "Paiment(dt):", nullptr));
        lineEdit_81->setText(QString());
        pushButton_39->setText(QCoreApplication::translate("justemp", "Quitter", nullptr));
        pushButton_40->setText(QCoreApplication::translate("justemp", "Modifier", nullptr));
        tab_client_3->setTabText(tab_client_3->indexOf(Modifier_7), QCoreApplication::translate("justemp", "modifier", nullptr));
        label_12->setText(QString());
        label_18->setText(QCoreApplication::translate("justemp", "YOSR MOUSSA ressources", nullptr));
        CherRessourceNom->setText(QCoreApplication::translate("justemp", "Chercher", nullptr));
        CherRessourceNom_2->setText(QCoreApplication::translate("justemp", "Gerer cette liste dans un fichier PDF", nullptr));
        label_6->setText(QString());
        groupBox_9->setTitle(QString());
        label_43->setText(QCoreApplication::translate("justemp", "Nom:", nullptr));
        label_44->setText(QCoreApplication::translate("justemp", "Pr\303\251nom :", nullptr));
        label_45->setText(QCoreApplication::translate("justemp", "T\303\251lephone :", nullptr));
        label_46->setText(QCoreApplication::translate("justemp", "Email :", nullptr));
        label_47->setText(QCoreApplication::translate("justemp", "Paiment(dt):", nullptr));
        NOM->setText(QString());
        pushButton_23->setText(QCoreApplication::translate("justemp", "Quitter", nullptr));
        AjouterClient->setText(QCoreApplication::translate("justemp", "Ajouter", nullptr));
        label_73->setText(QCoreApplication::translate("justemp", "CIN_Client", nullptr));
        CIN->setText(QString());
        label_75->setText(QCoreApplication::translate("justemp", "Adresse", nullptr));
        employes->setTabText(employes->indexOf(tab_7), QCoreApplication::translate("justemp", "ajouter", nullptr));
        employes->setTabText(employes->indexOf(tab_8), QCoreApplication::translate("justemp", "lister", nullptr));
        groupBox_10->setTitle(QString());
        label_48->setText(QCoreApplication::translate("justemp", "Nom:", nullptr));
        label_49->setText(QCoreApplication::translate("justemp", "Pr\303\251nom :", nullptr));
        label_50->setText(QCoreApplication::translate("justemp", "T\303\251lephone :", nullptr));
        label_51->setText(QCoreApplication::translate("justemp", "Email :", nullptr));
        label_52->setText(QCoreApplication::translate("justemp", "Paiment(dt):", nullptr));
        PRENOM2->setText(QString());
        pushButton_25->setText(QCoreApplication::translate("justemp", "Quitter", nullptr));
        pushButton_26->setText(QCoreApplication::translate("justemp", "Modifier", nullptr));
        NOM2->setText(QString());
        label_74->setText(QCoreApplication::translate("justemp", "CIN_Client:", nullptr));
        CIN2->setText(QString());
        label_76->setText(QCoreApplication::translate("justemp", "Adresse :", nullptr));
        employes->setTabText(employes->indexOf(Modifier_4), QCoreApplication::translate("justemp", "modifier", nullptr));
        label_13->setText(QCoreApplication::translate("justemp", "Aziz Akrout CLIENTS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class justemp: public Ui_justemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUSTEMP_H

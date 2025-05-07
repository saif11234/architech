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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
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
    QStackedWidget *stackedWidget;
    QWidget *page1_EMPLOYES;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_15;
    QTableView *trierTableView;
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
    QLabel *label_9;
    QTabWidget *TabP;
    QWidget *tab_12;
    QTableView *tableViewP;
    QPushButton *ExporterPDF;
    QComboBox *CombpBoxtrie_2;
    QPushButton *TRIERPartenair;
    QWidget *tab_3;
    QWidget *chartContainer;
    QPushButton *AfficherStatistique;
    QWidget *tab_5;
    QLineEdit *Taper;
    QPushButton *RechercherPartenair;
    QTableView *tableViewPartenair;
    QComboBox *CombpBoxRecherche;
    QWidget *tab_6;
    QLineEdit *phoneLineEdit;
    QLabel *label_21;
    QPushButton *sendButton;
    QTextEdit *messageTextEdit;
    QWidget *tab_17;
    QLineEdit *mail_3;
    QLabel *label_22;
    QPushButton *envoyer;
    QLabel *label_23;
    QLineEdit *objet;
    QTextEdit *corps;
    QRadioButton *urgent;
    QWidget *page5_RENDEZVOUS;
    QLabel *label_10;
    QLabel *label_11;
    QTabWidget *TabRV;
    QWidget *tab_34;
    QTableView *tableView2RV_7;
    QLineEdit *rechercheRV_7;
    QPushButton *chercherRV_7;
    QPushButton *afficherRV_7;
    QPushButton *exporterRV_7;
    QComboBox *comboBoxTriRV_7;
    QWidget *tab_36;
    QGraphicsView *graphicsViewCal_RV_7;
    QPushButton *pushButtonMoisPrecedent_RV_7;
    QPushButton *pushButtonMoisSuivant_RV_7;
    QWidget *page6_RESSOURCES;
    QLabel *label_12;
    QLabel *label_18;
    QTabWidget *tab_ressource;
    QWidget *AfficherRessources_10;
    QTableView *tableRessource_10;
    QWidget *ListeRessource_10;
    QLineEdit *chercherRESSOURCE_10;
    QPushButton *CherRessourceNom_10;
    QComboBox *trie_ressource_10;
    QPushButton *CherRessourceNom_7;
    QWidget *page2_CLIENTS;
    QLabel *label_6;
    QLabel *label_13;
    QTabWidget *TabC;
    QWidget *tab_8;
    QTableView *tableViewC;
    QPushButton *pushButtonTrier_C;
    QComboBox *comboBoxTri;
    QPushButton *Exporter_PDF;
    QLineEdit *lineEditRecherche;
    QPushButton *chercher;
    QWidget *tab;
    QWidget *widgetC;
    QWidget *tab_4;
    QTableWidget *RATINGS;

    void setupUi(QDialog *justemp)
    {
        if (justemp->objectName().isEmpty())
            justemp->setObjectName("justemp");
        justemp->resize(1090, 798);
        frame = new QFrame(justemp);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, -30, 231, 831));
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
        Projets->setGeometry(QRect(0, 360, 190, 71));
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
        deconnexionButton->setGeometry(QRect(1000, 10, 80, 18));
        rechercher = new QLineEdit(justemp);
        rechercher->setObjectName("rechercher");
        rechercher->setGeometry(QRect(340, 90, 261, 31));
        label = new QLabel(justemp);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 90, 61, 21));
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
        trierTableView = new QTableView(page1_EMPLOYES);
        trierTableView->setObjectName("trierTableView");
        trierTableView->setGeometry(QRect(190, 550, 351, 181));
        trierTableView->setStyleSheet(QString::fromUtf8("font: 300 italic 9pt \"Segoe UI\";\n"
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
        tabWidget_2->setGeometry(QRect(200, 250, 491, 411));
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
        label_9 = new QLabel(page4_PARTENAIRES);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(670, 30, 201, 41));
        TabP = new QTabWidget(page4_PARTENAIRES);
        TabP->setObjectName("TabP");
        TabP->setGeometry(QRect(190, 280, 491, 441));
        TabP->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral du QTabWidget */\n"
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
"} \n"
"QTableView {\n"
"    background: transparent;\n"
"    border: 2px solid rgba(255, 255, 255, 0.3);\n"
"    border-radius: 10px;\n"
"    color: white;\n"
"    gridline-color: rgba(255, 255, 255, 0.2);\n"
"    selection-background-color: rgba(0, 162, 232, 0.3); /* Bleu translucide */\n"
"    selection-color: white;\n"
"    font-weight: bold;  /* Contenu en gras */\n"
"}\n"
"\n"
"/* --- Style des cellules --- */\n"
"QTableView::item {\n"
"    background: rgba(0, 162, 232, 0.1); /* Bleu tr\303\250s l\303\251ger */\n"
"    border: none;\n"
"    padding: 5px;\n"
"    font-weight: bold; /* Gras */\n"
"}\n"
"\n"
"/* --- Effet au survol des cellules --- */\n"
"QTableView::item:hover {\n"
"    background: rgba(0, 162, 232, 0.2); /* Bleu un peu plus marqu\303\251 */\n"
"}\n"
"\n"
"/* --- S\303\251lection d'une cellule --- */\n"
"QTableView::item:selected {\n"
"    background: rgba(0, 162, 232, 0.5); /* Bleu plus visible */\n"
"    color: black;\n"
"}\n"
"\n"
"/* --- En-t\303\252tes de colonnes -"
                        "-- */\n"
"QHeaderView::section {\n"
"    background-color: rgba(0, 162, 232, 0.6); /* Bleu plus profond */\n"
"    color: white;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"    font-size: 12pt;\n"
"    border-bottom: 2px solid rgba(255, 255, 255, 0.5);\n"
"}\n"
"\n"
"/* --- En-t\303\252tes des lignes --- */\n"
"/* --- En-t\303\252tes des lignes --- */\n"
"QHeaderView::section:vertical {\n"
"    background: rgba(0, 162, 232, 0.3);\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-right: 2px solid rgba(255, 255, 255, 0.5);\n"
"}"));
        tab_12 = new QWidget();
        tab_12->setObjectName("tab_12");
        tableViewP = new QTableView(tab_12);
        tableViewP->setObjectName("tableViewP");
        tableViewP->setGeometry(QRect(0, 50, 481, 311));
        ExporterPDF = new QPushButton(tab_12);
        ExporterPDF->setObjectName("ExporterPDF");
        ExporterPDF->setGeometry(QRect(0, 360, 141, 41));
        CombpBoxtrie_2 = new QComboBox(tab_12);
        CombpBoxtrie_2->addItem(QString());
        CombpBoxtrie_2->addItem(QString());
        CombpBoxtrie_2->addItem(QString());
        CombpBoxtrie_2->setObjectName("CombpBoxtrie_2");
        CombpBoxtrie_2->setGeometry(QRect(10, 10, 91, 31));
        TRIERPartenair = new QPushButton(tab_12);
        TRIERPartenair->setObjectName("TRIERPartenair");
        TRIERPartenair->setGeometry(QRect(342, 10, 111, 41));
        TabP->addTab(tab_12, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        chartContainer = new QWidget(tab_3);
        chartContainer->setObjectName("chartContainer");
        chartContainer->setGeometry(QRect(0, 0, 481, 401));
        AfficherStatistique = new QPushButton(chartContainer);
        AfficherStatistique->setObjectName("AfficherStatistique");
        AfficherStatistique->setGeometry(QRect(350, 350, 121, 41));
        TabP->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        Taper = new QLineEdit(tab_5);
        Taper->setObjectName("Taper");
        Taper->setGeometry(QRect(110, 50, 231, 41));
        RechercherPartenair = new QPushButton(tab_5);
        RechercherPartenair->setObjectName("RechercherPartenair");
        RechercherPartenair->setGeometry(QRect(360, 50, 121, 41));
        tableViewPartenair = new QTableView(tab_5);
        tableViewPartenair->setObjectName("tableViewPartenair");
        tableViewPartenair->setGeometry(QRect(15, 111, 441, 261));
        CombpBoxRecherche = new QComboBox(tab_5);
        CombpBoxRecherche->addItem(QString());
        CombpBoxRecherche->addItem(QString());
        CombpBoxRecherche->addItem(QString());
        CombpBoxRecherche->setObjectName("CombpBoxRecherche");
        CombpBoxRecherche->setGeometry(QRect(5, 55, 91, 31));
        TabP->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        phoneLineEdit = new QLineEdit(tab_6);
        phoneLineEdit->setObjectName("phoneLineEdit");
        phoneLineEdit->setGeometry(QRect(220, 71, 171, 31));
        label_21 = new QLabel(tab_6);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(70, 71, 151, 31));
        sendButton = new QPushButton(tab_6);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(280, 260, 111, 41));
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
        messageTextEdit = new QTextEdit(tab_6);
        messageTextEdit->setObjectName("messageTextEdit");
        messageTextEdit->setGeometry(QRect(50, 100, 371, 151));
        TabP->addTab(tab_6, QString());
        tab_17 = new QWidget();
        tab_17->setObjectName("tab_17");
        mail_3 = new QLineEdit(tab_17);
        mail_3->setObjectName("mail_3");
        mail_3->setGeometry(QRect(130, 50, 231, 41));
        label_22 = new QLabel(tab_17);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(40, 100, 81, 41));
        envoyer = new QPushButton(tab_17);
        envoyer->setObjectName("envoyer");
        envoyer->setGeometry(QRect(330, 330, 141, 51));
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
        label_23 = new QLabel(tab_17);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(40, 50, 81, 41));
        objet = new QLineEdit(tab_17);
        objet->setObjectName("objet");
        objet->setGeometry(QRect(130, 100, 231, 41));
        corps = new QTextEdit(tab_17);
        corps->setObjectName("corps");
        corps->setGeometry(QRect(43, 150, 321, 161));
        urgent = new QRadioButton(tab_17);
        urgent->setObjectName("urgent");
        urgent->setGeometry(QRect(390, 60, 31, 24));
        TabP->addTab(tab_17, QString());
        stackedWidget->addWidget(page4_PARTENAIRES);
        page5_RENDEZVOUS = new QWidget();
        page5_RENDEZVOUS->setObjectName("page5_RENDEZVOUS");
        label_10 = new QLabel(page5_RENDEZVOUS);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(0, -140, 911, 1051));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/back.png")));
        label_11 = new QLabel(page5_RENDEZVOUS);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(670, 30, 201, 41));
        TabRV = new QTabWidget(page5_RENDEZVOUS);
        TabRV->setObjectName("TabRV");
        TabRV->setGeometry(QRect(190, 270, 491, 441));
        TabRV->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral du QTabWidget */\n"
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
        tab_34 = new QWidget();
        tab_34->setObjectName("tab_34");
        tableView2RV_7 = new QTableView(tab_34);
        tableView2RV_7->setObjectName("tableView2RV_7");
        tableView2RV_7->setGeometry(QRect(0, 60, 491, 301));
        rechercheRV_7 = new QLineEdit(tab_34);
        rechercheRV_7->setObjectName("rechercheRV_7");
        rechercheRV_7->setGeometry(QRect(10, 20, 261, 28));
        rechercheRV_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        chercherRV_7 = new QPushButton(tab_34);
        chercherRV_7->setObjectName("chercherRV_7");
        chercherRV_7->setGeometry(QRect(270, 10, 101, 41));
        afficherRV_7 = new QPushButton(tab_34);
        afficherRV_7->setObjectName("afficherRV_7");
        afficherRV_7->setGeometry(QRect(10, 360, 101, 41));
        exporterRV_7 = new QPushButton(tab_34);
        exporterRV_7->setObjectName("exporterRV_7");
        exporterRV_7->setGeometry(QRect(370, 360, 111, 41));
        comboBoxTriRV_7 = new QComboBox(tab_34);
        comboBoxTriRV_7->addItem(QString());
        comboBoxTriRV_7->addItem(QString());
        comboBoxTriRV_7->setObjectName("comboBoxTriRV_7");
        comboBoxTriRV_7->setGeometry(QRect(380, 20, 101, 28));
        TabRV->addTab(tab_34, QString());
        tab_36 = new QWidget();
        tab_36->setObjectName("tab_36");
        graphicsViewCal_RV_7 = new QGraphicsView(tab_36);
        graphicsViewCal_RV_7->setObjectName("graphicsViewCal_RV_7");
        graphicsViewCal_RV_7->setGeometry(QRect(10, 10, 461, 371));
        pushButtonMoisPrecedent_RV_7 = new QPushButton(tab_36);
        pushButtonMoisPrecedent_RV_7->setObjectName("pushButtonMoisPrecedent_RV_7");
        pushButtonMoisPrecedent_RV_7->setGeometry(QRect(30, 20, 83, 41));
        pushButtonMoisSuivant_RV_7 = new QPushButton(tab_36);
        pushButtonMoisSuivant_RV_7->setObjectName("pushButtonMoisSuivant_RV_7");
        pushButtonMoisSuivant_RV_7->setGeometry(QRect(360, 20, 83, 41));
        TabRV->addTab(tab_36, QString());
        stackedWidget->addWidget(page5_RENDEZVOUS);
        page6_RESSOURCES = new QWidget();
        page6_RESSOURCES->setObjectName("page6_RESSOURCES");
        label_12 = new QLabel(page6_RESSOURCES);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, -140, 911, 1061));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/back.png")));
        label_18 = new QLabel(page6_RESSOURCES);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(670, 29, 211, 51));
        tab_ressource = new QTabWidget(page6_RESSOURCES);
        tab_ressource->setObjectName("tab_ressource");
        tab_ressource->setGeometry(QRect(100, 60, 701, 561));
        tab_ressource->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral du QTabWidget */\n"
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
        AfficherRessources_10 = new QWidget();
        AfficherRessources_10->setObjectName("AfficherRessources_10");
        tableRessource_10 = new QTableView(AfficherRessources_10);
        tableRessource_10->setObjectName("tableRessource_10");
        tableRessource_10->setGeometry(QRect(-15, 90, 711, 301));
        tableRessource_10->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral pour le tableau */\n"
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
        ListeRessource_10 = new QWidget(AfficherRessources_10);
        ListeRessource_10->setObjectName("ListeRessource_10");
        ListeRessource_10->setGeometry(QRect(0, 0, 641, 401));
        chercherRESSOURCE_10 = new QLineEdit(ListeRessource_10);
        chercherRESSOURCE_10->setObjectName("chercherRESSOURCE_10");
        chercherRESSOURCE_10->setGeometry(QRect(20, 50, 331, 41));
        CherRessourceNom_10 = new QPushButton(ListeRessource_10);
        CherRessourceNom_10->setObjectName("CherRessourceNom_10");
        CherRessourceNom_10->setGeometry(QRect(365, 50, 111, 41));
        trie_ressource_10 = new QComboBox(ListeRessource_10);
        trie_ressource_10->setObjectName("trie_ressource_10");
        trie_ressource_10->setGeometry(QRect(150, 10, 171, 31));
        trie_ressource_10->setStyleSheet(QString::fromUtf8("QLineEdit, QDateEdit, QComboBox {\n"
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
        CherRessourceNom_7 = new QPushButton(ListeRessource_10);
        CherRessourceNom_7->setObjectName("CherRessourceNom_7");
        CherRessourceNom_7->setGeometry(QRect(320, 10, 281, 41));
        tab_ressource->addTab(AfficherRessources_10, QString());
        stackedWidget->addWidget(page6_RESSOURCES);
        page2_CLIENTS = new QWidget();
        page2_CLIENTS->setObjectName("page2_CLIENTS");
        label_6 = new QLabel(page2_CLIENTS);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, -10, 911, 801));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/back.png")));
        label_13 = new QLabel(page2_CLIENTS);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(670, 30, 151, 20));
        TabC = new QTabWidget(page2_CLIENTS);
        TabC->setObjectName("TabC");
        TabC->setGeometry(QRect(190, 280, 491, 441));
        TabC->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral du QTabWidget */\n"
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
"} \n"
"/* --- Style g\303\251n\303\251ral de la table --- */\n"
"QTableView {\n"
"    background: transparent;\n"
"    border: 2px solid rgba(255, 255, 255, 0.3);\n"
"    border-radius: 10px;\n"
"    color: white;\n"
"    gridline-color: rgba(255, 255, 255, 0.2);\n"
"    selection-background-color: rgba(0, 162, 232, 0.3); /* Bleu translucide */\n"
"    selection-color: white;\n"
"    font-weight: bold;  /* Contenu en gras */\n"
"}\n"
"\n"
"/* --- Style des cellules --- */\n"
"QTableView::item {\n"
"    background: rgba(0, 162, 232, 0.1); /* Bleu tr\303\250s l\303\251ger */\n"
"    border: none;\n"
"    padding: 5px;\n"
"    font-weight: bold; /* Gras */\n"
"}\n"
"\n"
"/* --- Effet au survol des cellules --- */\n"
"QTableView::item:hover {\n"
"    background: rgba(0, 162, 232, 0.2); /* Bleu un peu plus marqu\303\251 */\n"
"}\n"
"\n"
"/* --- S\303\251lection d'une cellule --- */\n"
"QTableView::item:selected {\n"
"    background: rgba(0, 162, 232, 0.5); /* Bleu plus visible */\n"
"    color: "
                        "black;\n"
"}\n"
"\n"
"/* --- En-t\303\252tes de colonnes --- */\n"
"QHeaderView::section {\n"
"    background-color: rgba(0, 162, 232, 0.6); /* Bleu plus profond */\n"
"    color: white;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"    font-size: 12pt;\n"
"    border-bottom: 2px solid rgba(255, 255, 255, 0.5);\n"
"}\n"
"\n"
"/* --- En-t\303\252tes des lignes --- */\n"
"/* --- En-t\303\252tes des lignes --- */\n"
"QHeaderView::section:vertical {\n"
"    background: rgba(0, 162, 232, 0.3);\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-right: 2px solid rgba(255, 255, 255, 0.5);\n"
"}\n"
"/* Style pour QTextEdit */\n"
"QTextEdit {\n"
"    font-size: 14px; /* Taille de police */\n"
"    color: #333333; /* Texte gris fonc\303\251 */\n"
"    background-color: rgba(240, 248, 255, 0.8); /* Fond bleu clair avec transparence */\n"
"    border: 2px solid #007acc; /* Bordure bleue */\n"
"    border-radius: 6px; /* Coins arrondis */\n"
"    padding: 8px; /* Espacement int\303\251"
                        "rieur */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Police moderne */\n"
"    font-weight: normal; /* Texte normal */\n"
"}\n"
"\n"
"/* Effet focus pour QTextEdit */\n"
"QTextEdit:focus {\n"
"    border: 2px solid #005fa3; /* Bordure plus fonc\303\251e lors du focus */\n"
"    background-color: rgba(224, 248, 255, 0.8); /* Fond bleu clair un peu plus marqu\303\251 lors du focus */\n"
"}\n"
"\n"
"/* Effet hover pour QTextEdit */\n"
"QTextEdit:hover {\n"
"    background-color: rgba(224, 248, 255, 0.9); /* Fond bleu clair un peu plus marqu\303\251 au survol */\n"
"}\n"
""));
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        tableViewC = new QTableView(tab_8);
        tableViewC->setObjectName("tableViewC");
        tableViewC->setGeometry(QRect(10, 60, 471, 291));
        pushButtonTrier_C = new QPushButton(tab_8);
        pushButtonTrier_C->setObjectName("pushButtonTrier_C");
        pushButtonTrier_C->setGeometry(QRect(310, 350, 171, 51));
        comboBoxTri = new QComboBox(tab_8);
        comboBoxTri->addItem(QString());
        comboBoxTri->addItem(QString());
        comboBoxTri->addItem(QString());
        comboBoxTri->setObjectName("comboBoxTri");
        comboBoxTri->setGeometry(QRect(0, 10, 101, 26));
        Exporter_PDF = new QPushButton(tab_8);
        Exporter_PDF->setObjectName("Exporter_PDF");
        Exporter_PDF->setGeometry(QRect(20, 350, 171, 51));
        lineEditRecherche = new QLineEdit(tab_8);
        lineEditRecherche->setObjectName("lineEditRecherche");
        lineEditRecherche->setGeometry(QRect(110, 0, 231, 41));
        chercher = new QPushButton(tab_8);
        chercher->setObjectName("chercher");
        chercher->setGeometry(QRect(350, 0, 121, 41));
        TabC->addTab(tab_8, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        widgetC = new QWidget(tab);
        widgetC->setObjectName("widgetC");
        widgetC->setGeometry(QRect(19, 19, 451, 331));
        TabC->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        RATINGS = new QTableWidget(tab_4);
        RATINGS->setObjectName("RATINGS");
        RATINGS->setGeometry(QRect(10, 71, 461, 311));
        TabC->addTab(tab_4, QString());
        stackedWidget->addWidget(page2_CLIENTS);
        frame->raise();
        rechercher->raise();
        label->raise();
        stackedWidget->raise();
        deconnexionButton->raise();

        retranslateUi(justemp);

        stackedWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);
        TabP->setCurrentIndex(4);
        TabRV->setCurrentIndex(0);
        tab_ressource->setCurrentIndex(0);
        TabC->setCurrentIndex(0);


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
        label_9->setText(QCoreApplication::translate("justemp", "Yasmine jbeli PARTENAIRE", nullptr));
        ExporterPDF->setText(QCoreApplication::translate("justemp", "Exprter Pdf", nullptr));
        CombpBoxtrie_2->setItemText(0, QCoreApplication::translate("justemp", "ID", nullptr));
        CombpBoxtrie_2->setItemText(1, QCoreApplication::translate("justemp", "adresse", nullptr));
        CombpBoxtrie_2->setItemText(2, QCoreApplication::translate("justemp", "Specialite", nullptr));

        TRIERPartenair->setText(QCoreApplication::translate("justemp", "Trier", nullptr));
        TabP->setTabText(TabP->indexOf(tab_12), QCoreApplication::translate("justemp", "lister", nullptr));
        AfficherStatistique->setText(QCoreApplication::translate("justemp", "aficherStat", nullptr));
        TabP->setTabText(TabP->indexOf(tab_3), QCoreApplication::translate("justemp", "statique", nullptr));
        RechercherPartenair->setText(QCoreApplication::translate("justemp", "Rechercher", nullptr));
        CombpBoxRecherche->setItemText(0, QCoreApplication::translate("justemp", "ID", nullptr));
        CombpBoxRecherche->setItemText(1, QCoreApplication::translate("justemp", "Specialite", nullptr));
        CombpBoxRecherche->setItemText(2, QCoreApplication::translate("justemp", "Email", nullptr));

        TabP->setTabText(TabP->indexOf(tab_5), QCoreApplication::translate("justemp", "Recherche", nullptr));
        label_21->setText(QCoreApplication::translate("justemp", "Entrer le num\303\251ro", nullptr));
        sendButton->setText(QCoreApplication::translate("justemp", "send", nullptr));
        TabP->setTabText(TabP->indexOf(tab_6), QCoreApplication::translate("justemp", "SMS", nullptr));
        label_22->setText(QCoreApplication::translate("justemp", "objet", nullptr));
        envoyer->setText(QCoreApplication::translate("justemp", "envoyer", nullptr));
        label_23->setText(QCoreApplication::translate("justemp", "mail", nullptr));
        urgent->setText(QString());
        TabP->setTabText(TabP->indexOf(tab_17), QCoreApplication::translate("justemp", "Mailing", nullptr));
        label_10->setText(QString());
        label_11->setText(QCoreApplication::translate("justemp", "BARAA Mensi RENDEZ-VOUS", nullptr));
        rechercheRV_7->setText(QString());
        rechercheRV_7->setPlaceholderText(QCoreApplication::translate("justemp", "Chercher un rendezvous", nullptr));
        chercherRV_7->setText(QCoreApplication::translate("justemp", "Chercher", nullptr));
        afficherRV_7->setText(QCoreApplication::translate("justemp", "Afficher", nullptr));
        exporterRV_7->setText(QCoreApplication::translate("justemp", "Exporter", nullptr));
        comboBoxTriRV_7->setItemText(0, QCoreApplication::translate("justemp", "Tri par date croissante", nullptr));
        comboBoxTriRV_7->setItemText(1, QCoreApplication::translate("justemp", "Tri par date d\303\251croissante", nullptr));

        comboBoxTriRV_7->setPlaceholderText(QCoreApplication::translate("justemp", "Date", nullptr));
        TabRV->setTabText(TabRV->indexOf(tab_34), QCoreApplication::translate("justemp", "lister", nullptr));
        pushButtonMoisPrecedent_RV_7->setText(QCoreApplication::translate("justemp", "<", nullptr));
        pushButtonMoisSuivant_RV_7->setText(QCoreApplication::translate("justemp", ">", nullptr));
        TabRV->setTabText(TabRV->indexOf(tab_36), QCoreApplication::translate("justemp", "calendrier", nullptr));
        label_12->setText(QString());
        label_18->setText(QCoreApplication::translate("justemp", "YOSR MOUSSA ressources", nullptr));
        CherRessourceNom_10->setText(QCoreApplication::translate("justemp", "Chercher", nullptr));
        CherRessourceNom_7->setText(QCoreApplication::translate("justemp", "Gerer cette liste dans un fichier PDF", nullptr));
        tab_ressource->setTabText(tab_ressource->indexOf(AfficherRessources_10), QCoreApplication::translate("justemp", "lister", nullptr));
        label_6->setText(QString());
        label_13->setText(QCoreApplication::translate("justemp", "Aziz Akrout CLIENTS", nullptr));
        pushButtonTrier_C->setText(QCoreApplication::translate("justemp", "Trier la liste ", nullptr));
        comboBoxTri->setItemText(0, QCoreApplication::translate("justemp", "Date d'inscription", nullptr));
        comboBoxTri->setItemText(1, QCoreApplication::translate("justemp", "Pr\303\251nom", nullptr));
        comboBoxTri->setItemText(2, QCoreApplication::translate("justemp", "Nom", nullptr));

        Exporter_PDF->setText(QCoreApplication::translate("justemp", "Exporter PDF", nullptr));
        chercher->setText(QCoreApplication::translate("justemp", "chercher", nullptr));
        TabC->setTabText(TabC->indexOf(tab_8), QCoreApplication::translate("justemp", "lister", nullptr));
        TabC->setTabText(TabC->indexOf(tab), QCoreApplication::translate("justemp", "statistique", nullptr));
        TabC->setTabText(TabC->indexOf(tab_4), QCoreApplication::translate("justemp", "Lister feedback", nullptr));
    } // retranslateUi

};

namespace Ui {
    class justemp: public Ui_justemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUSTEMP_H

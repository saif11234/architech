#include "Clients.h"
#include "qsqlerror.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>
#include <QObject>
#include <QRegularExpression>
#include <QVector>
#include <QPainter>
#include <QDate>
#include <QPdfWriter>
#include <QChartView>
#include <QGraphicsView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QBarCategoryAxis>

#include <QtCharts/QLegend>
// Constructeur par défaut
Clients::Clients(){}
Clients::Clients(int Cin_Client, QString Nom, QString Prenom, QString mail, QString adresse, float Paiments, QString Telephone, QString ModeP, QDate Date) {
    this->Cin_Client = Cin_Client;
    this->Nom = Nom;
    this->Prenom = Prenom;
    this->Mail = mail;
    this->Adresse = adresse;
    this->Paiments = Paiments;
    this->Telephone = Telephone;
    this->ModeP = ModeP;
    this->Date = Date;
}
Clients::Clients(int Cin_Client, QString Nom, QString Prenom, QString mail, QString adresse,  QString Telephone) {
    this->Cin_Client = Cin_Client;
    this->Nom = Nom;
    this->Prenom = Prenom;
    this->Mail = mail;
    this->Adresse = adresse;

    this->Telephone = Telephone;

}


// Getters
int Clients::getCinClient() {
    return Cin_Client;
}

QString Clients::getNom() {
    return Nom;
}

QString Clients::getPrenom() {
    return Prenom;
}

QString Clients::getMail() {
    return Mail;
}

QString Clients::getAdresse() {
    return Adresse;
}

QString Clients::getTelephone() {
    return Telephone;
}

float Clients::getPaiments() {
    return Paiments;
}
QString Clients::getModeP() {
    return ModeP;
}

QDate Clients::getDate() {
    return Date;
}

// Setters
void Clients::setCinClient(int cinClient) {
    this->Cin_Client = cinClient;
}

void Clients::setNom(QString nom) {
    this->Nom = nom;
}

void Clients::setPrenom(QString prenom) {
    this->Prenom = prenom;
}

void Clients::setMail(QString mail) {
    this->Mail = mail;
}

void Clients::setAdresse(QString adresse) {
    this->Adresse = adresse;
}

void Clients::setTelephone(QString telephone) {
    this->Telephone = telephone;
}

void Clients::setPaiments(float paiments) {
    this->Paiments = paiments;
}
// Nouveaux setters
void Clients::setModeP(QString modeP) {
    this->ModeP = modeP;
}

void Clients::setDate(QDate date) {
    this->Date = date;
}


float Clients:: calculerPrixAvecInteret(float prixInitial) {
    return prixInitial * 1.20; // Ajoute 20% au prix initial
}

float  Clients:: diviserParSix(float nombre) {
    return nombre / 6.0;
}
bool Clients::AjouterClients() {
    QSqlQuery query;

    // Préparation de la requête SQL sans les colonnes supprimées
    query.prepare("INSERT INTO CLIENT (CIN_CLIENT, NOM, PRENOM, ADRESSE, TELEPHONE, MAIL) "
                  "VALUES (:CIN_CLIENT, :NOM, :PRENOM, :ADRESSE, :TELEPHONE, :MAIL)");

    // Liaison des valeurs aux paramètres
    query.bindValue(":CIN_CLIENT", Cin_Client);
    query.bindValue(":NOM", Nom);
    query.bindValue(":PRENOM", Prenom);
    query.bindValue(":ADRESSE", Adresse);
    query.bindValue(":TELEPHONE", Telephone);
    query.bindValue(":MAIL", Mail);

    // Vérification des champs obligatoires
    if (Cin_Client == 0 || Nom.isEmpty() || Prenom.isEmpty() || Adresse.isEmpty() || Telephone.isEmpty() || Mail.isEmpty()) {
        qDebug() << "Invalid input data. Please make sure all fields are filled correctly.";
        return false;
    }

    // Exécution de la requête
    bool success = query.exec();

    // Vérification de l'exécution
    if (success) {
        qDebug() << "Client ajouté avec succès !";
    } else {
        qDebug() << "Erreur lors de l'ajout du client : " << query.lastError().text();
    }

    return success;
}
QSqlQueryModel* Clients::afficherC() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ARCHITECH.CLIENT");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin_Client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date INS"));

    return model;
}

bool Clients::modifierC(int oldCin) {
    QSqlQuery query;

    // Préparation de la requête SQL sécurisée (sans la colonne supprimée)
    query.prepare("UPDATE CLIENT SET "
                  "CIN_CLIENT = :cin, "
                  "NOM = :nom, "
                  "PRENOM = :prenom, "
                  "MAIL = :mail, "
                  "ADRESSE = :adresse, "
                  "TELEPHONE = :telephone "
                  "WHERE CIN_CLIENT = :old_cin");

    // Liaison des valeurs
    query.bindValue(":cin", Cin_Client);
    query.bindValue(":nom", Nom);
    query.bindValue(":prenom", Prenom);
    query.bindValue(":mail", Mail);
    query.bindValue(":adresse", Adresse);
    query.bindValue(":telephone", Telephone);
    query.bindValue(":old_cin", oldCin);

    // Exécution de la requête
    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        qDebug() << "Requête :" << query.lastQuery();
        return false;
    }
}

bool Clients::SupprimerClients(int id) {
    QSqlQuery query;


    query.prepare("SELECT 1 FROM CLIENT WHERE Cin_Client = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(nullptr, "Erreur", "Le CIN que vous avez saisi n'existe pas !");
        return false;
    }

    // Supprimer l'ID s'il existe
    query.prepare("DELETE FROM CLIENT WHERE Cin_Client = :id");
    query.bindValue(":id", id);

    return query.exec();
}
bool Clients::exporterPDF(const QString& fileName) {
    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize::A4);
    writer.setTitle("Liste des Clients");
    writer.setCreator("Smart Architect");

    QPainter painter(&writer);

    // Marges & layout
    int topMargin = 200;
    int leftMargin = 250;
    int rightMargin = writer.width() - 250;
    int contentWidth = rightMargin - leftMargin;
    int y = topMargin;

    QVector<int> colWidths = {600, 1000, 1000, 1500, 1000, 1500, 1500};  // Ajouter une colonne pour la date
    QStringList headers = {"CIN", "Nom", "Prénom", "Adresse", "Téléphone", "Mail", "Date d'inscription"};  // Ajouter la date dans l'en-tête
    int rowHeight = 500;

    // === LOGO en haut à droite ===
    QPixmap logo(":/logo.jpg");
    if (!logo.isNull()) {
        QPixmap scaledLogo = logo.scaledToHeight(900, Qt::SmoothTransformation);
        int logoX = rightMargin - scaledLogo.width();
        painter.drawPixmap(logoX, y, scaledLogo);
    }

    // === En-tête de page ===
    painter.setFont(QFont("Helvetica", 22, QFont::Bold));
    painter.setPen(QColor("#003366")); // Bleu foncé
    painter.drawText(leftMargin, y + 200, "Smart Architect");

    painter.setFont(QFont("Helvetica", 12));
    painter.setPen(Qt::darkGray);
    painter.drawText(leftMargin, y + 500, "📋 Liste des Clients");
    painter.drawText(leftMargin, y + 800, "🗓️ Exporté le : " + QDate::currentDate().toString("dd MMMM yyyy"));

    y += 1100;

    // === En-tête du tableau ===
    painter.setFont(QFont("Helvetica", 11, QFont::Bold));
    painter.setPen(Qt::black);
    painter.setBrush(QColor("#d9e1f2")); // bleu clair élégant
    painter.drawRect(leftMargin, y, contentWidth, rowHeight);

    int x = leftMargin;
    for (int i = 0; i < headers.size(); ++i) {
        painter.setPen(Qt::black);
        painter.drawRect(x, y, colWidths[i], rowHeight);
        painter.drawText(QRect(x, y, colWidths[i], rowHeight),
                         Qt::AlignCenter, headers[i]);
        x += colWidths[i] + 10;
    }

    y += rowHeight;

    // === Données du tableau ===
    QSqlQuery query("SELECT CIN_CLIENT, NOM, PRENOM, ADRESSE, TELEPHONE, MAIL, DATE_INSCRIPTION FROM CLIENT");
    painter.setFont(QFont("Helvetica", 10));
    int rowCount = 0;

    while (query.next()) {
        x = leftMargin;

        QColor bgColor = (rowCount % 2 == 0) ? QColor("#ffffff") : QColor("#f2f2f2"); // alternance
        painter.fillRect(leftMargin, y, contentWidth, rowHeight, bgColor);

        for (int i = 0; i < headers.size(); ++i) {
            painter.setPen(QColor("#cccccc")); // bordure grise douce
            painter.drawRect(x, y, colWidths[i], rowHeight);
            painter.setPen(Qt::black);

            if (i == 6) { // Si c'est la colonne "Date d'inscription", formate-la
                painter.drawText(QRect(x + 10, y, colWidths[i] - 20, rowHeight),
                                 Qt::AlignVCenter | Qt::AlignLeft,
                                 query.value(i).toDate().toString("dd MMMM yyyy"));  // Formate la date
            } else {
                painter.drawText(QRect(x + 10, y, colWidths[i] - 20, rowHeight),
                                 Qt::AlignVCenter | Qt::AlignLeft,
                                 query.value(i).toString());
            }

            x += colWidths[i] + 10;
        }

        y += rowHeight;
        rowCount++;
    }

    // === Pied de page ===
    painter.setPen(Qt::darkGray);
    painter.setFont(QFont("Helvetica", 9));
    painter.drawText(leftMargin, writer.height() - 200, "Smart Architect - Tous droits réservés © " + QDate::currentDate().toString("yyyy"));

    painter.end();
    return true;
}



QSqlQueryModel* Clients::afficherTrie(const QString &column)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // Liste des colonnes valides pour le tri
    QStringList validColumns = {"DATE_INSCRIPTION", "PRENOM", "NOM"};

    // Vérifier si la colonne est valide, sinon utiliser une valeur par défaut
    QString validColumn = validColumns.contains(column, Qt::CaseInsensitive) ? column : "DATE_INSCRIPTION";

    QString queryString;

    if (validColumn == "DATE_INSCRIPTION") {
        // Tri par date d'inscription (ordre chronologique)
        queryString = "SELECT CIN_CLIENT, NOM, PRENOM, MAIL, ADRESSE, TELEPHONE, DATE_INSCRIPTION "
                      "FROM ARCHITECH.CLIENT "
                      "ORDER BY DATE_INSCRIPTION ASC, LOWER(PRENOM), LOWER(NOM)";
    } else if (validColumn == "PRENOM") {
        // Tri par prénom (insensible à la casse)
        queryString = "SELECT CIN_CLIENT, NOM, PRENOM, MAIL, ADRESSE, TELEPHONE, DATE_INSCRIPTION "
                      "FROM ARCHITECH.CLIENT "
                      "ORDER BY LOWER(PRENOM), LOWER(NOM), DATE_INSCRIPTION ASC";
    } else if (validColumn == "NOM") {
        // Tri par nom (insensible à la casse)
        queryString = "SELECT CIN_CLIENT, NOM, PRENOM, MAIL, ADRESSE, TELEPHONE, DATE_INSCRIPTION "
                      "FROM ARCHITECH.CLIENT "
                      "ORDER BY LOWER(NOM), LOWER(PRENOM), DATE_INSCRIPTION ASC";
    }

    model->setQuery(queryString);

    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin_Client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date d'inscription"));

    // Vérifier les erreurs éventuelles
    if (model->lastError().isValid()) {
        qWarning() << "Erreur dans la requête de tri:" << model->lastError().text();
    }

    return model;
}

QSqlQueryModel* Clients::RECHERCHER(const QString &criteria, const QString &value)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Construction de la requête SQL en fonction du critère
    QString queryString;
    if (criteria == "CIN_CLIENT" || criteria == "NOM" || criteria == "PRENOM" || criteria == "MAIL" || criteria == "ADRESSE" || criteria == "TELEPHONE") {
        queryString = QString("SELECT CIN_CLIENT, NOM, PRENOM, MAIL, ADRESSE, TELEPHONE, DATE_INSCRIPTION "
                              "FROM ARCHITECH.CLIENT "
                              "WHERE LOWER(%1) LIKE :value "
                              "ORDER BY DATE_INSCRIPTION DESC, LOWER(PRENOM), LOWER(NOM)")
                          .arg(criteria);
    } else {
        // Si le critère n'est pas valide, on retourne un modèle vide
        return nullptr;
    }

    // Préparation de la requête
    query.prepare(queryString);
    query.bindValue(":value", "%" + value.toLower() + "%");

    // Exécution de la requête
    if (!query.exec()) {
        qWarning() << "Erreur dans la requête de recherche:" << query.lastError().text();
        return nullptr;
    }

    // Association des résultats au modèle
    model->setQuery(query);

    // Vérification des erreurs éventuelles
    if (model->lastError().isValid()) {
        qWarning() << "Erreur dans le modèle de requête:" << model->lastError().text();
        return nullptr;
    }

    return model;
}




QChartView* Clients::stat_paiement() {
    int payeCount = 0;
    int parFaciliteCount = 0;

    QSqlQuery query;
    // Compter les projets avec le mode de paiement 'Payé'
    query.prepare("SELECT COUNT(*) FROM PROJETS WHERE MODE_PAIEMENT = 'Payé'");
    if (query.exec() && query.next())
        payeCount = query.value(0).toInt();

    // Compter les projets avec le mode de paiement 'Par facilité'
    query.prepare("SELECT COUNT(*) FROM PROJETS WHERE MODE_PAIEMENT = 'Par facilité'");
    if (query.exec() && query.next())
        parFaciliteCount = query.value(0).toInt();

    // Création du jeu de barres avec les données
    QBarSet *set = new QBarSet("Nombre de Projets");
    *set << payeCount << parFaciliteCount;

    QBarSeries *series = new QBarSeries();
    series->append(set);

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des Méthodes de Paiement des Projets");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Définition des catégories pour l'axe X
    QStringList categories;
    categories << "Comptant" << "Par facilité";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Configuration de l'axe Y
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre de Projets");
    axisY->setRange(0, qMax(payeCount, parFaciliteCount) + 5);
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Personnalisation de la légende
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Création de la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}


bool Clients::ClientsExists(int cinClient)
{
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT CIN_CLIENT FROM CLIENT WHERE CIN_CLIENT = :cinClient");
    checkQuery.bindValue(":cinClient", cinClient);

    if (!checkQuery.exec())
    {
        qDebug() << "Erreur lors de la vérification du client:" << checkQuery.lastError().text();
        return false;
    }

    return checkQuery.next();
}


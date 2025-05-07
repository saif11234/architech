#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>
#include <QObject>
#include "rendezvous.h"
#include <QSqlError>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QMessageBox>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QResizeEvent>
#include <QtCharts/QBarCategoryAxis>
#include <QVariant>
#include <QDate>


//CONSTRUCT
RendezVous::RendezVous(){}
RendezVous::RendezVous(int id, int cin_employe, int cin_client, QString lieu, QString dt, QString statut)
{
    this->id=id;
    this->cin_employe=cin_employe;
    this->cin_client=cin_client;
    this->lieu=lieu;
    this->dt=dt;
    this->statut=statut;
}

//CRUD
bool RendezVous::AjouterRendezVous()
{
    // Convertir la date de type QString en QDate avec le format attendu "dd/MM/yyyy"
    QDate dateRendezVous = QDate::fromString(dt, "dd/MM/yyyy");

    if (!dateRendezVous.isValid()) {
        qWarning() << "La date fournie est invalide!";
        return false;  // Retourner false si la date n'est pas valide
    }

    // Vérifier si la date est déjà occupée
    if (estDateOccupee(dateRendezVous)) {
        // Si la date est déjà occupée, chercher une date libre
        QDate dateLibre = trouverJourLibre(dateRendezVous);
        dateRendezVous = dateLibre;  // Mettre à jour la date avec la première date libre trouvée
    }

    // Préparer la requête SQL pour insérer le rendez-vous
    QSqlQuery query;
    query.prepare("INSERT INTO RENDEZ_VOUS (ID_RENDEZVOUS, CIN_EMPLOYE, CIN_CLIENT, LIEU, DT, STATUT) "
                  "VALUES (:id, :cin_employe, :cin_client, :lieu, :dt, :statut)");

    query.bindValue(":id", id);  // L'ID manuellement passé
    query.bindValue(":cin_employe", cin_employe);
    query.bindValue(":cin_client", cin_client);
    query.bindValue(":lieu", lieu);
    query.bindValue(":dt", dateRendezVous.toString("dd/MM/yyyy"));  // Utiliser le format dd/MM/yyyy pour l'affichage et l'insertion
    query.bindValue(":statut", statut);

    // Exécuter la requête
    if (query.exec()) {
        qDebug() << "Rendez-vous ajouté avec succès.";
        return true;
    } else {
        qWarning() << "Erreur lors de l'ajout du rendez-vous : " << query.lastError();
        return false;
    }
}


bool RendezVous::ModifierRendezVous() {
    QSqlQuery query;
    QDate dateRendezVous = QDate::fromString(dt, "dd/MM/yyyy");

    if (!dateRendezVous.isValid()) {
        qWarning() << "La date fournie est invalide!";
        return false;  // Retourner false si la date n'est pas valide
    }

    // Vérifier si la date est déjà occupée
    if (estDateOccupee(dateRendezVous)) {
        // Si la date est déjà occupée, chercher une date libre
        QDate dateLibre = trouverJourLibre(dateRendezVous);
        dateRendezVous = dateLibre;  // Mettre à jour la date avec la première date libre trouvée
    }

    // Préparation de la requête SQL sécurisée
    query.prepare("UPDATE RENDEZ_VOUS SET "
                  "CIN_EMPLOYE = :cin_employe, "
                  "CIN_CLIENT = :cin_client, "
                  "LIEU = :lieu, "
                  "DT = :dt, "
                  "STATUT = :statut "
                  "WHERE ID_RENDEZVOUS = :id");

    // Liaison des valeurs
    query.bindValue(":id", id);
    query.bindValue(":cin_employe", cin_employe);
    query.bindValue(":cin_client", cin_client);
    query.bindValue(":lieu", lieu);
    query.bindValue(":dt", dateRendezVous.toString("dd/MM/yyyy"));  // Utiliser le format dd/MM/yyyy pour l'affichage et l'insertion
    query.bindValue(":statut", statut);

    // Exécution de la requête
    if (query.exec()) {
        return true;  // La requête a réussi
    } else {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        qDebug() << "Requête :" << query.lastQuery();
        return false;  // La requête a échoué
    }
    return query.exec();
}

bool RendezVous::SupprimerRendezVous(int id)
{
    QSqlQuery query;

    query.prepare("SELECT 1 FROM RENDEZ_VOUS WHERE ID_RENDEZVOUS = :id");
    query.bindValue(":id", id);

    if(!query.exec() || !query.next())
    {
        QMessageBox::warning(nullptr,"Erreur","Le RendezVous que vous avez saisi n'existe pas");
        return false;
    }

    // Préparer la requête SQL pour supprimer un rendez-vous par ID
    query.prepare("DELETE FROM RENDEZ_VOUS WHERE ID_RENDEZVOUS = :id");
    query.bindValue(":id", id);

    // Exécuter la requête et retourner le résultat
    if (query.exec()) {
        qDebug() << "Rendez-vous supprimé avec succès !";
        return true;
    } else {
        qDebug() << "Erreur lors de la suppression: " << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* RendezVous::AfficherRendezVous() {


    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_RENDEZVOUS, CIN_EMPLOYE, CIN_CLIENT, LIEU, DT, STATUT FROM RENDEZ_VOUS");


    // Définir les en-têtes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RENDEZVOUS"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN_EMPLOYE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN_CLIENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("STATUT"));

    return model;
}

void RendezVous::rechercher(QTableView *tableView, QString &texteRecherche)
{
    QAbstractItemModel *model = tableView->model();  // Obtenir le modèle du QTableView
    int lignes = model->rowCount();  // Nombre de lignes
    bool found;

    qDebug() << "Nombre de lignes dans le modèle: " << lignes;

    for (int i = 0; i < lignes; ++i) {
        found = false;
        for (int j = 0; j < model->columnCount(); ++j) {
            // Récupérer les données de chaque cellule
            QString text = model->index(i, j).data().toString();
            qDebug() << "Vérification de la cellule (" << i << "," << j << "): " << text;

            if (text.contains(texteRecherche, Qt::CaseInsensitive)) {
                found = true;
                break;
            }
        }

        // Cacher ou afficher la ligne en fonction de la recherche
        tableView->setRowHidden(i, !found);
    }
}

void RendezVous::exporter(QTableView* tableView)
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Enregistrer sous CSV", QString(), "CSV (*.csv)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Erreur", "Impossible d'ouvrir le fichier pour l'écriture.");
        return;
    }

    QTextStream out(&file);

    const int rowCount = tableView->model()->rowCount();
    const int columnCount = tableView->model()->columnCount();

    // Écrire les en-têtes
    for (int column = 0; column < columnCount; ++column) {
        if (!tableView->isColumnHidden(column)) {
            out << "\"" << tableView->model()->headerData(column, Qt::Horizontal).toString() << "\",";
        }
    }
    out << "\n";

    // Écrire les données des lignes
    for (int row = 0; row < rowCount; ++row) {
        for (int column = 0; column < columnCount; ++column) {
            if (!tableView->isColumnHidden(column)) {
                QString data = tableView->model()->data(tableView->model()->index(row, column)).toString().simplified();
                out << "\"" << data << "\",";
            }
        }
        out << "\n";
    }

    file.close();
    QMessageBox::information(nullptr, "Succès", "Le fichier CSV a été enregistré avec succès.");
}

void RendezVous::trierParId(QTableView* tableView)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_RENDEZVOUS, CIN_EMPLOYE, CIN_CLIENT, LIEU, DT, STATUT FROM RENDEZ_VOUS ORDER BY ID_RENDEZVOUS");

    tableView->setModel(model);
}

void RendezVous::trierParDate(QTableView* tableView, bool croissant)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString ordre = croissant ? "ASC" : "DESC";

    model->setQuery("SELECT ID_RENDEZVOUS, CIN_EMPLOYE, CIN_CLIENT, LIEU, DT, STATUT "
                    "FROM RENDEZ_VOUS ORDER BY TO_DATE(DT, 'dd/MM/yyyy') " + ordre);

    tableView->setModel(model);
}


void RendezVous::afficherStatistiques()
{
    // Créer la fenêtre de statistiques
    QDialog *statDialog = new QDialog();
    statDialog->setWindowTitle("Statistiques des Rendez-vous");

    // Initialiser les compteurs
    int prevus = 0, confirms = 0, annules = 0, total = 0;

    // Récupérer les données depuis la base de données
    QSqlQuery query("SELECT STATUT FROM RENDEZ_VOUS");
    while (query.next()) {
        QString statut = query.value(0).toString();
        if (statut == "Prévu") prevus++;
        else if (statut == "Confirmé") confirms++;
        else if (statut == "Annulé") annules++;
        total++;
    }

    if (total == 0) {
        QMessageBox::warning(nullptr, "Aucune donnée", "Aucun rendez-vous trouvé.");
        return;
    }

    // Convertir en pourcentage
    float prevusPercentage = (float)prevus / total * 100;
    float confirmsPercentage = (float)confirms / total * 100;
    float annulesPercentage = (float)annules / total * 100;

    QBarSeries *series = new QBarSeries();

    QBarSet *setStatut = new QBarSet("Statut");
    *setStatut << prevusPercentage << confirmsPercentage << annulesPercentage;

    series->append(setStatut);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des Rendez-vous (%)");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories = {"Prévu", "Confirmé", "Annulé"};
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 100); // Plage de 0 à 100%
    axisY->setTitleText("Pourcentage (%)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);

    QPushButton *closeButton = new QPushButton("Fermer");
    layout->addWidget(closeButton);
    QObject::connect(closeButton, &QPushButton::clicked, statDialog, &QDialog::accept);


    statDialog->setLayout(layout);
    statDialog->resize(600, 400);
    statDialog->exec();
}

int RendezVous::compterRendezVousDuJour()
{
    QSqlQuery query;

    query.prepare("SELECT COUNT(*) "
                  "FROM RENDEZ_VOUS "
                  "WHERE TO_DATE(DT, 'DD/MM/YYYY') = TO_DATE(:currentDate, 'DD/MM/YYYY')");

    QString currentDate = QDate::currentDate().toString("dd/MM/yyyy");

    query.bindValue(":currentDate", currentDate);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();  // Return the count of rendezvous for today
    } else {
        qDebug() << "Error executing query: " << query.lastError().text();
        return 0;  // Return 0 if there was an error
    }
}

QMap<QDate, int> RendezVous::recupererNombreRendezVousParDate()
{
    QMap<QDate, int> rdvMap;
    QSqlQuery query("SELECT DT FROM RENDEZ_VOUS");

    while (query.next()) {
        QString dateStr = query.value(0).toString();
        QDate date = QDate::fromString(dateStr, "dd/MM/yyyy");
        if (date.isValid()) {
            rdvMap[date]++;
        }
    }

    return rdvMap;
}

bool RendezVous::estDateOccupee(const QDate& date) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM RENDEZ_VOUS WHERE DT = :date");
    query.bindValue(":date", date.toString("dd/MM/yyyy"));
    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0; // Si il y a un rendez-vous pour cette date
    }
    return false;
}

QDate RendezVous::trouverJourLibre(QDate dateDepart) {
    for (int i = 0; i < 31; ++i) { // Parcours les 31 jours d'un mois
        QDate candidateDate = dateDepart.addDays(i);
        if (!estDateOccupee(candidateDate)) {
            return candidateDate; // Retourner la première date libre
        }
    }
    return dateDepart; // Si pas de jour libre (dans le cas extrême où tout est occupé)
}





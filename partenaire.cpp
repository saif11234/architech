#include "Partenaire.h"
#include "qsqlerror.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>
#include <QObject>
#include <QSqlError>
//#include <QMap>
#include <QPainter>
#include <QDate>
#include <QPdfWriter>
#include <QDate>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include "xlsxdocument.h"
using namespace QXlsx;

// Constructeur par défaut
Partenaire::Partenaire() {}

Partenaire::Partenaire(int id_partenaire, QString nom, QString specialite, QString adresse, QString telephone, QString email, QString contrat)
{
    this->id_partenaire = id_partenaire;
    this->nom = nom;
    this->specialite = specialite;
    this->email = email;
    this->telephone = telephone;
    this->adresse = adresse;
    this->contrat = contrat;
}

// Getters
int Partenaire::getIdPartenaire() { return id_partenaire; }
QString Partenaire::getNom() { return nom; }
QString Partenaire::getSpecialite() { return specialite; }
QString Partenaire::getEmail() { return email; }
QString Partenaire::getTelephone() { return telephone; }
QString Partenaire::getAdresse() { return adresse; }
QString Partenaire::getContrat() { return contrat; }

// Setters
void Partenaire::setIdPartenaire(int idPartenaire) { this->id_partenaire = idPartenaire; }
void Partenaire::setNom(QString nom) { this->nom = nom; }
void Partenaire::setSpecialite(QString specialite) { this->specialite = specialite; }
void Partenaire::setEmail(QString email) { this->email = email; }
void Partenaire::setTelephone(QString telephone) { this->telephone = telephone; }
void Partenaire::setAdresse(QString adresse) { this->adresse = adresse; }
void Partenaire::setContrat(QString contrat) { this->contrat = contrat; }

// Ajouter un partenaire
bool Partenaire::AjouterPartenaire() {
    QSqlQuery query;
    query.prepare("INSERT INTO PARTENAIRE (ID_PARTENAIR, NOM, SPECIALITE,ADRESSE, TELEPHONE, EMAIL, CONTRAT) "
                  "VALUES (:ID_PARTENAIRE, :NOM, :SPECIALITE, :ADRESSE, :TELEPHONE, :EMAIL, :CONTRAT)");
    query.bindValue(":ID_PARTENAIRE", id_partenaire);
    query.bindValue(":NOM", nom);
    query.bindValue(":SPECIALITE", specialite);
    query.bindValue(":EMAIL", email);
    query.bindValue(":TELEPHONE", telephone);
    query.bindValue(":ADRESSE", adresse);
    query.bindValue(":CONTRAT", contrat);

    return query.exec();
}

// Afficher les partenaires
QSqlQueryModel* Partenaire::afficherP() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM PARTENAIRE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PARTENAIR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SPECIALITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TELEPHONE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("CONTRAT"));
    return model;
}
bool Partenaire::modifierP(int oldIdPartenaire) {
    QSqlQuery query;

    // Préparation de la requête SQL sécurisée
    query.prepare("UPDATE PARTENAIRE SET "
                  "ID_PARTENAIR = :id_partenaire, "
                  "NOM = :nom, "
                  "SPECIALITE = :specialite, "
                  "ADRESSE = :adresse, "

                  "TELEPHONE = :telephone, "
                  "EMAIL = :email, "
                  "CONTRAT = :contrat "
                  "WHERE ID_PARTENAIR = :old_id_partenaire");  // Ancienne valeur pour la mise à jour



    // Liaison des valeurs
    query.bindValue(":id_partenaire", id_partenaire);  // Nouveau ID_PARTENAIR
    query.bindValue(":nom", nom);
    query.bindValue(":specialite", specialite);
    query.bindValue(":adresse", adresse);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":contrat", contrat);
    query.bindValue(":old_id_partenaire", oldIdPartenaire);  // Ancien ID pour le WHERE

    // 🔹 2️⃣ Affichage de la requête SQL avant exécution
    qDebug() << "📝 Requête préparée :" << query.lastQuery();

    // Exécution de la requête
    if (query.exec()) {
        qDebug() << "✅ Requête exécutée avec succès.";
        return true;
    } else {
        qDebug() << "❌ Erreur SQL :" << query.lastError().text();
        qDebug() << "📝 Requête exécutée :" << query.lastQuery();
        return false;
    }
}

bool Partenaire::SupprimerPartenaire(int id) {
    QSqlQuery query;
    QString res = QString::number(id);

    // Vérifier si l'ID existe dans la base
    query.prepare("SELECT COUNT(*) FROM PARTENAIRE WHERE ID_PARTENAIR = :id");
    query.bindValue(":id", res);
    if (!query.exec()) {
        qDebug() << "❌ Erreur lors de la vérification de l'ID :" << query.lastError().text();
        return false;
    }

    // Récupérer le résultat de la requête
    if (query.next() && query.value(0).toInt() == 0) {
        qDebug() << "⚠️ L'ID que vous voulez supprimer n'existe pas !";
        return false;
    }

    // L'ID existe, on peut le supprimer
    query.prepare("DELETE FROM PARTENAIRE WHERE ID_PARTENAIR = :id");
    query.bindValue(":id", res);

    if (query.exec()) {
        qDebug() << "✅ Partenaire supprimé avec succès !";
        return true;
    } else {
        qDebug() << "❌ Erreur lors de la suppression :" << query.lastError().text();
        return false;
    }
}



/*QMap<QString, int> Partenaire::obtenirStatistiquesPartenaire() {
    QMap<QString, int> stats;
    QSqlQuery query;

    if (query.exec("SELECT specialite, COUNT(*) FROM PARTENAIRE GROUP BY specialite")) {
        while (query.next()) {
            QString specialite = query.value(0).toString();
            int count = query.value(1).toInt();
            stats[specialite] = count;
        }
    } else {
        qDebug() << "Erreur SQL : " << query.lastError().text();
    }

    return stats;
}*/

QSqlQueryModel* Partenaire::RECHERCHER(const QString &criteria, const QString &value) {
    QSqlQueryModel* model = new QSqlQueryModel();

    // Choix de la requête en fonction du critère de recherche
    QString queryString;

    // Recherche exacte pour ID_PARTENAIR et SPECIALITE, sinon LIKE pour une recherche partielle
    if (criteria == "ID_PARTENAIR" || criteria == "SPECIALITE") {
        // Ici, on utilise QString::arg pour insérer le critère dans la requête
        queryString = QString("SELECT * FROM PARTENAIRE WHERE %1 = :value").arg(criteria);
    } if (criteria == "EMAIL") {
        queryString = "SELECT * FROM PARTENAIRE WHERE LOWER(EMAIL) = LOWER(:value)";
    } else {
        queryString = QString("SELECT * FROM PARTENAIRE WHERE %1 LIKE :value").arg(criteria);
    }

    // Préparation de la requête
    QSqlQuery query;
    query.prepare(queryString);

    // Associer la valeur liée : exacte ou partielle selon le critère
    if (criteria == "ID_PARTENAIR" || criteria == "SPECIALITE" || criteria == "EMAIL") {
        query.bindValue(":value", value); // Recherche exacte
    } else {
        // **Changement** : Pour les autres critères (recherche partielle), on lie la valeur avec des symboles "%" autour de la valeur
        // Cela permet de faire une recherche avec LIKE (partielle) sur les autres colonnes
        query.bindValue(":value", "%" + value + "%"); // Recherche partielle
    }

    // Affichage des détails pour le débogage
    qDebug() << "Requête SQL préparée : " << queryString;
    qDebug() << "Valeur liée pour la recherche : " << (criteria == "ID_PARTENAIR" || criteria == "SPECIALITE" || criteria == "EMAIL" ? value : "%" + value + "%");

    // Exécution de la requête
    if (!query.exec()) {
        qDebug() << "Erreur dans la requête de recherche:" << query.lastError().text();
        return nullptr; // retourne un modèle nul en cas d'erreur
    }

    // Associer les résultats au modèle
    model->setQuery(query);

    // Vérifier les erreurs dans l'exécution de la requête
    if (model->lastError().isValid()) {
        qDebug() << "Erreur dans la requête de recherche:" << model->lastError().text();
        return nullptr;
    }

    return model;
}


/*bool Partenaire::exporterPDF(const QString& fileName) {
    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize::A4);
    writer.setTitle("Liste des Partenaires");
    writer.setCreator("Smart Architect");

    QPainter painter(&writer);
    int y = 1200;
    int lineSpacing = 400;
    int leftMargin = 200;
    int rightMargin = writer.width() - 200;

    // En-tête de page
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.drawText(leftMargin, 400, "Smart Architect");
    painter.setFont(QFont("Arial", 12));
    painter.drawText(leftMargin, 600, "Liste des Partenaires");

    // Ligne de séparation
    painter.drawLine(leftMargin, 700, rightMargin, 700);
    painter.drawText(leftMargin, 900, "Date d'export : " + QDate::currentDate().toString("dd/MM/yyyy"));

    // Titres des colonnes
    painter.setFont(QFont("Arial", 8, QFont::Bold));
    painter.setBrush(Qt::lightGray);
    painter.drawRect(leftMargin, 1000, rightMargin - leftMargin, 400);

    painter.drawText(leftMargin + 100, 1300, "Nom");
    painter.drawText(leftMargin + 1000, 1300, "Specialite");
    painter.drawText(leftMargin + 2000, 1300, "Adresse");
    painter.drawText(leftMargin + 3500, 1300, "Telephone");
    painter.drawText(leftMargin + 4500, 1300, "Email");
    painter.drawText(leftMargin + 5500, 1300, "Contrat");

    painter.drawLine(leftMargin, 1350, rightMargin, 1350);
    y = 1600;


    QSqlQuery query;
    query.prepare("SELECT NOM, SPECIALITE, ADRESSE, TELEPHONE, EMAIL, CONTRAT FROM PARTENAIRE");

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de l'export PDF:" << query.lastError().text();
        return false;
    }


    painter.setFont(QFont("Arial", 8));
    while (query.next()) {
        painter.drawText(leftMargin + 100, y, query.value("NOM").toString());
        painter.drawText(leftMargin + 1000, y, query.value("SPECIALITE").toString());
        painter.drawText(leftMargin + 2000, y, query.value("ADRESSE").toString());
        painter.drawText(leftMargin + 3500, y, query.value("TELEPHONE").toString());
        painter.drawText(leftMargin + 4500, y, query.value("EMAIL").toString());
        painter.drawText(leftMargin + 5500, y, query.value("CONTRAT").toString());

        painter.drawLine(leftMargin, y + 100, rightMargin, y + 100);
        y += lineSpacing;
    }

    // Pied de page
    painter.drawLine(leftMargin, writer.height() - 200, rightMargin, writer.height() - 200);
    painter.drawText(leftMargin, writer.height() - 100, "Page 1");

    painter.end();
    return true;
}*/
//*******************************************Excel*****************


bool Partenaire::exporterExcel(const QString& fileName) {
    Document xlsx;

    // En-tête
    xlsx.write("A1", "Smart Architect");
    xlsx.write("A2", "Liste des Partenaires");
    xlsx.write("A3", "Date d'export : " + QDate::currentDate().toString("dd/MM/yyyy"));

    // Titres des colonnes
    xlsx.write("A5", "Nom");
    xlsx.write("B5", "Spécialité");
    xlsx.write("C5", "Adresse");
    xlsx.write("D5", "Téléphone");
    xlsx.write("E5", "Email");
    xlsx.write("F5", "Contrat");

    // Requête SQL
    QSqlQuery query;
    query.prepare("SELECT NOM, SPECIALITE, ADRESSE, TELEPHONE, EMAIL, CONTRAT FROM PARTENAIRE");

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de l'export Excel:" << query.lastError().text();
        return false;
    }

    // Remplir les données
    int row = 6;
    while (query.next()) {
        xlsx.write(row, 1, query.value("NOM").toString());
        xlsx.write(row, 2, query.value("SPECIALITE").toString());
        xlsx.write(row, 3, query.value("ADRESSE").toString());
        xlsx.write(row, 4, query.value("TELEPHONE").toString());
        xlsx.write(row, 5, query.value("EMAIL").toString());
        xlsx.write(row, 6, query.value("CONTRAT").toString());
        row++;
    }

    // Sauvegarder le fichier
    return xlsx.saveAs(fileName);
}


//************************************************************************
// Vérifier si un partenaire existe
/*bool Partenaire::PartenaireExists(int idPartenaire) {
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT ID_PARTENAIRE FROM PARTENAIRE WHERE ID_PARTENAIRE = :idPartenaire");
    checkQuery.bindValue(":idPartenaire", idPartenaire);
    if (!checkQuery.exec()) {
        qDebug() << "Erreur lors de la vérification du partenaire:" << checkQuery.lastError().text();
        return false;
    }
    return checkQuery.next();
}*/

/*void Partenaire::genererStatistiques(QWidget *chartContainer) {
    QSqlQuery query("SELECT SPECIALITE, COUNT(*) FROM PARTENAIRE GROUP BY SPECIALITE");
    QPieSeries *series = new QPieSeries();

    while (query.next()) {
        series->append(query.value(0).toString(), query.value(1).toInt());
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des partenaires par spécialité");
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(chartContainer);  // Affecter le graphique au conteneur

    chartView->resize(chartContainer->size());  // Ajuster la taille au conteneur
    chartView->show();
}*/
//*******************************************************************************************************

void Partenaire::genererStatistiques(QWidget *chartContainer) {
    QSqlQuery query("SELECT SPECIALITE, COUNT(*) FROM PARTENAIRE GROUP BY SPECIALITE");
    QPieSeries *series = new QPieSeries();

    int total = 0;
    QList<QPair<QString, int>> data;

    // Collecter les données et calculer le total
    while (query.next()) {
        QString specialite = query.value(0).toString();
        int count = query.value(1).toInt();
        total += count;
        data.append(qMakePair(specialite, count));
    }

    // Palette de couleurs personnalisées
    QList<QColor> colors = {
        QColor("#FF6B6B"),  // rouge doux
        QColor("#4ECDC4"),  // vert menthe
        QColor("#FFD93D"),  // jaune vif
        QColor("#1A535C"),  // bleu foncé
        QColor("#FF9F1C"),  // orange vif
        QColor("#2EC4B6"),  // turquoise
        QColor("#9E0059")   // violet profond
    };

    int colorIndex = 0;
    for (const auto &entry : data) {
        QString specialite = entry.first;
        int count = entry.second;
        qreal percentage = (double)count / total * 100;
        QPieSlice *slice = series->append(
            specialite + QString(" (%1%)").arg(QString::number(percentage, 'f', 1)),
            count
            );
        slice->setLabelVisible(true);
        slice->setPen(QPen(Qt::white, 2)); // contour blanc
        slice->setBrush(colors[colorIndex % colors.size()]); // couleur personnalisée
        colorIndex++;
    }

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("🎓 Répartition des partenaires par spécialité");
    chart->setTitleFont(QFont("Arial", 14, QFont::Bold));
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setFont(QFont("Arial", 10));
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setBackgroundBrush(Qt::white); // fond blanc
    chart->setBackgroundVisible(true);

    // Création de la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(chartContainer);
    chartView->resize(chartContainer->size());
    chartView->show();
}


//********************************************************************************************************
//urg

QString Partenaire::getNomPartenaire(const QString &email)
{
    QSqlQuery query;
    query.prepare("SELECT NOM FROM PARTENAIRE WHERE EMAIL = :email");
    query.bindValue(":email", email);

    if (query.exec() && query.next()) {
        return query.value(0).toString();
    } else {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        return "Partenaire inconnu";  // Nom par défaut si pas trouvé
    }
}
//*****************tri*************************************
QSqlQueryModel* Partenaire::AFFICHER_SORTED(const QString &column)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // Définir les noms de colonnes valides pour le tri
    QStringList validColumns = {"ID_PARTENAIR", "ADRESSE", "SPECIALITE"};

    // Vérifier si la colonne est valide, sinon utiliser une valeur par défaut
    QString validColumn;
    if (validColumns.contains(column)) {
        validColumn = column;
    } else {
        validColumn = "ID_PARTENAIR"; // Colonne par défaut en cas de colonne non valide
    }

    // Préparer et exécuter la requête avec la colonne validée
    QString queryString = QString("SELECT * FROM PARTENAIRE ORDER BY %1").arg(validColumn);

    // Associer la requête au modèle
    model->setQuery(queryString);

    // Vérifier les erreurs dans l'exécution de la requête
    if (model->lastError().isValid()) {
        qWarning() << "Erreur dans la requête de tri:" << model->lastError().text();
    }

    return model;
}

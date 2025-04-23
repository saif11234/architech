#include "projet.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QObject>
#include <QVariant>
#include <QList>
#include <QPainter>


Projet::Projet() {}
Projet::Projet(int id_projet, QString nom_projet, QString description, float budget, QString date_debut, QString date_fin, int cin_client,QString etat_projet,
               float latitude, float longitude)
{
    this->id_projet = id_projet;
    this->nom_projet = nom_projet;
    this->description = description;
    this->budget = budget;
    this->date_debut = date_debut;
    this->date_fin = date_fin;
    this->cin_client = cin_client;
    this->etat_projet = etat_projet;
    this->latitude = latitude;
    this->longitude = longitude;
}


bool Projet::ajouterProjet()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PROJET (ID_PROJET, NOM_PROJET, DESCRIPTION, BUDGET, DATE_DEBUT, DATE_FIN, CIN_CLIENT,ETAT_PROJET,LATITUDE,LONGITUDE) "
                  "VALUES (:id_projet, :nom_projet, :description, :budget, :date_debut, :date_fin, :cin_client, :etat_projet,:latitude,:longitude)");

    query.bindValue(":id_projet", id_projet);
    query.bindValue(":nom_projet", nom_projet);
    query.bindValue(":description", description);
    query.bindValue(":budget", budget);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);
    query.bindValue(":cin_client", cin_client);
    query.bindValue(":etat_projet", etat_projet);
    query.bindValue(":latitude", latitude);
    query.bindValue(":longitude", longitude);
    return query.exec();
}


bool Projet::modifierProjet()
{
    QSqlQuery query;
    query.prepare("UPDATE PROJET SET "
                  "NOM_PROJET = :nom_projet, "
                  "DESCRIPTION = :description, "
                  "BUDGET = :budget, "
                  "DATE_DEBUT = :date_debut, "
                  "DATE_FIN = :date_fin, "
                  "CIN_CLIENT = :cin_client, "
                  "ETAT_PROJET = :etat_projet, "
                  "LATITUDE = :latitude, "
                  "LONGITUDE = :longitude "
                  "WHERE ID_PROJET = :id_projet");

    query.bindValue(":id_projet", id_projet);
    query.bindValue(":nom_projet", nom_projet);
    query.bindValue(":description", description);
    query.bindValue(":budget", budget);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);
    query.bindValue(":cin_client", cin_client);
    query.bindValue(":etat_projet", etat_projet);
    query.bindValue(":latitude", latitude);
    query.bindValue(":longitude", longitude);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur SQL : " << query.lastError().text();
        return false;
    }
}


bool Projet::supprimerProjet(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM PROJET WHERE ID_PROJET = :id_projet");
    query.bindValue(":id_projet", id);

    if (query.exec()) {
        qDebug() << "Projet supprimé avec succès !";
        return true;
    } else {
        qDebug() << "Erreur lors de la suppression : " << query.lastError().text();
        return false;
    }
}


QSqlQueryModel *Projet::afficherProjets()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, BUDGET, DATE_DEBUT, DATE_FIN, CIN_CLIENT, ETAT_PROJET,LATITUDE,LONGITUDE FROM PROJET");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PROJET"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_FIN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN_CLIENT"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("ETAT_PROJET"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("LATITUDE"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("LONGITUDE"));
    return model;
}
QSqlQueryModel *Projet::rechercherProjetsParNom(const QString &prefixe)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, BUDGET, DATE_DEBUT, DATE_FIN, CIN_CLIENT, ETAT_PROJET,LATITUDE,LONGITUDE "
                  "FROM PROJET WHERE NOM_PROJET LIKE :prefixe || '%'");
    query.bindValue(":prefixe", prefixe);
    query.exec();
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PROJET"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_FIN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN_CLIENT"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("ETAT_PROJET"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("LATITUDE"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("LONGITUDE"));

    return model;
}
QMap<QString, int> Projet::getStatistiquesEtat()
{
    QMap<QString, int> statistiques;
    QSqlQuery query;
    query.prepare("SELECT ETAT_PROJET, COUNT(*) AS nombre FROM Projet GROUP BY ETAT_PROJET");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        return statistiques;
    }

    while (query.next()) {
        QString etat = query.value("ETAT_PROJET").toString();
        int nombre = query.value("nombre").toInt();
        statistiques.insert(etat, nombre);
    }

    return statistiques;
}

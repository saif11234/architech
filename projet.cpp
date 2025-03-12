#include "projet.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QObject>

// Constructeurs
Projet::Projet() {}
Projet::Projet(int id_projet, QString nom_projet, QString description, float budget, QString date_debut, QString date_fin, int cin_client)
{
    this->id_projet = id_projet;
    this->nom_projet = nom_projet;
    this->description = description;
    this->budget = budget;
    this->date_debut = date_debut;
    this->date_fin = date_fin;
    this->cin_client = cin_client;
}

// Ajouter un projet
bool Projet::ajouterProjet()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PROJET (ID_PROJET, NOM_PROJET, DESCRIPTION, BUDGET, DATE_DEBUT, DATE_FIN, CIN_CLIENT) "
                  "VALUES (:id_projet, :nom_projet, :description, :budget, :date_debut, :date_fin, :cin_client)");

    query.bindValue(":id_projet", id_projet);
    query.bindValue(":nom_projet", nom_projet);
    query.bindValue(":description", description);
    query.bindValue(":budget", budget);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);
    query.bindValue(":cin_client", cin_client);

    return query.exec();
}

// Modifier un projet
bool Projet::modifierProjet()
{
    QSqlQuery query;
    query.prepare("UPDATE PROJET SET "
                  "NOM_PROJET = :nom_projet, "
                  "DESCRIPTION = :description, "
                  "BUDGET = :budget, "
                  "DATE_DEBUT = :date_debut, "
                  "DATE_FIN = :date_fin, "
                  "CIN_CLIENT = :cin_client "
                  "WHERE ID_PROJET = :id_projet");

    query.bindValue(":id_projet", id_projet);
    query.bindValue(":nom_projet", nom_projet);
    query.bindValue(":description", description);
    query.bindValue(":budget", budget);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);
    query.bindValue(":cin_client", cin_client);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur SQL : " << query.lastError().text();
        return false;
    }
}

// Supprimer un projet
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

// Afficher les projets
QSqlQueryModel *Projet::afficherProjets()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, BUDGET, DATE_DEBUT, DATE_FIN, CIN_CLIENT FROM PROJET");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PROJET"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_FIN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN_CLIENT"));

    return model;
}

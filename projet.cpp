#include "projet.h"
#include <QDebug>
#include <QSqlError>

// Constructeur
Projet::Projet(int id, QString nom, QString etat, QString desc, float budget, QDate debut, QDate fin) {
    this->id_projet = id;
    this->nom_projet = nom;
    this->etat_projet = etat;
    this->description = desc;
    this->budget = budget;
    this->date_debut = debut;
    this->date_fin = fin;
}

// Ajouter un projet
bool Projet::ajouter() {

    QSqlQuery query;
    query.prepare("INSERT INTO projet (id_projet,nom_projet,etat_projet, description, budget, date_debut, date_fin) "
                  "VALUES (:id,:nom,:etat, :desc, :budget, :debut, :fin)");
    query.bindValue(":id", id_projet);
    query.bindValue(":nom", nom_projet);
    query.bindValue(":etat", etat_projet);
    query.bindValue(":desc", description);
    query.bindValue(":budget", budget);
    query.bindValue(":debut", date_debut.toString("yyyy-MM-dd"));
    query.bindValue(":fin", date_fin.toString("yyyy-MM-dd"));

    if (!query.exec()) {

        qDebug() << "Erreur SQL: " << query.lastError().text();
        return false;
    }
    return true;
}

// Modifier un projet
bool Projet::modifier(int id) {

    QSqlQuery query;
    query.prepare("UPDATE projet SET nom_projet = :nom,etat_projet=:etat, description = :desc, "
                  "budget = :budget, date_debut = :debut, date_fin = :fin WHERE id_projet = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom_projet);
    query.bindValue(":etat", etat_projet);
    query.bindValue(":desc", description);
    query.bindValue(":budget", budget);
    query.bindValue(":debut", date_debut.toString("yyyy-MM-dd"));
    query.bindValue(":fin", date_fin.toString("yyyy-MM-dd"));

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification du projet : " << query.lastError().text();
        return false;
    }
    return true;
}

// Supprimer un projet
bool Projet::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM projet WHERE id_projet = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression du projet : " << query.lastError().text();
        return false;
    }
    return true;
}

// Afficher les projets dans un QSqlQueryModel
QSqlQueryModel *Projet::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id_projet, nom_projet,etat_projet, description, budget, date_debut, date_fin FROM projet");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de la récupération des projets : " << model->lastError().text();
        return nullptr;
    }

    return model;
}

// Récupérer un projet par ID
Projet Projet::getProjetById(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM projet WHERE id_projet = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération du projet : " << query.lastError().text();
        return Projet();
    }

    if (query.next()) {
        return Projet(
            query.value("id_projet").toInt(),
            query.value("nom_projet").toString(),
            query.value("etat_projet").toString(),
            query.value("description").toString(),
            query.value("budget").toFloat(),
            query.value("date_debut").toDate(),
            query.value("date_fin").toDate()
            );
    }

    return Projet();
}

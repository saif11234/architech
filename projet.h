#ifndef PROJET_H
#define PROJET_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

class Projet
{
    int id_projet;
    QString nom_projet;
    QString description;
    float budget;
    QString date_debut;
    QString date_fin;
    int cin_client;

public:
    // Constructeurs
    Projet();
    Projet(int id_projet, QString nom_projet, QString description, float budget, QString date_debut, QString date_fin, int cin_client);

    // Getters
    int getIdProjet() const { return id_projet; };
    QString getNomProjet() const { return nom_projet; };
    QString getDescription() const { return description; };
    float getBudget() const { return budget; };
    QString getDateDebut() const { return date_debut; };
    QString getDateFin() const { return date_fin; };
    int getCinClient() const { return cin_client; };


    // Setters
    void setIdProjet(int newId) { id_projet = newId; };
    void setNomProjet(QString newNom) { nom_projet = newNom; };
    void setDescription(QString newDesc) { description = newDesc; };
    void setBudget(float newBudget) { budget = newBudget; };
    void setDateDebut(QString newDateDebut) { date_debut = newDateDebut; };
    void setDateFin(QString newDateFin) { date_fin = newDateFin; };
    void setCinClient(int newCin) { cin_client = newCin; };

    // CRUD
    bool ajouterProjet();
    bool modifierProjet();
    bool supprimerProjet(int);
    QSqlQueryModel *afficherProjets();
};

#endif // PROJET_H

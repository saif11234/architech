#ifndef PROJET_H
#define PROJET_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Projet {
    int id_projet;
    QString nom_projet;
    QString etat_projet;
    QString description;
    float budget;
    QDate date_debut;
    QDate date_fin;

public:
    Projet() {};
    Projet(int id, QString nom,QString etat, QString desc, float budget, QDate debut, QDate fin);

    int getId() const { return id_projet; }
    QString getNom() const { return nom_projet; }
    QString getEtat() const { return etat_projet; }
    QString getDescription() const { return description; }
    float getBudget() const { return budget; }
    QDate getDateDebut() const { return date_debut; }
    QDate getDateFin() const { return date_fin; }

    void setId(int id) { id_projet = id; }
    void setNom(const QString &nom) { nom_projet = nom; }
    void setEtat(const QString &etat) { etat_projet = etat; }
    void setDescription(const QString &desc) { description = desc; }
    void setBudget(float bud) { budget = bud; }
    void setDateDebut(const QDate &debut) { date_debut = debut; }
    void setDateFin(const QDate &fin) { date_fin = fin; }

    bool ajouter();
    bool modifier(int id);
    bool supprimer(int id);
    QSqlQueryModel *afficher();
    Projet getProjetById(int id);
};

#endif // PROJET_H

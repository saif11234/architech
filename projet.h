#ifndef PROJET_H
#define PROJET_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMap>
#include <QList>
#include <QVariant>
#include <QStandardItemModel>
#include <QPixmap>
#include <QPainter>

class Projet
{
    int id_projet;
    QString nom_projet;
    QString description;
    float budget;
    QString date_debut;
    QString date_fin;
    int cin_client;
    QString etat_projet;
    float latitude;
    float longitude;

public:

    Projet();
    Projet(int id_projet, QString nom_projet, QString description, float budget, QString date_debut, QString date_fin, int cin_client,QString etat_projet,
           float latitude, float longitude);


    int getIdProjet() const { return id_projet; };
    QString getNomProjet() const { return nom_projet; };
    QString getDescription() const { return description; };
    float getBudget() const { return budget; };
    QString getDateDebut() const { return date_debut; };
    QString getDateFin() const { return date_fin; };
    int getCinClient() const { return cin_client; };
    QString getEtat() const { return etat_projet; };
    float getLatitude() const { return latitude; }
    float getLongitude() const { return longitude; }




    void setIdProjet(int newId) { id_projet = newId; };
    void setNomProjet(QString newNom) { nom_projet = newNom; };
    void setDescription(QString newDesc) { description = newDesc; };
    void setBudget(float newBudget) { budget = newBudget; };
    void setDateDebut(QString newDateDebut) { date_debut = newDateDebut; };
    void setDateFin(QString newDateFin) { date_fin = newDateFin; };
    void setCinClient(int newCin) { cin_client = newCin; };
    void setEtat(QString newEtat) { etat_projet = newEtat; };
    void setLatitude(float lat) { latitude = lat; }
    void setLongitude(float lng) { longitude = lng; }

    bool ajouterProjet();
    bool modifierProjet();
    bool supprimerProjet(int);
    QSqlQueryModel *afficherProjets();
    QSqlQueryModel *rechercherProjetsParNom(const QString &prefixe);
    QMap<QString, int> getStatistiquesEtat();
};

#endif

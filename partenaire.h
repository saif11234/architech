#ifndef PARTENAIRE_H
#define PARTENAIRE_H

#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QMap>

class Partenaire
{
public:
    Partenaire();
    Partenaire(int id_partenaire, QString nom, QString specialite, QString email, QString telephone, QString adresse, QString contrat);

    int getIdPartenaire();
    QString getNom();
    QString getSpecialite();
    QString getEmail();
    QString getTelephone();
    QString getAdresse();
    QString getContrat();

    void setIdPartenaire(int idPartenaire);
    void setNom(QString nom);
    void setSpecialite(QString specialite);
    void setEmail(QString email);
    void setTelephone(QString telephone);
    void setAdresse(QString adresse);
    void setContrat(QString contrat);

    // Méthodes CRUD
    bool AjouterPartenaire();
    bool modifierP(int oldId);

    bool PartenaireExists(int idPartenaire);
    QSqlQueryModel * afficherP();
    bool SupprimerPartenaire(int id);
    //QMap<QString, int> obtenirStatistiquesPartenaire();
    QSqlQueryModel* RECHERCHER(const QString &criteria, const QString &value);
    QSqlQueryModel* AFFICHER_SORTED(const QString &column);
    //bool exporterPDF(const QString& fileName);
    bool exporterExcel(const QString& fileName);
    void genererStatistiques(QWidget *chartContainer);
    //fnl
    static QString getNomPartenaire(const QString &email);


private:
    int id_partenaire;
    QString nom;
    QString specialite;
    QString email;
    QString telephone;
    QString adresse;
    QString contrat;
};

#endif // PARTENAIRE_H



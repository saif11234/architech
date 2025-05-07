#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include <QString>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QTableView>


class RendezVous
{
    int id;
    int cin_employe;
    int cin_client;
    QString statut;
    QString lieu;
    QString dt;

public:
    // Constructeurs
    RendezVous();
    RendezVous(int id, int cin_employe, int cin_client, QString lieu, QString dt, QString statut);

    // Getters
    int getId() {return id;};
    int getCinEmploye() {return cin_employe;};
    int getCinClient() {return cin_client;};
    QString getLieu() {return lieu;};
    QString getDateTime() {return dt;};
    QString getStatut() {return statut;};

    // Setters
    void setId(int newid) {id = newid;};
    void setCinEmploye(int newcin_employe) {cin_employe = newcin_employe;};
    void setCinClient(int newcin_client) {cin_client = newcin_client;};
    void setLieu(QString newlieu) {lieu = newlieu;};
    void setDateTime(QString newdt) {dt = newdt;};
    void setStatut(QString newstatut) {statut = newstatut;};

    // CRUD
    bool AjouterRendezVous();
    bool ModifierRendezVous();
    QSqlQueryModel * AfficherRendezVous();
    bool SupprimerRendezVous(int);

    //METIER
    void rechercher(QTableView *tableView, QString &texteRecherche);  // Déclaration de la méthode rechercher
    void exporter(QTableView* tableView);
    void trierParId(QTableView* tableView);
    void trierParDate(QTableView* tableView, bool croissant);
    QSqlQueryModel* getStatistics();
    int getTotalRendezVous();
    void afficherStatistiques();
    int compterRendezVousDuJour();
    QMap<QDate, int> recupererNombreRendezVousParDate();
    bool estDateOccupee(const QDate& date);
    QDate trouverJourLibre(QDate dateDepart);



};

#endif // RENDEZVOUS_H

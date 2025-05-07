#ifndef CLIENTS_H
#define CLIENTS_H

#include <QString>
#include <QDate>

#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QChartView>
#include <QGraphicsView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QLegend>
class Clients
{
public:

    Clients();
    Clients(int Cin_Client, QString Nom, QString Prenom, QString mail, QString adresse,  QString Telephone);
    Clients(int Cin_Client,QString Nom, QString Prenom, QString mail, QString adresse,  float Paiments, QString Telephone,QString ModeP,QDate Date);


    int getCinClient() ;
    QString getNom() ;
    QString getPrenom() ;
    QString getMail() ;
    QString getAdresse() ;
    QString getTelephone() ;
    float getPaiments() ;
    QString getModeP();
    QDate getDate();

    void setCinClient(int cinClient);
    void setNom( QString nom);
    void setPrenom( QString prenom);
    void setMail( QString mail);
    void setAdresse( QString adresse);
    void setTelephone( QString Telephone);
    void setPaiments(float paiments);
    void setModeP(QString ModeP);
    void setDate(QDate Date);
    //mes methodes de CRUD
    float calculerPrixAvecInteret(float prixInitial) ;
    float diviserParSix(float nombre);
    //µµµ
    bool AjouterClients();
    bool modifierC(int oldCin);
    bool ClientsExists(int cinClient);
    QSqlQueryModel * afficherC();
    bool SupprimerClients(int);
    bool exporterPDF(const QString& fileName);
    QSqlQueryModel* afficherTrie(const QString &column);
    QChartView* stat_paiement();

    QSqlQueryModel* RECHERCHER(const QString &criteria, const QString &value);
private:
    int Cin_Client;
    QString Nom;
    QString Prenom;
    QString Mail;
    QString Adresse;
    QString Telephone;
    float Paiments;
    QString ModeP;
    QDate Date;
};

#endif // CLIENTS_H

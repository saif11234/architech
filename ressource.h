#ifndef RESSOURCE_H
#define RESSOURCE_H
#include<qstring>
#include <QDate>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMap>
#include <QList>
#include <QVariant>
#include <QStandardItemModel>
#include <QPixmap>
#include <QPainter>
#include "QrCode.h"
class Ressource
{
public:
    //Les constructeurs
     Ressource();
     Ressource(int id_ressource,QString typeRessource ,QString nomRessource ,QString etatRessource, QDate dateAcquisition);
      Ressource( int CINEmploye, int id_ressource,QString typeRessource ,QString nomRessource ,QString etatRessource, QDate dateAcquisition);
     Ressource(QString typeRessource ,QString nomRessource ,QString etatRessource, QDate dateAcquisition);

     // getters & Setters
    void setIdRessource(int id);
     void setIdEmploye(int id);
    void setType(QString t);
    void setNomRessource(QString n);
    void setEtat(QString etat);
    void setDateAcquisition(QDate date);
    int get_idRessource();
    QString get_Type();
    QString get_nomRessource();
    QString get_Etat();
    QDate get_DateAcquisition();
    int get_idEmploye();

    //Methode CRUD
    bool AjouterRessource();
    QSqlQueryModel * afficherRessource();
     QSqlQueryModel* recupererIDs();
     QSqlQueryModel* recupererIDsEmploye();
    bool SupprimerRessource(int);
    Ressource getRessourceById(int id);
    QSqlQueryModel * afficherRessourceEmplo(int cin);
    QStandardItemModel* chercherparCIN(const QString& nom, int cin);
    QStandardItemModel * trierRessourcesAvecQRCodeparCIN(int cin, const QString& colonne, bool croissant);
    QStandardItemModel* afficherRessourceAvecQRCodeparCIN(int cinEmploye);
    bool modifierRessource(Ressource& ressource);
    //Metiers
      static QStandardItemModel* trierRessourcesAvecQRCode(const QString& colonne, bool croissant);
      static QStandardItemModel* afficherRessourceAvecQRCode();
      static QPixmap generateQRCode(const QString& text, int size);
       static QPixmap generateQRCodeWithLogo(const QString &text, int size, const QString &logoPath);
    static  int compterRessourcesDisponibles(const QString &typeRessource);
    QMap<QString, int> getStatistiquesTypes();
    static  QStandardItemModel* chercher(const QString& nom);
    QString  generateRessourcesPDF();
   // QMap<QString, QMap<QString, int>> getStatistiquesCompletes();
private:
    int id_ressource;
    int CINEmploye;
    QString nomRessource ,typeRessource, etatRessource;
    QDate dateAcquisition;
};

#endif // RESSOURCE_H

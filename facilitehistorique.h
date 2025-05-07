#ifndef FACILITEHISTORIQUE_H
#define FACILITEHISTORIQUE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>
#include <QVariant>
class FaciliteHistorique
{
public:
    // Constructeurs
    FaciliteHistorique();
    FaciliteHistorique( int cin_client,int ID_P, QDate datel1, QDate datel2, QDate datel3,
                       QDate datel4, QDate datel5, QDate datel6,
                       float tranche1, float tranche2, float tranche3, float tranche4, float tranche5, float tranche6,
                       int box1, int box2, int box3, int box4, int box5, int box6);


    // Getters
    int getIdF() ;
    int getCinClient() ;
    int getID_P();
    QDate getDatel1() ;
    QDate getDatel2() ;
    QDate getDatel3() ;
    QDate getDatel4() ;
    QDate getDatel5() ;
    QDate getDatel6() ;
    float getTranche1() ;
    float getTranche2() ;
    float getTranche3() ;
    float getTranche4() ;
    float getTranche5() ;
    float getTranche6() ;
    bool getBox1() ;
    bool getBox2() ;
    bool getBox3() ;
    bool getBox4() ;
    bool getBox5() ;
    bool getBox6() ;

    // Setters
    void setIdF(int id_f);
    void setID_P(int id_f);
    void setCinClient(int cin_client);
    void setDatel1(QDate datel1);
    void setDatel2(QDate datel2);
    void setDatel3(QDate datel3);
    void setDatel4(QDate datel4);
    void setDatel5(QDate datel5);
    void setDatel6(QDate datel6);
    void setTranche1(float tranche1);
    void setTranche2(float tranche2);
    void setTranche3(float tranche3);
    void setTranche4(float tranche4);
    void setTranche5(float tranche5);
    void setTranche6(float tranche6);
    void setBox1(bool box1);
    void setBox2(bool box2);
    void setBox3(bool box3);
    void setBox4(bool box4);
    void setBox5(bool box5);
    void setBox6(bool box6);









    bool ajouterFacilite();
    bool HistoriqueFacilite(int cin);


private:
    int id_f;
    int cin_client;
    int ID_P;
    QDate datel1;
    QDate datel2;
    QDate datel3;
    QDate datel4;
    QDate datel5;
    QDate datel6;
    float tranche1;
    float tranche2;
    float tranche3;
    float tranche4;
    float tranche5;
    float tranche6;
    int  box1;
    int box2;
    int box3;
    int box4;
    int box5;
    int box6;
};

#endif // FACILITEHISTORIQUE_H

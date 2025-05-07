#include "facilitehistorique.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDate>
FaciliteHistorique::FaciliteHistorique() {

}

// Constructeur avec paramètres
FaciliteHistorique::FaciliteHistorique( int cin_client,int ID_P, QDate datel1, QDate datel2, QDate datel3,
                                       QDate datel4, QDate datel5, QDate datel6,
                                       float tranche1, float tranche2, float tranche3, float tranche4, float tranche5, float tranche6,
                                       int box1, int box2, int box3, int box4, int box5, int box6)
{

    this->cin_client = cin_client;
    this->ID_P=ID_P;
    this->datel1 = datel1;
    this->datel2 = datel2;
    this->datel3 = datel3;
    this->datel4 = datel4;
    this->datel5 = datel5;
    this->datel6 = datel6;
    this->tranche1 = tranche1;
    this->tranche2 = tranche2;
    this->tranche3 = tranche3;
    this->tranche4 = tranche4;
    this->tranche5 = tranche5;
    this->tranche6 = tranche6;
    this->box1 = box1;
    this->box2 = box2;
    this->box3 = box3;
    this->box4 = box4;
    this->box5 = box5;
    this->box6 = box6;
}

// Getters
int FaciliteHistorique::getIdF() {
    return id_f;
}
int FaciliteHistorique::getID_P() {
    return ID_P;
}

int FaciliteHistorique::getCinClient() {
    return cin_client;
}

QDate FaciliteHistorique::getDatel1() {
    return datel1;
}

QDate FaciliteHistorique::getDatel2() {
    return datel2;
}

QDate FaciliteHistorique::getDatel3() {
    return datel3;
}

QDate FaciliteHistorique::getDatel4() {
    return datel4;
}

QDate FaciliteHistorique::getDatel5() {
    return datel5;
}

QDate FaciliteHistorique::getDatel6() {
    return datel6;
}

float FaciliteHistorique::getTranche1() {
    return tranche1;
}

float FaciliteHistorique::getTranche2() {
    return tranche2;
}

float FaciliteHistorique::getTranche3() {
    return tranche3;
}

float FaciliteHistorique::getTranche4() {
    return tranche4;
}

float FaciliteHistorique::getTranche5() {
    return tranche5;
}

float FaciliteHistorique::getTranche6() {
    return tranche6;
}

bool FaciliteHistorique::getBox1() {
    return box1;
}

bool FaciliteHistorique::getBox2() {
    return box2;
}

bool FaciliteHistorique::getBox3() {
    return box3;
}

bool FaciliteHistorique::getBox4() {
    return box4;
}

bool FaciliteHistorique::getBox5() {
    return box5;
}

bool FaciliteHistorique::getBox6() {
    return box6;
}

// Setters
void FaciliteHistorique::setIdF(int id_f) {
    this->id_f = id_f;
}

void FaciliteHistorique::setID_P(int id_f) {
    this->ID_P = id_f;
}

void FaciliteHistorique::setCinClient(int cin_client) {
    this->cin_client = cin_client;
}

void FaciliteHistorique::setDatel1(QDate datel1) {
    this->datel1 = datel1;
}

void FaciliteHistorique::setDatel2(QDate datel2) {
    this->datel2 = datel2;
}

void FaciliteHistorique::setDatel3(QDate datel3) {
    this->datel3 = datel3;
}

void FaciliteHistorique::setDatel4(QDate datel4) {
    this->datel4 = datel4;
}

void FaciliteHistorique::setDatel5(QDate datel5) {
    this->datel5 = datel5;
}

void FaciliteHistorique::setDatel6(QDate datel6) {
    this->datel6 = datel6;
}

void FaciliteHistorique::setTranche1(float tranche1) {
    this->tranche1 = tranche1;
}

void FaciliteHistorique::setTranche2(float tranche2) {
    this->tranche2 = tranche2;
}

void FaciliteHistorique::setTranche3(float tranche3) {
    this->tranche3 = tranche3;
}

void FaciliteHistorique::setTranche4(float tranche4) {
    this->tranche4 = tranche4;
}

void FaciliteHistorique::setTranche5(float tranche5) {
    this->tranche5 = tranche5;
}

void FaciliteHistorique::setTranche6(float tranche6) {
    this->tranche6 = tranche6;
}

void FaciliteHistorique::setBox1(bool box1) {
    this->box1 = box1;
}

void FaciliteHistorique::setBox2(bool box2) {
    this->box2 = box2;
}

void FaciliteHistorique::setBox3(bool box3) {
    this->box3 = box3;
}

void FaciliteHistorique::setBox4(bool box4) {
    this->box4 = box4;
}

void FaciliteHistorique::setBox5(bool box5) {
    this->box5 = box5;
}

void FaciliteHistorique::setBox6(bool box6) {
    this->box6 = box6;
}
#include <QSqlError>


bool FaciliteHistorique::ajouterFacilite() {
    QSqlQuery query;
    query.prepare("INSERT INTO FACILITE (CIN, DATEL1, DATEL2, DATEL3, DATEL4, DATEL5, DATEL6, "
                  "TRANCHE1, TRANCHE2, TRANCHE3, TRANCHE4, TRANCHE5, TRANCHE6, "
                  "BOX1, BOX2, BOX3, BOX4, BOX5, BOX6, ID_PROJET) "
                  "VALUES (:cin, :datel1, :datel2, :datel3, :datel4, :datel5, :datel6, "
                  ":tranche1, :tranche2, :tranche3, :tranche4, :tranche5, :tranche6, "
                  ":box1, :box2, :box3, :box4, :box5, :box6, :id_projet)");

    query.bindValue(":cin", cin_client);
    query.bindValue(":datel1", datel1);
    query.bindValue(":datel2", datel2);
    query.bindValue(":datel3", datel3);
    query.bindValue(":datel4", datel4);
    query.bindValue(":datel5", datel5);
    query.bindValue(":datel6", datel6);
    query.bindValue(":tranche1", tranche1);
    query.bindValue(":tranche2", tranche2);
    query.bindValue(":tranche3", tranche3);
    query.bindValue(":tranche4", tranche4);
    query.bindValue(":tranche5", tranche5);
    query.bindValue(":tranche6", tranche6);
    query.bindValue(":box1", box1);
    query.bindValue(":box2", box2);
    query.bindValue(":box3", box3);
    query.bindValue(":box4", box4);
    query.bindValue(":box5", box5);
    query.bindValue(":box6", box6);
    query.bindValue(":id_projet", ID_P);  // ✅ Utilisation de l’attribut correct

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'insertion : " << query.lastError();
        return false;
    }
    return true;
}

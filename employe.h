#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>
#include <QTableView>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QValueAxis>
#include <QBarCategoryAxis>
#include <QDialog>
#include <QVBoxLayout>
#include <QWidget>
#include <QObject>
#ifndef EMPLOYE_H
#define EMPLOYE_H


class Employe
{
public:
 // Default constructor
    Employe();
    // ConstructorEmploye();
    Employe( const QString& nom, const QString& prenom, int age, float salaire,
            int telephone, const QString& gmail, int experience, const QString& etatcivil,
            QString presence, const QString& motDePasse, double impot);

    Employe(int cin, const QString& nom, const QString& prenom, int age, float salaire,
            int telephone, const QString& gmail, int experience, const QString& etatcivil,
            QString presence, const QString& motDePasse, double impot);

    bool AjouterEmploye();
    bool SupprimerEmploye(int cin);
    static bool ControleSaisir(int cin, const QString& nom, const QString& prenom, int age, float salaire,
                               int telephone, const QString& gmail, int experience,
                               const QString& etatcivil, const QString& motDePasse, double impot);

    bool ModifierEmploye(int cin);
    QSqlQueryModel* AfficherEmploye();
    bool ExisteCIN(int cin);
    void AfficherStatistiques(QWidget *parent = nullptr);  // Pass the parent QWidget for dialog

    // Getters and Setters
    double getCin() const;
    QString getNom() const;
    QString getPrenom() const;
    int getAge() const;
    float getSalaire() const;
    int getTelephone() const;
    QString getGmail() const;
    int getExperience() const;
    QString getEtatcivil() const;
    QString getPresence() const;
    QString getMotDePasse() const;
    double getImpot() const;

    void setCin(int cin);
    void setNom(const QString& nom);
    void setPrenom(const QString& prenom);
    void setAge(int age);
    void setSalaire(float salaire);
    void setTelephone(int telephone);
    void setGmail(const QString& gmail);
    void setExperience(int experience);
    void setEtatcivil(const QString& etatcivil);
    void setPresence(QString presence);
    void setMotDePasse(QString& motDePasse);
    void setImpot(double impot);


private:
    int _cin;
    QString _nom;
    QString _prenom;
    int _age;
    float _salaire;
    int _telephone;
    QString _gmail;
    int _experience;
    QString _etatcivil;
    QString _presence;
    QString _motDePasse;
    double _impot;


};

#endif // EMPLOYE_H

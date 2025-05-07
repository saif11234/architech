#include "employe.h"
#include "qsqlerror.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>
#include <QObject>
#include <QRegularExpression>
#include <QVector>
#include <QPainter>
#include <QDate>
#include <QPdfWriter>
#include <QGraphicsView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QSqlQuery>
#include <QMap>
#include <QDialog>
#include <QVBoxLayout>
#include <QtCharts/QChartView>


using namespace std;

// Default Constructor
Employe::Employe()
    : _cin(0), _nom(""), _prenom(""), _age(0), _salaire(0.0), _telephone(0),
    _gmail(""), _experience(0), _etatcivil(""), _presence(""), _motDePasse(""), _impot(0) {}

Employe::Employe( const QString& nom, const QString& prenom, int age, float salaire,
             int telephone, const QString& gmail, int experience, const QString& etatcivil,
            QString presence, const QString& motDePasse, double impot)
    :  _nom(nom), _prenom(prenom), _age(age), _salaire(salaire), _telephone(telephone),
    _gmail(gmail), _experience(experience), _etatcivil(etatcivil), _presence(presence),
    _motDePasse(motDePasse), _impot(impot) {}
Employe::Employe( int cin,const QString& nom, const QString& prenom, int age, float salaire,
                 int telephone, const QString& gmail, int experience, const QString& etatcivil,
                 QString presence, const QString& motDePasse, double impot)
    : _cin(cin) , _nom(nom), _prenom(prenom), _age(age), _salaire(salaire), _telephone(telephone),
    _gmail(gmail), _experience(experience), _etatcivil(etatcivil), _presence(presence),
    _motDePasse(motDePasse), _impot(impot) {}

//controle de saisir




void Employe::AfficherStatistiques(QWidget *parent) {
    QSqlQuery query;
    QMap<QString, int> stats; // Key: EXPERIENCE, Value: Count

    // Corrected SQL column to match the logic
    if (query.exec("SELECT EXPERIENCE, COUNT(*) FROM EMPLOYE GROUP BY EXPERIENCE")) {
        while (query.next()) {
            QString experience = query.value(0).toString();
            int count = query.value(1).toInt();
            stats[experience] = count;
        }
    } else {
        qDebug() << "❌ Erreur lors de la récupération des statistiques:" << query.lastError().text();
        return;
    }

    QBarSet *set = new QBarSet("Nombre d'employés");
    QStringList categories;

    for (auto it = stats.begin(); it != stats.end(); ++it) {
        *set << it.value();
        categories << it.key();
    }

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des employés par expérience");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create and display the dialog
    QDialog *dialog = new QDialog(parent);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);

    dialog->setWindowTitle("Statistiques des employés");
    dialog->resize(600, 400);
    dialog->exec();
}

bool Employe::ControleSaisir(int cin, const QString& nom, const QString& prenom, int age, float salaire,
                             int telephone, const QString& gmail, int experience,
                             const QString& etatcivil, const QString& motDePasse, double impot) {
    // Check if required fields are empty
    if (cin == 0 || nom.isEmpty() || prenom.isEmpty() || age <= 0 || salaire <= 0 ||
        telephone==0 || gmail.isEmpty() || experience < 0 || etatcivil.isEmpty() ||
        motDePasse.isEmpty() || impot < 0) {

        QMessageBox::warning(nullptr, "Erreur", "Tous les champs doivent être remplis correctement !");
        return false;
    }



    // Validate CIN (6-8 digits)
    if (QString::number(cin).length() < 6 || QString::number(cin).length() > 8) {
        QMessageBox::warning(nullptr, "Erreur", "Le CIN doit contenir entre 6 et 8 chiffres !");
        return false;
    }

    // Validate Age


    // Validate Telephone (10-digit number starting with 0)
    /*QRegularExpression phoneRegex("^0[5-9][0-9]{8}$");
    if (!phoneRegex.match(telephone).hasMatch()) {
        QMessageBox::warnin(nullptr, "Erreur", "Numéro de téléphone invalide !");
        return false;
    }
*/

    // Validate Email
    QRegularExpression emailRegex("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$");
    if (!emailRegex.match(gmail).hasMatch()) {
        QMessageBox::warning(nullptr, "Erreur", "Adresse e-mail invalide !");
        return false;
    }

    // Validate Experience (reasonable range)
    if (experience < 0 || experience > 50) {
        QMessageBox::warning(nullptr, "Erreur", "L'expérience doit être entre 0 et 50 ans !");
        return false;
    }

    // Validate Password (at least 6 characters)
    if (motDePasse.length() < 6) {
        QMessageBox::warning(nullptr, "Erreur", "Le mot de passe doit contenir au moins 6 caractères !");
        return false;
    }

    // Validation successful
    return true;
}



// Add Employee to Database
bool Employe::AjouterEmploye() {
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYE ( CIN_EMPLOYE, NOM, PRENOM, AGE, SALAIRE, TELEPHONE, EMAIL, EXPERIENCE, ETAT_CIVIL, PRESENCE, MOT_DE_PASSE, IMPOT) "
                  "VALUES (:cin, :nom, :prenom, :age, :salaire, :telephone, :gmail, :experience, :etatcivil, :presence, :motDePasse, :impot)");

    query.bindValue(":cin", _cin);
    query.bindValue(":nom", _nom);
    query.bindValue(":prenom", _prenom);
    query.bindValue(":age", _age);
    query.bindValue(":salaire", _salaire);
    query.bindValue(":telephone", _telephone);
    query.bindValue(":gmail", _gmail);
    query.bindValue(":experience", _experience);
    query.bindValue(":etatcivil", _etatcivil);
    query.bindValue(":presence", _presence);
    query.bindValue(":motDePasse", _motDePasse);
    query.bindValue(":impot", _impot);
    if (query.exec()) {
        QMessageBox::information(nullptr, "Succès", "L'employé a été ajouté avec succès !");
        //AfficherEmploye();  // Refresh TableView

        return true;
    } else {
        qDebug() << "Erreur lors de l'ajout de l'employé:" << query.lastError().text();
        QMessageBox::critical(nullptr, "Erreur", "Échec de l'ajout de l'employé !");
        return false;
    }
}
bool Employe::ExisteCIN(int cin) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EMPLOYE WHERE CIN_EMPLOYE   = :cin");
    query.bindValue(":cin", cin);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;  // Returns true if at least one record exists
    }
    return false;
}

bool Employe::SupprimerEmploye(int cin) {
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYE WHERE CIN_EMPLOYE = :cin");
    query.bindValue(":cin", cin);

    if (query.exec()) {
        AfficherEmploye();  // Refresh TableView

        return true;
    } else {
        qDebug() << "Erreur suppression employé:" << query.lastError().text();
        return false;
    }
}
/*bool Employe::ModifierEmploye() {
    QSqlQuery query;
    QString queryString = "UPDATE EMPLOYE SET ";
    bool hasChanges = false;

    if (!_nom.isEmpty()) {
        queryString += "NOM = :nom, ";
        query.bindValue(":nom", _nom);
        hasChanges = true;
    }
    if (!_prenom.isEmpty()) {
        queryString += "PRENOM = :prenom, ";
        query.bindValue(":prenom", _prenom);
        hasChanges = true;
    }
    if (_age > 0) {
        queryString += "AGE = :age, ";
        query.bindValue(":age", _age);
        hasChanges = true;
    }
    if (_salaire > 0) {
        queryString += "SALAIRE = :salaire, ";
        query.bindValue(":salaire", _salaire);
        hasChanges = true;
    }
    if (_telephone<8) {
        queryString += "TELEPHONE = :telephone, ";
        query.bindValue(":telephone", _telephone);
        hasChanges = true;
    }
    if (!_gmail.isEmpty()) {
        queryString += "GMAIL = :gmail, ";
        query.bindValue(":gmail", _gmail);
        hasChanges = true;
    }
    if (_experience > 0) {
        queryString += "EXPERIENCE = :experience, ";
        query.bindValue(":experience", _experience);
        hasChanges = true;
    }
    if (!_etatcivil.isEmpty()) {
        queryString += "ETAT_CIVIL = :etatcivil, ";
        query.bindValue(":etatcivil", _etatcivil);
        hasChanges = true;
    }
    if (!_presence.isEmpty()) {
        queryString += "PRESENCE = :presence, ";
        query.bindValue(":presence", _presence);
        hasChanges = true;
    }
    if (!_motDePasse.isEmpty()) {
        queryString += "MOT_DE_PASSE = :motDePasse, ";
        query.bindValue(":motDePasse", _motDePasse);
        hasChanges = true;
    }
    if (_impot >= 0) {
        queryString += "IMPOT = :impot, ";
        query.bindValue(":impot", _impot);
        hasChanges = true;
    }

    // If no changes were made, return false
    if (!hasChanges) {
        return false;
    }

    // Remove last comma and space
    queryString.chop(2);

    // Add WHERE condition
    queryString += " WHERE CIN_EMPLOYE = :cin";
    query.prepare(queryString);
    query.bindValue(":cin", _cin);

    return query.exec();
}

*/
/*bool Employe::ModifierEmploye() {
    QSqlQuery query;
    QString queryString = "UPDATE EMPLOYE SET ";
    bool hasChanges = false;

    if (!_nom.isEmpty()) {
        queryString += "NOM = :nom, ";
        query.bindValue(":nom", _nom);
        hasChanges = true;
    }
    if (!_prenom.isEmpty()) {
        queryString += "PRENOM = :prenom, ";
        query.bindValue(":prenom", _prenom);
        hasChanges = true;
    }
    if (_age > 0) {
        queryString += "AGE = :age, ";
        query.bindValue(":age", _age);
        hasChanges = true;
    }
    if (_salaire > 0) {
        queryString += "SALAIRE = :salaire, ";
        query.bindValue(":salaire", _salaire);
        hasChanges = true;
    }
    if (QString::number(_telephone).length() == 8) {  // Vérifie un numéro à 8 chiffres
        queryString += "TELEPHONE = :telephone, ";
        query.bindValue(":telephone", _telephone);
        hasChanges = true;
    }
    if (!_gmail.isEmpty()) {
        queryString += "EMAIL = :gmail, ";
        query.bindValue(":gmail", _gmail);
        hasChanges = true;
    }
    if (_experience > 0) {
        queryString += "EXPERIENCE = :experience, ";
        query.bindValue(":experience", _experience);
        hasChanges = true;
    }
    if (!_etatcivil.isEmpty()) {
        queryString += "ETAT_CIVIL = :etatcivil, ";
        query.bindValue(":etatcivil", _etatcivil);
        hasChanges = true;
    }
    if (!_presence.isEmpty()) {
        queryString += "PRESENCE = :presence, ";
        query.bindValue(":presence", _presence);
        hasChanges = true;
    }
    if (!_motDePasse.isEmpty()) {
        queryString += "MOT_DE_PASSE = :motDePasse, ";
        query.bindValue(":motDePasse", _motDePasse);
        hasChanges = true;
    }
    if (_impot >= 0) {
        queryString += "IMPOT = :impot, ";
        query.bindValue(":impot", _impot);
        hasChanges = true;
    }

    // Vérifier si des modifications ont été faites
    if (!hasChanges) {
        qDebug() << "❌ Aucune modification détectée. Requête annulée.";
        return false;
    }

    // Supprimer la dernière virgule et l'espace
    queryString.chop(2);

    // Ajouter la condition WHERE
    queryString += " WHERE CIN_EMPLOYE = :cin";
    query.prepare(queryString);
    query.bindValue(":cin", _cin);

    if (query.exec()) {
        qDebug() << "✅ Employé modifié avec succès, CIN:" << _cin;
        return true;
    } else {
        qDebug() << "❌ Erreur lors de la modification de l'employé:" << query.lastError().text();
        return false;
    }
}

*/
bool Employe::ModifierEmploye(int cin) {
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET NOM = :nom, PRENOM = :prenom, AGE = :age, SALAIRE = :salaire, TELEPHONE = :telephone, EMAIL = :email, EXPERIENCE = :experience, ETAT_CIVIL = :etatcivil, PRESENCE = :presence, MOT_DE_PASSE = :motDePasse, IMPOT = :impot WHERE CIN_EMPLOYE = :cin");

    query.bindValue(":nom", _nom);
    query.bindValue(":prenom", _prenom);
    query.bindValue(":age", _age);
    query.bindValue(":salaire", _salaire);
    query.bindValue(":telephone", _telephone);
    query.bindValue(":email", _gmail);
    query.bindValue(":experience", _experience);
    query.bindValue(":etatcivil", _etatcivil);
    query.bindValue(":presence", _presence);
    query.bindValue(":motDePasse", _motDePasse);
    query.bindValue(":impot", _impot);

    // ⚠️ Utiliser le `cin` passé en paramètre
    query.bindValue(":cin", cin);

    // 🔍 Debugging
    qDebug() << "📌 CIN utilisé : " << cin;

    if (query.exec()) {
        qDebug() << "✅ Employé modifié avec succès, CIN:" << cin;
        return true;
    } else {
        qDebug() << "❌ Erreur SQL: " << query.lastError().text();
        return false;
    }
}


QSqlQueryModel* Employe::AfficherEmploye()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // ❌ NO need to create QSqlQuery manually
    model->setQuery("SELECT CIN_EMPLOYE, NOM, PRENOM, AGE, SALAIRE, TELEPHONE, EMAIL, EXPERIENCE, ETAT_CIVIL, PRESENCE, IMPOT FROM EMPLOYE");

    if (model->lastError().isValid()) {
        qDebug() << "❌ Erreur dans le modèle :" << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}


// Getters
double Employe::getCin() const { return _cin; }
QString Employe::getNom() const { return _nom; }
QString Employe::getPrenom() const { return _prenom; }
int Employe::getAge() const { return _age; }
float Employe::getSalaire() const { return _salaire; } // ✅ Correct type

// Setters
void Employe::setCin(int cin) { _cin = cin; }
void Employe::setNom(const QString& nom) { _nom = nom; }
void Employe::setPrenom(const QString& prenom) { _prenom = prenom; }
void Employe::setAge(int age) { _age = age; }
void Employe::setSalaire(float salaire) { _salaire = salaire; } // ✅ Correct type

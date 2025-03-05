#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    afficherProjets();  // Charger la liste des projets au démarrage
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearFields()
{
    ui->nom_projet->clear();
    ui->description->clear();
    ui->budget->clear();
    ui->date_debut->setDate(QDate::currentDate());
    ui->date_fin->setDate(QDate::currentDate());
    ui->etat->setCurrentIndex(0);
}

void MainWindow::on_ajouter_clicked()
{
    int id = ui->id_projet->text().toInt();
    QString nom = ui->nom_projet->text();
    QString description = ui->description->text();
    float budget = ui->budget->text().toFloat();
    QDate dateDebut = ui->date_debut->date();
    QDate dateFin = ui->date_fin->date();
    QString etat = ui->etat->currentText();

    if (nom.isEmpty() || description.isEmpty() || budget <= 0) {
        QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs correctement.");
        return;
    }

    Projet projet(id, nom,etat, description, budget, dateDebut, dateFin);
    if (projet.ajouter()) {
        afficherProjets();
        clearFields();
        QMessageBox::information(this, "Succès", "Projet ajouté avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du projet.");
    }
}

void MainWindow::afficherProjets()
{
    QSqlQueryModel *model = projetActuel.afficher();
    ui->tableprojet->setModel(model);
}

void MainWindow::on_supprimerprojet_clicked()
{
    int row = ui->tableprojet->currentIndex().row();
    if (row >= 0) {
        int id = ui->tableprojet->model()->index(row, 0).data().toInt();
        if (projetActuel.supprimer(id)) {
            afficherProjets();
            QMessageBox::information(this, "Suppression", "Projet supprimé !");
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un projet.");
    }
}

void MainWindow::on_tableprojet_clicked(int row)
{
    QModelIndex index = ui->tableprojet->model()->index(row, 0);
    int id = index.data().toInt();
    projetActuel = projetActuel.getProjetById(id);

    ui->nom_projet->setText(projetActuel.getNom());
    ui->description->setText(projetActuel.getDescription());
    ui->budget->setText(QString::number(projetActuel.getBudget()));
    ui->date_debut->setDate(projetActuel.getDateDebut());
    ui->date_fin->setDate(projetActuel.getDateFin());
    ui->etat->setCurrentText(projetActuel.getEtat());
}

void MainWindow::on_modifierprojet_clicked()
{
    int row = ui->tableprojet->currentIndex().row();
    if (row >= 0) {
        int id = ui->tableprojet->model()->index(row, 0).data().toInt();
        QString nom = ui->nom_projet->text();
        QString description = ui->description->text();
        float budget = ui->budget->text().toFloat();
        QDate dateDebut = ui->date_debut->date();
        QDate dateFin = ui->date_fin->date();
        QString etat = ui->etat->currentText();

        Projet projet(id, nom,etat, description,budget, dateDebut, dateFin);
        if (projet.modifier(id)) {
            afficherProjets();
            clearFields();
            QMessageBox::information(this, "Succès", "Projet modifié avec succès.");
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la modification.");
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un projet.");
    }
}

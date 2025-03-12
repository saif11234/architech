#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modifierprojetdialog.h"
#include <QString>
#include <QDateTime>
#include <QSqlQueryModel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableViewProjets->setModel(projet.afficherProjets());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Employes_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page1_EMPLOYES);
}

void MainWindow::on_Clients_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page2_CLIENTS);
}

void MainWindow::on_Projets_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page3_PROJETS);
    ui->tableViewProjets->setModel(projet.afficherProjets());
}

void MainWindow::on_Partenaire_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page4_PARTENAIRES);
}

void MainWindow::on_Ressources_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page6_RESSOURCES);
}

void MainWindow::on_AjouterProjet_clicked()
{
    QString nom = ui->nom_projet_3->text();
    QString description = ui->description_3->text();
    int id_projet = ui->id_projet_3->text().toInt();
    bool okBudget, okCinClient;
    float budget = ui->budget_3->text().toFloat(&okBudget);
    int cin_client = ui->cin_client_3->text().toInt(&okCinClient);
    QString date_debut_str = ui->date_debut_3->text();
    QString date_fin_str = ui->date_fin_3->text();

    QDateTime date_debut = QDateTime::fromString(date_debut_str, "dd/mm/yyyy");
    QDateTime date_fin = QDateTime::fromString(date_fin_str, "dd/mm/yyyy");

    if(nom.isEmpty() || description.isEmpty() || date_debut_str.isEmpty() || date_fin_str.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
        return;
    }

    if (!okBudget || !okCinClient) {
        QMessageBox::warning(this, "Erreur de saisie", "Le budget et le CIN client doivent être des nombres valides.");
        return;
    }

    // Vérification du format de date
    if (!date_debut.isValid() || !date_fin.isValid()) {
        QMessageBox::warning(this, "Format de date incorrect", "Veuillez entrer les dates au format DD/MM/YYYY.");
        return;
    }

    // Vérification si la date de début est avant la date de fin
    if (date_debut > date_fin) {
        QMessageBox::warning(this, "Erreur de date", "La date de début doit être antérieure à la date de fin.");
        return;
    }

    Projet p(id_projet,nom, description, budget, date_debut_str, date_fin_str, cin_client);
    bool success = p.ajouterProjet();

    if (success) {
        ui->tableViewProjets->setModel(projet.afficherProjets()); // Rafraîchir la table
        QMessageBox::information(this, "Succès", "Projet ajouté avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout du projet a échoué.");
    }
}


void MainWindow::on_ModifierProjet_clicked()
{
    QModelIndex index = ui->tableViewProjets->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Sélection requise", "Veuillez sélectionner un projet à modifier.");
        return;
    }

    int row = index.row();
    int id = ui->tableViewProjets->model()->index(row, 0).data().toInt();
    QString nom = ui->tableViewProjets->model()->index(row, 1).data().toString();
    QString description = ui->tableViewProjets->model()->index(row, 2).data().toString();
    float budget = ui->tableViewProjets->model()->index(row, 3).data().toFloat();
    QString date_debut = ui->tableViewProjets->model()->index(row, 4).data().toString();
    QString date_fin = ui->tableViewProjets->model()->index(row, 5).data().toString();
    int cin_client = ui->tableViewProjets->model()->index(row, 6).data().toInt();

    Projet p(id, nom, description, budget, date_debut, date_fin, cin_client);

    ModifierProjetDialog dialog(this);
    dialog.setProjet(p);

    if (dialog.exec() == QDialog::Accepted) {
        ui->tableViewProjets->setModel(projet.afficherProjets()); // Rafraîchir la liste
    }
}



void MainWindow::on_SupprimerProjet_clicked()
{
    QModelIndex index = ui->tableViewProjets->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Sélection requise", "Veuillez sélectionner un projet à modifier.");
        return;
    }

    int row = index.row();
    int id = ui->tableViewProjets->model()->index(row, 0).data().toInt();
    bool success = projet.supprimerProjet(id);

    if (success) {
        ui->tableViewProjets->setModel(projet.afficherProjets());
        QMessageBox::information(this, "Succès", "Projet supprimé avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "La suppression du projet a échoué.");
    }
}

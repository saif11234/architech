#include "modifierprojetdialog.h"
#include "ui_modifierprojetdialog.h"
#include <QMessageBox>
#include <QDateTime>
ModifierProjetDialog::ModifierProjetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifierProjetDialog)
{
    ui->setupUi(this);
}

ModifierProjetDialog::~ModifierProjetDialog()
{
    delete ui;
}

void ModifierProjetDialog::setProjet(const Projet &projet)
{
    projetId = projet.getIdProjet(); // Stocker l'ID du projet
    ui->lineEditNom->setText(projet.getNomProjet());
    ui->lineEditDescription->setText(projet.getDescription());
    ui->lineEditBudget->setText(QString::number(projet.getBudget()));
    ui->lineEditCinClient->setText(QString::number(projet.getCinClient()));
    ui->lineEditDateDebut->setText(projet.getDateDebut());
    ui->lineEditDateFin->setText(projet.getDateFin());
}

void ModifierProjetDialog::on_buttonValider_clicked()
{
    // Récupérer les valeurs modifiées
    QString nom = ui->lineEditNom->text();
    QString description = ui->lineEditDescription->text();
    float budget = ui->lineEditBudget->text().toFloat();
    int cin_client = ui->lineEditCinClient->text().toInt();
    QString date_debut = ui->lineEditDateDebut->text();
    QString date_fin = ui->lineEditDateFin->text();

    // Vérifications des champs
    if(nom.isEmpty() || description.isEmpty() || date_debut.isEmpty() || date_fin.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
        return;
    }

    // Vérification du format des dates
    QDateTime debut = QDateTime::fromString(date_debut, "dd/mm/yyyy");
    QDateTime fin = QDateTime::fromString(date_fin, "dd/mm/yyyy");

    if (!debut.isValid() || !fin.isValid()) {
        QMessageBox::warning(this, "Format de date incorrect", "Veuillez entrer les dates au format dd/mm/yyyy.");
        return;
    }

    if (debut > fin) {
        QMessageBox::warning(this, "Erreur de date", "La date de début doit être avant la date de fin.");
        return;
    }

    // Mise à jour du projet
    Projet p(projetId, nom, description, budget, date_debut, date_fin, cin_client);
    if (p.modifierProjet()) {
        QMessageBox::information(this, "Succès", "Projet modifié avec succès !");
        accept(); // Fermer la boîte de dialogue
    } else {
        QMessageBox::critical(this, "Erreur", "La modification du projet a échoué.");
    }
}

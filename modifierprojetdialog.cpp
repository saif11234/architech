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
    projetId = projet.getIdProjet();
    ui->lineEditNom->setText(projet.getNomProjet());
    ui->lineEditDescription->setText(projet.getDescription());
    ui->lineEditBudget->setText(QString::number(projet.getBudget()));
    ui->lineEditCinClient->setText(QString::number(projet.getCinClient()));
    ui->lineEditDateDebut->setText(projet.getDateDebut());
    ui->lineEditDateFin->setText(projet.getDateFin());
    ui->comboBox->setCurrentText(projet.getEtat());
    ui->latitude->setText(QString::number(projet.getLatitude()));
    ui->longitude->setText(QString::number(projet.getLongitude()));
}

void ModifierProjetDialog::on_buttonValider_clicked()
{

    QString nom = ui->lineEditNom->text();
    QString description = ui->lineEditDescription->text();
    bool okBudget, okCinClient;
    float budget = ui->lineEditBudget->text().toFloat(&okBudget);
    int cin = ui->lineEditCinClient->text().toInt(&okCinClient);
    QString date_debut = ui->lineEditDateDebut->text();
    QString date_fin = ui->lineEditDateFin->text();
    QString etat = ui->comboBox->currentText();
    bool okLatitude, okLongitude;
    float latitude = ui->latitude->text().toFloat(&okLatitude);
    float longitude = ui->longitude->text().toFloat(&okLongitude);

    if(nom.isEmpty() || description.isEmpty() || date_debut.isEmpty() || date_fin.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
        return;
    }

    QDateTime debut = QDateTime::fromString(date_debut, "dd/mm/yyyy");
    QDateTime fin = QDateTime::fromString(date_fin, "dd/mm/yyyy");

    if (!okLatitude || !okLongitude) {
        QMessageBox::warning(this, "Erreur de saisie", "La latitude et la longitude doivent être des nombres valides.");
        return;
    }
    if (!debut.isValid() || !fin.isValid()) {
        QMessageBox::warning(this, "Format de date incorrect", "Veuillez entrer les dates au format dd/mm/yyyy.");
        return;
    }
    if (!okBudget || !okCinClient) {
        QMessageBox::warning(this, "Erreur de saisie", "Le budget et le CIN client doivent être des nombres valides.");
        return;
    }

    if (debut > fin) {
        QMessageBox::warning(this, "Erreur de date", "La date de début doit être avant la date de fin.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM client WHERE cin_client = :cin");
    query.bindValue(":cin", cin);
    if (query.exec()) {
        if (query.next()) {
            int count = query.value(0).toInt();
            if (count == 0) {
                QMessageBox::warning(this, "Erreur de saisie", "Le CIN client doit être valide.");
                return;
            }
        }
    }
    Projet p(projetId, nom, description, budget, date_debut, date_fin, cin,etat,latitude,longitude);
    if (p.modifierProjet()) {
        QMessageBox::information(this, "Succès", "Projet modifié avec succès !");
        accept();
    } else {
        QMessageBox::critical(this, "Erreur", "La modification du projet a échoué.");
    }
}

#ifndef MODIFIERPROJETDIALOG_H
#define MODIFIERPROJETDIALOG_H

#include <QDialog>
#include "projet.h"

namespace Ui {
class ModifierProjetDialog;
}

class ModifierProjetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierProjetDialog(QWidget *parent = nullptr);
    ~ModifierProjetDialog();

    void setProjet(const Projet &projet); // Remplir les champs avec les infos du projet

private slots:
    void on_buttonValider_clicked(); // Quand l'utilisateur valide

private:
    Ui::ModifierProjetDialog *ui;
    int projetId; // Stocker l'ID du projet
};

#endif // MODIFIERPROJETDIALOG_H

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

    void setProjet(const Projet &projet);

private slots:
    void on_buttonValider_clicked();

private:
    Ui::ModifierProjetDialog *ui;
    int projetId;
};

#endif // MODIFIERPROJETDIALOG_H

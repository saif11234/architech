#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "projet.h"
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();  // Ajout projet
    void on_supprimerprojet_clicked();  // Suppression projet
    void on_tableprojet_clicked(int row);  // Sélection projet
    void on_modifierprojet_clicked();  // Modification projet
    void afficherProjets();  // Afficher tous les projets

private:
    Ui::MainWindow *ui;
    Projet projetActuel;  // Objet projet pour manipuler la BDD
    void clearFields();  // Fonction pour vider les champs
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "projet.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Employes_clicked();
    void on_Clients_clicked();
    void on_Projets_clicked();
    void on_Partenaire_clicked();
    void on_Ressources_clicked();

    void on_AjouterProjet_clicked();
   void on_ModifierProjet_clicked();
   void on_SupprimerProjet_clicked();

private:
    Ui::MainWindow *ui;
    Projet projet;
};

#endif // MAINWINDOW_H

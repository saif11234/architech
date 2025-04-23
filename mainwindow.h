#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "projet.h"
#include "projetmodel.h"
#include <QChartView>
#include <QGraphicsView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QLegend>





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
    void on_AnnulerProjet_clicked();
   void on_ModifierProjet_clicked();
   void on_SupprimerProjet_clicked();
   void on_recherche_pin_clicked();

   void on_rechercheprojet_textChanged(const QString &text);
   void on_downloadprojet_clicked();
    void afficherStatistiquesEtat();

   void on_id_employe_currentIndexChanged(int index);
   void displayTasks(int employeeId);
   void clearTables();
   void on_add_clicked();
   int generateUniqueTaskId();
   void on_movetodoing_clicked();
   void on_movetodone_clicked();
   void moveTask(int newType,int taskId);
   void on_delete_2_clicked();


private:
    Ui::MainWindow *ui;
    Projet projet;
    ProjetModel *m_projetModel;

};

#endif // MAINWINDOW_H

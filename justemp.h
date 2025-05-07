#ifndef JUSTEMP_H
#define JUSTEMP_H

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>
#include <QTableView>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QValueAxis>
#include <QBarCategoryAxis>
#include <QDialog>
#include <QVBoxLayout>
#include <QWidget>
#include <QObject>
#include <qlistwidget.h>
#include "employe.h"
#include "ressource.h"
#include "rendezvous.h"
#include "partenaire.h"
#include "clients.h"
#include "projet.h"
namespace Ui {
class justemp;
}

class justemp : public QDialog
{
    Q_OBJECT

public:
    explicit justemp(QWidget *parent = nullptr);
    ~justemp();
    void setCIN(int cin); // ✅ AJOUTE CETTE LIGNE
   void afficheremploye();
    void trier(const QString &critere);
   void chargerComboBoxtriRessources();
     void gestionRessourcesparCIN(int cin);
   void afficherRessourcesemploye(int cin);


private slots:
    void on_TrierButton_clicked();

    void on_deconnexionButton_clicked();

    void on_ExporterPDFButton_clicked();

    void on_StatistiqueButton_clicked();

    void on_rechercher_textChanged(const QString &arg1);
    // Navigation buttons
    void on_Employes_clicked();
    void on_Clients_clicked();
    void on_Projets_clicked();
    void on_Partenaire_clicked();
    void on_RendezVous_clicked();
    void on_Ressources_clicked();
    void on_chercherRESSOURCE_textChanged(const QString &arg1);
    void on_trie_ressource_currentIndexChanged(int index);
    void on_CherRessourceNom_7_clicked();
    //RENDEZVOUS
    void on_afficherRV_7_clicked();
    void on_chercherRV_7_clicked();
    void on_exporterRV_7_clicked();
    void afficherNotification(const QString &message);
    void afficherRendezVousAujourdHui();
    void displayCalendar();
    void previousMonth();
    void nextMonth();
    void displayTasks();
    void clearTables();
    void on_add_clicked();
    int generateUniqueTaskId();
    void on_movetodoing_clicked();
    void on_movetodone_clicked();
    void moveTask(int newType,int taskId);
    void on_delete_2_clicked();
//yass
    void on_RechercherPartenair_clicked();
    void on_ExporterPDF_clicked();
    void on_AfficherStatistique_clicked();
    void on_envoyer_clicked();
    void on_sendButton_clicked();
    void onCorpsTextChanged();  // slot pour texte changé
    void onSuggestionClicked(QListWidgetItem* item); // si utilisateur clique sur suggestion
    void onEmailTextChanged();
    void on_TRIERPartenair_clicked();
    void on_TabP_tabBarClicked(int index);
    //azizakrt
    void on_TabC_tabBarClicked(int index);
    void on_Exporter_PDF_clicked();
    void on_pushButtonTrier_C_clicked();
    void on_chercher_clicked();

private:
    QListWidget *suggestionListWidget;  // widget pour suggestions
    void showSuggestions(const QStringList &suggestions);  // afficher suggestions
    Clients Cli;
    QVector<QPushButton*> stars; // Liste des étoiles
    void updateStars(int rating);
    void loadRatings();
    //urgent
    QListWidget *emailSuggestionList;
    Ui::justemp *ui;
    int cin;
    int employeeId;
    Employe emp;
    Ressource Res;
    RendezVous Rv;
    QDate currentDate;
    QMap<QDate, int> rdvParJour;
    int currentCin = -1;
    void filterTable (const QString &searchTerm);
    Partenaire Part;
    Projet projet;


    void setupPermissions();

};

#endif // JUSTEMP_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QSystemTrayIcon>
#include <QTimer>
#include <QDialog>
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
#include "employe.h"
#include "ressource.h" // Include this if Ressource is declared in another header
#include "rendezvous.h"
#include "partenaire.h"
#include "clients.h"
#include <QListWidget>

//
#include "facilitehistorique.h"
#include "Feedback.h"
#include <QRegularExpression>
#include <QChartView>
#include <QGraphicsView>
#include <qvector.h>
#include <QPushButton>
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void AfficherListeEmploye();
    void setCIN(int cin);

    void verifierDisponibiliteRessources();
    void chargerComboBoxtriRessources();
    void gestionRessources();
    void afficherRessources();
    void afficherStatistiquesTypes();

    // Misc
    void on_on_exitButton_clicked_clicked();
    void on_on_exitButton_clicked_2_clicked();
    void on_on_exitButton_clicked_3_clicked();
    void on_pushButton_clicked();


private slots:
    // Employe slots
    void on_AjouterEmploye_clicked();
    void on_SupprimerEmploye_clicked();
    void on_ModifierEmploye_clicked();
    void on_tab_client_3_tabBarClicked(int index);
    void on_TrierButton_clicked();
    void on_ExporterPDFButton_clicked();
    void on_StatistiqueButton_clicked();
    void on_rechercher_textChanged(const QString &arg1);
    void on_deconnexionButton_clicked();
    // Navigation buttons

    void on_Employes_clicked();
    void on_Clients_clicked();
    void on_Projets_clicked();
    void on_Partenaire_clicked();
    void on_RendezVous_clicked();
    void on_Ressources_clicked();

    void on_AjouterProjet_clicked();
    void on_AnnulerProjet_clicked();
    void on_ModifierProjet_clicked();
    void on_SupprimerProjet_clicked();
    void on_recherche_pin_clicked();

    void on_rechercheprojet_textChanged(const QString &text);
    void on_downloadprojet_clicked();
    void afficherStatistiquesEtat();

    void displayTasks();
    void clearTables();
    void on_add_clicked();
    int generateUniqueTaskId();
    void on_movetodoing_clicked();
    void on_movetodone_clicked();
    void moveTask(int newType,int taskId);
    void on_delete_2_clicked();
    // Ressource slots
    void chargerComboBoxIDS();
    void chargerComboBoxIDM();
    void on_Ajouter_ressource_clicked();
    void on_SupprimerRessource_clicked();
    void on_ID_ressources2_currentIndexChanged(int index);
    void on_ModifierRessource_clicked();
    void on_QuitterModifRessource_clicked();
    void on_Enexploitation_toggled(bool checked);
    void on_QuitterSuppRessource_clicked();
    void chargerComboBoxCIN_Employe();
    void on_QuitterAjoutRessource_clicked();
    void on_chercherRESSOURCE_textChanged(const QString &arg1);
    void on_CherRessourceNom_2_clicked();
    void on_trie_ressource_currentIndexChanged(int index);

    //RENDEZVOUS slots
    void on_AjouterRV_clicked();
    void on_tableView2RV_doubleClicked(const QModelIndex &index);
    void on_ModifierRV_clicked();
    void on_SupprimerRV_clicked();
    void on_afficherRV_clicked();

    void on_chercherRV_clicked();
    void on_exporterRV_clicked();
    void on_statRV_clicked();
    void afficherNotification(const QString &message);
    void afficherRendezVousAujourdHui();

    void displayCalendar();
    void previousMonth();
    void nextMonth();
    //RENDEZVOUS

    void on_stackedWidget_currentChanged(int arg1);

    /*****yasss*/

    void on_Ajouter_Partenaire_clicked();

    void on_suppP_clicked();

    void on_Modifier_P_clicked();
    void on_TabP_tabBarClicked(int index);
    void on_tableViewP_doubleClicked(const QModelIndex &index);
    bool controleSaisiePartenaire();
    bool controleSaisiePartenaire2();
    void on_RechercherPartenair_clicked();
    void on_ExporterPDF_clicked();
    void on_AfficherStatistique_clicked();
    void on_envoyer_clicked();
    void on_sendButton_clicked();
    void onCorpsTextChanged();  // slot pour texte changé
    void onSuggestionClicked(QListWidgetItem* item); // si utilisateur clique sur suggestion

    /********clients**************/
    bool controleSaisie1();
    bool controleSaisie2();
    void on_AjouterClient_clicked();
    void on_tableViewC_doubleClicked(const QModelIndex &index);
    void on_MODIFIERC_clicked();
    void on_supprimerC_clicked();
    void on_TabC_tabBarClicked(int index);
    void on_supprimerC_2_clicked();
    void on_Exporter_PDF_clicked();
    void on_pushButtonTrier_C_clicked();
    void on_ValiderFaciliter_clicked();
    void on_VOIRHIST_clicked();
    void on_ValiderHistorique_clicked();
    void on_chercher_clicked();
    void on_chargerlesdonnees_clicked();
    void activerChampsFacilite(bool actif);
    void onStarClicked();
    void on_ValiderRating_clicked();
    //arduino coffre fort
    void update_label();
    void  on_FermerC_clicked();
    void on_OuvrirC_clicked();
private slots:
    void onEmailTextChanged();


    void on_TRIERPartenair_clicked();
    void on_lineEdit_CP_editingFinished();


private:
    QListWidget *suggestionListWidget;  // widget pour suggestions
    void showSuggestions(const QStringList &suggestions);  // afficher suggestions
    //urgent
    QListWidget *emailSuggestionList;
    Ui::MainWindow *ui;
    Employe emp;
    Ressource Res;
    QTimer *m_alertTimer;
    QDialog *m_currentAlert;
    QSystemTrayIcon *trayIcon = nullptr;
    int loggedInCIN;
    bool m_alertClosedManually = false;
    int currentUserCIN;
    QDate currentDate;
    QMap<QDate, int> rdvParJour;
    RendezVous Rv;
    Projet projet;
    ProjetModel *m_projetModel;
    Partenaire Part;
    int    employeeId;

    void filterTable(const QString &searchTerm);
    void setupPermissions();


    //aziz akrt
    FaciliteHistorique Fac;
    Feedback Fd;
    Clients Cli;
    QVector<QPushButton*> stars; // Liste des étoiles
    void updateStars(int rating);
    void loadRatings();
    //-------------------------arduino
    QByteArray Data;
    Arduino A;
};

#endif // MAINWINDOW_H

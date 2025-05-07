#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogPDF_RESSOURCE.h"
#include <QHBoxLayout>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlError>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include "ressource.h"
#include <QVariant>
#include <QPieSeries>
#include <QPieSlice>
#include <QChartView>
#include <QGroupBox>
#include <QScrollArea>
#include <QTableWidget>
#include <QSqlRecord>
#include <QPrinter>       // Pour la génération PDF
#include <QTextDocument>  // Pour créer le contenu PDF
#include <QFileDialog>    // Pour choisir l'emplacement du PDF
#include <QDesktopServices>
#include <QPdfWriter>
#include <QToolTip>
#include <QPainter>
#include <QScreen>
#include <QApplication>
#include <QTimer>
#include <QListWidget>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QSoundEffect>
#include <QSequentialAnimationGroup>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include "dialog.h"
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QPushButton>
#include <QDate>
#include "rendezvous.h"
#include "qlayout.h"
#include "modifierprojetdialog.h"
#include <QDateTime>
#include <QLayoutItem>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQuickItem>
#include "projetmodel.h"

#include "partenaire.h"
#include <mailing.h>
#include <QProcess>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
//urgence
#include <QCompleter>
//azizakr
#include <QHBoxLayout>
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "clients.h"
#include "Feedback.h"
#include "facilitehistorique.h"
#include <QTableView>
#include <QTableWidget>
#include <QRegularExpression>
#include <QFileDialog>
#include <QChartView>
#include <QGraphicsView>
#include <QTableWidgetItem>
#include <QLabel>
#include <QPixmap>
#include <QTableWidget>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QProcess>
#include <QJsonDocument>
#include <QJsonObject>
#include <qtimer.h>

#include "arduino.h"
MainWindow::~MainWindow()
{
    delete ui;
    if (m_currentAlert)
        m_currentAlert->deleteLater();
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
//*******************************************************
     m_alertTimer(new QTimer(this)),
    m_currentAlert(nullptr)
//****************************************************************
{
    ui->setupUi(this);
    m_projetModel = new ProjetModel(this);
    m_projetModel->refreshProjets();

    ui->quickWidget_MapView->engine()->rootContext()->setContextProperty("projetModel", m_projetModel);
    ui->quickWidget_MapView->setSource(QUrl(QStringLiteral("qrc:/QmlMap.qml")));
    ui->quickWidget_MapView->show();
//*******************************************************************
    connect(m_alertTimer, &QTimer::timeout, this, &MainWindow::verifierDisponibiliteRessources);
    m_alertTimer->start(1000);
    //**********************************************************

    //RENDEZVOUS
    QTimer::singleShot(0, this, &MainWindow::afficherRendezVousAujourdHui);
    connect(ui->comboBoxTriRV, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int index) {
        RendezVous rdv;
        bool croissant = (index == 0);
        rdv.trierParDate(ui->tableView2RV, croissant);
    });

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsViewCal_RV->setScene(scene);
    currentDate = QDate::currentDate();

    QTimer::singleShot(0, this, [this]() {
        RendezVous rdv;
        rdvParJour = rdv.recupererNombreRendezVousParDate();
        displayCalendar();
    });
    displayCalendar();

    connect(ui->pushButtonMoisPrecedent_RV, &QPushButton::clicked, this, &MainWindow::previousMonth);
    connect(ui->pushButtonMoisSuivant_RV, &QPushButton::clicked, this, &MainWindow::nextMonth);

    //RENDEZVOUS



    //partenaire


    // Connecter changement de texte
    connect(ui->corps, &QTextEdit::textChanged, this, &MainWindow::onCorpsTextChanged);

    // Créer la liste de suggestions dynamiques
    suggestionListWidget = new QListWidget(this);
    suggestionListWidget->hide();
    suggestionListWidget->setWindowFlags(Qt::ToolTip); // Apparence "popup"
    connect(suggestionListWidget, &QListWidget::itemClicked, this, &MainWindow::onSuggestionClicked);

    emailSuggestionList = new QListWidget(this);

    emailSuggestionList->setWindowFlags(Qt::ToolTip);

    // Connexion pour afficher les suggestions dynamiques
    connect(ui->mail_3, &QLineEdit::textChanged, this, &MainWindow::onEmailTextChanged);

    // Connexion pour récupérer l'email choisi directement lors du clic sur un élément
    connect(emailSuggestionList, &QListWidget::itemClicked, this, [this](QListWidgetItem *item) {
        ui->mail_3->setText(item->text());
        emailSuggestionList->hide();  // Cacher la liste après le choix
    });
//azizakr




    stars = { ui->star1, ui->star2, ui->star3, ui->star4, ui->star5 };


    for (QPushButton *star : stars) {
        connect(star, &QPushButton::clicked, this, &MainWindow::onStarClicked);
    }
    //end
//arduinoo
    //====================================================arduino



    int ret = A.connect_arduino();
    switch(ret) {
    case 0:
        qDebug() << "Arduino is available and connected to:" << A.getarduino_port_name();
        break;
    case 1:
        qDebug() << "Arduino is available but not connected to:" << A.getarduino_port_name();
        break;
    case 2:
        qDebug() << "Arduino not available";
        break;
    }
    // Quand de nouvelles données arrivent sur le port série, cette ligne met à jour un label dans l'interface.
    QObject::connect(A.getserial(), SIGNAL(readyRead()),this,SLOT(update_label()));
    /*Toutes les 1 seconde, le minuteur déclenche un appel à update_label() pour peut-être actualiser l'interface,
   même s'il n'y a pas de nouvelles données.*/
    QTimer *timer = new QTimer(this); // Crée un minuteur
    connect(timer, &QTimer::timeout, this, &MainWindow::update_label); // Quand le minuteur "sonne", on appelle update_label()
    timer->start(1000); // Toutes les 1000 ms (1 seconde)


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
    displayTasks();

    ui->stackedWidget->setCurrentWidget(ui->page3_PROJETS);
    ui->tableViewProjets->setModel(projet.afficherProjets());
    afficherStatistiquesEtat();

    m_projetModel->refreshProjets();

    QQuickItem *rootItem = qobject_cast<QQuickItem*>(ui->quickWidget_MapView->rootObject());
    if (rootItem) {
        QVariant returnedValue;
        QMetaObject::invokeMethod(rootItem, "setPinLocation",
                                  Q_RETURN_ARG(QVariant, returnedValue),
                                  Q_ARG(QVariant, QVariant(36.8979693)),
                                  Q_ARG(QVariant, QVariant(10.1890552)));
    }}


void MainWindow::on_Partenaire_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page4_PARTENAIRES);
}


void MainWindow::on_RendezVous_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page5_RENDEZVOUS);
}



void MainWindow::on_Ressources_clicked()
{
    qDebug() << "Ressources button clicked";
    qDebug() << "Current page before change:" << ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentWidget(ui->page6_RESSOURCES);
    qDebug() << "Current page after change:" << ui->stackedWidget->currentIndex();
}
//***************************************************************************************************************
void MainWindow::chargerComboBoxIDS() {

    ui->ID_ressources->clear();
    ui->ID_ressources->addItem("Choisi un IDRessource");
 ui->ID_ressources->setItemData(0, QVariant(0), Qt::UserRole - 1);

    QSqlQueryModel* model = Res.recupererIDs();

    for (int i = 0; i < model->rowCount(); ++i) {
        QString id = model->data(model->index(i, 0)).toString();
        ui->ID_ressources->addItem(id);
    }

    if (ui->ID_ressources->count() == 0) {
        ui->ID_ressources->addItem("Aucun ID disponible");
    }

    delete model;
}


void MainWindow::chargerComboBoxIDM() {

    ui->ID_ressources2->clear();
    ui->ID_ressources2->addItem("Choisi un IDRessource");
    ui->ID_ressources2->setItemData(0, QVariant(0), Qt::UserRole - 1);

    QSqlQueryModel* model = Res.recupererIDs(); // Récupérer le modèle des IDs

    for (int i = 0; i < model->rowCount(); ++i) {
        QString id = model->data(model->index(i, 0)).toString(); // Récupérer l'ID
        ui->ID_ressources2->addItem(id);
    }

    if (ui->ID_ressources2->count() == 0) {
        ui->ID_ressources2->addItem("Aucun ID disponible");
    }

    delete model;
}

void MainWindow::chargerComboBoxCIN_Employe() {
    ui->IDEmploye->clear();
    ui->IDEmploye->addItem("Choisi le CIN");
    ui->IDEmploye->setItemData(0, QVariant(0), Qt::UserRole - 1);
    QSqlQueryModel* model = Res.recupererIDsEmploye();

    if (!model) {
        qDebug() << "Erreur : Le modèle est nul.";
        return;
    }

    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL :" << model->lastError().text();
        return;
    }
    int count = 0;
    for (int row = 0; row < model->rowCount(); ++row) {
        QString cin = model->record(row).value("CIN_EMPLOYE").toString();
        ui->IDEmploye->addItem(cin, cin.toInt());
        count++;
    }

    if (count == 0) {
        ui->IDEmploye->addItem("Aucun ID disponible");
    }
    delete model;
}
/*parite Aziz */




void MainWindow::setCIN(int cin)
{
    ui->cinLabel->setText(QString("CIN connecté : %1").arg(cin));

    QSqlQuery query;
    query.prepare("SELECT POSTE FROM EMPLOYE WHERE CIN_EMPLOYE = :cin");
    query.bindValue(":cin", cin);

    if (query.exec()) {
        if (query.next()) {
            QString role = query.value("poste").toString();
            ui->roleLabel->setText("  " + role);
        } else {
            ui->roleLabel->setText("Rôle : Inconnu");
        }
    } else {
        qDebug() << "Erreur lors de la récupération du rôle:" << query.lastError().text();
        ui->roleLabel->setText("Rôle : Erreur");
    }
    employeeId=cin;

}

/*MainWindow::~MainWindow()
{
    qDebug() << "❌ MainWindow destructor called! Window closed.";
    delete ui;
}

*/

void MainWindow::on_AjouterEmploye_clicked() {

    qDebug() << "Ajouter button clicked!";

    // Validate CIN input
    // Get values from input fields
    int cin = ui->cinLineEdit->text().toInt();
    QString nom = ui->nomLineEdit->text();
    QString prenom = ui->prenomLineEdit->text();
    int age = ui->ageLineEdit->text().toInt();
    double salaire = ui->salaireLineEdit->text().toDouble();
    int telephone = ui->telephoneLineEdit->text().toInt();
    QString gmail = ui->gmailLineEdit->text();
    int experience = ui->experienceLineEdit->text().toInt();
    QString etatcivil = ui->etatcivilLineEdit->text();
    QString presence = ui->presenceLineEdit->text();  // Assuming presence is a text
    QString motDePasse = ui->motDePasseLineEdit->text();
    double impot = ui->etatcivilLineEdit->text().toDouble();

    // Create an Employe object with all parameters

    Employe emp( cin, nom, prenom, age, salaire, telephone, gmail, experience, etatcivil, presence, motDePasse, impot);
    // Validate input
    /*

    if (!Employe::ControleSaisir(cin, nom, prenom, age, salaire, telephone, gmail, experience, etatcivil, motDePasse, impot)) {
        return; // Stop execution if validation fails
    }

*/

    // Call the AjouterEmploye function to add the employee
    if (emp.AjouterEmploye()) {
        QMessageBox::information(this, "Succès", "L'employé a été ajouté avec succès !");
        ui->cinLineEdit->clear();
        ui->nomLineEdit->clear();
        ui->prenomLineEdit->clear();
        ui->ageLineEdit->clear();
        ui->salaireLineEdit->clear();
        ui->telephoneLineEdit->clear();
        ui->gmailLineEdit->clear();
        ui->experienceLineEdit->clear();
        ui->etatcivilLineEdit->clear();
        ui->motDePasseLineEdit->clear();
        ui->presenceLineEdit->clear();
        ui->impotLineEdit->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'employé.");
    }

    qDebug() << "Employé ajouté avec CIN:" << cin;
}


void MainWindow::on_on_exitButton_clicked_clicked ()
{
    int ret = QMessageBox::question(this, "Quitter", "Êtes-vous sûr de vouloir quitter ?",
                                    QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        QApplication::quit(); // Close the application
    }
}




void MainWindow::on_TrierButton_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT CIN_EMPLOYE, NOM, PRENOM, AGE, SALAIRE, TELEPHONE, EMAIL, EXPERIENCE, ETAT_CIVIL, PRESENCE, IMPOT "
                    "FROM EMPLOYE ORDER BY SALAIRE ASC");

    if (model->lastError().isValid()) {
        qDebug() << "❌ Erreur lors du tri :" << model->lastError().text();
        delete model;
        QMessageBox::critical(this, "Erreur", "Erreur lors du tri des employés.");
        return;
    }

    ui->trierTableView->setModel(model);
}
void MainWindow::on_ExporterPDFButton_clicked()
{
    // Open file dialog to choose where to save the PDF file
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le fichier PDF", "", "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty())
        return;

    // Set up the printer
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));  // Optional: Set page margins

    // Create the QPainter object for rendering content to the PDF
    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "Erreur", "Impossible de démarrer le rendu du PDF !");
        return;
    }

    // Get the page rectangle for accurate layout
    QRectF pageRect = printer.pageLayout().paintRectPixels(printer.resolution());
    int leftMargin = 500;  // Left margin
    int rightMargin = pageRect.width() - 100;  // Right margin

    // Title setup
    painter.setFont(QFont("Helvetica", 18, QFont::Bold));
    painter.setPen(Qt::black);
    painter.drawText(pageRect, Qt::AlignCenter, "Liste des noms des employés");

    // Date and Time below the title
    QFont italicFont("Helvetica", 12);
    italicFont.setItalic(true);
    painter.setFont(italicFont);
    QString currentDateTime = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
    painter.drawText(pageRect.adjusted(0, 40, -20, 0), Qt::AlignRight, "Date d'enregistrement : " + currentDateTime);

    // Draw a horizontal line to separate title and content
    painter.setPen(QPen(Qt::lightGray, 1, Qt::DashLine));
    painter.drawLine(leftMargin, 160, rightMargin, 160);  // Horizontal line below title

    // Query employee names from the database
    QSqlQuery query;
    if (!query.exec("SELECT NOM FROM EMPLOYE")) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        painter.end();
        return;
    }

    // Table content setup
    int y = 500;  // Starting position for list
    int lineHeight = 250;  // Height for each line of content
    int maxHeight = pageRect.height() - 100;  // Maximum height before starting a new page

    // Table header
    painter.setFont(QFont("Helvetica", 12, QFont::Bold));
    painter.setPen(Qt::black);
    painter.drawText(leftMargin, y, "Nom");
    painter.drawLine(leftMargin, y + 20, rightMargin, y + 10);  // Draw a line below header
    y += lineHeight + 20;  // Adjust for next content

    // Table body setup
    painter.setFont(QFont("Helvetica", 12));  // Set body font
    while (query.next()) {
        // Check if the content exceeds the maxHeight (page limit)
        if (y > maxHeight) {
            printer.newPage();  // Start a new page if the content exceeds current page
            y = 200;  // Reset y position to top of the new page

            // Redraw header on new page
            painter.setFont(QFont("Helvetica", 12, QFont::Bold));
            painter.drawText(leftMargin, y, "Nom");
            painter.drawLine(leftMargin, y + 5, rightMargin, y + 5);  // Header line
            y += lineHeight + 5;  // Adjust for next content

            painter.setFont(QFont("Helvetica", 12));  // Set font for body content again
        }

        // Retrieve the employee name from the query result
        QString nom = query.value(0).toString();
        painter.drawText(leftMargin, y, nom);  // Draw name in table
        y += lineHeight;  // Move to next line
    }

    // End PDF rendering
    painter.end();

    // Inform user of successful PDF export
    QMessageBox::information(this, "Succès", "✅ PDF exporté avec succès !");
}

/*
void MainWindow::on_ExporterPDFButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le fichier PDF", "", "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty())
        return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageMargins(QMarginsF(15, 20, 15, 20), QPageLayout::Millimeter); // Margins

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "Erreur", "Impossible de démarrer le rendu du PDF !");
        return;
    }

    // Setup fonts
    QFont titleFont("Times New Roman", 16, QFont::Bold);
    QFont dateFont("Times New Roman", 10, QFont::StyleItalic);
    QFont listFont("Arial", 11);

    // Draw title
    painter.setFont(titleFont);
    QRectF titleRect = printer.pageRect(QPrinter::Millimeter);
    titleRect.setTop(0);
    titleRect.setHeight(20);
    painter.drawText(titleRect, Qt::AlignCenter, "Liste des noms des employés");

    // Draw date
    painter.setFont(dateFont);
    QString dateText = "Date d'enregistrement : " + QDate::currentDate().toString("dd/MM/yyyy");
    QRectF dateRect = printer.pageRect(QPrinter::Millimeter);
    dateRect.setTop(20);
    dateRect.setHeight(10);
    painter.drawText(dateRect, Qt::AlignCenter, dateText);

    // Query data
    QSqlQuery query;
    if (!query.exec("SELECT NOM FROM EMPLOYE")) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        painter.end();
        return;
    }

    // Draw employee names
    painter.setFont(listFont);
    int y = 40; // mm from top
    const int lineSpacing = 7; // mm
    const int bottomLimit = printer.pageRect(QPrinter::Millimeter).height() - 20;

    while (query.next()) {
        QString nom = query.value(0).toString();
        painter.drawText(QPointF(20, y), "- " + nom);  // 20mm from left

        y += lineSpacing;

        // Check for new page
        if (y > bottomLimit) {
            printer.newPage();
            y = 20;
        }
    }

    painter.end();
    QMessageBox::information(this, "Succès", "✅ PDF exporté avec succès !");
}
*/
void MainWindow::on_StatistiqueButton_clicked()
{
    Employe emp;
    emp.AfficherStatistiques(this);  // Pass `this` as the parent to the dialog
}
void MainWindow::on_on_exitButton_clicked_2_clicked()
{
    int ret = QMessageBox::question(this, "Quitter", "Êtes-vous sûr de vouloir quitter ?",
                                    QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {

        QApplication::quit(); // Close the application
    }
}
void MainWindow::on_pushButton_clicked()
{    Employe emp;

    int cin = ui->cinModifierLineEdit->text().toInt();
    if (!emp.ExisteCIN(cin)) {
        QMessageBox::warning(this, "Erreur", "Cet employé n'existe pas dans la base de données !");
        return;
    }
    else
    {
        on_ModifierEmploye_clicked();

    }


    return ;
}



void MainWindow::on_deconnexionButton_clicked()
{
    this->hide(); // hide the main window
    Dialog *loginWindow = new Dialog(); // reopen the login dialog
    loginWindow->show();
}


void MainWindow::on_tab_client_3_tabBarClicked(int index)
{
    AfficherListeEmploye();  // Load data into TableView

}







void MainWindow::on_ModifierEmploye_clicked() {
    int cin = ui->cinModifierLineEdit->text().toInt();
    QString nom = ui->nomModifierLineEdit->text();
    QString prenom = ui->prenomModifierLineEdit->text();
    int age = ui->ageModifierLineEdit->text().toInt();
    double salaire = ui->salaireModifierLineEdit->text().toDouble();
    int telephone = ui->telephoneModifierLineEdit->text().toInt();
    QString gmail = ui->gmailModifierLineEdit->text();
    int experience = ui->experienceModifierLineEdit->text().toInt();
    QString etatcivil = ui->etatcivilLineEdit->text();
    QString presence = ui->presenceModifierLineEdit->text();
    QString motDePasse = ui->motDePasseLineEdit->text();
    double impot = ui->impotModifierLineEdit->text().toDouble();

    // Create an employee object
    Employe emp(cin,nom, prenom, age, salaire, telephone, gmail, experience, etatcivil, presence, motDePasse, impot);

    // Check if the CIN exists before modification

    // Call the modification function
    if (emp.ModifierEmploye(cin)) {
        QMessageBox::information(this, "Succès", "L'employé a été modifié avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification de l'employé !");
    }
}
void MainWindow::AfficherListeEmploye()
{
    Employe emp;
    QSqlQueryModel* model = emp.AfficherEmploye();  // <- Possibilité ici

    if (model == nullptr) {
        qDebug() << "❌ Error: Model is null!";
        return;
    }

    if (model->lastError().isValid()) {
        qDebug() << "❌ Query Error: " << model->lastError().text();
        return;
    }

    ui->employeTableView->setModel(model);  // <- Si model est supprimé après, crash assuré ici
}




void MainWindow::on_SupprimerEmploye_clicked() {
    int cin1 = ui->cinsupprimerLineEdit->text().toInt();

    if (cin1 == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un CIN valide !");
        return;
    }

    // Create an employee object
    Employe emp1;

    // Check if the CIN exists before attempting deletion
    if (!emp1.ExisteCIN(cin1)) {
        QMessageBox::warning(this, "Erreur", "Cet employé n'existe pas dans la base de données !");
        return;
    }

    // If the CIN exists, proceed with deletion
    if (emp1.SupprimerEmploye(cin1)) {
        QMessageBox::information(this, "Succès", "L'employé a été supprimé avec succès !");
        ui->cinsupprimerLineEdit->clear();  // Clear the CIN input field
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression de l'employé.");
    }
}

void MainWindow::on_on_exitButton_clicked_3_clicked()
{
    int ret = QMessageBox::question(this, "Quitter", "Êtes-vous sûr de vouloir quitter ?",
                                    QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        QApplication::quit(); // Close the application
    }
}

void MainWindow::filterTable(const QString &searchTerm)
{
    // Create a query model to display filtered data
    QSqlQueryModel *model = new QSqlQueryModel(this);

    // Prepare the SQL query with the filtering condition
    QSqlQuery query;
    query.prepare("SELECT CIN_EMPLOYE, NOM, PRENOM, AGE, SALAIRE, TELEPHONE, EMAIL, EXPERIENCE, ETAT_CIVIL FROM EMPLOYE "
                  "WHERE NOM LIKE :searchTerm OR PRENOM LIKE :searchTerm OR EMAIL LIKE :searchTerm");

    query.bindValue(":searchTerm", "%" + searchTerm + "%");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    // Set the model to the query result
    model->setQuery(query);

    // Set the model to the QTableView
    ui->employeTableView->setModel(model);
}

void MainWindow::on_rechercher_textChanged(const QString &arg1)
{
    // Use the trimmed version of the text input for search
    QString searchTerm = arg1.trimmed();
    filterTable(searchTerm);
}




void MainWindow::on_Ajouter_ressource_clicked()
{

    QString nomRessource=ui->NomRessource->text();
    QString typeRessource=ui->TypeRessource->currentText();;
    QString etatRessource="Disponible";
    QDate dateAcquisition=ui->DateAcquisition->date();

    if (nomRessource.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le nom de la ressource est obligatoire.");
    }
    else if(dateAcquisition>QDate::currentDate())
    {
         QMessageBox::warning(this, "Erreur de saisie", "La date d'acquisition doit etre avant la date d'aujourd'hui .");
    }

    else
    {
    Ressource R (typeRessource ,nomRessource ,etatRessource, dateAcquisition);


    bool test=R.AjouterRessource();




    if (test) {
             m_alertClosedManually = false;
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        verifierDisponibiliteRessources();

    } else {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué\n"
                                          "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }

    qDebug() << "Bouton Ajouter Ressource cliqué !";

}
}



void MainWindow::afficherRessources()
{


        //QSqlQueryModel * model = Res.afficherRessource();
       // ui->tableRessource->setModel(model);
        QStandardItemModel *model = Res.afficherRessourceAvecQRCode();

        // Afficher le modèle dans la table
        ui->tableRessource->setModel(model);
        ui->tableRessource->resizeColumnsToContents();
        ui->tableRessource->resizeRowsToContents();
        ui->chercherRESSOURCE->setPlaceholderText("Recherche des ressources par nom");
        ui->tableRessource->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void MainWindow::on_SupprimerRessource_clicked()

{
    int SUPP = ui->ID_ressources->currentText().toInt();
    if (SUPP <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Vous n'avez pas saisi l'ID de ressource a supprimer.");
    }
    else
    {
     QString Type=Res.get_Type();
    bool test = Res.SupprimerRessource(SUPP);

    if (test) {
         m_alertClosedManually = false;
        verifierDisponibiliteRessources();
        QMessageBox::information(nullptr, QObject::tr("Suppression réussie"),
                                 QObject::tr("La ressource a été supprimé avec succès."),
                                 QMessageBox::Ok);
        afficherRessources();
          chargerComboBoxIDS();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Échec de la suppression"),
                              QObject::tr("Erreur lors de la suppression de la ressource."),
                              QMessageBox::Ok);
    }

    qDebug() << "Bouton Supprimer Ressource cliqué !";

    }}




void MainWindow::on_ID_ressources2_currentIndexChanged(int index)
{
    bool ok;
    int idRessource = ui->ID_ressources2->currentText().toInt(&ok);

    if (ok && idRessource > 0) {
        Ressource res = Res.getRessourceById(idRessource);
        if (res.get_idRessource() <= 0) {
            qDebug() << "Erreur : Aucune ressource trouvée pour l'ID" << idRessource;
            return;
        }

        if (res.get_Etat() == "Affecter") {
            ui->IDEmploye->setEnabled(true);
        } else {
            ui->IDEmploye->setEnabled(false);
        }

        // Remplir le QComboBox TypeRessource2 (une seule fois)
        if (ui->TypeRessource2->count() == 0) {
            ui->TypeRessource2->addItem("Imprimante 3D");
            ui->TypeRessource2->addItem("Bureau");
            ui->TypeRessource2->addItem("Ordinateur");
        }

        // Activer les champs de saisie
        ui->TypeRessource2->setEnabled(true);
        ui->NomRessource2->setEnabled(true);
        ui->etat->setEnabled(true);
        ui->DateAcquisition2->setEnabled(true);
        ui->ModifierRessource->setEnabled(true);

        // Afficher les données dans les champs de saisie
        int typeIndex = ui->TypeRessource2->findText(res.get_Type());
        if (typeIndex != -1) {
            ui->TypeRessource2->setCurrentIndex(typeIndex);
        } else {
            qDebug() << "Erreur : Le type" << res.get_Type() << "n'existe pas dans le QComboBox.";
        }

        ui->NomRessource2->setText(res.get_nomRessource());

        // Sélectionner le bon QRadioButton en fonction de l'état
        QString etat = res.get_Etat();
        if (etat == "Disponible") {
            ui->Disponible->setChecked(true);
        } else if (etat == "En panne") {
            ui->Enpanne->setChecked(true);
        } else if (etat == "Affecter") {
            ui->Enexploitation->setChecked(true);
            ui->IDEmploye->setEnabled(true);
            int CINIndex = ui->IDEmploye->findData(res.get_idEmploye());
             ui->IDEmploye->setCurrentIndex(CINIndex);
        }

        ui->DateAcquisition2->setDate(res.get_DateAcquisition());

    } else {
        // Désactiver les champs de saisie si aucun ID n'est sélectionné
        ui->TypeRessource2->setEnabled(false);
        ui->NomRessource2->setEnabled(false);
        ui->etat->setEnabled(false);
        ui->DateAcquisition2->setEnabled(false);
        ui->ModifierRessource->setEnabled(false);
        ui->IDEmploye->setEnabled(false);

        // Effacer les champs de saisie
        ui->TypeRessource2->clear();
        ui->NomRessource2->clear();

        // Désélectionner tous les QRadioButton
        ui->Disponible->setAutoExclusive(false);
        ui->Disponible->setChecked(false);
        ui->Enpanne->setChecked(false);
        ui->Enexploitation->setChecked(false);
        ui->Disponible->setAutoExclusive(true);

        // Réinitialiser la date
        ui->DateAcquisition2->setDate(QDate::currentDate());
    }
}

void MainWindow::on_Enexploitation_toggled(bool checked)
{
    if (checked) {
        ui->IDEmploye->setEnabled(true);
    } else {
        ui->IDEmploye->setEnabled(false);
    }
}

void MainWindow::on_ModifierRessource_clicked()
{
    int idRessource = ui->ID_ressources2->currentText().toInt();
    // Récupérer les nouvelles valeurs depuis les champs de saisie
    QString type = ui->TypeRessource2->currentText();
    QString nom = ui->NomRessource2->text();
    QString etat;
    int employeId=NULL;

    // Déterminer l'état sélectionné
    if (ui->Disponible->isChecked()) {
        etat = "Disponible";

    } else if (ui->Enpanne->isChecked()) {
        etat = "En panne";

    } else if (ui->Enexploitation->isChecked()) {
        etat = "Affecter";
        bool ok;
         employeId = ui->IDEmploye->currentText().toInt(&ok);

    }

    QDate dateAcquisition = ui->DateAcquisition2->date();
 int idEmploye = ui->IDEmploye->currentText().toInt();
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le nom de la ressource est obligatoire.");

    }else if (etat == "Affecter" && idEmploye <= 0) {
                QMessageBox::warning(this, "Erreur de saisie", "Veuillez choisir un ID d'employé valide lorsque l'état est 'Affecter'.");
                return;
            }
    else if(dateAcquisition>QDate::currentDate())
    {
        QMessageBox::warning(this, "Erreur de saisie", "La date d'acquisition doit etre avant la date d'aujourd'hui .");
    }
     else {
        // Créer un objet Ressource avec les nouvelles valeurs
        Ressource ressource;
        ressource.setIdEmploye(employeId);
        ressource.setIdRessource(idRessource);
        ressource.setType(type);
        ressource.setNomRessource(nom);
        ressource.setEtat(etat);
        ressource.setDateAcquisition(dateAcquisition);
        if (Res.modifierRessource(ressource)) {
             m_alertClosedManually = false;
            verifierDisponibiliteRessources();

            QMessageBox::information(this, "Succès", "La ressource a été modifiée avec succès !");
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de la modification de la ressource.");
        }
    }
}


void MainWindow::on_QuitterModifRessource_clicked()
{
    ui->tab_ressource->setCurrentWidget(ui->AfficherRessources);
}


void MainWindow::on_QuitterSuppRessource_clicked()
{
    ui->tab_ressource->setCurrentWidget(ui->AfficherRessources);
}


void MainWindow::on_QuitterAjoutRessource_clicked()
{
    ui->tab_ressource->setCurrentWidget(ui->AfficherRessources);
}

//Metier Statistique
void MainWindow::afficherStatistiquesTypes()
{
    QLayout *layout = ui->statistiqueRessources->layout();
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0))) {
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
    }

    // Récupérer les statistiques des types de ressources
    QMap<QString, int> statistiques = Res.getStatistiquesTypes();

    // Calculer le total pour les pourcentages
    int total = 0;
    for (auto it = statistiques.begin(); it != statistiques.end(); ++it) {
        total += it.value();
    }

    // Créer un ensemble de barres
    QBarSet *barSet = new QBarSet("Types de ressources");

    // Ajouter les données à l'ensemble de barres
    for (auto it = statistiques.begin(); it != statistiques.end(); ++it) {
        *barSet << it.value();
    }

    // Créer une série de barres
    QBarSeries *barSeries = new QBarSeries();
    barSeries->append(barSet);

    // Connecter le signal hovered pour afficher le pourcentage
    QObject::connect(barSeries, &QBarSeries::hovered, [=](bool status, int index, QBarSet *barset) {
        if (status) { // Si la souris est sur la barre
            int value = barset->at(index);
            double percentage = (total > 0) ? (value * 100.0 / total) : 0;

            // Afficher une infobulle avec le pourcentage
            QToolTip::showText(QCursor::pos(),
                               QString("%1\n%2 occurrences\n%3% du total")
                                   .arg(statistiques.keys().at(index))
                                   .arg(value)
                                   .arg(QString::number(percentage, 'f', 1)));
        } else {
            QToolTip::hideText();
        }
    });

    // Créer un graphique
    QChart *chart = new QChart();
    chart->addSeries(barSeries);
    chart->setTitle("Statistiques des types de ressources");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Axes
    QStringList categories;
    for (auto it = statistiques.begin(); it != statistiques.end(); ++it) {
        categories << it.key();
    }
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    // Afficher le graphique dans une vue
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Ajouter la vue du graphique au QWidget
    if (ui->statistiqueRessources->layout()) {
        ui->statistiqueRessources->layout()->addWidget(chartView);
    } else {
        QVBoxLayout *layout = new QVBoxLayout(ui->statistiqueRessources);
        layout->addWidget(chartView);
        ui->statistiqueRessources->setLayout(layout);
    }
}



void MainWindow::verifierDisponibiliteRessources() {
    if (m_alertClosedManually) {
        return;
    }
    QStringList types = {"Ordinateur", "Bureau", "Imprimante 3D"};
    QStringList indisponibles;

    // Vérifier quelles ressources sont indisponibles
    for (const QString &type : types)
    {
        int count = Res.compterRessourcesDisponibles(type);
        if (count == 0)
            indisponibles << type;
    }

    // Si aucune ressource n'est indisponible, fermer l'alerte si elle existe
    if (indisponibles.isEmpty())
    {
        if (m_currentAlert)
        {
            m_currentAlert->close();
            m_currentAlert = nullptr;
        }
        return;
    }

    // Si l'alerte existe déjà, mettre à jour la liste
    if (m_currentAlert)
    {
        QListWidget *list = m_currentAlert->findChild<QListWidget*>();
        if (list)
        {
            list->clear();
            for (const QString &res : indisponibles)
            {
                QListWidgetItem *item = new QListWidgetItem("• " + res);
                item->setForeground(QColor("#b71c1c"));
                list->addItem(item);
            }
        }
        return;
    }

    // Sinon, créer une nouvelle alerte
    m_currentAlert = new QDialog(this, Qt::Tool | Qt::WindowStaysOnTopHint);
    m_currentAlert->setAttribute(Qt::WA_DeleteOnClose);
    m_currentAlert->setWindowTitle("⚠ ALERTE D'INDISPONIBILITÉ");
    m_currentAlert->setFixedSize(330, 190);

    m_currentAlert->setStyleSheet(R"(
        QDialog {
            background-color: #ffebee;
            border: 2px solid #f44336;
            border-radius: 6px;
        }
        QLabel {
            color: #d32f2f;
            font-weight: bold;
        }
        QPushButton {
            background-color: #f44336;
            color: white;
            padding: 6px 15px;
            border-radius: 3px;
            min-width: 80px;
            font-weight: bold;
        }
        QPushButton:hover {
            background-color: #e53935;
        }
        QListWidget {
            background-color: #fff0f0;
            border: 1px solid #ffcdd2;
            outline: 0;
            border-radius: 4px;
        }
    )");

    QVBoxLayout *layout = new QVBoxLayout(m_currentAlert);

    // Titre animé
    QGraphicsScene *scene = new QGraphicsScene(m_currentAlert);
    QGraphicsView *view = new QGraphicsView(scene, m_currentAlert);
    view->setStyleSheet("background: transparent; border: none;");
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setRenderHint(QPainter::Antialiasing);
    view->setAlignment(Qt::AlignCenter);

    QLabel *title = new QLabel("<h3 style='color:#d32f2f;'>⚠ RESSOURCES INDISPONIBLES</h3>");
    title->setAlignment(Qt::AlignCenter);
    title->setFixedWidth(300);

    QGraphicsProxyWidget *proxy = scene->addWidget(title);
    proxy->setTransformOriginPoint(proxy->boundingRect().center());

    view->setFixedHeight(title->sizeHint().height() + 10);
    view->setFixedWidth(m_currentAlert->width() - 20);
    layout->addWidget(view);

    // Animation de zoom
    QPropertyAnimation *zoomAnimation = new QPropertyAnimation(proxy, "scale");
    zoomAnimation->setDuration(1000);
    zoomAnimation->setStartValue(1.0);
    zoomAnimation->setKeyValueAt(0.5, 1.15);
    zoomAnimation->setEndValue(1.0);
    zoomAnimation->setEasingCurve(QEasingCurve::InOutQuad);
    zoomAnimation->setLoopCount(-1);
    zoomAnimation->start();

    // Animation de couleur
    QTimer *colorTimer = new QTimer(m_currentAlert);
    bool isHighlighted = false;
    connect(colorTimer, &QTimer::timeout, [title, &isHighlighted]() {
        isHighlighted = !isHighlighted;
        title->setStyleSheet(isHighlighted ? "color: #ff2b00; font-weight: bold;" : "color: #8b160b; font-weight: bold;");
    });
    colorTimer->start(600);
    connect(m_currentAlert, &QDialog::finished, colorTimer, &QTimer::stop);

    layout->addWidget(new QLabel("<p>Les ressources suivantes sont complètement réservées :</p>"));

    QListWidget *list = new QListWidget();
    for (const QString &res : indisponibles)
    {
        QListWidgetItem *item = new QListWidgetItem("• " + res);
        item->setForeground(QColor("#b71c1c"));
        list->addItem(item);
    }
    layout->addWidget(list);

    // Son d'alerte
    QSoundEffect *alertSound = new QSoundEffect(this);
    alertSound->setSource(QUrl::fromLocalFile("../alerte.wav"));
    alertSound->setVolume(0.8f);
    alertSound->play();

    QPushButton *closeBtn = new QPushButton("Fermer");
    connect(closeBtn, &QPushButton::clicked, [this]() {
        m_alertClosedManually = true; // On marque que l'alerte a été fermée manuellement

        QPropertyAnimation *fadeOut = new QPropertyAnimation(this->m_currentAlert, "windowOpacity");
        fadeOut->setDuration(250);
        fadeOut->setStartValue(1);
        fadeOut->setEndValue(0);
        connect(fadeOut, &QPropertyAnimation::finished, m_currentAlert, &QDialog::close);
        fadeOut->start(QAbstractAnimation::DeleteWhenStopped);
    });

    layout->addWidget(closeBtn, 0, Qt::AlignRight);

    // Positionnement en bas à droite
    QRect ecran = QGuiApplication::primaryScreen()->geometry();
    m_currentAlert->move(ecran.right() - m_currentAlert->width() - 20,
                         ecran.bottom() - m_currentAlert->height() - 80);

    // Animation d'apparition
    m_currentAlert->setWindowOpacity(0);
    QPropertyAnimation *fadeIn = new QPropertyAnimation(m_currentAlert, "windowOpacity");
    fadeIn->setDuration(300);
    fadeIn->setStartValue(0);
    fadeIn->setEndValue(1);

    QPropertyAnimation *slide = new QPropertyAnimation(m_currentAlert, "geometry");
    slide->setDuration(500);
    QRect startGeometry = m_currentAlert->geometry();
    startGeometry.moveRight(ecran.right() + 50);
    slide->setStartValue(startGeometry);
    slide->setEndValue(m_currentAlert->geometry());
    slide->setEasingCurve(QEasingCurve::OutBack);

    // Animation de secousse
    QPropertyAnimation *shake = new QPropertyAnimation(m_currentAlert, "pos");
    shake->setDuration(200);
    QPoint basePos = m_currentAlert->pos();
    QList<QPoint> shakePoints = {basePos, basePos + QPoint(-5, 0), basePos + QPoint(5, 0),
                                 basePos + QPoint(-3, 0), basePos + QPoint(3, 0), basePos};
    for (int i = 0; i < shakePoints.size(); i++)
        shake->setKeyValueAt(i / static_cast<double>(shakePoints.size() - 1), shakePoints.at(i));

    QSequentialAnimationGroup *seqAnim = new QSequentialAnimationGroup(m_currentAlert);
    seqAnim->addAnimation(slide);
    seqAnim->addAnimation(fadeIn);
    seqAnim->addAnimation(shake);

    connect(closeBtn, &QPushButton::clicked, [this]() {
        QPropertyAnimation *fadeOut = new QPropertyAnimation(this->m_currentAlert, "windowOpacity");
        fadeOut->setDuration(250);
        fadeOut->setStartValue(1);
        fadeOut->setEndValue(0);
        connect(fadeOut, &QPropertyAnimation::finished, m_currentAlert, &QDialog::close);
        fadeOut->start(QAbstractAnimation::DeleteWhenStopped);
    });

    connect(m_currentAlert, &QDialog::destroyed, [this]() {
        m_currentAlert = nullptr;
    });

    m_currentAlert->show();
    seqAnim->start();
}

//Metier Recherche
void MainWindow::on_chercherRESSOURCE_textChanged(const QString &arg1)
{
   QString nomRecherche = ui->chercherRESSOURCE->text().trimmed();
        QStandardItemModel* nouveauModel = nullptr;

        if (nomRecherche.isEmpty()) {

            nouveauModel = Ressource::afficherRessourceAvecQRCode();
        } else {

            nouveauModel = Ressource::chercher(nomRecherche);
        }

        // Vérifier si le modèle est valide
        if (!nouveauModel) {
            qDebug() << "Erreur : modèle non valide.";
            return;
        }

        // Définir le nouveau modèle dans la vue
        ui->tableRessource->setModel(nouveauModel);

        // Ajuster la largeur des colonnes pour s'adapter au contenu
        ui->tableRessource->resizeColumnsToContents();

        // Ajuster la hauteur des lignes pour s'adapter au contenu (si nécessaire)
        ui->tableRessource->resizeRowsToContents();
        if (nouveauModel->rowCount() == 0) {
            QMessageBox::information(this, "Information", "Aucune ressource trouvée.");
            afficherRessources();
        }

    }


//Metier PDF
 void MainWindow::on_CherRessourceNom_2_clicked()
    {

        QSqlQueryModel *model = Res.afficherRessource();

         DialogRessource dialog;
        dialog.genererPDF(model);  // Génère et affiche le PDF
        dialog.exec();             // Affiche la fenêtre modale
        dialog.deleteLater();      // Nettoyage mémoire

        delete model;  // Nettoyage du modèle

    }

//Metier tri
 void MainWindow::chargerComboBoxtriRessources() {
        ui->trie_ressource->clear();
        ui->trie_ressource->addItem("trier ressource par");
        ui->trie_ressource->setItemData(0, QVariant(0), Qt::UserRole - 1);
        ui->trie_ressource->addItem("Nom Ressource ▲");
          ui->trie_ressource->addItem("Nom Ressource ▼");
         ui->trie_ressource->addItem("ID Ressource ▲");
          ui->trie_ressource->addItem("ID Ressource ▼");
          ui->trie_ressource->addItem("Date d'acquisition ▲");
          ui->trie_ressource->addItem("Date d'acquisition ▼");}

 void MainWindow::on_trie_ressource_currentIndexChanged(int index)
 {
     if (index == 0) {
         QStandardItemModel *model = Res.afficherRessourceAvecQRCode();
         ui->tableRessource->setModel(model);
         return;
     }

     QString colonne;
     bool croissant;

     switch(index) {
     case 1: colonne = "NOM_RESSOURCE"; croissant = true; break;
     case 2: colonne = "NOM_RESSOURCE"; croissant = false; break;
     case 3: colonne = "ID_RESSOURCE"; croissant = true; break;
     case 4: colonne = "ID_RESSOURCE"; croissant = false; break;
     case 5: colonne = "DATE_AQCISITION"; croissant = true; break;
     case 6: colonne = "DATE_AQCISITION"; croissant = false; break;
     }

     QStandardItemModel *model = Res.trierRessourcesAvecQRCode(colonne, croissant);
     ui->tableRessource->setModel(model);
     ui->tableRessource->resizeColumnsToContents();
     ui->tableRessource->resizeRowsToContents();
 }


 void MainWindow::gestionRessources()
 {
     chargerComboBoxIDS();
     chargerComboBoxIDM();
     afficherRessources();
     afficherStatistiquesTypes();
     verifierDisponibiliteRessources();
     chargerComboBoxtriRessources();
       chargerComboBoxCIN_Employe();

 }

//**************************************************************************************************************************************************

 void MainWindow::on_stackedWidget_currentChanged(int arg1)
 {

 }


 // RENDEZVOUS
 void MainWindow::on_AjouterRV_clicked()
 {
     QString ID = ui->ID_RV->text();  // ID_RENDEZVOUS
     QString CINE = ui->CINE_RV->text();  // CIN_EMPLOYE
     QString CINC = ui->CINC_RV->text();  // CIN_CLIENT
     QString LIEU = ui->LIEU_RV->text();  // LIEU
     QString DATE = ui->DATE_RV->text();  // DT
     QString STATUT = ui->STATUT_RV->text();  // STATUT

     if(ID.isEmpty() || CINE.isEmpty() || CINC.isEmpty() || LIEU.isEmpty() || DATE.isEmpty() || STATUT.isEmpty())
     {
         QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs avant d'ajouter un rendez-vous.");
         return;
     }

     bool test1, test2, test3;
     int id = ID.toInt(&test1);
     int cine = CINE.toInt(&test2);
     int cinc = CINC.toInt(&test3);

     if(!test1 || !test2 || !test3)
     {
         QMessageBox::warning(this, "Erreur de saisie", "L'ID, CIN Employé et CIN Client doivent étre des nombres.");
         return;
     }

     QDateTime dateTime = QDateTime::fromString(DATE, "dd/MM/yyyy");
     if(!dateTime.isValid())
     {
         QMessageBox::warning(this, "Format de date incorrect", "La date doit étre au format DD/MM/YYYY");
         return;
     }

     QStringList statutValide= {"Prévu", "Confirmé", "Annulé"};
     if(!statutValide.contains(STATUT))
     {
         QMessageBox::warning(this, "Statut invalide", "Le statut doit étre 'Prévu', 'Confirmé' ou 'Annulé'.");
         return;
     }

     if(LIEU.length()<3)
     {
         QMessageBox::warning(this, "Erreur de saisie", "Le lieu doit contenir au moins 3 caractéres.");
         return;
     }

     RendezVous RV(id, cine, cinc, LIEU, DATE, STATUT);

     bool test = RV.AjouterRendezVous();

     if (test) {
         ui->tableView2RV->setModel(Rv.AfficherRendezVous());
         QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("Ajout effectué\n"
                                              "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
         rdvParJour = RendezVous().recupererNombreRendezVousParDate();
         displayCalendar();
     } else {
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("Ajout non effectué\n"
                                           "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
     }

     qDebug() << "Bouton Ajouter RendezVous cliqué !";
 }

 void MainWindow::on_ModifierRV_clicked()
 {
     QString ID2=ui->ID2_RV->text();
     QString CINE2=ui->CINE2_RV->text();
     QString CINC2=ui->CINC2_RV->text();
     QString LIEU2=ui->LIEU2_RV->text();
     QString DATE2=ui->DATE2_RV->text();
     QString STATUT2=ui->STATUT2_RV->text();

     if(ID2.isEmpty() || CINE2.isEmpty() || CINC2.isEmpty() || LIEU2.isEmpty() || DATE2.isEmpty() || STATUT2.isEmpty())
     {
         QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs avant d'ajouter un rendez-vous.");
         return;
     }

     bool testv1, testv2, testv3;
     int id2 = ID2.toInt(&testv1);
     int cine2 = CINE2.toInt(&testv2);
     int cinc2 = CINC2.toInt(&testv3);

     if(!testv1 || !testv2 || !testv3)
     {
         QMessageBox::warning(this, "Erreur de saisie", "L'ID, CIN Employé et CIN Client doivent étre des nombres.");
         return;
     }

     QDateTime dateTime2 = QDateTime::fromString(DATE2, "dd/mm/yyyy");
     if(!dateTime2.isValid())
     {
         QMessageBox::warning(this, "Format de date incorrect", "La date doit étre au format DD/MM/YYYY");
         return;
     }

     QStringList statutValide2= {"Prévu", "Confirmé", "Annulé"};
     if(!statutValide2.contains(STATUT2))
     {
         QMessageBox::warning(this, "Statut invalide", "Le statut doit étre 'Prévu', 'Confirmé' ou 'Annulé'.");
         return;
     }

     if(LIEU2.length()<3)
     {
         QMessageBox::warning(this, "Erreur de saisie", "Le lieu doit contenir au moins 3 caractéres.");
         return;
     }

     RendezVous RV(id2, cine2, cinc2, LIEU2, DATE2, STATUT2);
     bool test=RV.ModifierRendezVous();
     if (test) {
         ui->tableView2RV->setModel(Rv.AfficherRendezVous());
         QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("Modification effectué\n"
                                              "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
         rdvParJour = RendezVous().recupererNombreRendezVousParDate();
         displayCalendar();

     } else {
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("Modification non effectué\n"
                                           "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
     }

 }

 void MainWindow::on_tableView2RV_doubleClicked(const QModelIndex &index)
 {

     int row = index.row();

     // Récupère les données de chaque colonne
     QString id = ui->tableView2RV->model()->index(row, 0).data().toString();
     QString cin_employe = ui->tableView2RV->model()->index(row, 1).data().toString();
     QString cin_client = ui->tableView2RV->model()->index(row, 2).data().toString();
     QString lieu = ui->tableView2RV->model()->index(row, 3).data().toString();
     QString dt = ui->tableView2RV->model()->index(row, 4).data().toString();
     QString statut = ui->tableView2RV->model()->index(row, 5).data().toString();

     // Affiche les données dans les QLineEdit
     ui->ID2_RV->setText(id);
     ui->CINE2_RV->setText(cin_employe);
     ui->CINC2_RV->setText(cin_client);
     ui->LIEU2_RV->setText(lieu);
     ui->DATE2_RV->setText(dt);
     ui->STATUT2_RV->setText(statut);
     ui->TabRV->setCurrentIndex(2);

 }


 void MainWindow::on_SupprimerRV_clicked()
 {
     int SUPP = ui->SUPP_RV->text().toInt();  // Récupérer l'ID depuis l'interface utilisateur

     bool test = Rv.SupprimerRendezVous(SUPP);

     if (test) {
         ui->tableView2RV->setModel(Rv.AfficherRendezVous());
         QMessageBox::information(nullptr, QObject::tr("Suppression réussie"),
                                  QObject::tr("Le rendez-vous a été supprimé avec succès."),
                                  QMessageBox::Ok);
         rdvParJour = RendezVous().recupererNombreRendezVousParDate();
         displayCalendar();

     } else {
         QMessageBox::critical(nullptr, QObject::tr("Échec de la suppression"),
                               QObject::tr("Erreur lors de la suppression du rendez-vous."),
                               QMessageBox::Ok);
     }

     qDebug() << "Bouton Supprimer RendezVous cliqué !";
 }

 void MainWindow::on_afficherRV_clicked()
 {
     QSqlQueryModel* model = new QSqlQueryModel();
     RendezVous r;

     model = r.AfficherRendezVous();

     ui->tableView2RV->setModel(model);

     for (int i = 0; i < model->rowCount(); ++i) {
         ui->tableView2RV->setRowHidden(i, false); // Montrer toutes les lignes
     }

     r.trierParId(ui->tableView2RV);
 }




 void MainWindow::on_chercherRV_clicked()
 {
     QString texteRecherche = ui->rechercheRV->text();  // Récupérer le texte de recherche

     if (texteRecherche.isEmpty()) {
         QMessageBox::warning(this, "Erreur", "Veuillez entrer un texte à rechercher.");
         return;
     }

     RendezVous r;
     r.rechercher(ui->tableView2RV, texteRecherche);
 }

 void MainWindow::on_exporterRV_clicked()
 {
     RendezVous r;

     r.exporter(ui->tableView2RV);

     QMessageBox::information(this, "Succès", "Le fichier CSV a été exporté avec succès.");
 }

 void MainWindow::on_statRV_clicked()
 {
     RendezVous r;
     r.afficherStatistiques();
 }

 void MainWindow::afficherNotification(const QString &message)
 {
     QWidget *notification = new QWidget(nullptr, Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
     notification->setAttribute(Qt::WA_TranslucentBackground);
     notification->setStyleSheet("background-color: rgba(0, 0, 0, 180); color: white; "
                                 "border-radius: 10px; padding: 10px; font-size: 14px;");

     QLabel *label = new QLabel(message, notification);
     label->setAlignment(Qt::AlignCenter);

     QVBoxLayout *layout = new QVBoxLayout(notification);
     layout->addWidget(label);
     notification->setLayout(layout);

     notification->resize(250, 60);

     // Position en bas à droite de l'écran
     QRect screenGeometry = QGuiApplication::primaryScreen()->availableGeometry();
     int x = screenGeometry.right() - notification->width() - 20;
     int y = screenGeometry.bottom() - notification->height() - 238;
     notification->move(x, y);

     notification->show();

     // Disparition automatique après 3 secondes
     QTimer::singleShot(5000, notification, &QWidget::close);
 }


 void MainWindow::afficherRendezVousAujourdHui()
 {
     RendezVous r;
     int nombreRendezVous = r.compterRendezVousDuJour();

     QString message = QString("Vous avez %1 rendez-vous aujourd'hui").arg(nombreRendezVous);
     afficherNotification(message);

 }

 void MainWindow::displayCalendar()
 {
     ui->graphicsViewCal_RV->scene()->clear();

     QString monthName = currentDate.toString("MMMM yyyy");

     QGraphicsTextItem *monthLabel = new QGraphicsTextItem(monthName);
     monthLabel->setPos(100, 10);
     ui->graphicsViewCal_RV->scene()->addItem(monthLabel);

     QStringList daysOfWeek = {"Lun", "Mar", "Mer", "Jeu", "Ven", "Sam", "Dim"};
     int xOffset = 20;
     int yOffset = 50;

     for (int i = 0; i < 7; ++i) {
         QGraphicsTextItem *dayOfWeekLabel = new QGraphicsTextItem(daysOfWeek[i]);
         dayOfWeekLabel->setPos(xOffset + i * 50, yOffset);
         ui->graphicsViewCal_RV->scene()->addItem(dayOfWeekLabel);
     }

     QDate firstOfMonth(currentDate.year(), currentDate.month(), 1);
     int firstDayOfWeek = firstOfMonth.dayOfWeek();
     int daysInMonth = currentDate.daysInMonth();

     RendezVous r;
     QMap<QDate, int> rdvParJour = r.recupererNombreRendezVousParDate(); // Fonction à ajouter dans rendezvous.cpp


     int dayX = 20;
     int dayY = yOffset + 20;
     for (int i = 1; i <= daysInMonth; ++i) {
         int col = (firstDayOfWeek - 1 + i - 1) % 7;
         int row = (firstDayOfWeek - 1 + i - 1) / 7;

         QPointF dayPos(dayX + col * 50, dayY + row * 50);

         QGraphicsTextItem *dayItem = new QGraphicsTextItem(QString::number(i));
         dayItem->setPos(dayPos);
         ui->graphicsViewCal_RV->scene()->addItem(dayItem);

         QDate currentDay(currentDate.year(), currentDate.month(), i);
         if (rdvParJour.contains(currentDay)) {
             QGraphicsEllipseItem *circle = new QGraphicsEllipseItem(dayPos.x(), dayPos.y() + 20, 10, 10);
             circle->setBrush(Qt::blue);
             circle->setPen(Qt::NoPen);
             ui->graphicsViewCal_RV->scene()->addItem(circle);
         }
     }
 }

 void MainWindow::previousMonth()
 {
     currentDate = currentDate.addMonths(-1);
     displayCalendar();
 }

 void MainWindow::nextMonth()
 {
     currentDate = currentDate.addMonths(1);
     displayCalendar();
 }
 //RENDEZVOUS

 void MainWindow::on_AjouterProjet_clicked()
 {
     QString nom = ui->nom_projet_3->text();
     QString etat = ui->etat_projet_3->currentText();
     QString description = ui->description_3->text();
     int id_projet=0;
     bool okBudget, okCin,valide=true;
     float budget = ui->budget_3->text().toFloat(&okBudget);
     int cin = ui->cin_client_3->text().toInt(&okCin);
     QString date_debut_str = ui->date_debut_3->text();
     QString date_fin_str = ui->date_fin_3->text();
     bool okLatitude, okLongitude;
     float latitude = ui->latitude->text().toFloat(&okLatitude);
     float longitude = ui->longitude->text().toFloat(&okLongitude);


     QDateTime date_debut = QDateTime::fromString(date_debut_str, "dd/mm/yyyy");
     QDateTime date_fin = QDateTime::fromString(date_fin_str, "dd/mm/yyyy");

     if (!okLatitude || !okLongitude) {
         QMessageBox::warning(this, "Erreur de saisie", "La latitude et la longitude doivent être des nombres valides.");
         return;
     }
     if (latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180) {
         QMessageBox::warning(this, "Erreur", "Les coordonnées sont hors limites géographiques valides.");
         return;
     }

     if(nom.isEmpty() || description.isEmpty() || date_debut_str.isEmpty() || date_fin_str.isEmpty()) {
         QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
         return;
     }

     if (!okBudget || !okCin) {
         QMessageBox::warning(this, "Erreur de saisie", "Le budget et le CIN client doivent être des nombres valides.");
         return;
     }

     QSqlQuery query;
     do {
         id_projet++;
         query.prepare("SELECT COUNT(*) FROM projet WHERE id_projet = :id_projet");
         query.bindValue(":id_projet", id_projet);

         if (query.exec()) {
             if (query.next()) {
                 int count = query.value(0).toInt();
                 valide = (count == 0);
             }}
     }while(!valide);
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
     if (!date_debut.isValid() || !date_fin.isValid()) {
         QMessageBox::warning(this, "Format de date incorrect", "Veuillez entrer les dates au format DD/MM/YYYY.");
         return;
     }

     if (date_debut > date_fin) {
         QMessageBox::warning(this, "Erreur de date", "La date de début doit être antérieure à la date de fin.");
         return;
     }

     Projet p(id_projet,nom, description, budget, date_debut_str, date_fin_str, cin,etat,latitude,longitude);
     bool success = p.ajouterProjet();

     if (success) {
         ui->tableViewProjets->setModel(projet.afficherProjets());
         QMessageBox::information(this, "Succès", "Projet ajouté avec succès !");
         ui->nom_projet_3->clear();
         ui->description_3->clear();
         ui->budget_3->clear();
         ui->cin_client_3->clear();
         ui->date_debut_3->clear();
         ui->date_fin_3->clear();
         ui->latitude->clear();
         ui->longitude->clear();
         afficherStatistiquesEtat();
         m_projetModel->refreshProjets();
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
     QString etat = ui->tableViewProjets->model()->index(row, 7).data().toString();
     float latitude = ui->tableViewProjets->model()->index(row, 8).data().toFloat();
     float longitude = ui->tableViewProjets->model()->index(row, 9).data().toFloat();
     Projet p(id, nom, description, budget, date_debut, date_fin, cin_client,etat,latitude,longitude);

     ModifierProjetDialog dialog(this);
     dialog.setProjet(p);

     if (dialog.exec() == QDialog::Accepted) {
         ui->tableViewProjets->setModel(projet.afficherProjets());
         afficherStatistiquesEtat();
         m_projetModel->refreshProjets();
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
         afficherStatistiquesEtat();
         QMessageBox::information(this, "Succès", "Projet supprimé avec succès !");
         m_projetModel->refreshProjets();
     } else {
         QMessageBox::critical(this, "Erreur", "La suppression du projet a échoué.");
     }
 }
 void MainWindow::on_AnnulerProjet_clicked()
 {
     ui->nom_projet_3->clear();
     ui->description_3->clear();
     ui->budget_3->clear();
     ui->cin_client_3->clear();
     ui->date_debut_3->clear();
     ui->date_fin_3->clear();
     ui->latitude->clear();
     ui->longitude->clear();
 }
 void MainWindow::on_rechercheprojet_textChanged(const QString &text)
 {
     ui->tableViewProjets->setModel(projet.rechercherProjetsParNom(text));
 }

 void MainWindow::on_downloadprojet_clicked()
 {
     QModelIndex index = ui->tableViewProjets->currentIndex();
     if (!index.isValid()) {
         QMessageBox::warning(this, "Aucun projet sélectionné", "Veuillez sélectionner un projet dans la table.");
         return;
     }

     int row = index.row();
     QString nom = ui->tableViewProjets->model()->index(row, 1).data().toString();
     QString description = ui->tableViewProjets->model()->index(row, 2).data().toString();
     float budget = ui->tableViewProjets->model()->index(row, 3).data().toFloat();
     QString date_debut = ui->tableViewProjets->model()->index(row, 4).data().toString();
     QString date_fin = ui->tableViewProjets->model()->index(row, 5).data().toString();
     int cin_client = ui->tableViewProjets->model()->index(row, 6).data().toInt();
     QString etat = ui->tableViewProjets->model()->index(row, 7).data().toString();
     float latitude = ui->tableViewProjets->model()->index(row, 8).data().toFloat();
     float longitude = ui->tableViewProjets->model()->index(row, 9).data().toFloat();
     QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer le projet", nom + ".pdf", "PDF Files (*.pdf)");
     if (fileName.isEmpty())
         return;

     QPdfWriter writer(fileName);
     writer.setPageSize(QPageSize(QPageSize::A4));
     writer.setPageMargins(QMarginsF(30, 30, 30, 30));

     QPainter painter(&writer);
     QFont font("Helvetica", 11);
     font.setBold(true);
     painter.setFont(font);

     painter.drawText(100, 100, "📁 Coordonnées du Projet");

     font.setBold(false);
     painter.setFont(font);

     painter.drawText(100, 2000, "🧾 Nom : " + nom);
     painter.drawText(100, 3000, "📄 Description : " + description);
     painter.drawText(100, 4000, "💰 Budget : " + QString::number(budget, 'f', 2));
     painter.drawText(100, 5000, "📅 Date début : " + date_debut);
     painter.drawText(100, 6000, "📅 Date fin : " + date_fin);
     painter.drawText(100, 7000, "🆔 CIN Client : " + QString::number(cin_client));
     painter.drawText(100, 8000, "📌 État : " + etat);
     painter.drawText(100, 9000, "x latitude : " + QString::number(latitude, 'f', 2));
     painter.drawText(100, 10000, "y longitude : " + QString::number(longitude, 'f', 2));
     painter.end();

     QMessageBox::information(this, "PDF Enregistré", "Le projet a été exporté avec succès en PDF.");
 }
 void MainWindow::afficherStatistiquesEtat() {
     QLayout *oldLayout = ui->statistique->layout();
     if (oldLayout != nullptr) {
         QLayoutItem *item;
         while ((item = oldLayout->takeAt(0)) != nullptr) {
             if (QWidget *widget = item->widget()) {
                 widget->deleteLater();
             }
             delete item;
         }
         delete oldLayout;
     }

     QSqlQuery query;
     QMap<QString, int> etatCounts;
     int totalCount = 0;

     if (query.exec("SELECT etat_projet, COUNT(*) FROM projet GROUP BY etat_projet")) {
         while (query.next()) {
             QString etat = query.value(0).toString();
             int count = query.value(1).toInt();
             etatCounts[etat] = count;
             totalCount += count;
         }
     }

     QBarSeries *series = new QBarSeries();
     QBarSet *set = new QBarSet("Projets");

     QStringList categories;
     for (auto it = etatCounts.begin(); it != etatCounts.end(); ++it) {
         *set << it.value();
         categories << it.key();
     }

     series->append(set);

     QChart *barChart = new QChart();
     barChart->addSeries(series);
     barChart->setTitle("Nombre de projets par état");

     QBarCategoryAxis *axis = new QBarCategoryAxis();
     axis->append(categories);
     barChart->createDefaultAxes();
     barChart->setAxisX(axis, series);

     QChartView *barChartView = new QChartView(barChart);
     barChartView->setMinimumHeight(400);
     barChartView->setRenderHint(QPainter::Antialiasing);


     QPieSeries *pieSeries = new QPieSeries();
     for (auto it = etatCounts.begin(); it != etatCounts.end(); ++it) {
         qreal percentage = (qreal)it.value() / totalCount * 100.0;
         pieSeries->append(it.key() + QString(" (%1%)").arg(percentage, 0, 'f', 1), it.value());
     }

     QChart *pieChart = new QChart();
     pieChart->addSeries(pieSeries);
     pieChart->setTitle("Répartition des projets par état");

     QChartView *pieChartView = new QChartView(pieChart);
     pieChartView->setMinimumHeight(400);
     pieChartView->setRenderHint(QPainter::Antialiasing);


     QWidget *contentWidget = new QWidget;
     QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);
     contentLayout->addWidget(barChartView);
     contentLayout->addSpacing(30);
     contentLayout->addWidget(pieChartView);
     contentWidget->setLayout(contentLayout);

     QScrollArea *scrollArea = new QScrollArea(ui->statistique);
     scrollArea->setWidgetResizable(true);
     scrollArea->setWidget(contentWidget);

     QVBoxLayout *statLayout = new QVBoxLayout(ui->statistique);
     statLayout->addWidget(scrollArea);
     ui->statistique->setLayout(statLayout);
 }

 void MainWindow::displayTasks()
 {
     QSqlQuery query;
     query.prepare("SELECT ID_TASK, CONTENU, TYPE FROM TASK WHERE ID_EMPLOYE = :id_employe");
     query.bindValue(":id_employe", employeeId);

     if (query.exec()) {
         QStandardItemModel *todoModel = new QStandardItemModel;
         QStandardItemModel *doingModel = new QStandardItemModel;
         QStandardItemModel *doneModel = new QStandardItemModel;


         todoModel->setHorizontalHeaderLabels({"ID_TASK", "CONTENU"});
         doingModel->setHorizontalHeaderLabels({"ID_TASK", "CONTENU"});
         doneModel->setHorizontalHeaderLabels({"ID_TASK", "CONTENU"});


         while (query.next()) {
             int taskType = query.value("TYPE").toInt();
             QString idTask = query.value("ID_TASK").toString();
             QString contenu = query.value("CONTENU").toString();

             QStandardItem *idItem = new QStandardItem(idTask);
             QStandardItem *contenuItem = new QStandardItem(contenu);

             if (taskType == 1) {
                 todoModel->appendRow({idItem, contenuItem});
             } else if (taskType == 2) {
                 doingModel->appendRow({idItem, contenuItem});
             } else if (taskType == 3) {
                 doneModel->appendRow({idItem, contenuItem});
             }
         }


         ui->todo->setModel(todoModel);
         ui->doing->setModel(doingModel);
         ui->done->setModel(doneModel);


         ui->todo->horizontalHeader()->setVisible(false);
         ui->doing->horizontalHeader()->setVisible(false);
         ui->done->horizontalHeader()->setVisible(false);


         ui->todo->verticalHeader()->setVisible(false);
         ui->doing->verticalHeader()->setVisible(false);
         ui->done->verticalHeader()->setVisible(false);


         ui->todo->setColumnWidth(0, 25);
         ui->doing->setColumnWidth(0, 25);
         ui->done->setColumnWidth(0, 25);
     }
 }



 void MainWindow::clearTables()
 {
     ui->todo->setModel(nullptr);
     ui->doing->setModel(nullptr);
     ui->done->setModel(nullptr);
 }

 void MainWindow::on_add_clicked()
 {
     QString taskContent = ui->task->text();

     if (taskContent.isEmpty() || employeeId == 0) {
         qDebug() << "Empty task or invalid employee ID!";
         return;
     }

     QSqlQuery checkQuery;
     checkQuery.prepare("SELECT COUNT(*) FROM TASK WHERE ID_EMPLOYE = :id_employe AND CONTENU = :contenu");
     checkQuery.bindValue(":id_employe", employeeId);
     checkQuery.bindValue(":contenu", taskContent);

     if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
         QMessageBox::information(this, "Duplicate Task", "ce task exister pour ce employee.");
         return;
     }

     int taskId = generateUniqueTaskId();
     QSqlQuery query;
     query.prepare("INSERT INTO TASK (ID_TASK, CONTENU, ID_EMPLOYE, TYPE) "
                   "VALUES (:id_task, :contenu, :id_employe, :type)");
     query.bindValue(":id_task", taskId);
     query.bindValue(":contenu", taskContent);
     query.bindValue(":id_employe", employeeId);
     query.bindValue(":type", 1);

     if (query.exec()) {
         qDebug() << "Task ajouter avec succe!";
         displayTasks();
         ui->task->clear();
     } else {
         qDebug() << "Error adding task: " << query.lastError().text();
     }
 }

 int MainWindow::generateUniqueTaskId()
 {
     int id_task = 0;
     bool unique = false;

     while (!unique) {
         id_task++;

         QSqlQuery checkQuery;
         checkQuery.prepare("SELECT COUNT(*) FROM TASK WHERE ID_TASK = :id_task");
         checkQuery.bindValue(":id_task", id_task);

         if (checkQuery.exec()) {
             if (checkQuery.next()) {
                 int count = checkQuery.value(0).toInt();
                 unique = (count == 0);
             }
         }
     }

     return id_task;
 }


 void MainWindow::on_movetodoing_clicked()
 {
     QModelIndex selectedIndex= ui->todo->selectionModel()->currentIndex();
     if (selectedIndex.isValid()) {
         int taskId = selectedIndex.siblingAtColumn(0).data().toInt();
         moveTask(2,taskId);
     }}

 void MainWindow::on_movetodone_clicked()
 {
     QModelIndex selectedIndex= ui->doing->selectionModel()->currentIndex();
     if (selectedIndex.isValid()) {
         int taskId = selectedIndex.siblingAtColumn(0).data().toInt();
         moveTask(3,taskId);
     }}
 void MainWindow::moveTask(int newType,int taskId)
 {

     QSqlQuery query;
     query.prepare("UPDATE TASK SET TYPE = :type WHERE ID_TASK = :id_task");
     query.bindValue(":type", newType);
     query.bindValue(":id_task", taskId);

     if (query.exec()) {
         qDebug() << "Task passer avec succee!";
         displayTasks();

     } else {
         qDebug() << "Error moving task: " << query.lastError().text();
     }
 }


 void MainWindow::on_delete_2_clicked()
 {
     QModelIndex selectedIndex = ui->done->selectionModel()->currentIndex();

     if (selectedIndex.isValid()) {
         int taskId = selectedIndex.siblingAtColumn(0).data().toInt();

         QSqlQuery query;
         query.prepare("DELETE FROM TASK WHERE ID_TASK = :id_task");
         query.bindValue(":id_task", taskId);

         if (query.exec()) {
             qDebug() << "Task deleted successfully!";
             displayTasks();
         } else {
             qDebug() << "Error deleting task: " << query.lastError().text();
         }
     }
 }

 void MainWindow::on_recherche_pin_clicked()
 {
     bool okId;
     int id = ui->id_pin->text().toInt(&okId);
     if (!okId) {
         QMessageBox::warning(this, "Erreur de saisie", "L'ID doit être un nombre valide.");
         return;
     }

     QSqlQuery query;
     query.prepare("SELECT LATITUDE, LONGITUDE FROM PROJET WHERE ID_PROJET = :id");
     query.bindValue(":id", id);

     if (query.exec()) {
         if (query.next()) {
             double latitude = query.value(0).toDouble();
             double longitude = query.value(1).toDouble();

             QVariant returnedValue;
             QVariant lat = latitude;
             QVariant lon = longitude;

             QObject *rootObject = ui->quickWidget_MapView->rootObject();
             QMetaObject::invokeMethod(rootObject, "setPinLocation",
                                       Q_RETURN_ARG(QVariant, returnedValue),
                                       Q_ARG(QVariant, lat),
                                       Q_ARG(QVariant, lon));

         } else {
             QMessageBox::warning(this, "Erreur", "Aucun projet trouvé avec cet ID.");
         }
     } else {
         QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
     }
 }


/******yasmine***********************************/

 void MainWindow::on_Ajouter_Partenaire_clicked()
 {
     if (!controleSaisiePartenaire2()) {
         return; // Si la saisie est incorrecte, on ne poursuit pas la modification
     }

     // Récupération des données du formulaire
     int ID_P = ui->id_P->text().toInt();
     QString NOMP = ui->nomP->text();
     QString SPECIALITEP = ui->specialiteP->text();
     QString ADRESSEP = ui->adresseP->text();
     QString TELEPHONEP = ui->telephoneP->text();
     QString MAILP = ui->emailP->text();
     QString CONTRATP = ui->contratP->text();

     // Création de l'objet Partenaire
     Partenaire P(ID_P, NOMP, SPECIALITEP, ADRESSEP, TELEPHONEP, MAILP, CONTRATP);

     // Ajouter le partenaire
     bool test = P.AjouterPartenaire();
     if (test) {
         ui->tableViewP->setModel(Part.afficherP());
         QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("Ajout effectué\n"
                                              "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);

         // Redirection vers le Tab 6
         ui->TabP->setCurrentIndex(6);  // Changer pour Tab 6

         // Mise à jour de ui->phoneLineEdit avec le téléphone du partenaire
         ui->phoneLineEdit->setText("+216" + TELEPHONEP);  // Ajouter le préfixe "+216" au numéro
         ui-> messageTextEdit->setText("Bonjour " + NOMP + ",\n\n"
                                                          "Bienvenue, nous sommes très heureux de notre nouveau partenariat. "
                                                          "Nous espérons vivre une expérience enrichissante et professionnelle ensemble.");

     } else {
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("Ajout non effectué\n"
                                           "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
     }

     qDebug() << "Bouton Ajouter partenaire cliqué !";
 }





 void MainWindow::on_suppP_clicked()
 {
     int id_P=ui->idP_sup->text().toInt();
     bool test=Part.SupprimerPartenaire(id_P);
     if (test) {

         QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("Suppression effectué\n"
                                              "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);

     } else {
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("Suppression non effectué\n"
                                           "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
     }
 }

 bool MainWindow::controleSaisiePartenaire() {
     // Récupérer les valeurs des champs
     QString IDP = ui->id_P_22->text();
     QString NOMP2 = ui->nomP_2->text();
     QString SPECIALETE2 = ui->specialiteP_2->text();
     QString EMAILlP2 = ui->emailP_2->text();
     QString TELEPHONEP2 = ui->telephoneP_2->text();
     QString ADRESSEP2 = ui->adresseP_2->text();
     QString CONTRATP2 = ui->contratP_2->text();

     // Créer des expressions régulières pour chaque champ
     QRegularExpression regexNom("^[A-Za-zÀ-ÖØ-öø-ÿ\\s-]+$");  // Noms et spécialités
     QRegularExpression regexEmail("^[\\w-\\.]+@[\\w-]+\\.[a-z]{2,3}$");  // Email valide
     QRegularExpression regexTelephone("^\\d{8}$");  // Téléphone 8 chiffres

     // Vérifier les champs avec les expressions régulières
     if (IDP.isEmpty() || IDP.toInt() <= 0) {
         QMessageBox::warning(this, "Erreur", "L'ID doit être un nombre positif !");
         return false;
     }

     if (NOMP2.isEmpty() || !regexNom.match(NOMP2).hasMatch()) {
         QMessageBox::warning(this, "Erreur", "Le nom est invalide !");
         return false;
     }

     if (SPECIALETE2.isEmpty() || !regexNom.match(SPECIALETE2).hasMatch()) {
         QMessageBox::warning(this, "Erreur", "La spécialité est invalide !");
         return false;
     }

     if (EMAILlP2.isEmpty() || !EMAILlP2.endsWith("@gmail.com")) {
         QMessageBox::warning(this, "Erreur", "Format invalide d'email !");
         return false;
     }

     if (TELEPHONEP2.length() != 8 || !TELEPHONEP2.toInt()) {
         QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
         return false;
     }

     if (ADRESSEP2.isEmpty()) {
         QMessageBox::warning(this, "Erreur", "L'adresse ne peut pas être vide !");
         return false;
     }

     if (CONTRATP2.isEmpty()) {
         QMessageBox::warning(this, "Erreur", "Le contrat ne peut pas être vide !");
         return false;
     }

     // Si tout est valide
     return true;
 }

 bool MainWindow::controleSaisiePartenaire2() {
     // Récupérer les valeurs des champs
     QString IDP = ui->id_P->text();
     QString NOMP2 = ui->nomP->text();
     QString SPECIALETE2 = ui->specialiteP->text();
     QString EMAILlP2 = ui->emailP->text();
     QString TELEPHONEP2 = ui->telephoneP->text();
     QString ADRESSEP2 = ui->adresseP->text();
     QString CONTRATP2 = ui->contratP->text();

     // Créer des expressions régulières pour chaque champ
     QRegularExpression regexNom("^[A-Za-zÀ-ÖØ-öø-ÿ\\s-]+$");  // Noms et spécialités
     QRegularExpression regexEmail("^[\\w-\\.]+@[\\w-]+\\.[a-z]{2,3}$");  // Email valide
     QRegularExpression regexTelephone("^\\d{8}$");  // Téléphone 8 chiffres

     // Vérifier les champs avec les expressions régulières
     if (IDP.isEmpty() || IDP.toInt() <= 0) {
         QMessageBox::warning(this, "Erreur", "L'ID doit être un nombre positif !");
         return false;
     }

     if (NOMP2.isEmpty() || !regexNom.match(NOMP2).hasMatch()) {
         QMessageBox::warning(this, "Erreur", "Le nom est invalide !");
         return false;
     }

     if (SPECIALETE2.isEmpty() || !regexNom.match(SPECIALETE2).hasMatch()) {
         QMessageBox::warning(this, "Erreur", "La spécialité est invalide !");
         return false;
     }

     if (EMAILlP2.isEmpty() || !EMAILlP2.endsWith("@gmail.com")) {
         QMessageBox::warning(this, "Erreur", "Format invalide d'email !");
         return false;
     }

     if (TELEPHONEP2.length() != 8 || !TELEPHONEP2.toInt()) {
         QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
         return false;
     }

     if (ADRESSEP2.isEmpty()) {
         QMessageBox::warning(this, "Erreur", "L'adresse ne peut pas être vide !");
         return false;
     }

     if (CONTRATP2.isEmpty()) {
         QMessageBox::warning(this, "Erreur", "Le contrat ne peut pas être vide !");
         return false;
     }

     // Si tout est valide
     return true;
 }







 void MainWindow::on_Modifier_P_clicked()
 {
     if (!controleSaisiePartenaire()) {
         return; // Si la saisie est incorrecte, on ne poursuit pas la modification
     }
     qDebug() << "ID stocké dans oldIDP : " << ui->id_P_22->property("oldIDP").toInt();

     int oldIDP = ui->id_P_22->property("oldIDP").toInt();  // Récupérer l'ancien ID stocké
     int newIDP = ui->id_P_22->text().toInt();  // Récupérer le nouvel ID saisi

     QString NOMP2 = ui->nomP_2->text();
     QString SPECIALETE2 = ui->specialiteP_2->text();
     QString EMAILlP2 = ui->emailP_2->text();
     QString TELEPHONEP2 = ui->telephoneP_2->text();
     QString ADRESSEP2 = ui->adresseP_2->text();
     QString CONTRATP2 = ui->contratP_2->text();

     Partenaire P(newIDP, NOMP2, SPECIALETE2,ADRESSEP2, TELEPHONEP2,  EMAILlP2, CONTRATP2);

     bool test = P.modifierP(oldIDP);  // Passer l'ancien ID pour la modification
     qDebug() << "Ancien ID : " << oldIDP;
     qDebug() << "Nouveau ID : " << newIDP;

     if (test) {
         QMessageBox::information(nullptr, QObject::tr("Succès"),
                                  QObject::tr("Modification effectuée avec succès !"),
                                  QMessageBox::Ok);

         // 🚀 **Vider les champs après modification**
         ui->id_P_22->clear();
         ui->nomP_2->clear();
         ui->specialiteP_2->clear();
         ui->emailP_2->clear();
         ui->telephoneP_2->clear();
         ui->adresseP_2->clear();
         ui->contratP_2->clear();

         // Supprimer l'ancien ID stocké
         ui->id_P_22->setProperty("oldIDP", QVariant());
     }
     else {
         QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                               QObject::tr("La modification a échoué. Vérifiez l'ID."),
                               QMessageBox::Ok);
     }

     ui->TabP->setCurrentIndex(0); // Retour à l'onglet principal
 }
 void MainWindow::on_TabP_tabBarClicked(int index)
 {
     ui->tableViewP->setModel(Part.afficherP());
 }




 void MainWindow::on_tableViewP_doubleClicked(const QModelIndex &index)
 {
     int row = index.row();

     // Récupérer les données de chaque colonne
     QString id_p = ui->tableViewP->model()->index(row, 0).data().toString();  // ID du partenaire
     QString nomp = ui->tableViewP->model()->index(row, 1).data().toString();  // Nom
     QString specialetep = ui->tableViewP->model()->index(row, 2).data().toString();  // Spécialité
     QString mailp = ui->tableViewP->model()->index(row, 5).data().toString();  // Email
     QString telephonep = ui->tableViewP->model()->index(row, 4).data().toString();  // Téléphone
     QString adressep = ui->tableViewP->model()->index(row, 3).data().toString();  // Adresse
     QString contratp = ui->tableViewP->model()->index(row, 6).data().toString();  // Contrat

     // Stocker l'ancien ID dans une propriété cachée
     ui->id_P_22->setProperty("oldIDP", id_p.toInt());

     // Afficher les données dans les champs de saisie
     ui->id_P_22->setText(id_p);
     ui->nomP_2->setText(nomp);
     ui->specialiteP_2->setText(specialetep);
     ui->emailP_2->setText(mailp);
     ui->telephoneP_2->setText(telephonep);
     ui->adresseP_2->setText(adressep);
     ui->contratP_2->setText(contratp);

     // Vérification avec qDebug()
     qDebug() << "🔹 ID affiché : " << id_p;
     qDebug() << "🔹 ID stocké dans oldIDP : " << ui->id_P_22->property("oldIDP").toInt();

     // Changer d'onglet pour modification
     ui->TabP->setCurrentIndex(2);
 }
 /*void MainWindow::afficherStatistiques() {
    // 1. Obtenir les statistiques des partenaires
    qDebug() << "Le bouton a été cliqué !";
    QMap<QString, int> stats = Part.obtenirStatistiquesPartenaire();

    // 2. Créer une série de type camembert
    QPieSeries *series = new QPieSeries();

    // 3. Ajouter les données à la série
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        series->append(it.key(), it.value());
    }

    // 4. Créer le graphique et y ajouter la série
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des partenaires par spécialité");

    // 5. Créer une vue pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // 6. Ajouter le graphique dans le widget chartContainer
    chartView->setParent(ui->chartContainer);
    chartView->resize(ui->chartContainer->size());
}*/



 void MainWindow::on_RechercherPartenair_clicked()
 {
     QString criteria = ui->CombpBoxRecherche->currentText();
     QString value = ui->Taper->text();

     QString dbField;
     if (criteria == "ID") {
         dbField = "ID_PARTENAIR" ;
     } else if (criteria == "Specialite") {
         dbField = "SPECIALITE";
     } else if (criteria == "Email") {
         dbField = "EMAIL";
     } else {
         QMessageBox::warning(this, "Recherche", "Critère de recherche non valide.");
         return;
     }

     // Utilisation de dbField pour la recherche
     QSqlQueryModel* model = Part.RECHERCHER(dbField, value);
     if (model) {
         ui->tableViewPartenair->setModel(model); // Appliquer le modèle au tableau
     } else {
         QMessageBox::warning(this, "Recherche", "Erreur lors de la recherche.");
     }
 }


 void MainWindow::on_ExporterPDF_clicked()
 {
     /*QString fileName = QFileDialog::getSaveFileName(this, tr("Exporter en PDF"), "Liste_Partenaire.pdf", tr("Fichiers PDF (*.pdf)"));

    if (!fileName.isEmpty()) {
        bool success = Part.exporterPDF(fileName);
        if (success) {
            QMessageBox::information(this, tr("Export PDF"), tr("Exportation en PDF réussie."));
        } else {
            QMessageBox::critical(this, tr("Erreur"), tr("Échec de l'exportation en PDF."));
        }
    }*/

     QString fileName = QFileDialog::getSaveFileName(this, tr("Exporter en Excel"), "Liste_Partenaire.xlsx", tr("Fichiers Excel (*.xlsx)"));

     if (!fileName.isEmpty()) {
         // Appeler la fonction exporterExcel et vérifier si l'exportation a réussi
         bool success = Part.exporterExcel(fileName);
         if (success) {
             QMessageBox::information(this, tr("Export Excel"), tr("Exportation en Excel réussie."));
         } else {
             QMessageBox::critical(this, tr("Erreur"), tr("Échec de l'exportation en Excel."));
         }
     }
 }


 void MainWindow::on_AfficherStatistique_clicked()
 {

     QWidget *chartWidget = findChild<QWidget *>("chartContainer");
     if (chartWidget) {
         Part.genererStatistiques(chartWidget);
     } else {
         qDebug() << "Erreur : chartContainer introuvable.";
     }
 }

 //****************************mailing*******************************************************
 /*
void MainWindow::on_envoyer_clicked()
{

        QString email = ui->mail_3->text();
        QString objet = ui->objet->text();
        QString corps = ui->corps->toPlainText(); // ✅ CORRECT POUR QTextEdit







        //// email
        //////////////////// mailing




        QString executablePath = "C:\\Users\\user\\Documents\\pr c++\\architech cr\\email\\mail.exe";

        // Arguments à passer au fichier exécutable
        QStringList arguments;
        arguments << email<< objet << corps;

        // Lancer le fichier exécutable avec les arguments
        QProcess process;
        process.start(executablePath, arguments);
        process.waitForFinished(-1); // Attendre la fin de l'exécution

        // Récupérer la sortie de la console
        QByteArray output = process.readAllStandardOutput();
        qDebug() << "Output:" << output;



        ///////////////////////////////
    }

 /*#include"mailing.h"
    void MainWindowFacture::on_email_clicked()
    {
        //  hide() ;
        mailing mailing  ;
        mailing .setModal(true) ;
        mailing .exec() ;

    }*/

 void MainWindow::on_envoyer_clicked()
 {
     // Récupérer l'email et l'objet saisis par l'utilisateur
     QString email = ui->mail_3->text();
     QString objet = ui->objet->text();
     QString corps = ui->corps->toPlainText(); // ✅ CORRECT POUR QTextEdit

     // Vérifier si le bouton radio "urgent" est activé
     if (ui->urgent->isChecked()) {
         // Si urgent est coché, on remplit l'objet et le corps avec des valeurs statiques
         qDebug() << "Le bouton urgent est activé.";  // Message de débogage pour confirmer que le bouton est coché
         ui->objet->setText("Cas Urgent");  // Utiliser setText() pour modifier l'objet
         ui->corps->setPlainText("Bonjour " + Partenaire::getNomPartenaire(email) + ",\n\n"
                                                                                    "Venez ici, c'est très urgent !\n\n");  // Utiliser setPlainText() pour modifier le corps

         // Afficher un message d'information si l'email a été envoyé en cas d'urgence
         QMessageBox::information(this, "Email envoyé", "L'email a été envoyé en tant que cas urgent.");
     } else {
         qDebug() << "Le bouton urgent n'est pas activé.";  // Message de débogage pour confirmer que le bouton n'est pas coché
         // Afficher un message d'information si l'email a été envoyé sans cas urgent
         QMessageBox::information(this, "Email envoyé", "L'email a été envoyé sans cas urgent.");
     }

     // Logique d'envoi d'email (avec les valeurs mises à jour)
     QString executablePath = "E:\\c++projet\\projet\\email\\mail.exe";

     // Arguments à passer au fichier exécutable
     QStringList arguments;
     arguments << email << ui->objet->text() << ui->corps->toPlainText();  // Utiliser les valeurs mises à jour

     // Lancer le fichier exécutable avec les arguments
     QProcess process;
     process.start(executablePath, arguments);
     process.waitForFinished(-1); // Attendre la fin de l'exécution

     // Récupérer la sortie de la console
     QByteArray output = process.readAllStandardOutput();
     qDebug() << "Output:" << output;

     ///////////////////////////////
 }

 //********************************sms*****************************************************


 void MainWindow::on_sendButton_clicked()
 {

     QString phoneNumber = ui->phoneLineEdit->text();
     QString message = ui->messageTextEdit->toPlainText();


     if (phoneNumber.isEmpty() || message.isEmpty()) {
         qDebug() << "Erreur: Veuillez remplir tous les champs.";
         QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
         return;
     }

     // Chemin vers l'exécutable du script Python converti en .exe
     QString executablePath = "E:\\c++projet\\projet\\tsms\\sms.exe";

     // Arguments : numéro de téléphone et message
     QStringList arguments;
     arguments << phoneNumber << message;

     // Exécuter le fichier .exe
     QProcess process;
     process.start(executablePath, arguments);
     process.waitForFinished(-1); // Attendre la fin du script

     QByteArray output = process.readAllStandardOutput();
     qDebug() << "Output:" << output;


 }
 /*********************************************/
 void MainWindow::onCorpsTextChanged()
 {
     QString text = ui->corps->toPlainText();
     QString lastWords = text.section(' ', -2);  // récupère 2 derniers mots
     QStringList suggestions = mailing::getDynamicSuggestions(lastWords);

     if (!suggestions.isEmpty()) {
         showSuggestions(suggestions);
     } else {
         suggestionListWidget->hide();
     }
 }
 void MainWindow::showSuggestions(const QStringList &suggestions)
 {
     suggestionListWidget->clear();
     suggestionListWidget->addItems(suggestions);

     // Position sous le QTextEdit
     QPoint pos = ui->corps->mapToGlobal(QPoint(0, ui->corps->height()));
     suggestionListWidget->move(pos);
     suggestionListWidget->resize(300, suggestions.size() * 30);
     suggestionListWidget->show();
 }
 void MainWindow::onSuggestionClicked(QListWidgetItem* item)
 {
     QString selectedText = item->text();

     // Ajoute la suggestion au texte existant
     QString currentText = ui->corps->toPlainText();

     // On remplace juste le dernier mot
     QStringList words = currentText.split(" ");
     if (!words.isEmpty()) {
         words.removeLast();  // supprime dernier mot
     }
     currentText = words.join(" ") + " " + selectedText;

     ui->corps->setPlainText(currentText);
     ui->corps->moveCursor(QTextCursor::End);  // replacer le curseur à la fin

     suggestionListWidget->hide();
 }


 void MainWindow::onEmailTextChanged()
 {
     QString input = ui->mail_3->text();

     // Si l'input est vide, récupérer tous les e-mails
     QStringList suggestions = mailing::getEmailSuggestions(input);

     // Si la liste est vide, cacher la suggestion
     if (suggestions.isEmpty()) {
         emailSuggestionList->hide();
         return;
     }

     // Si l'input est vide, récupérer tous les emails
     if (input.isEmpty()) {
         suggestions = mailing::getEmailSuggestions("");  // Récupérer tous les emails sans filtre
     }

     // Affichage des suggestions dans le QListWidget
     emailSuggestionList->clear();
     emailSuggestionList->addItems(suggestions);

     // Positionner le widget de suggestions sous le QLineEdit
     QPoint pos = ui->mail_3->mapToGlobal(QPoint(0, ui->mail_3->height()));
     emailSuggestionList->move(pos);
     emailSuggestionList->resize(300, suggestions.size() * 28); // Ajuster la taille selon le nombre de suggestions
     emailSuggestionList->show();
 }

 //*************tri**************

 void MainWindow::on_TRIERPartenair_clicked()
 {
     // Obtenir le critère de tri sélectionné dans ComboBox
     QString sortCriterion = ui->CombpBoxtrie_2->currentText();
     QString column;

     // Correspondre le critère avec la colonne appropriée
     if (sortCriterion =="ID")  {
         column ="ID_PARTENAIR";
     } else if (sortCriterion =="adresse") {
         column ="ADRESSE";
     } else if (sortCriterion =="Specialite") {
         column ="SPECIALITE";
     }
     // Rafraîchir le modèle dans tableView avec la liste triée

     ui->tableViewP->setModel(Part.AFFICHER_SORTED(column));
 }















 /**********************endyasmine*************************/
 //azizakrt
 bool MainWindow::controleSaisie1() {
     // Récupérer les valeurs des champs
     QString CIN = ui->CIN->text();
     QString NOM = ui->NOM->text();
     QString PRENOM = ui->PRENOM->text();
     QString ADRESSE = ui->ADRESSE->text();
     QString TELEPHONE = ui->TELEPHONE->text();
     QString MAIL = ui->MAIL->text();


     // Créer des expressions régulières pour chaque champ
     QRegularExpression regexNomPrenom("^[A-Za-zÀ-ÖØ-öø-ÿ\\s-]+$");  // Pour les noms et prénoms (lettres et espaces)
     QRegularExpression regexEmail("^[\\w-\\.]+@[\\w-]+\\.[a-z]{2,3}$");  // Pour un email valide
     QRegularExpression regexTelephone("^\\d{10}$");  // Pour un numéro de téléphone avec 10 chiffres

     // Vérifier les champs avec les expressions régulières
     if (CIN.isEmpty() || CIN.length() < 5 || !CIN.toInt()) {
         QMessageBox::warning(this, "Erreur", "Le CIN doit contenir exactement 5 chiffres !");
         return false;
     }

     if (NOM.isEmpty() || !regexNomPrenom.match(NOM).hasMatch()) {
         QMessageBox::warning(this, "Erreur", "Le nom est invalide !");
         return false;
     }

     if (PRENOM.isEmpty() || !regexNomPrenom.match(PRENOM).hasMatch()) {
         QMessageBox::warning(this, "Erreur", "Le prénom est invalide !");
         return false;
     }

     if (ADRESSE.isEmpty()) {
         QMessageBox::warning(this, "Erreur", "L'adresse est vide !");
         return false;
     }

     if (TELEPHONE.length() != 8 || !TELEPHONE.toInt()) {
         QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
         return false;
     }

     if (MAIL.isEmpty() || !MAIL.endsWith("@gmail.com")) {
         QMessageBox::warning(this, "Erreur", "Format invalide d'email !");
         return false;
     }



     // Si tout est valide
     return true;
 }


 bool MainWindow::controleSaisie2() {
     // Récupérer les valeurs des champs
     QString CIN = ui->CIN2->text();
     QString NOM = ui->NOM2->text();
     QString PRENOM = ui->PRENOM2->text();
     QString ADRESSE = ui->ADRESSE2->text();
     QString TELEPHONE = ui->TELEPHONE2->text();
     QString MAIL = ui->MAIL2->text();


     QRegularExpression regexNomPrenom("^[A-Za-zÀ-ÖØ-öø-ÿ\\s-]+$");  // Pour les noms et prénoms (lettres et espaces)
     QRegularExpression regexEmail("^[\\w-\\.]+@[\\w-]+\\.[a-z]{2,3}$");  // Pour un email valide
     QRegularExpression regexTelephone("^\\d{10}$");  // Pour un numéro de téléphone avec 10 chiffres


     if (CIN.isEmpty() || CIN.length() != 5 || !CIN.toInt()) {
         QMessageBox::warning(this, "Erreur", "Le CIN doit contenir exactement 5 chiffres !");
         return false;
     }

     if (NOM.isEmpty() || NOM.length() <3 || !regexNomPrenom.match(NOM).hasMatch()) {
         QMessageBox::warning(this, "Erreur", "Le nom est invalide !");
         return false;
     }

     if (PRENOM.isEmpty() ||PRENOM.length() <3|| !regexNomPrenom.match(PRENOM).hasMatch()) {
         QMessageBox::warning(this, "Erreur", "Le prénom est invalide !");
         return false;
     }

     if (ADRESSE.isEmpty()) {
         QMessageBox::warning(this, "Erreur", "L'adresse est vide !");
         return false;
     }

     if (TELEPHONE.length() != 8 || !TELEPHONE.toInt()) {
         QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
         return false;
     }
     if (MAIL.isEmpty() || !MAIL.endsWith("@gmail.com")) {
         QMessageBox::warning(this, "Erreur", "Format invalide d'email !");
         return false;
     }


     // Si tout est valide
     return true;
 }
 void MainWindow::on_AjouterClient_clicked()
 {
     if (!controleSaisie1()) {
         return; // Saisie incorrecte, on arrête ici
     }

     int CIN = ui->CIN->text().toInt();
     QString NOM = ui->NOM->text();
     QString PRENOM = ui->PRENOM->text();
     QString ADRESSE = ui->ADRESSE->text();
     QString TELEPHONE = ui->TELEPHONE->text();
     QString MAIL = ui->MAIL->text();

     // Adapté au nouveau constructeur de Clients sans les colonnes supprimées
     Clients C(CIN, NOM, PRENOM, MAIL, ADRESSE, TELEPHONE);

     bool test = C.AjouterClients();
     if (test) {
         ui->tableViewC->setModel(Cli.afficherC());
         QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("Ajout effectué\n"
                                              "Cliquez sur Annuler pour quitter."),
                                  QMessageBox::Cancel);

         // Tu peux ajouter ici une vérification du mode paiement si besoin
         // if (ui->modePaiementComboBox->currentText() == "Par facilité") { ... }

     } else {
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("Ajout non effectué\n"
                                           "Cliquez sur Annuler pour quitter."),
                               QMessageBox::Cancel);
     }

     qDebug() << "Bouton Ajouter Client cliqué !";
 }

 void MainWindow::on_tableViewC_doubleClicked(const QModelIndex &index)
 {
     int row = index.row();
     QString cin = ui->tableViewC->model()->index(row, 0).data().toString();  // Ancien CIN

     // Stocker l'ancien CIN dans un attribut caché
     ui->CIN2->setProperty("oldCIN", cin.toInt());

     // Affichage des données dans les champs de saisie
     ui->CIN2->setText(cin);
     ui->supp2->setText(cin);
     ui->NOM2->setText(ui->tableViewC->model()->index(row, 1).data().toString());
     ui->PRENOM2->setText(ui->tableViewC->model()->index(row, 2).data().toString());
     ui->MAIL2->setText(ui->tableViewC->model()->index(row, 3).data().toString());
     ui->ADRESSE2->setText(ui->tableViewC->model()->index(row, 4).data().toString());
     ui->TELEPHONE2->setText(ui->tableViewC->model()->index(row, 5).data().toString());

     // Supprimé : ui->PAIMENT2->setText(...); // Car la colonne n'existe plus

     ui->TabC->setCurrentIndex(3);  // Aller à l'onglet de modification
 }

 void MainWindow::on_MODIFIERC_clicked()
 {
     if (!controleSaisie2()) {
         return;
     }

     int oldCIN = ui->CIN2->property("oldCIN").toInt();  // Ancien CIN
     int newCIN = ui->CIN2->text().toInt();              // Nouveau CIN saisi

     QString NOM2 = ui->NOM2->text();
     QString PRENOM2 = ui->PRENOM2->text();
     QString ADRESSE2 = ui->ADRESSE2->text();
     QString TELEPHONE2 = ui->TELEPHONE2->text();
     QString MAIL2 = ui->MAIL2->text();

     // Ne plus utiliser PAIMENT2 ni date, ils ont été supprimés
     Clients C(newCIN, NOM2, PRENOM2, MAIL2, ADRESSE2, TELEPHONE2);  // Constructeur mis à jour

     bool test = C.modifierC(oldCIN);  // Modification

     if (test) {
         QMessageBox::information(nullptr, QObject::tr("Succès"),
                                  QObject::tr("Modification effectuée avec succès !"),
                                  QMessageBox::Ok);

         ui->CIN2->clear();
         ui->NOM2->clear();
         ui->PRENOM2->clear();
         ui->MAIL2->clear();
         ui->ADRESSE2->clear();
         ui->TELEPHONE2->clear();

         ui->CIN2->setProperty("oldCIN", QVariant());  // Réinitialiser
     }
     else {
         QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                               QObject::tr("La modification a échoué. Vérifiez le CIN."),
                               QMessageBox::Ok);
     }

     ui->TabC->setCurrentIndex(0); // Retour à l'accueil
 }




 void MainWindow::on_supprimerC_clicked()
 {

     int CIN2=ui->CIN2->text().toInt();
     bool test=Cli.SupprimerClients(CIN2);
     if (test) {

         QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("Suppression effectué\n"
                                              "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);

     } else {
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("Suppression non effectué\n"
                                           "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
     }
 }










 void MainWindow::on_TabC_tabBarClicked(int index)
 {
     ui->tableViewC->setModel(Cli.afficherC());




     /******************************/
     // Nettoyer le layout existant dans le widgetC
     QLayout* oldLayout = ui->widgetC->layout();
     if (oldLayout) {
         QLayoutItem* item;
         while ((item = oldLayout->takeAt(0)) != nullptr) {
             if (item->widget()) {
                 item->widget()->deleteLater();
             }
             delete item;
         }
         delete oldLayout;
     }

     // Créer un nouveau layout pour widgetC
     QVBoxLayout* layout = new QVBoxLayout(ui->widgetC);
     ui->widgetC->setLayout(layout);

     // Obtenir la vue du graphique et l'ajouter au layout
     QChartView* chartView = Cli.stat_paiement();
     layout->addWidget(chartView);

     /****************************/

     loadRatings();






 }


 void MainWindow::on_supprimerC_2_clicked()
 {
     int CIN2=ui->supp2->text().toInt();
     bool test=Cli.SupprimerClients(CIN2);
     if (test) {

         QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("Suppression effectué\n"
                                              "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);

     } else {
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("Suppression non effectué\n"
                                           "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
     }
 }




 void MainWindow::on_Exporter_PDF_clicked()
 {
     QString fileName = QFileDialog::getSaveFileName(this, tr("Exporter en PDF"), "Liste_Clients.pdf", tr("Fichiers PDF (*.pdf)"));

     if (!fileName.isEmpty()) {
         bool success = Cli.exporterPDF(fileName);
         if (success) {
             QMessageBox::information(this, tr("Export PDF"), tr("Exportation en PDF réussie."));
         } else {
             QMessageBox::critical(this, tr("Erreur"), tr("Échec de l'exportation en PDF."));
         }
     }
 }

 void MainWindow::on_pushButtonTrier_C_clicked()
 {
     // Récupérer le critère sélectionné dans la comboBox
     QString critere = ui->comboBoxTri->currentText();
     QString column;

     // Associer le critère à la colonne correspondante
     if (critere == "Date d'inscription") {
         column = "DATE_INSCRIPTION";
     } else if (critere == "Prénom") {
         column = "PRENOM";
     } else if (critere == "Nom") {
         column = "NOM";
     } else {
         column = "DATE_INSCRIPTION"; // Valeur par défaut
     }

     // Mettre à jour le modèle de la tableView avec les données triées
     ui->tableViewC->setModel(Cli.afficherTrie(column));
 }
 void MainWindow::on_chercher_clicked()
 {
     // Récupérer le critère sélectionné dans la comboBox
     QString critere = ui->comboBoxTri->currentText();
     QString column;

     // Associer le critère à la colonne correspondante
     if (critere == "Date d'inscription") {
         column = "DATE_INSCRIPTION";
     } else if (critere == "Prénom") {
         column = "PRENOM";
     } else if (critere == "Nom") {
         column = "NOM";
     } else {
         column = "DATE_INSCRIPTION"; // Valeur par défaut
     }

     // Récupérer la valeur saisie par l'utilisateur
     QString valeur = ui->lineEditRecherche->text();

     // Mettre à jour le modèle de la tableView avec les données filtrées
     ui->tableViewC->setModel(Cli.RECHERCHER(column, valeur));
 }
//------------------------------------------------------------------------------


 void MainWindow::on_chargerlesdonnees_clicked()
 {
     int CIN = ui->lineEdit_CP->text().toInt();
     int id_p = ui->ID_PROJET->text().toInt();

     // 1. Vérifier si le projet est déjà dans la table FACILITE
     QSqlQuery checkFacilite;
     checkFacilite.prepare("SELECT ID_PROJET FROM FACILITE WHERE CIN = :cin AND ID_PROJET = :id_p");
     checkFacilite.bindValue(":cin", CIN);
     checkFacilite.bindValue(":id_p", id_p);

     if (checkFacilite.exec() && checkFacilite.next()) {
         QMessageBox::warning(nullptr, QObject::tr("Déjà enregistré"),
                              QObject::tr("Ce projet a déjà un mode de paiement facilité enregistré.\nUn seul enregistrement est autorisé."),
                              QMessageBox::Cancel);
         activerChampsFacilite(false); // Désactive les champs
         return;
     }

     // 2. Continuer si pas encore enregistré
     QSqlQuery query;
     query.prepare("SELECT BUDGET, MODE_PAIEMENT, DATE_DEBUT FROM PROJETS WHERE CIN_CLIENT = :cin AND ID_PROJET = :id_p");
     query.bindValue(":cin", CIN);
     query.bindValue(":id_p", id_p);

     if (query.exec() && query.next()) {
         QString modePaiement = query.value("MODE_PAIEMENT").toString();

         if (modePaiement == "Par facilité") {
             float budget = query.value("BUDGET").toFloat();
             QDate dateDebut = query.value("DATE_DEBUT").toDate();

             float totalAvecInteret = budget * 1.2;
             float tranche = totalAvecInteret / 6;

             ui->PARF->setText(QString::number(totalAvecInteret, 'f', 2));

             ui->lineEditCC1->setText(QString::number(tranche, 'f', 2));
             ui->lineEditCC2->setText(QString::number(tranche, 'f', 2));
             ui->lineEditCC3->setText(QString::number(tranche, 'f', 2));
             ui->lineEditCC4->setText(QString::number(tranche, 'f', 2));
             ui->lineEditCC5->setText(QString::number(tranche, 'f', 2));
             ui->lineEditCC6->setText(QString::number(tranche, 'f', 2));

             ui->dateEditC1->setText(dateDebut.toString("dd/MM/yyyy"));
             ui->dateEditC2->setText(dateDebut.addMonths(4).toString("dd/MM/yyyy"));
             ui->dateEditC3->setText(dateDebut.addMonths(8).toString("dd/MM/yyyy"));
             ui->dateEditC4->setText(dateDebut.addMonths(12).toString("dd/MM/yyyy"));
             ui->dateEditC5->setText(dateDebut.addMonths(16).toString("dd/MM/yyyy"));
             ui->dateEditC6->setText(dateDebut.addMonths(20).toString("dd/MM/yyyy"));

             activerChampsFacilite(true); // Active les champs car c'est nouveau
         } else {
             QMessageBox::information(nullptr, QObject::tr("Paiement déjà effectué"),
                                      QObject::tr("Le mode de paiement est : %1\nLe client a déjà payé.").arg(modePaiement),
                                      QMessageBox::Ok);
             activerChampsFacilite(false);
         }
     } else {
         QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Aucun projet trouvé avec ce CIN et ID_PROJET. Vérifiez les informations saisies."),
                              QMessageBox::Cancel);
         activerChampsFacilite(false);
     }
 }


 void MainWindow::activerChampsFacilite(bool actif)
 {
     ui->lineEditCC1->setEnabled(actif);
     ui->lineEditCC2->setEnabled(actif);
     ui->lineEditCC3->setEnabled(actif);
     ui->lineEditCC4->setEnabled(actif);
     ui->lineEditCC5->setEnabled(actif);
     ui->lineEditCC6->setEnabled(actif);

     ui->dateEditC1->setEnabled(actif);
     ui->dateEditC2->setEnabled(actif);
     ui->dateEditC3->setEnabled(actif);
     ui->dateEditC4->setEnabled(actif);
     ui->dateEditC5->setEnabled(actif);
     ui->dateEditC6->setEnabled(actif);
 }



 void MainWindow::on_ValiderFaciliter_clicked()
 {
     int CIN = ui->lineEdit_CP->text().toInt();
     int id_p = ui->ID_PROJET->text().toInt();

     QDate DATEL1 = QDate::fromString(ui->dateEditC1->text(), "dd/MM/yyyy");
     QDate DATEL2 = QDate::fromString(ui->dateEditC2->text(), "dd/MM/yyyy");
     QDate DATEL3 = QDate::fromString(ui->dateEditC3->text(), "dd/MM/yyyy");
     QDate DATEL4 = QDate::fromString(ui->dateEditC4->text(), "dd/MM/yyyy");
     QDate DATEL5 = QDate::fromString(ui->dateEditC5->text(), "dd/MM/yyyy");
     QDate DATEL6 = QDate::fromString(ui->dateEditC6->text(), "dd/MM/yyyy");

     float TRANCHE1 = ui->lineEditCC1->text().toFloat();
     float TRANCHE2 = ui->lineEditCC2->text().toFloat();
     float TRANCHE3 = ui->lineEditCC3->text().toFloat();
     float TRANCHE4 = ui->lineEditCC4->text().toFloat();
     float TRANCHE5 = ui->lineEditCC5->text().toFloat();
     float TRANCHE6 = ui->lineEditCC6->text().toFloat();

     int BOX1 = 0, BOX2 = 0, BOX3 = 0, BOX4 = 0, BOX5 = 0, BOX6 = 0;

     // Vérification que le CIN existe
     QSqlQuery query;
     query.prepare("SELECT CIN_CLIENT FROM CLIENT WHERE CIN_CLIENT = :cin");
     query.bindValue(":cin", CIN);
     query.exec();

     if (!query.next()) {
         QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Le CIN n'existe pas dans la table CLIENT.\nVeuillez d'abord ajouter le client."),
                              QMessageBox::Cancel);
         return;
     }

     // Vérification que le projet existe et appartient au client
     QSqlQuery query2;
     query2.prepare("SELECT MODE_PAIEMENT FROM PROJETS WHERE ID_PROJET = :id_p AND CIN_CLIENT = :cin");
     query2.bindValue(":id_p", id_p);
     query2.bindValue(":cin", CIN);
     query2.exec();

     if (!query2.next()) {
         QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Projet introuvable ou n'appartient pas au client."),
                              QMessageBox::Cancel);
         return;
     }

     QString modePaiement = query2.value("MODE_PAIEMENT").toString();
     if (modePaiement != "Par facilité") {
         QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Ce projet n'est pas en mode de paiement par facilité."),
                              QMessageBox::Cancel);
         return;
     }

     // Vérifier si le projet et le CIN ont déjà un mode de paiement facilité
     QSqlQuery query4;
     query4.prepare("SELECT ID_PROJET FROM FACILITE WHERE CIN_CLIENT = :cin AND ID_PROJET = :id_p");
     query4.bindValue(":cin", CIN);
     query4.bindValue(":id_p", id_p);
     query4.exec();

     if (query4.next()) {
         QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Ce projet a déjà un mode de paiement facilité enregistré.\nUn seul enregistrement est autorisé."),
                              QMessageBox::Cancel);
         return;
     }

     // Vérifier que le projet n'a pas déjà un paiement facilité enregistré
     QSqlQuery query3;
     query3.prepare("SELECT ID_PROJET FROM FACILITE WHERE ID_PROJET = :id_p");
     query3.bindValue(":id_p", id_p);
     query3.exec();

     if (query3.next()) {
         QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Ce projet a déjà un mode de paiement facilité enregistré.\nUn seul enregistrement est autorisé."),
                              QMessageBox::Cancel);
         return;
     }

     // ⚠️ Contrôle de saisie des tranches
     QList<float> tranches = {TRANCHE1, TRANCHE2, TRANCHE3, TRANCHE4, TRANCHE5, TRANCHE6};
     for (int i = 0; i < tranches.size(); ++i) {
         if (tranches[i] <= 0) {
             QMessageBox::warning(this, "Erreur de saisie",
                                  QString("La tranche %1 doit être un montant positif.").arg(i + 1));
             return;
         }
     }

     float sommeTranches = std::accumulate(tranches.begin(), tranches.end(), 0.0f);
     float totalAvecInteret = ui->PARF->text().toFloat();

     if (sommeTranches > totalAvecInteret) {
         QMessageBox::warning(this, "Erreur de saisie",
                              QString("La somme des tranches (%.2f) dépasse le total avec intérêt (%.2f).")
                                  .arg(sommeTranches).arg(totalAvecInteret));
         return;
     }

     // Création de l'objet FaciliteHistorique
     FaciliteHistorique hf(CIN, id_p, DATEL1, DATEL2, DATEL3, DATEL4, DATEL5, DATEL6,
                           TRANCHE1, TRANCHE2, TRANCHE3, TRANCHE4, TRANCHE5, TRANCHE6,
                           BOX1, BOX2, BOX3, BOX4, BOX5, BOX6);

     if (hf.ajouterFacilite()) {
         QMessageBox::information(nullptr, QObject::tr("Succès"),
                                  QObject::tr("Facilité ajoutée avec succès !"), QMessageBox::Ok);
     } else {
         QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Échec de l'ajout."), QMessageBox::Cancel);
     }
 }






 //---------------------------------------------------------------------------------------------------------------------------------
 void MainWindow::on_VOIRHIST_clicked()
 {
     int IdP = ui->IDPROJ->text().toInt();  // Récupérer l'ID du projet
     int CIN = ui->CINHIS->text().toInt();  // Récupérer le CIN

     // Vérifier si une entrée existe dans la table FACILITE pour ce CIN et ID_PROJET
     QSqlQuery queryFacilite;
     queryFacilite.prepare("SELECT * FROM FACILITE WHERE CIN = :cin AND ID_PROJET = :idp");
     queryFacilite.bindValue(":cin", CIN);
     queryFacilite.bindValue(":idp", IdP);

     if (!queryFacilite.exec()) {
         QMessageBox::warning(this, "Erreur", "Problème de connexion à la base de données !");
         return;
     }

     if (!queryFacilite.next()) {
         QMessageBox::warning(this, "Erreur", "Aucun historique trouvé pour ce client et ce projet !");
         return;
     }
     // Définir la locale en anglais
     QLocale locale(QLocale::English);

     // Liste des paires (champ de la base de données, label correspondant)
     QList<QPair<QString, QLabel*>> dateFields = {
         {"DATEL1", ui->LD1},
         {"DATEL2", ui->LD2},
         {"DATEL3", ui->LD3},
         {"DATEL4", ui->LD4},
         {"DATEL5", ui->LD5},
         {"DATEL6", ui->LD6}
     };

     // Parcourir chaque champ et mettre à jour le label correspondant
     for (const auto& field : dateFields) {
         QString dateStr = queryFacilite.value(field.first).toString();
         QDate date = locale.toDate(dateStr, "dd-MMM-yy");
         if (date.isValid()) {
             field.second->setText(date.toString("dd/MM/yyyy"));
         } else {
             field.second->setText("Date invalide");
         }
     }

     /*

    // Répétez pour les autres champs DATEL*/

     // Affichage des tranches
     ui->LT1->setText(QString::number(queryFacilite.value("TRANCHE1").toFloat(), 'f', 2));
     ui->LT2->setText(QString::number(queryFacilite.value("TRANCHE2").toFloat(), 'f', 2));
     ui->LT3->setText(QString::number(queryFacilite.value("TRANCHE3").toFloat(), 'f', 2));
     ui->LT4->setText(QString::number(queryFacilite.value("TRANCHE4").toFloat(), 'f', 2));
     ui->LT5->setText(QString::number(queryFacilite.value("TRANCHE5").toFloat(), 'f', 2));
     ui->LT6->setText(QString::number(queryFacilite.value("TRANCHE6").toFloat(), 'f', 2));

     // Récupération des BOX
     int box1 = queryFacilite.value("BOX1").toInt();
     int box2 = queryFacilite.value("BOX2").toInt();
     int box3 = queryFacilite.value("BOX3").toInt();
     int box4 = queryFacilite.value("BOX4").toInt();
     int box5 = queryFacilite.value("BOX5").toInt();
     int box6 = queryFacilite.value("BOX6").toInt();

     // Mise à jour des checkboxes
     auto updateCheckbox = [](QCheckBox* checkBox, int value) {
         bool isExecuted = (value == 1);
         checkBox->setChecked(isExecuted);
         checkBox->setText(isExecuted ? "✅" : "⏳");
         checkBox->setEnabled(!isExecuted);
     };

     updateCheckbox(ui->check1, box1);
     updateCheckbox(ui->check2, box2);
     updateCheckbox(ui->check3, box3);
     updateCheckbox(ui->check4, box4);
     updateCheckbox(ui->check5, box5);
     updateCheckbox(ui->check6, box6);

     QMessageBox::information(this, "Historique", "Les informations du client ont été chargées !");
 }



 void MainWindow::on_lineEdit_CP_editingFinished()
 {
     QString cin = ui->lineEdit_CP->text().trimmed();

     if (cin.isEmpty()) return;

     QSqlQuery query;
     query.prepare("SELECT ID_PROJET FROM PROJETS WHERE CIN_CLIENT = :cin");
     query.bindValue(":cin", cin);

     if (!query.exec()) {
         qDebug() << "Erreur SQL:" << query.lastError().text();
         return;
     }

     QStringList listeProjets;
     while (query.next()) {
         listeProjets << query.value(0).toString();
     }

     if (!listeProjets.isEmpty()) {
         QCompleter* completer = new QCompleter(listeProjets, this);
         completer->setCompletionMode(QCompleter::PopupCompletion);
         completer->setCaseSensitivity(Qt::CaseInsensitive);
         completer->setFilterMode(Qt::MatchContains);

         ui->ID_PROJET->setCompleter(completer);
     }
 }


 void MainWindow::on_ValiderHistorique_clicked()
 {
     // Récupérer l'ID du projet et le CIN du client
     bool okIdP, okCIN;
     int IdP = ui->IDPROJ->text().toInt(&okIdP);
     int CIN = ui->CINHIS->text().toInt(&okCIN);

     if (!okIdP || !okCIN || CIN == 0) {
         QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID de projet et un CIN valides !");
         return;
     }

     // Préparer la requête pour mettre à jour les valeurs des checkboxes dans la base de données
     QSqlQuery query;
     query.prepare(R"(
        UPDATE FACILITE
        SET BOX1 = :box1, BOX2 = :box2, BOX3 = :box3,
            BOX4 = :box4, BOX5 = :box5, BOX6 = :box6
        WHERE CIN = :cin AND ID_PROJET = :idp
    )");

     // Affecter les valeurs des checkboxes
     query.bindValue(":box1", ui->check1->isChecked() ? 1 : 0);
     query.bindValue(":box2", ui->check2->isChecked() ? 1 : 0);
     query.bindValue(":box3", ui->check3->isChecked() ? 1 : 0);
     query.bindValue(":box4", ui->check4->isChecked() ? 1 : 0);
     query.bindValue(":box5", ui->check5->isChecked() ? 1 : 0);
     query.bindValue(":box6", ui->check6->isChecked() ? 1 : 0);
     query.bindValue(":cin", CIN);
     query.bindValue(":idp", IdP);

     // Exécuter la mise à jour
     if (!query.exec()) {
         QMessageBox::critical(this, "Erreur SQL", "Échec de la mise à jour des données : " + query.lastError().text());
         return;
     }

     // Si mise à jour réussie, désactiver les checkboxes cochées et changer leur texte
     QList<QCheckBox*> checkboxes = { ui->check1, ui->check2, ui->check3, ui->check4, ui->check5, ui->check6 };
     for (QCheckBox* checkBox : checkboxes) {
         if (checkBox->isChecked()) {
             checkBox->setText("✅ " + checkBox->text());
             checkBox->setEnabled(false);  // Désactiver pour empêcher toute modification
         }
     }

     QMessageBox::information(this, "Succès", "L'historique a été mis à jour avec succès !");

     // Nettoyage des champs
     ui->LT1->clear();
     ui->LT2->clear();
     ui->LT3->clear();
     ui->LT4->clear();
     ui->LT5->clear();
     ui->LT6->clear();

     ui->LD1->clear();
     ui->LD2->clear();
     ui->LD3->clear();
     ui->LD4->clear();
     ui->LD5->clear();
     ui->LD6->clear();

     ui->IDPROJ->clear();
     ui->CINHIS->clear();

     // Réinitialiser les checkboxes (même celles non cochées)
     for (QCheckBox* checkBox : checkboxes) {
         checkBox->setChecked(false);
         checkBox->setEnabled(true);
         QString text = checkBox->text();
         if (text.startsWith("✅ ")) {
             checkBox->setText(text.mid(2));
         }
     }
 }



 /*-----------------------------------------------------------------------------------------------------------------*/
 void MainWindow::updateStars(int rating) {
     for (int i = 0; i < stars.size(); ++i) {
         if (i < rating) {
             stars[i]->setStyleSheet(
                 "QPushButton {"
                 "   image: url(:/GoldStar.png);"
                 "   all: unset;"
                 "   background: none;"
                 "   border: none;"
                 "   color: black;"
                 "   font: inherit;"
                 "   qproperty-iconSize: QSize(100, 100);"
                 "   padding: 0;"
                 "}"
                 );
         } else {
             stars[i]->setStyleSheet(
                 "QPushButton {"
                 "   image: url(:/GrayStar.png);"
                 "   all: unset;"
                 "   background: none;"
                 "   border: none;"
                 "   color: black;"
                 "   font: inherit;"
                 "   qproperty-iconSize: QSize(100, 100);"
                 "   padding: 0;"
                 "}"
                 );
         }
     }
 }

 void MainWindow::onStarClicked() {
     QPushButton *clickedButton = qobject_cast<QPushButton*>(sender()); // Trouve le bouton cliqué
     int index = stars.indexOf(clickedButton); // Trouve l'index du bouton cliqué
     int currentRating = 0;

     // Vérifie combien d'étoiles sont actuellement allumées (Gold)
     for (int i = 0; i < stars.size(); ++i) {
         if (stars[i]->styleSheet().contains("GoldStar.png")) {
             currentRating = i + 1; // On prend le dernier index allumé +1
         }
     }

     // Si on clique sur la dernière étoile allumée -> on l'éteint
     int newRating = (currentRating == index + 1) ? index : index + 1;

     updateStars(newRating);
 }
 /*****************************************************************************************************************************************************/
 void MainWindow::on_ValiderRating_clicked()
 {
     // Calculer la note actuelle basée sur les étoiles dorées
     int rating = 0;
     for (int i = 0; i < stars.size(); ++i) {
         if (stars[i]->styleSheet().contains("GoldStar.png")) {
             rating = i + 1;
         }
     }

     // Vérifier si une note a été sélectionnée
     if (rating == 0) {
         qDebug() << "Aucune note sélectionnée.";
         return;
     }

     qDebug() << "Rating sélectionné :" << rating;

     // Récupérer le commentaire de l'utilisateur
     QString reviewComment = ui->reviewCommentTextEdit->toPlainText();
     int CIN = ui->Rating->text().toInt();

     qDebug() << "Commentaire original :" << reviewComment;
     qDebug() << "CIN :" << CIN;

     // Charger la liste des mots interdits et filtrer le commentaire
     QStringList badWords = Feedback::getBadWords();
     QString filteredComment = Feedback::filterBadWords(reviewComment, badWords);

     // Vérifier si le commentaire a été modifié (mots interdits trouvés)
     if (filteredComment != reviewComment) {
         QMessageBox::warning(this, "Alerte", "Vous avez commenté avec un mot interdit. Votre commentaire a été modifié.", QMessageBox::Ok);
     }

     qDebug() << "Commentaire filtré :" << filteredComment;

     // Mettre à jour l'objet Feedback
     Fd.setClientId(CIN);
     Fd.setRating(rating);
     Fd.setReviewComment(filteredComment);  // On enregistre le commentaire filtré

     // Enregistrer la note dans la base de données
     if (Fd.saveRating()) {
         qDebug() << "Note enregistrée avec succès.";
         loadRatings();  // Recharge la table après l'enregistrement
     } else {
         qDebug() << "Erreur lors de l'enregistrement de la note.";
     }
 }



 void MainWindow::loadRatings() {

     ui->RATINGS->clearContents();
     ui->RATINGS->setRowCount(0);


     ui->RATINGS->setColumnCount(5);
     QStringList headers = {"Client", "Commentaire", "Date", "Étoiles", "Moyenne"};
     ui->RATINGS->setHorizontalHeaderLabels(headers);


     ui->RATINGS->setColumnWidth(0, 150);
     ui->RATINGS->setColumnWidth(1, 250);
     ui->RATINGS->setColumnWidth(2, 150);
     ui->RATINGS->setColumnWidth(3, 280);  // Colonne des étoiles
     ui->RATINGS->setColumnWidth(4, 100);  // Colonne de la moyenne des étoiles


     QPixmap halfStar(":/HalfGoldStar.png");
     if (halfStar.isNull()) {
         qDebug() << "Impossible de charger HalfGoldStar.png !";
     }


     QSqlQuery query;
     query.prepare(
         "SELECT CLIENT.NOM, CLIENT.PRENOM, RATINGS.REVIEW_COMMENT, "
         "RATINGS.DATE_FEEDBACK, RATINGS.RATING "
         "FROM RATINGS "
         "JOIN CLIENT ON RATINGS.CLIENT_ID = CLIENT.CIN_CLIENT "
         "ORDER BY RATINGS.DATE_FEEDBACK DESC"
         );

     if (!query.exec()) {
         qDebug() << "Erreur lors de la récupération des notes :" << query.lastError().text();
         return;
     }

     double totalRatings = 0.0;
     int countRatings = 0;

     // Ajout des avis dans le tableau
     while (query.next()) {
         int row = ui->RATINGS->rowCount();
         ui->RATINGS->insertRow(row);
         ui->RATINGS->setRowHeight(row, 50);

         QString clientName   = query.value(0).toString() + " " + query.value(1).toString();
         QString reviewComment= query.value(2).toString();
         QString dateFeedback = query.value(3).toString();
         int     rating       = query.value(4).toInt();

         ui->RATINGS->setItem(row, 0, new QTableWidgetItem(clientName));
         ui->RATINGS->setItem(row, 1, new QTableWidgetItem(reviewComment));
         ui->RATINGS->setItem(row, 2, new QTableWidgetItem(dateFeedback));

         // Étoiles pour chaque note
         QWidget *starWidget = new QWidget();
         QHBoxLayout *layout = new QHBoxLayout(starWidget);
         layout->setContentsMargins(5,5,5,5);
         layout->setSpacing(2);

         for (int i = 0; i < 5; ++i) {
             QLabel *starLabel = new QLabel();
             starLabel->setFixedSize(51,41);
             starLabel->setPixmap(
                 QPixmap(i < rating ? ":/GoldStar.png" : ":/GrayStar.png")
                     .scaled(51,41,Qt::KeepAspectRatio)
                 );
             layout->addWidget(starLabel);
         }

         starWidget->setLayout(layout);
         ui->RATINGS->setCellWidget(row, 3, starWidget);

         totalRatings += rating;
         ++countRatings;
     }

     // Afficher la moyenne si des avis existent
     if (countRatings > 0) {
         double avgRating   = totalRatings / countRatings;
         double roundedAvg  = std::ceil(avgRating * 2.0) / 2.0;  // Arrondi à 0.5 près

         int lastRow = ui->RATINGS->rowCount();
         ui->RATINGS->insertRow(lastRow);
         ui->RATINGS->setRowHeight(lastRow, 50);

         // Label "Moyenne des étoiles"
         QTableWidgetItem *avgLabel = new QTableWidgetItem("Moyenne des étoiles");
         avgLabel->setFont(QFont("Arial",10,QFont::Bold));
         avgLabel->setTextAlignment(Qt::AlignCenter);
         ui->RATINGS->setItem(lastRow, 0, avgLabel);

         // Widget pour afficher les étoiles de la moyenne
         QWidget *avgStarWidget = new QWidget();
         QHBoxLayout *starsLayout = new QHBoxLayout(avgStarWidget);
         starsLayout->setContentsMargins(5,5,5,5);
         starsLayout->setSpacing(2);

         int fullStars  = static_cast<int>(roundedAvg);
         bool hasHalf   = (roundedAvg - fullStars) >= 0.5;
         int grayStars  = 5 - fullStars - (hasHalf ? 1 : 0);

         // 1️⃣ Étoiles pleines
         for (int i = 0; i < fullStars; ++i) {
             QLabel *lbl = new QLabel();
             lbl->setFixedSize(51,41);
             lbl->setPixmap(QPixmap(":/GoldStar.png").scaled(51,41,Qt::KeepAspectRatio));
             starsLayout->addWidget(lbl);
         }
         // 2️⃣ Demi-étoile si nécessaire
         if (hasHalf) {
             QLabel *lbl = new QLabel();
             lbl->setFixedSize(51,41);
             lbl->setPixmap(QPixmap(":/HalfGoldStar.png").scaled(51,41,Qt::KeepAspectRatio));
             starsLayout->addWidget(lbl);
         }
         // 3️⃣ Étoiles grises restantes
         for (int i = 0; i < grayStars; ++i) {
             QLabel *lbl = new QLabel();
             lbl->setFixedSize(51,41);
             lbl->setPixmap(QPixmap(":/GrayStar.png").scaled(51,41,Qt::KeepAspectRatio));
             starsLayout->addWidget(lbl);
         }

         avgStarWidget->setLayout(starsLayout);
         ui->RATINGS->setCellWidget(lastRow, 3, avgStarWidget);

         // Afficher la valeur numérique de la moyenne
         QTableWidgetItem *avgValue = new QTableWidgetItem(QString::number(roundedAvg,'f',1));
         avgValue->setTextAlignment(Qt::AlignCenter);
         ui->RATINGS->setItem(lastRow, 4, avgValue);
     }

     // Si pas d'avis
     if (countRatings == 0) {
         ui->RATINGS->setRowCount(1);
         QTableWidgetItem *noData = new QTableWidgetItem("Aucun avis disponible");
         noData->setTextAlignment(Qt::AlignCenter);
         ui->RATINGS->setItem(0, 0, noData);
     }
 }
 //--------------------------------------------------------------------------------------arduino coffre fort
 void MainWindow::update_label() {
     QByteArray arduinoData = A.read_from_arduino();// code carte
     QString uid = QString::fromUtf8(arduinoData).trimmed().toLower();

     qDebug() << "RFID reçu :" << uid;

     if (!uid.isEmpty()) {
         // Vérifie l'UID dans la base et décide si on ouvre ou ferme le coffre
         bool isUidValid = A.compare_with_database(uid);  // Vérifier si l'UID est valide

         if (isUidValid) {
             // Récupérer l'état actuel du coffre
             int etatCoffre = A.getETATCOOFRE(uid);  // Récupère l'état du coffre (0 ou 1)
             QString nomEmploye = A.getNomEmploye(uid);


             if (etatCoffre == 0) {
                 // Si le coffre est fermé, on l'ouvre
                 QString nomEmploye = A.getNomEmploye(uid);
                 ui->Etat_coffre->setText(" Accès autorisé : " + nomEmploye + " a ouvert le coffre");


                 A.write_to_arduino("1");  // Signal ouverture
                 A.write_to_arduino("NOM:" + nomEmploye.toUtf8() + "\n");

             } else if (etatCoffre == 1) {
                 // Si le coffre est déjà ouvert, on le ferme
                 ui->Etat_coffre->setText(" Accès autorisé : " + nomEmploye + " coffre fermé");
                 A.write_to_arduino("2");  // Signal fermeture (utiliser "2" pour la fermeture)
             }
         } else {
             ui->Etat_coffre->setText(" Accès refusé : badge inconnu");
             A.write_to_arduino("0");  // Signal refus
         }
     }
 }


 void MainWindow::on_OuvrirC_clicked()
 {
     QString cin = ui->CINCOF->text();
     QString code = ui->CODE->text();

     if (cin.isEmpty() || code.isEmpty()) {
         QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs.");
         return;
     }

     QSqlQuery query;
     query.prepare("SELECT PRENOM, CIN_EMPLOYE FROM EMPLOYE WHERE CIN_EMPLOYE = :cin AND CODECOFFRE = :code");
     query.bindValue(":cin", cin.toInt());
     query.bindValue(":code", code.toInt());

     if (query.exec()) {
         if (query.next()) {
             QString nom = query.value(0).toString();
             int cinResult = query.value(1).toInt();

             // Mise à jour de l'état du coffre à 1 (ouvert)
             QSqlQuery update;
             update.prepare("UPDATE EMPLOYE SET ETATCOFFRE = 0 WHERE CIN_EMPLOYE = :cin");
             update.bindValue(":cin", cinResult);

             if (update.exec()) {
                 QMessageBox::information(this, "Accès autorisé", "Coffre ouvert pour : " + nom);
                 qDebug() << "Envoi à Arduino : 1";
                 A.write_to_arduino("5");

                 qDebug() << "Envoi à Arduino : NOM:" << nom;


                 A.write_to_arduino("NOM:" + nom.toUtf8() + "\n"); // Nom à afficher sur l'écran LCD
             } else {
                 QMessageBox::critical(this, "Erreur", "Impossible de mettre à jour l'état du coffre.");
             }
         } else {
             QMessageBox::warning(this, "Erreur", "Le CIN ou le CODECOFFRE ne correspond à aucun employé.");
         }
     } else {
         QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
     }
 }
 void MainWindow::on_FermerC_clicked()
 {
     QString cin = ui->CINCOF->text();
     QString code = ui->CODE->text();

     if (cin.isEmpty() || code.isEmpty()) {
         QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs.");
         return;
     }

     QSqlQuery query;
     query.prepare("SELECT CIN_EMPLOYE FROM EMPLOYE WHERE CIN_EMPLOYE = :cin AND CODECOFFRE = :code");
     query.bindValue(":cin", cin.toInt());
     query.bindValue(":code", code.toInt());

     if (query.exec()) {
         if (query.next()) {
             int cinResult = query.value(0).toInt();

             // Mise à jour de l'état du coffre à 0 (fermé)
             QSqlQuery update;
             update.prepare("UPDATE EMPLOYE SET ETATCOFFRE = 1 WHERE CIN_EMPLOYE = :cin");
             update.bindValue(":cin", cinResult);

             if (update.exec()) {
                 QMessageBox::information(this, "Fermeture", "Coffre fermé pour l'employé CIN : " + QString::number(cinResult));
                 A.write_to_arduino("6");  // Signal de fermeture
             } else {
                 QMessageBox::critical(this, "Erreur", "Impossible de mettre à jour l'état du coffre.");
             }
         } else {
             QMessageBox::warning(this, "Erreur", "Le CIN ou le CODECOFFRE ne correspond à aucun employé.");
         }
     } else {
         QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
     }
 }




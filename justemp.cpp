#include "justemp.h"
#include "ui_justemp.h"
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
#include <QDate>
#include <QWidget>
#include <QDateTime>
#include <QObject>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <qprocess.h>
#include "dialog.h"
#include "employe.h"
#include "ressource.h"
#include "dialogPDF_RESSOURCE.h"
#include "rendezvous.h"
#include "partenaire.h"
#include "mailing.h"
#include "ui_mailing.h"
justemp::justemp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::justemp)
{

    ui->setupUi(this);
    connect(ui->rechercher, &QLineEdit::textChanged, this, &justemp::on_rechercher_textChanged);



    connect(ui->chercherRESSOURCE_10, &QLineEdit::textChanged,
            this, &justemp::on_chercherRESSOURCE_textChanged);
    connect(ui->trie_ressource_10, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &justemp::on_trie_ressource_currentIndexChanged);

    //RENDEZVOUS
    QTimer::singleShot(0, this, &justemp::afficherRendezVousAujourdHui);
    connect(ui->comboBoxTriRV_7, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int index) {
        RendezVous rdv;
        bool croissant = (index == 0);
        rdv.trierParDate(ui->tableView2RV_7, croissant);
    });

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsViewCal_RV_7->setScene(scene);
    currentDate = QDate::currentDate();

    QTimer::singleShot(0, this, [this]() {
        RendezVous rdv;
        rdvParJour = rdv.recupererNombreRendezVousParDate();
        displayCalendar();
    });
    displayCalendar();

    connect(ui->pushButtonMoisPrecedent_RV_7, &QPushButton::clicked, this, &justemp::previousMonth);
    connect(ui->pushButtonMoisSuivant_RV_7, &QPushButton::clicked, this, &justemp::nextMonth);

    //RENDEZVOUS

}
void justemp::on_Employes_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page1_EMPLOYES);
        qDebug() << "Employes clicked in JustEmp";


}

void justemp::on_Clients_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page2_CLIENTS);
}

void justemp::on_Projets_clicked()
{
    displayTasks();

    ui->stackedWidget->setCurrentWidget(ui->page3_PROJETS);
}


void justemp::on_Partenaire_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page4_PARTENAIRES);
}


void justemp::on_RendezVous_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page5_RENDEZVOUS);
}


void justemp::on_Ressources_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page6_RESSOURCES);
}


justemp::~justemp()
{
    delete ui;
}
void justemp::filterTable(const QString &searchTerm)
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
    ui->employeTableView1->setModel(model);
}
/* button employe */


void justemp::on_rechercher_textChanged(const QString &arg1)
{
    // Use the trimmed version of the text input for search
    QString searchTerm = arg1.trimmed();
    filterTable(searchTerm);
}
void justemp::setCIN(int cin)
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

void justemp::afficheremploye()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE");
    ui->employeTableView1->setModel(model);  // Use your actual tableView name
}


void justemp::on_TrierButton_clicked()
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



void justemp::on_ExporterPDFButton_clicked()
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


void justemp::on_StatistiqueButton_clicked()
{
    Employe emp;
    emp.AfficherStatistiques(this);  // Pass `this` as the parent to the dialog
}


void justemp::on_deconnexionButton_clicked()
{
    this->hide(); // hide the main window
    Dialog *loginWindow = new Dialog(); // reopen the login dialog
    loginWindow->show();
}

void justemp::on_trie_ressource_currentIndexChanged(int index)
{
    if(currentCin == -1) return; // Protection si aucun CIN n'est défini

    if (index == 0) {
        QStandardItemModel *model = Res.afficherRessourceAvecQRCodeparCIN(currentCin);
        if(model) {
            ui->tableRessource_10->setModel(model);
            ui->tableRessource_10->resizeColumnsToContents();
            ui->tableRessource_10->resizeRowsToContents();
        }
        return;
    }

    QString colonne;
    bool croissant = true;

    switch (index) {
    case 1: colonne = "NOM_RESSOURCE"; croissant = true; break;
    case 2: colonne = "NOM_RESSOURCE"; croissant = false; break;
    case 3: colonne = "ID_RESSOURCE"; croissant = true; break;
    case 4: colonne = "ID_RESSOURCE"; croissant = false; break;
    case 5: colonne = "DATE_AQCISITION"; croissant = true; break;
    case 6: colonne = "DATE_AQCISITION"; croissant = false; break;
    default:
        qDebug() << "Index de tri invalide :" << index;
        return;
    }

    QStandardItemModel *model = Res.trierRessourcesAvecQRCodeparCIN(currentCin, colonne, croissant);
    if (model) {
        ui->tableRessource_10->setModel(model);
        ui->tableRessource_10->resizeColumnsToContents();
        ui->tableRessource_10->resizeRowsToContents();
    } else {
        qDebug() << "Échec du tri des ressources";
    }
}


void justemp::afficherRessourcesemploye(int cin)
{


    //QSqlQueryModel * model = Res.afficherRessource();
    // ui->tableRessource->setModel(model);
    QStandardItemModel *model = Res.afficherRessourceAvecQRCodeparCIN(cin);

    // Afficher le modèle dans la table
    ui->tableRessource_10->setModel(model);
    ui->tableRessource_10->resizeColumnsToContents();
    ui->tableRessource_10->resizeRowsToContents();
    ui->chercherRESSOURCE_10->setPlaceholderText("Recherche des ressources par nom");
    ui->tableRessource_10->setEditTriggers(QAbstractItemView::NoEditTriggers);

}
void justemp::on_chercherRESSOURCE_textChanged(const QString &arg1)
{
    if(currentCin == -1) return; // Protection si aucun CIN n'est défini

    QString nomRecherche = arg1.trimmed();
    QStandardItemModel* nouveauModel = nullptr;

    if (nomRecherche.isEmpty()) {
        nouveauModel = Res.afficherRessourceAvecQRCodeparCIN(currentCin);
    } else {
        nouveauModel = Res.chercherparCIN(nomRecherche, currentCin);
    }

    if (nouveauModel) {
        ui->tableRessource_10->setModel(nouveauModel);
        ui->tableRessource_10->resizeColumnsToContents();
        ui->tableRessource_10->resizeRowsToContents();

        if (nouveauModel->rowCount() == 0 && !nomRecherche.isEmpty()) {
            QMessageBox::information(this, "Information", "Aucune ressource trouvée.");
            // Recharger toutes les ressources
            QStandardItemModel* model = Res.afficherRessourceAvecQRCodeparCIN(currentCin);
            ui->tableRessource_10->setModel(model);
            ui->tableRessource_10->resizeColumnsToContents();
            ui->tableRessource_10->resizeRowsToContents();
            ui->chercherRESSOURCE_10->setPlaceholderText("Recherche des ressources par nom");
            ui->tableRessource_10->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }
    } else {
        qDebug() << "Erreur lors de la création du modèle";
    }
}
//Metier tri
void justemp::chargerComboBoxtriRessources() {
    ui->trie_ressource_10->clear();
    ui->trie_ressource_10->addItem("trier ressource par");
    ui->trie_ressource_10->setItemData(0, QVariant(0), Qt::UserRole - 1);
    ui->trie_ressource_10->addItem("Nom Ressource ▲");
    ui->trie_ressource_10->addItem("Nom Ressource ▼");
    ui->trie_ressource_10->addItem("ID Ressource ▲");
    ui->trie_ressource_10->addItem("ID Ressource ▼");
    ui->trie_ressource_10->addItem("Date d'acquisition ▲");
    ui->trie_ressource_10->addItem("Date d'acquisition ▼");}



void justemp::gestionRessourcesparCIN(int cin)
{
    currentCin = cin;
    afficherRessourcesemploye(cin);

    chargerComboBoxtriRessources();

}

//Metier PDF
void justemp::on_CherRessourceNom_7_clicked()
{
    QSqlQueryModel *model = Res.afficherRessourceEmplo(currentCin);

    DialogRessource dialog;
    dialog.genererPDF(model);  // Génère et affiche le PDF
    dialog.exec();             // Affiche la fenêtre modale
    dialog.deleteLater();      // Nettoyage mémoire

    delete model;  // Nettoyage du modèle
}

//RENDEZVOUS
void justemp::on_afficherRV_7_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    RendezVous r;

    model = r.AfficherRendezVous();

    ui->tableView2RV_7->setModel(model);

    for (int i = 0; i < model->rowCount(); ++i) {
        ui->tableView2RV_7->setRowHidden(i, false); // Montrer toutes les lignes
    }

    r.trierParId(ui->tableView2RV_7);
}

void justemp::on_chercherRV_7_clicked()
{
    QString texteRecherche = ui->rechercheRV_7->text();  // Récupérer le texte de recherche

    if (texteRecherche.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un texte à rechercher.");
        return;
    }

    RendezVous r;
    r.rechercher(ui->tableView2RV_7, texteRecherche);
}

void justemp::on_exporterRV_7_clicked()
{
    RendezVous r;

    r.exporter(ui->tableView2RV_7);

    QMessageBox::information(this, "Succès", "Le fichier CSV a été exporté avec succès.");
}

void justemp::afficherNotification(const QString &message)
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

void justemp::afficherRendezVousAujourdHui()
{
    RendezVous r;
    int nombreRendezVous = r.compterRendezVousDuJour();

    QString message = QString("Vous avez %1 rendez-vous aujourd'hui").arg(nombreRendezVous);
    afficherNotification(message);

}

void justemp::displayCalendar()
{
    ui->graphicsViewCal_RV_7->scene()->clear();

    QString monthName = currentDate.toString("MMMM yyyy");

    QGraphicsTextItem *monthLabel = new QGraphicsTextItem(monthName);
    monthLabel->setPos(100, 10);
    ui->graphicsViewCal_RV_7->scene()->addItem(monthLabel);

    QStringList daysOfWeek = {"Lun", "Mar", "Mer", "Jeu", "Ven", "Sam", "Dim"};
    int xOffset = 20;
    int yOffset = 50;

    for (int i = 0; i < 7; ++i) {
        QGraphicsTextItem *dayOfWeekLabel = new QGraphicsTextItem(daysOfWeek[i]);
        dayOfWeekLabel->setPos(xOffset + i * 50, yOffset);
        ui->graphicsViewCal_RV_7->scene()->addItem(dayOfWeekLabel);
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
        ui->graphicsViewCal_RV_7->scene()->addItem(dayItem);

        QDate currentDay(currentDate.year(), currentDate.month(), i);
        if (rdvParJour.contains(currentDay)) {
            QGraphicsEllipseItem *circle = new QGraphicsEllipseItem(dayPos.x(), dayPos.y() + 20, 10, 10);
            circle->setBrush(Qt::blue);
            circle->setPen(Qt::NoPen);
            ui->graphicsViewCal_RV_7->scene()->addItem(circle);
        }
    }
}

void justemp::previousMonth()
{
    currentDate = currentDate.addMonths(-1);
    displayCalendar();
}

void justemp::nextMonth()
{
    currentDate = currentDate.addMonths(1);
    displayCalendar();
}
//--------------------------------- yasss


void justemp::on_sendButton_clicked()
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
void justemp::onCorpsTextChanged()
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
void justemp::showSuggestions(const QStringList &suggestions)
{
    suggestionListWidget->clear();
    suggestionListWidget->addItems(suggestions);

    // Position sous le QTextEdit
    QPoint pos = ui->corps->mapToGlobal(QPoint(0, ui->corps->height()));
    suggestionListWidget->move(pos);
    suggestionListWidget->resize(300, suggestions.size() * 30);
    suggestionListWidget->show();
}
void justemp::onSuggestionClicked(QListWidgetItem* item)
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


void justemp::onEmailTextChanged()
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

void justemp::on_TRIERPartenair_clicked()
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
void justemp::on_envoyer_clicked()
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


}

void justemp::on_ExporterPDF_clicked()
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


void justemp::on_AfficherStatistique_clicked()
{

    QWidget *chartWidget = findChild<QWidget *>("chartContainer");
    if (chartWidget) {
        Part.genererStatistiques(chartWidget);
    } else {
        qDebug() << "Erreur : chartContainer introuvable.";
    }
}

void justemp::on_RechercherPartenair_clicked()
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
void justemp::on_TabP_tabBarClicked(int index)
{
    ui->tableViewP->setModel(Part.afficherP());
}

//----------------------------aziz




void justemp::on_TabC_tabBarClicked(int index)
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




void justemp::on_Exporter_PDF_clicked()
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

void justemp::on_pushButtonTrier_C_clicked()
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
void justemp::on_chercher_clicked()
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


void justemp::loadRatings() {

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

void justemp::displayTasks()
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



void justemp::clearTables()
{
    ui->todo->setModel(nullptr);
    ui->doing->setModel(nullptr);
    ui->done->setModel(nullptr);
}

void justemp::on_add_clicked()
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

int justemp::generateUniqueTaskId()
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


void justemp::on_movetodoing_clicked()
{
    QModelIndex selectedIndex= ui->todo->selectionModel()->currentIndex();
    if (selectedIndex.isValid()) {
        int taskId = selectedIndex.siblingAtColumn(0).data().toInt();
        moveTask(2,taskId);
    }}

void justemp::on_movetodone_clicked()
{
    QModelIndex selectedIndex= ui->doing->selectionModel()->currentIndex();
    if (selectedIndex.isValid()) {
        int taskId = selectedIndex.siblingAtColumn(0).data().toInt();
        moveTask(3,taskId);
    }}
void justemp::moveTask(int newType,int taskId)
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


void justemp::on_delete_2_clicked()
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



#include "mainwindow.h"
#include "qlayout.h"
#include "ui_mainwindow.h"
#include "QSqlError"
#include "empreinte.h"
#include "modifierprojetdialog.h"
#include <QString>
#include <QDateTime>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QLayoutItem>
#include <QPieSlice>
#include <QPieSeries>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQuickItem>
#include "projetmodel.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_projetModel = new ProjetModel(this);
    m_projetModel->refreshProjets();

    ui->quickWidget_MapView->engine()->rootContext()->setContextProperty("projetModel", m_projetModel);
    ui->quickWidget_MapView->setSource(QUrl(QStringLiteral("qrc:/QmlMap.qml")));
    ui->quickWidget_MapView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
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
    }

}


void MainWindow::on_Partenaire_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page4_PARTENAIRES);
}

void MainWindow::on_Ressources_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page6_RESSOURCES);
}

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

void MainWindow::on_id_employe_currentIndexChanged(int index)
{
    if (index == 0) {
        clearTables();
    } else {
        int employeeId = ui->id_employe->currentText().toInt();
        displayTasks(employeeId);
    }
}

void MainWindow::displayTasks(int employeeId)
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
    int employeeId = ui->id_employe->currentText().toInt();

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
        displayTasks(employeeId);
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
            displayTasks(ui->id_employe->currentText().toInt());
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
            displayTasks(ui->id_employe->currentText().toInt());
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

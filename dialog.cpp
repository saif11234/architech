#include "dialog.h"
#include "ui_dialog.h"
#include "connection.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include "employe.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>
#include <QGraphicsView>
#include "mainwindow.h"
#include <QApplication>
#include <QBuffer>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QStandardPaths>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    serial(new QSerialPort(this))

{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("COM5"); // Replace with your actual Arduino COM port
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    connect(serial, &QSerialPort::readyRead, this, &Dialog::readSerial);
    if (!serial->open(QIODevice::ReadWrite)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le port série.");
    } else {
        QMessageBox::information(this, "OK", "Port série ouvert avec succès.");
    }
    QList<QCameraDevice> cameras = QMediaDevices::videoInputs();
    if (cameras.isEmpty()) {
        qDebug() << "No camera found!";
        return;
    }

    camera = new QCamera(cameras.first(), this);
    captureSession = new QMediaCaptureSession(this);
    imageCapture = new QImageCapture(this);

    captureSession->setCamera(camera);
    captureSession->setImageCapture(imageCapture);

    connect(imageCapture, &QImageCapture::imageCaptured,
            this, &Dialog::handleImageCaptured);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_loginButton_clicked()
{
    int cin = ui->cin_login->text().toInt();
    QString password = ui->mot_de_passe_login->text();

    if (cin == 0 || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYE WHERE CIN_EMPLOYE = :cin AND MOT_DE_PASSE = :password");
    query.bindValue(":cin", cin);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        qDebug() << "✅ Login successful!";
        int loggedInCIN = query.value("CIN_EMPLOYE").toInt();
        qDebug() << "👤 CIN transmis:" << loggedInCIN;

        if (loggedInCIN == 121212) {
            // Afficher MainWindow pour l'admin
            MainWindow *mainWindow = new MainWindow();
            mainWindow->setCIN(loggedInCIN);
            mainWindow->show();
            accept();
       } else {
            // Afficher justemp pour un employé normal
            justemp *empWindow = new justemp();
            empWindow->setCIN(loggedInCIN); // crée cette méthode si besoin
            empWindow->show();


       this->hide();
        accept();
       }
    }else {
        QMessageBox::warning(this, "Erreur", "Nom d'utilisateur ou mot de passe incorrect !");
    }


}
void Dialog::on_signup_clicked()
{
    QString cin = ui->lineEdit_cin->text();
    QString mdp = ui->lineEdit_mdp->text();

    QSqlQuery query;
    query.prepare("SELECT empreinte FROM employe WHERE cin_employe = :cin AND mot_de_passe = :mdp");
    query.bindValue(":cin", cin);
    query.bindValue(":mdp", mdp);

    if (query.exec() && query.next()) {
        int empreinte = query.value(0).toInt();
        if (empreinte == 1) {
            QMessageBox::information(this, "Erreur", "Empreinte déjà enregistrée.");
            return;
        }

        currentCin = cin.toInt();
        currentCommand = "signup";
        sendCommandToArduino("signup", currentCin);

    } else {
        QMessageBox::warning(this, "Erreur", "CIN ou mot de passe incorrect.");
    }
}



void Dialog::on_login_clicked()
{
    currentCin = ui->cin_login->text().toInt();

    QSqlQuery query;
    query.prepare("SELECT empreinte , chance FROM employe WHERE cin_employe = :cin");
    query.bindValue(":cin", currentCin);

    if (!query.exec() || !query.next()) {
        showError("CIN non trouvé");
        return;
    }

    int empreinteStatus = query.value(0).toInt();
    if (empreinteStatus != 1) {
        showError("Aucune empreinte enregistrée");
        return;
    }
    int chance = query.value(1).toInt();
    chance-=1;
    query.prepare("UPDATE employe SET chance = :chance WHERE cin_employe = :cin");
    query.bindValue(":chance", chance);
    query.bindValue(":cin", currentCin);

    if (!query.exec()) {
        showError("Échec de la mise à jour de 'chance'");
        return;
    }


    if(chance<1) {
        silentCaptureAndSave();
        serial->write("alarmon");
    }
    currentCommand = "login";
    sendCommandToArduino("login", currentCin);
}

void Dialog::sendCommandToArduino(const QString &command, int cin)
{
    QString message = QString("%1:%2\n").arg(command).arg(cin);
    serial->write(message.toUtf8());
}

void Dialog::readSerial()
{
    QByteArray data = serial->readAll();
    QString response = QString::fromUtf8(data).trimmed();

    if (currentCommand == "signup") {
        if (response == "success") {
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE employe SET empreinte = 1, signup_date = TO_TIMESTAMP(SYSDATE, 'YYYY-MM-DD HH24:MI:SS') WHERE cin_employe = :cin");
            updateQuery.bindValue(":cin", currentCin);

            if (updateQuery.exec()) {
                showSuccess("Inscription réussie et date d'inscription enregistrée");
            } else {
                showError("Échec de la mise à jour SQL");
            }
        } else if (response == "fail")  {
            showError("Échec de l'enregistrement de l'empreinte");
        }
    } else if (currentCommand == "login") {
        if (response == "match") {
            showSuccess("Connexion réussie");
            QSqlQuery query;
            query.prepare("SELECT empreinte , chance FROM employe WHERE cin_employe = :cin");
            query.bindValue(":cin", currentCin);
            int chance = query.value(1).toInt();
            chance=3;
            query.prepare("UPDATE employe SET chance = :chance WHERE cin_employe = :cin");
            query.bindValue(":chance", chance);
            query.bindValue(":cin", currentCin);
            if (currentCin == 121212) {
                MainWindow *mainWindow = new MainWindow();
                mainWindow->setCIN(currentCin);
                mainWindow->show();
                accept();
            } else {
                justemp *empWindow = new justemp();
                empWindow->setCIN(currentCin);
                empWindow->show();
                this->hide();
                accept();
            }
        } else if(response=="different"){
            showError("Empreinte incorrecte");
        }
    }
    currentCommand.clear();
}

void Dialog::showError(const QString &message)
{
    QMessageBox::critical(this, "Erreur", message);
}

void Dialog::showSuccess(const QString &message)
{
    QMessageBox::information(this, "Succès", message);
}
void Dialog::on_annuler_clicked()
{
    ui->lineEdit_cin->clear();
    ui->lineEdit_mdp->clear();
}
void Dialog::on_Rest_Button_clicked()
{
    ui->cin_login->clear();
}
void Dialog::silentCaptureAndSave() {
    if (camera) {
        camera->start();
        imageCapture->capture();
    }
}

void Dialog::handleImageCaptured(int id, const QImage &img) {
    QByteArray imageData;
    QBuffer buffer(&imageData);
    buffer.open(QIODevice::WriteOnly);
    if (!img.save(&buffer, "PNG")) {
        qDebug() << "Failed to convert image to PNG!";
        return;
    }

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE employe SET picture = :imageData WHERE cin_employe = :cin");
    updateQuery.bindValue(":imageData", imageData);
    updateQuery.bindValue(":cin", currentCin);

    if (!updateQuery.exec()) {
        showError("Échec de la mise à jour SQL");
    }

    camera->stop();
}


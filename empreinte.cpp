#include "empreinte.h"
#include "ui_empreinte.h"
#include "mainwindow.h"
#include <QBuffer>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QStandardPaths>
empreinte::empreinte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::empreinte),
    serial(new QSerialPort(this))
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("COM4"); // Replace with your actual Arduino COM port
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    connect(serial, &QSerialPort::readyRead, this, &empreinte::readSerial);


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
            this, &empreinte::handleImageCaptured);

}

empreinte::~empreinte()
{
    delete ui;
}

void empreinte::on_signup_clicked()
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



void empreinte::on_login_clicked()
{
    currentCin = ui->lineEdit_cin2->text().toInt();

    QSqlQuery query;
    query.prepare("SELECT empreinte FROM employe WHERE cin_employe = :cin");
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

    currentCommand = "login";
    sendCommandToArduino("login", currentCin);
}

void empreinte::sendCommandToArduino(const QString &command, int cin)
{
    QString message = QString("%1:%2\n").arg(command).arg(cin);
    serial->write(message.toUtf8());
}

void empreinte::readSerial()
{
    QByteArray data = serial->readAll();
    QString response = QString::fromUtf8(data).trimmed();

    if (currentCommand == "signup") {
        if (response == "success") {
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE employe SET empreinte = 1 WHERE cin_employe = :cin");
            updateQuery.bindValue(":cin", currentCin);
            if (updateQuery.exec()) {
                showSuccess("Inscription réussie");
            } else {
                showError("Échec de la mise à jour SQL");
            }
        } else if (response == "fail")  {
            showError("Échec de l'enregistrement de l'empreinte");
        }
    } else if (currentCommand == "login") {
        if (response == "match") {
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE employe SET lastlogin =  TO_CHAR(SYSDATE, 'YYYY-MM-DD HH24:MI:SS') WHERE cin_employe = :cin");
            updateQuery.bindValue(":cin", currentCin);
            showSuccess("Connexion réussie");
            this->close();
            MainWindow *mainWin = new MainWindow();
            mainWin->show();
        } else if(response=="different"){
            showError("Empreinte incorrecte");
        }else if(response=="problem"){
            silentCaptureAndSave();
        }
    }
    currentCommand.clear();
}

void empreinte::showError(const QString &message)
{
    QMessageBox::critical(this, "Erreur", message);
}

void empreinte::showSuccess(const QString &message)
{
    QMessageBox::information(this, "Succès", message);
}
void empreinte::on_annuler_clicked()
{
   ui->lineEdit_cin->clear();
    ui->lineEdit_mdp->clear();
}
void empreinte::on_annuler2_clicked()
{
    ui->lineEdit_cin2->clear();
}
void empreinte::silentCaptureAndSave() {
    if (camera) {
        camera->start();
        imageCapture->capture();
    }
}

void empreinte::handleImageCaptured(int id,const QImage &img) {
    QByteArray imageData;
    QBuffer buffer(&imageData);
    buffer.open(QIODevice::WriteOnly);
    if (!img.save(&buffer, "PNG")) {
        qDebug() << "Failed to convert image to PNG!";
        return;
    }

    int id_alarm = 0;
    bool unique = false;

    while (!unique) {
        id_alarm++;

        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT COUNT(*) FROM ALARM WHERE ID_ALARM = :id_alarm");
        checkQuery.bindValue(":id_alarm", id_alarm);

        if (checkQuery.exec() && checkQuery.next()) {
            unique = (checkQuery.value(0).toInt() == 0);
        } else {
            qDebug() << "ID check error:" << checkQuery.lastError().text();
            return;
        }
    }

    QSqlQuery query;
    query.prepare(
        "INSERT INTO alarm (id_alarm, date_alarm, picture) "
        "VALUES (:id_alarm, TO_CHAR(SYSDATE, 'YYYY-MM-DD HH24:MI:SS'), :picture)"
        );
    query.bindValue(":id_alarm", id_alarm);
    query.bindValue(":picture", imageData);

    if (!query.exec()) {
        qDebug() << "Oracle error:" << query.lastError().text();
    } else {
        qDebug() << "PNG saved to Oracle with ID:" << id_alarm;
    }

    camera->stop();
}

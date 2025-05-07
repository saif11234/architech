#include "arduino.h"
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QSqlQuery>
#include <QSqlError>
#include "Arduino.h"

Arduino::Arduino() {
    serial = new QSerialPort();
    arduino_is_available = false;
    arduino_port_name = "COM3";
    data = "";
}

int Arduino::connect_arduino() {
    // Vérification des ports disponibles
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Port trouvé: " << serial_port_info.portName();
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
                serial_port_info.productIdentifier() == arduino_uno_producy_id) {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
                qDebug() << "Arduino trouvé sur le port :" << arduino_port_name;
                break;
            }
        }
    }

    // Si l'Arduino a été trouvé
    if (arduino_is_available) {
        serial->setPortName(arduino_port_name);
        if (serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);

            qDebug() << "Connexion Arduino réussie.";
            return 0;  // Connexion réussie
        } else {
            // Échec de l'ouverture du port
            qDebug() << "Échec de l'ouverture du port : " << serial->errorString();
            return 1;  // Échec
        }
    } else {
        qDebug() << "Aucun Arduino trouvé.";
        return 2;  // Aucun Arduino détecté
    }
}

void Arduino::reconnect() {
    if (serial->isOpen()) {
        serial->close();
    }
    connect_arduino();
}

int Arduino::close_arduino (){
    if(serial->isOpen()) {
        serial->close();
        return 0;
    }
    return 1;
}
QByteArray Arduino::read_from_arduino() {
    if (serial->canReadLine()) {
        QByteArray line = serial->readLine().trimmed();  // lit une ligne complète
        return line;
    }
    return QByteArray();
}





void Arduino:: write_to_arduino ( QByteArray d ){ //ychuf ken el port dispo

    if(serial->isWritable()){

        serial->write(d);
    }else{
        // envoyer des donnés vers Arduino
        qDebug() << "Couldn't write to serial!";
    }
}
QSerialPort* Arduino::getserial() // Renvoie le pointeur vers le port série
{
    return serial;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}
//jdod
bool Arduino::compare_with_database(QString rfidCode) {
    QSqlQuery query;
    query.prepare("SELECT CIN_EMPLOYE, ETATCOFFRE FROM EMPLOYE WHERE RFIDCODE = :code");
    query.bindValue(":code", rfidCode);

    if (query.exec() && query.next()) {
        int cin = query.value(0).toInt();
        int etatCoffre = query.value(1).toInt();  //te5o l'etat de coffre


        if (etatCoffre == 1) {

            QSqlQuery update;
            update.prepare("UPDATE EMPLOYE SET ETATCOFFRE = 0 WHERE CIN_EMPLOYE = :cin");
            update.bindValue(":cin", cin);
            update.exec();
            qDebug() << "Coffre fermé pour CIN_EMPLOYE" << cin;
            return true;
        }


        if (etatCoffre == 0) {

            QSqlQuery update;
            update.prepare("UPDATE EMPLOYE SET ETATCOFFRE = 1 WHERE CIN_EMPLOYE = :cin");
            update.bindValue(":cin", cin);
            update.exec();
            qDebug() << "Coffre ouvert pour CIN_EMPLOYE" << cin;
            return true;
        }

        return false;
    } else {
        qDebug() << "RFID inconnu dans la base de données : " << rfidCode;
        return false;  // RFID inconnu
    }
}
int Arduino::getETATCOOFRE(QString rfidCode) {
    if (rfidCode.isEmpty()) {
        qDebug() << "rfidCode est vide, impossible de récupérer l'état du coffre.";
        return -1;
    }

    QSqlQuery query;
    query.prepare("SELECT ETATCOFFRE FROM EMPLOYE WHERE RFIDCODE = :code");  // Requête pour récupérer l'état du coffre
    query.bindValue(":code", rfidCode);
    if (query.exec() && query.next()) {
        int etatCoffre = query.value(0).toInt();  // Récupère l'état du coffre
        qDebug() << "État du coffre : " << etatCoffre;
        return etatCoffre;  // Retourne l'état du coffre (0 ou 1)
    } else {
        // Ajout de détails supplémentaires pour déboguer l'erreur
        qDebug() << "Erreur lors de la récupération de l'état du coffre : ";
        qDebug() << "Requête SQL : " << query.lastQuery();
        qDebug() << "Erreur SQL : " << query.lastError().text();
        return -1;  // Retourne -1 en cas d'erreur de requête ou si le RFID est inconnu
    }
}
QString Arduino::getNomEmploye(QString rfidCode) {
    if (rfidCode.isEmpty()) {
        qDebug() << "rfidCode est vide, impossible de récupérer le nom.";
        return QString();
    }

    QSqlQuery query;
    query.prepare("SELECT PRENOM FROM EMPLOYE WHERE RFIDCODE = :code");
    query.bindValue(":code", rfidCode);

    if (query.exec() && query.next()) {
        QString nom = query.value(0).toString();
        qDebug() << "Nom de l'employé : " << nom;
        return nom;
    } else {
        qDebug() << "Erreur lors de la récupération du nom : " << query.lastError().text();
        return QString();
    }
}

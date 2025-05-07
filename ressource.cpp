#include "ressource.h"
#include "qsqlerror.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>
#include <QObject>
#include <QVariant>
#include <QList>
#include <QPainter>
#include "connection.h"
#include <QPrinter>       // Pour la génération PDF
#include <QTextDocument>  // Pour créer le contenu PDF
#include <QFileDialog>    // Pour choisir l'emplacement du PDF
#include <QDesktopServices>
#include <QPdfWriter>


//Constructeur par defaut
Ressource::Ressource() {
    nomRessource="";
    typeRessource="";
    etatRessource="";
}

//Constructeur parametre 1
Ressource:: Ressource(int idEmploye, int id_ressource, QString typeRessource ,QString nomRessource ,QString etatRessource, QDate dateAcquisition)
{
     this->CINEmploye=idEmploye;
     this->id_ressource=id_ressource;
     this->typeRessource=typeRessource;
     this->nomRessource=nomRessource;
     this->etatRessource=etatRessource;
     this->dateAcquisition=dateAcquisition;
}


//constructeur parametre 2
Ressource::Ressource(int id_ressource, QString typeRessource ,QString nomRessource ,QString etatRessource, QDate dateAcquisition)
{

    this->id_ressource=id_ressource;
    this->typeRessource=typeRessource;
    this->nomRessource=nomRessource;
    this->etatRessource=etatRessource;
    this->dateAcquisition=dateAcquisition;

}
//constructeur parametre 3
Ressource::Ressource(QString typeRessource ,QString nomRessource ,QString etatRessource, QDate dateAcquisition)
{
    this->typeRessource=typeRessource;
    this->nomRessource=nomRessource;
    this->etatRessource=etatRessource;
    this->dateAcquisition=dateAcquisition;

}
// Les setters
void Ressource:: setIdEmploye(int id) { CINEmploye = id; }
void Ressource::setIdRessource(int id) { id_ressource = id; }
void Ressource::setType(QString t) { typeRessource = t; }
void Ressource::setNomRessource(QString n) { nomRessource = n; }
void Ressource::setEtat(QString etat) { etatRessource = etat; }
void Ressource::setDateAcquisition(QDate date) { dateAcquisition = date; }

//Les getters
int Ressource::get_idEmploye() { return CINEmploye; }
int Ressource::get_idRessource() { return id_ressource; }
QString Ressource::get_Type() { return typeRessource; }
QString Ressource::get_nomRessource() { return nomRessource; }
QString Ressource::get_Etat() { return etatRessource; }
QDate Ressource::get_DateAcquisition() { return dateAcquisition; }

//Les methodes CRUD
//Ajout
 bool Ressource::AjouterRessource()
{
     QSqlQuery query;
    query.prepare("INSERT INTO RESSOURCES (NOM_RESSOURCE, TYPE, ETAT, DATE_AQCISITION) "
                  "VALUES (:NOM_RESSOURCE, :TYPE, :ETAT, TO_DATE(:DATE_AQCISITION, 'DD-MM-YYYY'))");
    query.bindValue(":NOM_RESSOURCE", nomRessource);
    query.bindValue(":TYPE", typeRessource);
    query.bindValue(":ETAT", "Disponible");
    query.bindValue(":DATE_AQCISITION", dateAcquisition.toString("dd-MM-yyyy"));
    return query.exec();

}


Ressource Ressource::getRessourceById(int id)
{
    QSqlQuery query;
    Ressource res;

    // Préparation de la requête SQL pour récupérer la ressource par son ID
    query.prepare("SELECT * FROM ressources WHERE id_ressource = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        Ressource res(query.value("id_ressource").toInt(), query.value("type").toString() ,query.value("nom_Ressource").toString() ,query.value("etat").toString(), query.value("date_aqcisition").toDate());

            res.setIdRessource(query.value("id_ressource").toInt());
            res.setType(query.value("type").toString());
            res.setNomRessource(query.value("nom_ressource").toString());
            res.setEtat(query.value("etat").toString());
            res.setDateAcquisition(query.value("date_aqcisition").toDate());
            if(res.get_Etat()=="Affecter")
                res.setIdEmploye(query.value("cin_employe").toInt());
            return res;
    } else {
        qDebug() << "Erreur lors de la récupération de la ressource:" << query.lastError().text();
    }

    return res;
}
//Affichage
QPixmap Ressource::generateQRCode(const QString& text, int size) {
    qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(text.toUtf8().constData(), qrcodegen::QrCode::Ecc::MEDIUM);
    QImage image(qr.getSize(), qr.getSize(), QImage::Format_RGB32);
    image.fill(Qt::white);

    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            if (qr.getModule(x, y)) {
                image.setPixel(x, y, qRgb(0, 0, 0));  // Module noir
            }
        }
    }

    return QPixmap::fromImage(image.scaled(size, size, Qt::KeepAspectRatio));
}

// Méthode pour afficher les ressources avec QR codes
QStandardItemModel* Ressource::afficherRessourceAvecQRCode() {
    QSqlQuery query("SELECT ID_RESSOURCE, NOM_RESSOURCE, TYPE, ETAT, DATE_AQCISITION, CIN_EMPLOYE FROM RESSOURCES");

    // Créer un modèle personnalisé
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(7);  // Ajouter une colonne pour le QR code

    // Définir les en-têtes avec des retours à la ligne
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom\nRessource"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type\nRessource"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat\nRessource"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date\nd'acquisition"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN\nemploye"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("QR Code"));  // Colonne QR code

    int row = 0;
    while (query.next()) {
        // Récupérer les données de la base de données
        QString id = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString type = query.value(2).toString();
        QString etat = query.value(3).toString();
        QDate date = query.value(4).toDate();
        QString cin = query.value(5).toString();
        // Formater la date en YYYY/MM/DD
        QString formattedDate = date.toString("yyyy/MM/dd");

        // Ajouter les données au modèle
        model->setItem(row, 0, new QStandardItem(id));
        model->setItem(row, 1, new QStandardItem(nom));
        model->setItem(row, 2, new QStandardItem(type));
        model->setItem(row, 3, new QStandardItem(etat));
        model->setItem(row, 4, new QStandardItem(formattedDate));
        model->setItem(row, 5, new QStandardItem(cin));

        // Générer le QR code pour l'état de la ressource
       // QPixmap qrCodePixmap = generateQRCode(etat, 60);  // Taille du QR code : 60x60
       // QStandardItem *qrCodeItem = new QStandardItem();
       // qrCodeItem->setData(qrCodePixmap, Qt::DecorationRole);  // Ajouter l'image du QR code
       // model->setItem(row, 6, qrCodeItem);

       // row++;
        if (cin=="0")
        {        QString qrData = QString("ID de Ressouce : %1\nNom du Ressouce : %2\nType du Ressource : %3\nEtat du ressource : %4\n Date d'acquisition : %5")
                                 .arg(id)
                                 .arg(nom)
                                 .arg(type)
                                 .arg(etat)
                                 .arg(formattedDate);
            // Générer le QR code pour l'état de la ressource
            QString logoPath = "../logo.jpg";  // Chemin vers le logo
            QPixmap qrCodePixmap = generateQRCodeWithLogo(qrData, 100, logoPath);
            // QPixmap qrCodePixmap = generateQRCode(qrData, 80);  // Taille du QR code : 60x60
            QStandardItem *qrCodeItem = new QStandardItem();
            qrCodeItem->setData(qrCodePixmap, Qt::DecorationRole);  // Ajouter l'image du QR code
            model->setItem(row, 6, qrCodeItem);

            row++;
        }
        else{
            QString qrData = QString("ID de Ressouce : %1\nNom du Ressouce : %2\nType du Ressource : %3\nEtat du ressource : %4\n Date d'acquisition : %5\n CIN de l'employe: %6")
            .arg(id)
                .arg(nom)
                .arg(type)
                .arg(etat)
                .arg(formattedDate)
                .arg(cin);

            // Générer le QR code pour l'état de la ressource
            QString logoPath = "../logo.jpg";  // Chemin vers le logo
            QPixmap qrCodePixmap = generateQRCodeWithLogo(qrData, 100, logoPath);
            // QPixmap qrCodePixmap = generateQRCode(qrData, 80);  // Taille du QR code : 60x60
            QStandardItem *qrCodeItem = new QStandardItem();
            qrCodeItem->setData(qrCodePixmap, Qt::DecorationRole);  // Ajouter l'image du QR code
            model->setItem(row, 6, qrCodeItem);

            row++;
        }
    }


    return model;
}

QSqlQueryModel *Ressource::afficherRessource() {
    QSqlQueryModel *model = new QSqlQueryModel();

    // Modifier la requête pour sélectionner les colonnes de la table ressource
    model->setQuery("SELECT ID_RESSOURCE,NOM_RESSOURCE, TYPE, ETAT, DATE_AQCISITION,CIN_EMPLOYE FROM RESSOURCES");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID \n Ressource"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom du \nRessource"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type de\n ressource"));

    model->setHeaderData(3,Qt::Horizontal,QObject::tr("etat du\n ressource"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date \n d'acquisition"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("CIN \n employees"));

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de la récupération des ressources : " << model->lastError().text();
        return nullptr;
    }

    return model;
}


//Suppression
bool Ressource::SupprimerRessource(int id)
{
    QSqlQuery query;
    if (id <= 0) {
        qDebug() << "Erreur : ID invalide. L'ID doit être un nombre positif.";
        return false;
    }
    // Préparer la requête SQL pour supprimer une ressource par ID
    query.prepare("DELETE FROM RESSOURCES WHERE ID_RESSOURCE = :id");
    query.bindValue(":id", id);

    // Exécuter la requête et retourner le résultat
    if (query.exec()) {
        qDebug() << "Ressource supprimée avec succès !";
        return true;
    } else {
        qDebug() << "Erreur lors de la suppression: " << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* Ressource::recupererIDs() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_RESSOURCE FROM RESSOURCES");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de la récupération des IDs :" << model->lastError().text();
    }

    return model;
}

 QSqlQueryModel* Ressource::recupererIDsEmploye()
{
     QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("SELECT CIN_EMPLOYE FROM EMPLOYE");

     if (model->lastError().isValid()) {
         qDebug() << "Erreur lors de la récupération des IDs :" << model->lastError().text();
     }

     return model;
}


//Modifier
bool Ressource::modifierRessource(Ressource& ressource)
{
    QSqlQuery query;
    query.prepare("UPDATE ressources SET TYPE = :type, NOM_RESSOURCE = :nom, ETAT = :etat, DATE_AQCISITION = :date, CIN_EMPLOYE = :cinE WHERE ID_RESSOURCE = :id");

    // Liaison des valeurs aux paramètres de la requête
    query.bindValue(":type", ressource.get_Type());
    query.bindValue(":nom", ressource.get_nomRessource());
    query.bindValue(":etat", ressource.get_Etat());
    query.bindValue(":date", ressource.get_DateAcquisition());
    query.bindValue(":id", ressource.get_idRessource());
    if (ressource.get_Etat() == "Affecter") {
        query.bindValue(":cinE", ressource.get_idEmploye()); // Utiliser la valeur de l'employé
    } else {
        query.bindValue(":cinE", QVariant(QVariant::Int)); // NULL pour "Disponible" ou "En panne"
    }
    if (query.exec()) {
        qDebug() << "Ressource modifiée avec succès !";
        return true;
    } else {
        qDebug() << "Erreur lors de la modification de la ressource :" << query.lastError().text();
        return false;
    }
}


//Metier Statistique
QMap<QString, int> Ressource::getStatistiquesTypes()
{

    QMap<QString, int> statistiques;
    QSqlQuery query;
    query.prepare("SELECT TYPE, COUNT(*) AS nombre FROM RESSOURCES GROUP BY TYPE");
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        return statistiques;
    }
    // Remplir la map avec les résultats de la requête
    while (query.next()) {
        QString type = query.value("TYPE").toString();
        int nombre = query.value("nombre").toInt();
        statistiques.insert(type, nombre);
    }
    return statistiques;
}

/*
QMap<QString, QMap<QString, int>> Ressource::getStatistiquesCompletes()
{
    QMap<QString, QMap<QString, int>> result;

    QSqlQuery query("SELECT type, "
                    "SUM(CASE WHEN etat='disponible' THEN 1 ELSE 0 END) as disponible, "
                    "SUM(CASE WHEN etat='panne' THEN 1 ELSE 0 END) as panne, "
                    "SUM(CASE WHEN etat='affecte' THEN 1 ELSE 0 END) as affecte "
                    "FROM ressources GROUP BY type");

    while (query.next()) {
        QString type = query.value("type").toString();
        result[type]["disponible"] = query.value("disponible").toInt();
        result[type]["panne"] = query.value("panne").toInt();
        result[type]["affecte"] = query.value("affecte").toInt();
    }

    return result;
}

*/

//Metier Recherche
QStandardItemModel* Ressource::chercher(const QString& nom) {
    // Créer un modèle personnalisé
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(7);  // Ajouter une colonne pour le QR code
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom\nRessource"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type\nRessource"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat\nRessource"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date\nd'acquisition"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN\nemploye"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("QRCode"));  // Colonne QR code

    // Préparer la requête SQL
    QSqlQuery query;
    query.prepare("SELECT ID_RESSOURCE, NOM_RESSOURCE, TYPE, ETAT, DATE_AQCISITION, CIN_EMPLOYE FROM RESSOURCES WHERE nom_ressource LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%");

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        delete model;
        return nullptr;
    }

    // Parcourir les résultats de la requête
    int row = 0;
    while (query.next()) {
        // Récupérer les données de la base de données
        QString id = query.value(0).toString();
        QString nomRessource = query.value(1).toString();
        QString type = query.value(2).toString();
        QString etat = query.value(3).toString();
        QDate date = query.value(4).toDate();
        QString cin = query.value(5).toString();

        // Formater la date en YYYY/MM/DD
        QString formattedDate = date.toString("yyyy/MM/dd");

        // Ajouter les données au modèle
        model->setItem(row, 0, new QStandardItem(id));
        model->setItem(row, 1, new QStandardItem(nomRessource));
        model->setItem(row, 2, new QStandardItem(type));
        model->setItem(row, 3, new QStandardItem(etat));
        model->setItem(row, 4, new QStandardItem(formattedDate));
        model->setItem(row, 5, new QStandardItem(cin));
        if (cin=="0")
        {        QString qrData = QString("ID de Ressouce : %1\nNom du Ressouce : %2\nType du Ressource : %3\nEtat du ressource : %4\n Date d'acquisition : %5")
                                 .arg(id)
                                 .arg(nomRessource)
                                 .arg(type)
                                 .arg(etat)
                                 .arg(formattedDate);
            // Générer le QR code pour l'état de la ressource
            QString logoPath = "../logo.jpg";  // Chemin vers le logo
            QPixmap qrCodePixmap = generateQRCodeWithLogo(qrData, 100, logoPath);
            // QPixmap qrCodePixmap = generateQRCode(qrData, 80);  // Taille du QR code : 60x60
            QStandardItem *qrCodeItem = new QStandardItem();
            qrCodeItem->setData(qrCodePixmap, Qt::DecorationRole);  // Ajouter l'image du QR code
            model->setItem(row, 6, qrCodeItem);

            row++;
                                 }
        else{
        QString qrData = QString("ID de Ressouce : %1\nNom du Ressouce : %2\nType du Ressource : %3\nEtat du ressource : %4\n Date d'acquisition : %5\n CIN de l'employe: %6")
                             .arg(id)
                             .arg(nomRessource)
                             .arg(type)
                             .arg(etat)
                             .arg(formattedDate)
                             .arg(cin);

        // Générer le QR code pour l'état de la ressource
        QString logoPath = "../logo.jpg";  // Chemin vers le logo
        QPixmap qrCodePixmap = generateQRCodeWithLogo(qrData, 100, logoPath);
       // QPixmap qrCodePixmap = generateQRCode(qrData, 80);  // Taille du QR code : 60x60
        QStandardItem *qrCodeItem = new QStandardItem();
        qrCodeItem->setData(qrCodePixmap, Qt::DecorationRole);  // Ajouter l'image du QR code
        model->setItem(row, 6, qrCodeItem);

        row++;
                                 }
    }

    return model;
}


//Metier Alerte
int Ressource::compterRessourcesDisponibles(const QString &typeRessource)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM ressources WHERE type = :type AND etat = 'Disponible'");
    query.bindValue(":type", typeRessource);
    if (query.exec() && query.next()) {
        return query.value(0).toInt(); // Retourne le nombre de ressources disponibles
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        return -1; // Retourne -1 en cas d'erreur
    }
}







//Metier QrCode
QPixmap Ressource::generateQRCodeWithLogo(const QString &text, int size, const QString &logoPath) {
    // Générer le QR code
    qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(text.toUtf8().constData(), qrcodegen::QrCode::Ecc::LOW);

    // Créer une image à partir du QR code
    QImage qrImage(qr.getSize(), qr.getSize(), QImage::Format_ARGB32);
    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            if (qr.getModule(x, y)) {
                qrImage.setPixel(x, y, qRgb(0, 0, 0));  // Noir pour les modules du QR code
            } else {
                qrImage.setPixel(x, y, qRgb(255, 255, 255));  // Blanc pour le fond
            }
        }
    }

    // Redimensionner l'image du QR code à la taille souhaitée
    qrImage = qrImage.scaled(size, size, Qt::KeepAspectRatio);

    // Charger le logo
    QPixmap logo(logoPath);
    if (logo.isNull()) {
        qDebug() << "Erreur : impossible de charger le logo.";
        return QPixmap::fromImage(qrImage);  // Retourner le QR code sans logo
    }

    // Redimensionner le logo pour qu'il s'adapte au centre du QR code
    int logoSize = size / 3.2;  // Taille du logo (1/4 de la taille du QR code)
    logo = logo.scaled(logoSize, logoSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Convertir l'image du QR code en QPixmap
    QPixmap qrPixmap = QPixmap::fromImage(qrImage);

    // Créer un QPainter pour dessiner le logo sur le QR code
    QPainter painter(&qrPixmap);
    int x = (size - logoSize) / 2;  // Position X pour centrer le logo
    int y = (size - logoSize) / 2;  // Position Y pour centrer le logo
    painter.drawPixmap(x, y, logo);  // Dessiner le logo au centre du QR code
    painter.end();

    return qrPixmap;
}

// Metier tri
QStandardItemModel* Ressource::trierRessourcesAvecQRCode(const QString& colonne, bool croissant)
{
    // Construire la requête avec tri
    QString requete = "SELECT ID_RESSOURCE, NOM_RESSOURCE, TYPE, ETAT, DATE_AQCISITION, CIN_EMPLOYE FROM RESSOURCES";

    if (!colonne.isEmpty()) {
        requete += " ORDER BY " + colonne + (croissant ? " ASC" : " DESC");
    }

    QSqlQuery query(requete);

    // Créer le modèle
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(7);

    // Définir les en-têtes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom\nRessource"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type\nRessource"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat\nRessource"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date\nd'acquisition"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN\nemploye"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("QR Code"));

    int row = 0;
    while (query.next()) {
        // Récupération des données
        QString id = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString type = query.value(2).toString();
        QString etat = query.value(3).toString();
        QDate date = query.value(4).toDate();
        QString cin = query.value(5).toString();
        QString formattedDate = date.toString("yyyy/MM/dd");

        // Ajout des données au modèle
        model->setItem(row, 0, new QStandardItem(id));
        model->setItem(row, 1, new QStandardItem(nom));
        model->setItem(row, 2, new QStandardItem(type));
        model->setItem(row, 3, new QStandardItem(etat));
        model->setItem(row, 4, new QStandardItem(formattedDate));
        model->setItem(row, 5, new QStandardItem(cin));

        // Génération du QR Code
        QString qrData;
        if (cin == "0") {
            qrData = QString("ID: %1\nNom: %2\nType: %3\nEtat: %4\nDate: %5")
            .arg(id).arg(nom).arg(type).arg(etat).arg(formattedDate);
        } else {
            qrData = QString("ID: %1\nNom: %2\nType: %3\nEtat: %4\nDate: %5\nCIN: %6")
            .arg(id).arg(nom).arg(type).arg(etat).arg(formattedDate).arg(cin);
        }

        QString logoPath = "../logo.jpg";
        QPixmap qrCodePixmap = generateQRCodeWithLogo(qrData, 100, logoPath);
        QStandardItem *qrCodeItem = new QStandardItem();
        qrCodeItem->setData(qrCodePixmap, Qt::DecorationRole);
        model->setItem(row, 6, qrCodeItem);

        row++;
    }

    return model;
}

QSqlQueryModel * Ressource::afficherRessourceEmplo(int cin)
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // Préparation de la requête SQL avec paramètre lié (plus sécurisé que la concaténation)
    QSqlQuery query;
    query.prepare("SELECT ID_RESSOURCE, NOM_RESSOURCE, TYPE, ETAT, DATE_AQCISITION, CIN_EMPLOYE "
                  "FROM RESSOURCES "
                  "WHERE CIN_EMPLOYE = :cin");
    query.bindValue(":cin", cin);

    // Exécution de la requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        delete model;  // Nettoyage mémoire en cas d'erreur
        return nullptr;
    }

    // Attribution des résultats au modèle
    model->setQuery(query);

    // Vérification des erreurs après setQuery
    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de la récupération des ressources :" << model->lastError().text();
        delete model;
        return nullptr;
    }

    // Définition des en-têtes avec setHeaderData (compatible avec QSqlQueryModel)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID \n Ressource"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom du \nRessource"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type de\n ressource"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat du\n ressource"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date \n d'acquisition"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN \n employé"));

    return model;
}


QStandardItemModel* Ressource::trierRessourcesAvecQRCodeparCIN(int cin, const QString& colonne, bool croissant)
{
    // Construire la requête avec filtre CIN et tri optionnel
    QString requete = "SELECT ID_RESSOURCE, NOM_RESSOURCE, TYPE, ETAT, DATE_AQCISITION, CIN_EMPLOYE "
                      "FROM RESSOURCES "
                      "WHERE CIN_EMPLOYE = :cin";

    if (!colonne.isEmpty()) {
        requete += " ORDER BY " + colonne + (croissant ? " ASC" : " DESC");
    }

    QSqlQuery query;
    query.prepare(requete);
    query.bindValue(":cin", cin);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
        return nullptr;
    }

    // Créer le modèle
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(7); // 6 colonnes de données + 1 pour le QR Code

    // Définir les en-têtes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom\nRessource"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type\nRessource"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat\nRessource"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date\nd'acquisition"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN\nemploye"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("QR Code"));

    int row = 0;
    while (query.next()) {
        // Récupération des données
        QString id = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString type = query.value(2).toString();
        QString etat = query.value(3).toString();
        QDate date = query.value(4).toDate();
        QString cin_emp = query.value(5).toString();
        QString formattedDate = date.toString("yyyy/MM/dd");

        // Ajout des données au modèle
        model->setItem(row, 0, new QStandardItem(id));
        model->setItem(row, 1, new QStandardItem(nom));
        model->setItem(row, 2, new QStandardItem(type));
        model->setItem(row, 3, new QStandardItem(etat));
        model->setItem(row, 4, new QStandardItem(formattedDate));
        model->setItem(row, 5, new QStandardItem(cin_emp));

        // Génération du QR Code
        QString qrData = QString("ID: %1\nNom: %2\nType: %3\nEtat: %4\nDate: %5\nCIN: %6")
                             .arg(id).arg(nom).arg(type).arg(etat).arg(formattedDate).arg(cin_emp);

        // Chemin du logo - utiliser le système de ressources Qt si possible
        QString logoPath = ":/images/logo.jpg"; // Chemin dans les ressources
        QPixmap qrCodePixmap = generateQRCodeWithLogo(qrData, 100, logoPath);

        if (qrCodePixmap.isNull()) {
            qDebug() << "Erreur lors de la génération du QR Code pour la ressource ID:" << id;
        }

        QStandardItem *qrCodeItem = new QStandardItem();
        qrCodeItem->setData(qrCodePixmap, Qt::DecorationRole);
        model->setItem(row, 6, qrCodeItem);

        row++;
    }

    if (row == 0) {
        qDebug() << "Aucune ressource trouvée pour le CIN:" << cin;
    }

    return model;
}

QStandardItemModel* Ressource::chercherparCIN(const QString& nom, int cin)
{
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(7);

    // Définition des en-têtes de colonnes
    QStringList headers = {
        QObject::tr("ID"),
        QObject::tr("Nom\nRessource"),
        QObject::tr("Type\nRessource"),
        QObject::tr("Etat\nRessource"),
        QObject::tr("Date\nd'acquisition"),
        QObject::tr("CIN\nEmployé"),
        QObject::tr("QR Code")
    };

    for (int i = 0; i < headers.size(); ++i) {
        model->setHeaderData(i, Qt::Horizontal, headers[i]);
    }

    // Préparation de la requête SQL
    QSqlQuery query;
    QString requete = "SELECT ID_RESSOURCE, NOM_RESSOURCE, TYPE, ETAT, DATE_AQCISITION, CIN_EMPLOYE "
                      "FROM RESSOURCES "
                      "WHERE NOM_RESSOURCE LIKE :nom ";

    if (cin > 0) {
        requete += "AND CIN_EMPLOYE = :cin";
    }

    query.prepare(requete);
    query.bindValue(":nom", "%" + nom + "%");

    if (cin > 0) {
        query.bindValue(":cin", cin);
    }

    if (!query.exec()) {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        delete model;
        return nullptr;
    }

    // Lecture des résultats
    int row = 0;
    while (query.next()) {
        QString id = query.value(0).toString();
        QString nomRessource = query.value(1).toString();
        QString type = query.value(2).toString();
        QString etat = query.value(3).toString();
        QString formattedDate = query.value(4).toDate().toString("yyyy/MM/dd");
        QString cinEmp = query.value(5).toString();

        // Insertion des données dans le modèle
        model->setItem(row, 0, new QStandardItem(id));
        model->setItem(row, 1, new QStandardItem(nomRessource));
        model->setItem(row, 2, new QStandardItem(type));
        model->setItem(row, 3, new QStandardItem(etat));
        model->setItem(row, 4, new QStandardItem(formattedDate));
        model->setItem(row, 5, new QStandardItem(cinEmp));

        // Données à encoder dans le QR Code
        QString qrData = QString("ID: %1\nNom: %2\nType: %3\nEtat: %4\nDate: %5\nCIN: %6")
                             .arg(id, nomRessource, type, etat, formattedDate, cinEmp);

        // Génération du QR Code
        QPixmap qrCodePixmap = generateQRCodeWithLogo(qrData, 100, ":/images/logo.jpg");

        QStandardItem *qrItem = new QStandardItem();
        if (!qrCodePixmap.isNull()) {
            qrItem->setData(qrCodePixmap, Qt::DecorationRole);
        } else {
            qDebug() << "Erreur de génération du QR Code pour la ressource ID:" << id;
            qrItem->setText("QR Erreur");
        }

        model->setItem(row, 6, qrItem);
        row++;
    }

    if (row == 0) {
        qDebug() << "Aucun résultat trouvé pour nom =" << nom << "et CIN =" << cin;
    }

    return model;
}



QStandardItemModel* Ressource::afficherRessourceAvecQRCodeparCIN(int cinEmploye) {
    QSqlQuery query;
    query.prepare("SELECT ID_RESSOURCE, NOM_RESSOURCE, TYPE, ETAT, DATE_AQCISITION, CIN_EMPLOYE FROM RESSOURCES WHERE CIN_EMPLOYE = :cin");
    query.bindValue(":cin", cinEmploye);
    query.exec();

    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(7);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom\nRessource"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type\nRessource"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat\nRessource"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date\nd'acquisition"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN\nEmployé"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("QR Code"));

    int row = 0;
    while (query.next()) {
        QString id = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString type = query.value(2).toString();
        QString etat = query.value(3).toString();
        QDate date = query.value(4).toDate();
        QString cin = query.value(5).toString();

        QString formattedDate = date.toString("yyyy/MM/dd");

        model->setItem(row, 0, new QStandardItem(id));
        model->setItem(row, 1, new QStandardItem(nom));
        model->setItem(row, 2, new QStandardItem(type));
        model->setItem(row, 3, new QStandardItem(etat));
        model->setItem(row, 4, new QStandardItem(formattedDate));
        model->setItem(row, 5, new QStandardItem(cin));

        // Générer le QR code
        QString qrData = QString("ID : %1\nNom : %2\nType : %3\nÉtat : %4\nDate : %5\nCIN : %6")
                             .arg(id, nom, type, etat, formattedDate, cin);
        QString logoPath = "../logo.jpg";
        QPixmap qrCodePixmap = generateQRCodeWithLogo(qrData, 100, logoPath);

        QStandardItem *qrCodeItem = new QStandardItem();
        qrCodeItem->setData(qrCodePixmap, Qt::DecorationRole);
        model->setItem(row, 6, qrCodeItem);

        row++;
    }

    return model;
}

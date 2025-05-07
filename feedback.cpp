#include "Feedback.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QRegularExpression>
#include <QString>

// Constructeur
Feedback::Feedback() {
    this->rating = 0;
    this->clientId = 0;
    this->reviewComment = "";

}

// Constructeur avec paramètres
Feedback::Feedback(int rating, int clientId,  QString reviewComment) {
    this->rating = rating;
    this->clientId = clientId;
    this->reviewComment = reviewComment;

}

// Accesseurs (getters)
int Feedback::getRating() {
    return rating;
}

int Feedback::getClientId() {
    return clientId;
}

QString Feedback::getReviewComment() {
    return reviewComment;
}

// Mutateurs (setters)
void Feedback::setRating(int rating) {
    this->rating = rating;
}

void Feedback::setClientId(int clientId) {
    this->clientId = clientId;
}

void Feedback::setReviewComment(QString reviewComment) {
    this->reviewComment = reviewComment;
}


bool Feedback::saveRating() {
    // 1. Vérifier si le client existe dans la table CLIENT
    QSqlQuery clientCheckQuery;
    clientCheckQuery.prepare("SELECT COUNT(*) FROM CLIENT WHERE CIN_CLIENT = :client_id");
    clientCheckQuery.bindValue(":client_id", clientId);

    if (!clientCheckQuery.exec()) {
        qDebug() << "Erreur lors de la vérification du client : " << clientCheckQuery.lastError().text();
        return false;
    }

    clientCheckQuery.next();
    int clientExists = clientCheckQuery.value(0).toInt();

    if (clientExists == 0) {
        // Le client n'existe pas dans la table CLIENT
        QMessageBox::warning(nullptr, "Alerte", "Ce client n'existe pas dans la base de données.", QMessageBox::Ok);
        return false;
    }

    // 2. Vérifier si ce client a déjà commenté
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM RATINGS WHERE CLIENT_ID = :client_id");
    checkQuery.bindValue(":client_id", clientId);

    if (!checkQuery.exec()) {
        qDebug() << "Erreur lors de la vérification de l'existence du commentaire : " << checkQuery.lastError().text();
        return false;
    }

    checkQuery.next();
    int count = checkQuery.value(0).toInt();

    if (count > 0) {
        // Le client a déjà commenté
        QMessageBox::warning(nullptr, "Alerte", "Vous avez déjà commenté.", QMessageBox::Ok);
        return false;
    }

    // 3. Insérer le nouveau rating
    QSqlQuery query;
    query.prepare("INSERT INTO RATINGS (RATING, CLIENT_ID, REVIEW_COMMENT)"
                  "VALUES (:rating, :client_id, :review_comment)");
    query.bindValue(":rating", rating);
    query.bindValue(":client_id", clientId);
    query.bindValue(":review_comment", reviewComment);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'insertion : " << query.lastError().text();
        return false;
    }
    QMessageBox::information(nullptr, "Succès", "Note enregistrée avec succès.", QMessageBox::Ok);

    qDebug() << "Note enregistrée avec succès.";
    return true;
}
// Définition correcte des méthodes statiques de Feedback
QStringList Feedback::getBadWords() {
    QStringList badWords;
    QSqlQuery query("SELECT WORD FROM BAD_WORDS");

    while (query.next()) {
        badWords.append(query.value(0).toString());
    }
    return badWords;
}
QString Feedback::filterBadWords(const QString &comment, const QStringList &badWords) {
    QString filteredComment = comment;
    qDebug() << "Début du filtrage du commentaire : " << filteredComment;

    for (const QString &badWord : badWords) {
        QString mask = QString(badWord.length(), '*');
        qDebug() << "Remplacement de : " << badWord << " par " << mask;
        filteredComment.replace(QRegularExpression("\\b" + QRegularExpression::escape(badWord) + "\\b",
                                                   QRegularExpression::CaseInsensitiveOption),
                                mask);
    }

    qDebug() << "Commentaire après filtrage : " << filteredComment;
    return filteredComment;
}


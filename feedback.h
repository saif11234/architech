
#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QString>

class Feedback {


public:
    // Constructeur
    Feedback();
    Feedback(int rating, int clientId, QString reviewComment);

    // Accesseurs (getters)
    int getRating();
    int getClientId() ;
    QString getReviewComment() ;

    // Mutateurs (setters)
    void setRating(int rating);
    void setClientId(int clientId);
    void setReviewComment(QString reviewComment);

    bool saveRating();
    static QStringList getBadWords();
    static QString filterBadWords(const QString &comment, const QStringList &badWords);
private:
    int rating;
    int clientId;
    QString reviewComment;
};

#endif // FEEDBACK_H

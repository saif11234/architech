#ifndef MAILING_H
#define MAILING_H
#include <QDialog>

#include "ui_mailing.h"
namespace Ui {
class mailing;
}

class mailing : public QDialog
{
    Q_OBJECT

public:
    explicit mailing(QWidget *parent = nullptr);
    static QStringList getDynamicSuggestions(const QString &currentText);  // Suggestion dynamique
    //urgence
    static QStringList getEmailSuggestions(const QString &input);
    //2
    static QStringList getEmailsPartenaires(); // récupère tous les emails
    static QString getNomFromEmail(const QString &email); // récupère nom selon email


    ~mailing();


private slots:
    void on_envoyer_clicked();


private:
    Ui::mailing *ui;

};

#endif // MAILING_H

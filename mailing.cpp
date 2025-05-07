#include "mailing.h"
#include "ui_mailing.h"
#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
mailing::mailing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mailing)
{
    ui->setupUi(this);

}

mailing::~mailing()
{
    delete ui;
}
void mailing::on_envoyer_clicked()
{
    QString email = ui->mail_3->text();
    QString objet = ui->objet->text();
    QString corps = ui->corps->toPlainText(); // ✅ CORRECT POUR QTextEdit










    //// email
    //////////////////// mailing




   // QString executablePath = "C:\\Users\\user\\Documents\\pr c++\\projet (7)\\projet\\email\\mail.exe";
QString executablePath = "E:\\c++projet\\projet\\email\\mail.exe";

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

}
QStringList mailing::getDynamicSuggestions(const QString &currentText)
{
    QStringList suggestions;
    QString input = currentText.trimmed().toLower();

    if (input.endsWith("bonjour")) {
        suggestions << "J’espère que vous allez bien."
                    << "Bonjour Monsieur/Madame,"
                    << "Bonjour à tous,";
    }
    else if (input.endsWith("je suis")) {
        suggestions << "Je suis très honoré de vous contacter concernant..."
                    << "Je suis disponible pour toute information complémentaire."
                    << "Je suis à votre disposition.";
    }
    else if (input.endsWith("bon")) {
        suggestions << "Bonjour"
                    << "Bonne idée"
                    << "Bon courage"
                    << "Bon début de semaine";
    }
    else if (input.endsWith("merci")) {
        suggestions << "Merci beaucoup pour votre temps."
                    << "Merci de votre retour."
                    << "Merci infiniment.";
    }
    else if (input.endsWith("cordialement")) {
        suggestions << "Cordialement,"
                    << "Bien cordialement,"
                    << "Avec mes salutations distinguées.";
    }
    else if (input.endsWith("sincèrement")) {
        suggestions << "Sincèrement vôtre,"
                    << "Avec sincérité,"
                    << "Très sincèrement.";
    }

    return suggestions;
}

QStringList mailing::getEmailsPartenaires()
{
    QStringList emailList;
    QSqlQuery query("SELECT EMAIL FROM PARTENAIRE");

    while (query.next()) {
        emailList << query.value(0).toString();
    }

    return emailList;
}

QString mailing::getNomFromEmail(const QString &email)
{
    QSqlQuery query;
    query.prepare("SELECT NOM FROM PARTENAIRE WHERE EMAIL = :email");
    query.bindValue(":email", email);
    if (query.exec() && query.next()) {
        return query.value(0).toString();
    }
    return "Partenaire";
}
QStringList mailing::getEmailSuggestions(const QString &input)
{
    QStringList suggestions;
    QSqlQuery query;

    // Si input est vide, récupérer tous les e-mails
    if (input.isEmpty()) {
        query.prepare("SELECT EMAIL FROM PARTENAIRE");
    } else {
        query.prepare("SELECT EMAIL FROM PARTENAIRE WHERE EMAIL LIKE :input");
        query.bindValue(":input", input + "%");
    }

    if (query.exec()) {
        while (query.next()) {
            suggestions << query.value(0).toString();
        }
    } else {
        qDebug() << "Erreur SQL:" << query.lastError().text();
    }

    return suggestions;
}

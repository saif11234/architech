#include "sms.h"
#include "ui_sms.h"
#include <QProcess>
#include <QDebug>
#include <QTextEdit>  // Nécessaire pour utiliser QTextEdit et ses méthodes comme toPlainText()
#include <QMessageBox>

sms::sms(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sms)
{
    ui->setupUi(this);
}

sms::~sms()
{
    delete ui;
}
void sms::on_sendButton_clicked()
{
    QString phoneNumber = ui->phoneLineEdit->text();
    QString message = ui->messageTextEdit->toPlainText(); // ✅ CORRECT POUR QTextEdit;


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

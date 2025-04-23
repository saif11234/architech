#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "projetmodel.h"        // 👈 Inclure le header du modèle
#include <QQmlEngine>           // 👈 Nécessaire pour qmlRegisterType
#include <QtQml>                // 👈 Nécessaire aussi

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ✅ Enregistrement du modèle C++ pour qu'il soit reconnu dans QML
    qmlRegisterType<ProjetModel>("com.yourcompany.models", 1, 0, "ProjetModel");

    MainWindow w;
    Connection c;
    bool test = c.createconnect();

    if (test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "empreinte.h"
#include "projetmodel.h"
#include <QQmlEngine>
#include <QtQml>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qmlRegisterType<ProjetModel>("com.yourcompany.models", 1, 0, "ProjetModel");

    empreinte w;
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

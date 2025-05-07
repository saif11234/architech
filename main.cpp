#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "projetmodel.h"
#include <QQmlEngine>
#include <QtQml>
#include "dialog.h"
#include "mainwindow.h"
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qmlRegisterType<ProjetModel>("com.yourcompany.models", 1, 0, "ProjetModel");

    // 1. Try connecting to the database
    Connection c;
    bool test = c.createconnect();
    if (!test) {
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                              QObject::tr("❌ Connection failed. Check your database settings."),
                              QMessageBox::Cancel);
        return -1;
    }


    Dialog w;
    w.show();
 return a.exec();
}

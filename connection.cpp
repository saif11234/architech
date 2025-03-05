#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("architech");
    db.setUserName("architech");
    db.setPassword("architech");

    qDebug() << "Available drivers:" << QSqlDatabase::drivers();

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    }

    qDebug() << "Database connection established.";
    return true;
}

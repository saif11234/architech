#include "connection.h"
#include <QSqlDatabase>
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("architech");//inserer le nom de la source de données
db.setUserName("architech");//inserer nom de l'utilisateur
db.setPassword("architech");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

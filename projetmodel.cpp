// projetmodel.cpp
#include "projetmodel.h"
#include <QSqlRecord>

ProjetModel::ProjetModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int ProjetModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_projets.count();
}

QVariant ProjetModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_projets.size())
        return QVariant();

    const Projet &projet = m_projets.at(index.row());

    switch (role) {
    case IdRole:
        return projet.getIdProjet();
    case NomRole:
        return projet.getNomProjet();
    case DescriptionRole:
        return projet.getDescription();
    case BudgetRole:
        return projet.getBudget();
    case DateDebutRole:
        return projet.getDateDebut();
    case DateFinRole:
        return projet.getDateFin();
    case CinClientRole:
        return projet.getCinClient();
    case EtatRole:
        return projet.getEtat();
    case LatitudeRole:
        return projet.getLatitude();
    case LongitudeRole:
        return projet.getLongitude();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ProjetModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id_projet";
    roles[NomRole] = "nom_projet";
    roles[DescriptionRole] = "description";
    roles[BudgetRole] = "budget";
    roles[DateDebutRole] = "date_debut";
    roles[DateFinRole] = "date_fin";
    roles[CinClientRole] = "cin_client";
    roles[EtatRole] = "etat_projet";
    roles[LatitudeRole] = "latitude";
    roles[LongitudeRole] = "longitude";
    return roles;
}

void ProjetModel::setProjets(const QList<Projet> &projets)
{
    beginResetModel();
    m_projets = projets;
    endResetModel();
}

void ProjetModel::refreshProjets()
{
    // Create an instance of Projet to access the database methods
    Projet projetHelper;

    // Get all projects from the database
    QSqlQueryModel* sqlModel = projetHelper.afficherProjets();

    // Convert the SQL model to our list
    QList<Projet> projets;
    for (int i = 0; i < sqlModel->rowCount(); ++i) {
        int id = sqlModel->record(i).value("ID_PROJET").toInt();
        QString nom = sqlModel->record(i).value("NOM_PROJET").toString();
        QString desc = sqlModel->record(i).value("DESCRIPTION").toString();
        float budget = sqlModel->record(i).value("BUDGET").toFloat();
        QString dateDebut = sqlModel->record(i).value("DATE_DEBUT").toString();
        QString dateFin = sqlModel->record(i).value("DATE_FIN").toString();
        int cinClient = sqlModel->record(i).value("CIN_CLIENT").toInt();
        QString etat = sqlModel->record(i).value("ETAT_PROJET").toString();
        float latitude = sqlModel->record(i).value("LATITUDE").toFloat();
        float longitude = sqlModel->record(i).value("LONGITUDE").toFloat();

        Projet projet(id, nom, desc, budget, dateDebut, dateFin, cinClient, etat, latitude, longitude);
        projets.append(projet);
    }

    // Update the model
    setProjets(projets);

    // Clean up
    delete sqlModel;
}

#ifndef PROJETMODEL_H
#define PROJETMODEL_H

#include <QAbstractListModel>
#include <QList>
#include "projet.h"

class ProjetModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum ProjetRoles {
        IdRole = Qt::UserRole + 1,
        NomRole,
        DescriptionRole,
        BudgetRole,
        DateDebutRole,
        DateFinRole,
        CinClientRole,
        EtatRole,
        LatitudeRole,
        LongitudeRole
    };

    explicit ProjetModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void setProjets(const QList<Projet> &projets);
    void refreshProjets();

private:
    QList<Projet> m_projets;
};

#endif // PROJETMODEL_H

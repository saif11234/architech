#include "dialogPDF_RESSOURCE.h"
#include "ui_dialogPDF_RESSOURCE.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QVBoxLayout>
DialogRessource::DialogRessource(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogRESSOURCE),
    m_pdfView(new QPdfView(this)),
    m_pdfDocument(new QPdfDocument(this))
{
    ui->setupUi(this);
    setupUI();
}
void DialogRessource::setupUI()
{
    // Ajout du PDF Viewer
    QVBoxLayout *layout = new QVBoxLayout(ui->pdfContainer);
    layout->addWidget(m_pdfView);
    layout->setContentsMargins(0, 0, 0, 0);

}
void DialogRessource::genererPDF(QSqlQueryModel *model)
{
    if (!model || model->rowCount() == 0) {
        QMessageBox::warning(this, "Erreur", "Aucune donnée à exporter !");
        return;
    }

    // Création d'un fichier temporaire
    m_pdfTempPath = QDir::tempPath() + "/liste_ressources_temp.pdf";

    QPdfWriter pdfWriter(m_pdfTempPath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);
    pdfWriter.setPageMargins(QMarginsF(20, 20, 20, 30));

    QPainter painter(&pdfWriter);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 3. Paramètres de style
    QFont titleFont("Arial", 16, QFont::Bold);
    QFont subtitleFont("Arial", 10);
    QFont headerFont("Arial", 10, QFont::Bold);
    QFont dataFont("Arial", 9);
    QFont footerFont("Arial", 8);

    const int margin = 40;
    int currentPage = 1;
    int yPos = margin;
    const int lineHeight = 130;
    const int cellPadding = 8;
    const int borderWidth = 1;

    // 4. Calcul des largeurs de colonnes
    QVector<int> colWidths;
    const int minColWidth = 320;
    const int maxColWidth = 950;

    for (int col = 0; col < model->columnCount(); ++col) {
        QFontMetrics fm(headerFont);
        int width = fm.horizontalAdvance(model->headerData(col, Qt::Horizontal).toString()) + 2*cellPadding;

        fm = QFontMetrics(dataFont);
        for (int row = 0; row < model->rowCount(); ++row) {
            width = qMax(width, fm.horizontalAdvance(model->data(model->index(row, col)).toString()) + 2*cellPadding);
        }

        colWidths.append(qBound(minColWidth, width, maxColWidth));
    }

    // 5. Fonction pour dessiner l'en-tête
    auto drawHeader = [&]() {
        QPixmap logo(":/logo.jpg");
        if (!logo.isNull()) {
            painter.drawPixmap(margin, yPos, logo.scaled(550, 280, Qt::KeepAspectRatio));
            yPos += 400; // Espace après le logo
        }
        painter.setFont(titleFont);
        painter.drawText(margin +600, yPos, "LISTE DES RESSOURCES");
        yPos += lineHeight;

        painter.setFont(subtitleFont);
        painter.drawText(margin, yPos, "Généré le: " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm"));
        yPos += lineHeight * 1.5;

        // En-têtes de colonnes
        painter.setFont(headerFont);
        painter.setPen(QPen(Qt::black, borderWidth));
        painter.setBrush(QColor(240, 240, 240));

        int xPos = margin;
        for (int col = 0; col < model->columnCount(); ++col) {
            painter.drawRect(xPos, yPos, colWidths[col], lineHeight);
            QString header = model->headerData(col, Qt::Horizontal).toString().toUpper();
            painter.drawText(QRect(xPos + cellPadding, yPos + cellPadding,
                                   colWidths[col] - 2*cellPadding, lineHeight - 2*cellPadding),
                             Qt::AlignCenter, header);
            xPos += colWidths[col];
        }
        yPos += lineHeight;
    };

    // 6. Fonction pour le pied de page
    auto drawFooter = [&]() {
        // 1. Définir la police
        painter.setFont(QFont("Arial", 9));
        painter.setPen(Qt::darkGray);

        // 2. Dessiner une ligne de séparation
        int lineY = pdfWriter.height() - 35;
        painter.drawLine(margin, lineY, pdfWriter.width() - margin, lineY);


        // 4. Numéro de page à droite
        QString pageText = QString("Page %1").arg(currentPage);
        painter.drawText(pdfWriter.width() - margin - 50, lineY + 50, pageText);
    };

    // 7. Dessin initial
    drawHeader();

    // 8. Dessin des données
    painter.setFont(dataFont);
    bool alternateRow = false;

    for (int row = 0; row < model->rowCount(); ++row) {
        // Gestion des sauts de page
        if (yPos > pdfWriter.height() - margin - lineHeight - 30) {
            drawFooter();
            pdfWriter.newPage();
            currentPage++;
            yPos = margin;
            alternateRow = false;
            drawHeader();
        }

        // Dessin des cellules
        int xPos = margin;
        for (int col = 0; col < model->columnCount(); ++col) {
            painter.setPen(QPen(Qt::black, borderWidth));
            painter.setBrush(alternateRow ? QColor(245, 245, 245) : Qt::white);
            painter.drawRect(xPos, yPos, colWidths[col], lineHeight);

            QString data = model->data(model->index(row, col)).toString();

            // Formatage spécial pour les dates
            if (model->headerData(col, Qt::Horizontal).toString().contains("DATE", Qt::CaseInsensitive)) {
                QDateTime date = QDateTime::fromString(data, Qt::ISODate);
                if (date.isValid()) data = date.toString("dd/MM/yyyy");
            }

            Qt::Alignment align = Qt::AlignCenter;
            if (col == 0) align = Qt::AlignLeft|Qt::AlignVCenter; // Alignement à gauche pour la première colonne

            painter.drawText(QRect(xPos + cellPadding, yPos + cellPadding,
                                   colWidths[col] - 2*cellPadding, lineHeight - 2*cellPadding),
                             align, data);
            xPos += colWidths[col];
        }

        yPos += lineHeight;
        alternateRow = !alternateRow;
    }

    // 9. Pied de page final
    drawFooter();


    painter.end();

    // Affichage du PDF généré
    m_pdfDocument->load(m_pdfTempPath);
    m_pdfView->setDocument(m_pdfDocument);
}

void DialogRessource::telechargerPDF()
{
    if (m_pdfTempPath.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun PDF généré");
        return;
    }

    QString savePath = QFileDialog::getSaveFileName(
        this,
        "Enregistrer le PDF",
        QDir::homePath() + "/liste_ressources.pdf",
        "Fichiers PDF (*.pdf)"
        );

    if (!savePath.isEmpty()) {
        if (QFile::copy(m_pdfTempPath, savePath)) {
            QMessageBox::information(this, "Succès", "PDF enregistré avec succès !");
            QDesktopServices::openUrl(QUrl::fromLocalFile(savePath));
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de l'enregistrement");
        }
    }
}

void DialogRessource::on_TelechargerListRessources_clicked()
{
    telechargerPDF();
}


void DialogRessource::on_Quitter_clicked()
{
     this->close();
}

void DialogRessource::nettoyerFichierTemporaire()
{
    if (!m_pdfTempPath.isEmpty()) {
        QFile::remove(m_pdfTempPath);
    }
}

DialogRessource::~DialogRessource()
{
    nettoyerFichierTemporaire();
    delete m_pdfDocument;
    delete ui;
}


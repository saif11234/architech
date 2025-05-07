#ifndef DIALOGPDF_RESSOURCE_H
#define DIALOGPDF_RESSOURCE_H
#include <QMainWindow>
#include <QDialog>

#include <QPdfView>
#include <QPdfDocument>
#include <QSqlQueryModel>
namespace Ui {
class DialogRESSOURCE;
}

class DialogRessource : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRessource(QWidget *parent = nullptr);
    void genererPDF(QSqlQueryModel *model);  // Génère et affiche le PDF
    void telechargerPDF();                   // Télécharge le PDF
    ~DialogRessource();

private slots:
    void on_TelechargerListRessources_clicked();
    void on_Quitter_clicked();

private:
    Ui::DialogRESSOURCE *ui;
    QString m_pdfTempPath;      // Chemin du PDF temporaire
    QPdfView *m_pdfView;        // Vue PDF
    QPdfDocument *m_pdfDocument;// Document PDF

    void setupUI();
    void nettoyerFichierTemporaire();
};

#endif // DIALOGPDF_RESSOURCE_H

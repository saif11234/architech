#ifndef EMPREINTE_H
#define EMPREINTE_H
#include <QDialog>
#include <QSerialPort>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QCameraDevice>
#include <QMediaDevices>
#include <QImageCapture>
#include <QSqlDatabase>
#include <QSqlQuery>


namespace Ui {
class empreinte;
}

class empreinte : public QDialog
{
    Q_OBJECT

public:
    explicit empreinte(QWidget *parent = nullptr);
    ~empreinte();
    void silentCaptureAndSave();
private slots:
    void on_signup_clicked();
    void on_login_clicked();
    void on_annuler_clicked();
    void on_annuler2_clicked();
    void readSerial();
    void handleImageCaptured(int id,const QImage &img);
private:
    Ui::empreinte *ui;
    QSerialPort *serial;
    QString currentCommand;
    int currentCin;
    void sendCommandToArduino(const QString &command, int cin);
    void showError(const QString &message);
    void showSuccess(const QString &message);
    QCamera *camera;
    QMediaCaptureSession *captureSession;
    QImageCapture *imageCapture;
};

#endif // EMPREINTE_H

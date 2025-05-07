#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include <QSqlDatabase>
#include "justemp.h"
#include <QSerialPort>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QCameraDevice>
#include <QMediaDevices>
#include <QImageCapture>
#include <QSqlQuery>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    MainWindow *mainWindow; // Pointer to MainWindow

private slots:
    void on_loginButton_clicked(); // Function to handle login

    void on_signup_clicked();
    void on_login_clicked();
    void on_annuler_clicked();
    void on_Rest_Button_clicked();
    void readSerial();
    void handleImageCaptured(int id,const QImage &img);
    void silentCaptureAndSave();
private:
    Ui::Dialog *ui;
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

#endif // DIALOG_H

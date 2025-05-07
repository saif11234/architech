#ifndef SMS_H
#define SMS_H



#include <QDialog>

namespace Ui {
class sms;
}

class sms : public QDialog
{
    Q_OBJECT

public:
    explicit sms(QWidget *parent = nullptr);
    ~sms();

private slots:
    void on_sendButton_clicked();

private:
    Ui::sms *ui;
};

#endif // SMS_H

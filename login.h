#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>

#include "secdialog.h"
#include "signin.h"
#include "reminder.h"
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    QString username;



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    //void on_label_4_linkActivated(const QString &link);

    void on_pushButton_3_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase mydb;
    SecDialog *secDialog;
    signin *Signin;
    Reminder *reminder;
};

#endif // LOGIN_H

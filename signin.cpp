#include <QDesktopWidget>
#include <QMainWindow>
#include <QDateTime>

#include "signin.h"
#include "ui_signin.h"
#include "login.h"

signin::signin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);

}

signin::~signin()
{
    delete ui;
}

void signin::on_pushButton_clicked()
{

    QSqlQuery qry;
    QString username, password, passwordrepeat;
    //bool alreadyExist = false;
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_2_password->text();
    passwordrepeat = ui->lineEdit_3_passwordrepeat->text();
    QDate date = QDate::currentDate();
    QString dateString = date.toString("dd.MM.yyyy");

    if(password != passwordrepeat)
        QMessageBox::warning(this,"Password","You put two different password in the form. Try again");
    else if(username.isEmpty() || password.isEmpty())
        QMessageBox::warning(this,"Password","You must put some date in your form to register. Try again.");

    else{
        bool ok = qry.exec("select 1 from users where username='"+username+"'");
        qDebug()<<ok;
        if(ok && qry.next())
        {
            QMessageBox::warning(this,"Sign in","Your username is already used. Try another one");
        }
        else
        {
            qry.prepare("INSERT INTO users(username, password, date) values(:username,:password,:date)");
            qry.bindValue(":username",username);
            qry.bindValue(":password",password);
            qry.bindValue(":date",date);

            if(qry.exec())
                QMessageBox::information(this,"Sign in","Your were sucessfully registered.");
            else
                QMessageBox::warning(this,"Sign in","We couldn't register you. Try again.");
        }

        //qDebug()<<qry.prepare("INSERT INTO users(username, password, date) values(:username,:password,:date)");

    }
}
void signin::on_pushButton_2_clicked()
{
    hide();
    Login *w = new Login(this);
//    QDesktopWidget dw;
//    double x=dw.width()*0.5;
//    double y=dw.height()*0.5;
//    int xw = static_cast<int>(x);
//    int yw = static_cast<int>(y);
//    w->setFixedSize(xw,yw);
    w->show();
}

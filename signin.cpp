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
    QString questions[10] = {"What is your favorite book?","What is the name of the road you grew up on?","What is your mother’s maiden name?","What was the name of your first/current/favorite pet?","What was the first company that you worked for?","Where did you meet your spouse?","Where did you go to high school/college?","What is your favorite food?","What city were you born in?","Where is your favorite place to vacation?"};
    int High = 9;
    int Low = 0;
    qsrand(QTime::currentTime().msec());
    ui->label_question->setText(questions[(qrand() % ((High + 1) - Low) + Low)]);
}

signin::~signin()
{
    delete ui;
}

void signin::on_pushButton_clicked()
{

    QSqlQuery qry;
    QString username, password, passwordrepeat,que,answer;
    //bool alreadyExist = false;
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_2_password->text();
    passwordrepeat = ui->lineEdit_3_passwordrepeat->text();
    que = ui->label_question->text();
    answer = ui->lineEdit_answer->text();

    QDate date = QDate::currentDate();
    QString dateString = date.toString("dd.MM.yyyy");

    if(password != passwordrepeat)
        QMessageBox::warning(this,"Password","You put two different password in the form. Try again");
    else if(username.isEmpty() || password.isEmpty())
        QMessageBox::warning(this,"Password","You must put some date in your form to register. Try again.");

    else{
        bool ok = qry.exec("select 1 from users where username='"+username+"'");
        //qDebug()<<ok;
        if(ok && qry.next())
        {
            QMessageBox::warning(this,"Sign in","Your username is already used. Try another one");
        }
        else
        {
            qry.prepare("INSERT INTO users(username, password, date, question, answer) values(:username,:password,:date,:question,:answer)");
            qry.bindValue(":username",username);
            qry.bindValue(":password",password);
            qry.bindValue(":date",date);
            qry.bindValue(":question",que);
            qry.bindValue(":answer",answer);

            if(qry.exec())
                QMessageBox::information(this,"Sign in","Your were sucessfully registered.");
            else
                QMessageBox::warning(this,"Sign in","We couldn't register you. Try again.");
        }

        qDebug()<<qry.prepare("INSERT INTO users(username, password, date, answer) values(:username,:password,:date,:answer)");

    }
}
void signin::on_pushButton_2_clicked()
{
    hide();
    Login *w = new Login(this);
    w->show();
}

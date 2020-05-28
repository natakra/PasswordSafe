#include "reminder.h"
#include "ui_reminder.h"
#include "login.h"

#include <QMessageBox>
#include <QDebug>

Reminder::Reminder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reminder)
{
    ui->setupUi(this);
    ui->label_question->hide();
    ui->lineEdit_answer->hide();
    ui->pushButton_s_question->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->lineEdit_password->hide();
    ui->lineEdit_repeat->hide();
    ui->pushButton_save->hide();
}

Reminder::~Reminder()
{
    delete ui;
}

void Reminder::on_pushButton_submit_user_clicked()
{
    username = ui->lineEdit_username->text();
    QSqlQuery qry;

    if(qry.exec("select * from users where username='"+username+"'"))
    {
        int count=0;
        while(qry.next()){
            count++;
        }
        if(count==1)
        {
            QMessageBox::information(this,"Username","Your username is correct.");
            qry.prepare("select * from users where username='"+username+"'");
            if(qry.exec())
            {
                while(qry.next())
                {

                    ui->label_question->setText(qry.value(4).toString());
                }
            }
            ui->label_question->show();
            ui->lineEdit_answer->show();
            ui->pushButton_s_question->show();

        }
        if(count<1)
            QMessageBox::warning(this,"Login","Your username is invalid. Try once again.");
    }
    else
        qDebug()<<"not working!";
}

void Reminder::on_pushButton_s_question_clicked()
{
    QString answer = ui->lineEdit_answer->text();
    QString old_answer = "";
    QSqlQuery qry;
    qry.prepare("select * from users where username='"+username+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            old_answer = qry.value(5).toString();
        }
        if (old_answer == answer)
        {
            QMessageBox::information(this,"Answer","Your answer is correct.");
            ui->label_2->show();
            ui->label_3->show();
            ui->lineEdit_password->show();
            ui->lineEdit_repeat->show();
            ui->pushButton_save->show();
        }
        else
        {
            QMessageBox::warning(this,"Answer","Your answer isn't correct.");
        }
    }
}

void Reminder::on_pushButton_save_clicked()
{
    QString password = ui->lineEdit_password->text();
    QString password_1 = ui->lineEdit_repeat->text();
    if (password == password_1)
    {
        QSqlQuery qry;
        qry.prepare("update users set password='"+password+"' where username='"+username+"'");
        if(qry.exec())
        {
            QMessageBox::information(this,"Password change", "Your password was successfully changed.");
        }
        else
        {
            QMessageBox::warning(this,"Password change", "Your password wasn't successfully changed. Try again.");
        }
    }

}

void Reminder::on_pushButton_clicked()
{
    hide();
    Login *w = new Login(this);
    w->show();
}

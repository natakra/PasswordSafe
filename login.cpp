#include "login.h"
#include "ui_login.h"
#include <QDesktopWidget>
#include <QMainWindow>
#include <QDir>


Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    QString gdziejestem= QDir::currentPath();
    if (!QDir(gdziejestem+"/users").exists())
        QDir().mkdir(gdziejestem+"/users");
    QString str = "allusers.db";

    QString path = gdziejestem+"/users/"+str;
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(path);
    mydb.open();
    if(!mydb.open())
        QMessageBox::warning(this,"Database","Database failed to connect. Try once again");

    QSqlQuery query;
    query.exec("create table users "
              "(id integer primary key, "
              "username varchar(100), "
              "password varchar(100), "
              "date varchar(128), "
              "question varchar(128), "
              "answer varchar(100))");
    //qDebug()<<query.exec();
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    //QString username, password;
    QString password;
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(!mydb.isOpen()) {

        qDebug()<<"Failed to open the database.";
        return;
    }

    QSqlQuery qry;

    if(qry.exec("select * from users where username='"+username+"' and password='"+password+"'"))
    {
        int count=0;
        while(qry.next()){
            count++;
        }
        if(count==1)
        {
            //ui->label->setText("correct");
            hide();
            secDialog = new SecDialog(this);
            secDialog->setLabelText(username);
            secDialog->show();
            secDialog->on_table();
        }
        if(count<1)
            QMessageBox::warning(this,"Login","Your username or password is invalid. Try once again.");
        if(count>1)
            QMessageBox::warning(this,"Login","Your username and password are the same. Try once again.");
    }
    else
        qDebug()<<"not working!";
}

void Login::on_pushButton_2_clicked()
{
    hide();
    Signin = new signin(this);
    Signin->show();

}

//void Login::on_label_4_linkActivated(const QString &link)
//{
    //qDebug()<<"working!";
//}

void Login::on_pushButton_3_clicked()
{
    hide();
    reminder = new Reminder(this);
    reminder->show();
}

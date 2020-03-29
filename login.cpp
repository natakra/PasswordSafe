#include "login.h"
#include "ui_login.h"
#include <QDesktopWidget>
#include <QMainWindow>


Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/home/nkrauze/sqlite_DB/database.db");

    if(!mydb.open())
        //ui->label->setText("Failed to open database.");
        QMessageBox::warning(this,"Database","Database failed to connect. Try once again");
   // else
        //ui->label->setText("Your database is connected.");
        //QMessageBox::information(this,"Database","Database was successfully connected.");

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username, password;
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
            QDesktopWidget dw;
            double x=dw.width()*0.5;
            double y=dw.height()*0.5;
            int xw = static_cast<int>(x);
            int yw = static_cast<int>(y);
            secDialog->setFixedSize(xw,yw);
            secDialog->show();
        }
        if(count<1)
            //ui->label->setText("not correct");
            QMessageBox::warning(this,"Login","Your username or password is invalid. Try once again.");
        if(count>1)
            QMessageBox::warning(this,"Login","Your username and password are the same. Try once again.");
    }
    else qDebug()<<"not working!";
}

void Login::on_pushButton_2_clicked()
{
    //QSqlDatabase::removeDatabase("mydb");
    hide();
    Signin = new signin(this);
//    QDesktopWidget dw;
//    double x=dw.width()*0.5;
//    double y=dw.height()*0.5;
//    int xw = static_cast<int>(x);
//    int yw = static_cast<int>(y);

//    Signin->setFixedSize(xw,yw);
    Signin->show();


}

#include "secdialog.h"
#include "ui_secdialog.h"
#include "login.h"
#include "randompassword.h"
//#include "accounts.h"

#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QDir>


SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    //on_table();
    //ui->label_username->setText("username");
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_logout_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Logout", "Logout?",QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        close();
        Login *w = new Login(this);
        w->show();
    }
    //else
    //{
        //qDebug() << "Yes was *not* clicked";
    //}

}

void SecDialog::on_passwordrandom_clicked()
{
    //moving to the window of generating random passwords
    RandomPassword *r = new RandomPassword(this);
    r->show();

}

void SecDialog::setLabelText(QString str)
{
    ui->label_username->setText(str);
    QString username = ui->label_username->text();

}

QSqlDatabase SecDialog::get_database(QString str)
{
    //creating unique database (if doesn't exist) for given username, which is also unique
    //QString user = ui->label_username->text();
    //qDebug()<<user;
    QString gdziejestem= QDir::currentPath();
    if (!QDir(gdziejestem+"/users").exists())
        QDir().mkdir(gdziejestem+"/users");
    //QString gdziejestem= QDir::currentPath();
    //QString path = "/home/nkrauze/sqlite_DB/users/"+str+".db";
    QString path = gdziejestem+"/users/"+str+".db";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();
    QSqlQuery query;
    query.exec("create table user "
              "(id integer primary key, "
              "website varchar(100), "
              "email varchar(100), "
              "password varchar(128))");
    return db;

}
void SecDialog::on_table()
{
    QSqlDatabase db = get_database(ui->label_username->text());
    qDebug()<<db;
    db.open();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery(db);

    query->prepare("select website,email,password from user");
    if(query->exec())
    {
        qDebug()<<"it is ok";
    }
    model->setQuery(*query);
    ui->tableView->setModel(model);
    get_database(ui->label_username->text()).close();
    for (int col=0; col<3; col++)
    {
           ui->tableView->setColumnWidth(col,308);
    }
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


}

void SecDialog::on_pushButton_add_clicked()
{
    QString website = ui->lineEdit_website->text();
    QString email = ui->lineEdit_email->text();
    QString password = ui->lineEdit_password->text();

    if(website != "" || email != "" || password != "")
    {

        if(get_database(ui->label_username->text()).open())
        {
            qDebug()<<"Something went wrong";
        }

        QSqlQuery qry;
        qry.prepare("insert into user (website,email,password) values ('"+website+"','"+email+"','"+password+"')");

        if(qry.exec())
        {
            QMessageBox::information(this,tr("Your account was added"),tr("Your account was succesfully added."));
            //row_number+=1;
            get_database(ui->label_username->text()).close();
        }

        else
        {
            QMessageBox::critical(this,tr("Your account couldn't be added"),qry.lastError().text());
        }
    }
    else
    {
        QMessageBox::warning(this,"Warning","Nie możesz dodać pustego konta");
    }
    //setusernametext(usernametopass);
    on_table();
}


void SecDialog::on_pushButton_delete_clicked()
{

    QItemSelectionModel *select = ui->tableView->selectionModel();

    QItemSelectionModel* selectionModel = ui->tableView->selectionModel();
    QModelIndexList selected = selectionModel->selectedRows();
    QVector<QString> ind;
    for(int i= 0; i< selected.count();i++)
    {
        QModelIndex index = selected.at(i);
        //qDebug() << index.row();
        ind.append(QString::number(index.row()+1));
    }
    if(get_database(ui->label_username->text()).open())
    {
        qDebug()<<"Something went wrong";
    }
    qDebug() << ind.size();
    QSqlQuery qry;
    for(int k = 0; k<ind.size();k++)
    {

        qDebug()<<ind[k];
        //qDebug() << ind[;
        qry.prepare("delete from user where id='"+ind[k]+"'");
        //qry.prepare("delete from user where email='"+ema+"' and website='"+web+"'");

        if(qry.exec())
        {
            QMessageBox::information(this,tr("Your account was deleted"),tr("Your account was succesfully deleted."));
            //get_database(usernametopass).close();
        }

        else
        {
            QMessageBox::critical(this,tr("Your account couldn't be deleted"),qry.lastError().text());
        }
    }
    on_table();

}


void SecDialog::on_tableView_activated(const QModelIndex &index)
{

    QString val = ui->tableView->model()->data(index).toString();
    //qDebug()<<val;
    get_database(ui->label_username->text()).open();
    QSqlQuery qry;
    //id_to_check = qry.value(0).toString();
    //qDebug()<<id_to_check;
    qry.prepare("select * from user where id='"+val+"' or website='"+val+"' or email='"+val+"' or password='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            //ui->lineEdit_website->setText(qry.value(0).toString());
            //id_to_check = qry.value(0).toString();
            //qDebug()<<id_to_check;
            ui->lineEdit_website->setText(qry.value(1).toString());
            ui->lineEdit_email->setText(qry.value(2).toString());
            ui->lineEdit_password->setText(qry.value(3).toString());
        }
    }
    else
    {
        QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }
}

void SecDialog::on_pushButton_clicked()
{
    QString website = ui->lineEdit_website->text();
    QString email = ui->lineEdit_email->text();
    QString password = ui->lineEdit_password->text();

    if(website != "" || email != "" || password != "")
    {

        if(get_database(ui->label_username->text()).open())
        {
            qDebug()<<"Something went wrong";
        }

        QSqlQuery qry;
        qry.prepare("update user set website='"+website+"', email='"+email+"', password='"+password+"' where id='"+id_to_check+"'");

        if(qry.exec())
        {
            QMessageBox::information(this,tr("Your account was updated"),tr("Your account was succesfully updated."));
            get_database(ui->label_username->text()).close();
        }

        else
        {
            QMessageBox::critical(this,tr("Your account couldn't be updated"),qry.lastError().text());
        }
    }
    else
    {
        QMessageBox::warning(this,"Warning","You can't add an empty record.");
    }
    //setusernametext(usernametopass);
    on_table();
}

void SecDialog::on_pushButton_2_clicked()
{
    QMessageBox::about(this, "Guide","To delete mark the row and click delete button; to edit click the cell in website column, change data in the poll and click edit");
}

#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QModelIndex>


namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT
    //void on_table();

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();
    QSqlDatabase db;

    void setLabelText(QString str);
    QSqlDatabase get_database(QString str);
    void on_table();


private slots:
    void on_logout_clicked();

    void on_passwordrandom_clicked();


    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SecDialog *ui;

    //Login *l;
    //QSqlDatabase db = get_database(ui->label_username->text());
    //qDebug()<<db;
    //db.open();
    //QSqlQueryModel *model = new QSqlQueryModel();

    //qDebug()<<w.username;
    //QSqlQuery *query=new QSqlQuery(db);

    //query->prepare("select website,email,password from user");
    //if(query->exec())
    //{
        //qDebug()<<"it is ok";
    //}
    //model->setQuery(*query);

};

#endif // SECDIALOG_H

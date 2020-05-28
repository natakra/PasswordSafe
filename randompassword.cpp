#include "randompassword.h"
#include "ui_randompassword.h"
#include <QDebug>
#include <random>
#include <QTime>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

RandomPassword::RandomPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandomPassword)
{
    ui->setupUi(this);
}

RandomPassword::~RandomPassword()
{
    delete ui;
}

void RandomPassword::on_spinBox_valueChanged(int arg1)
{
    if (arg1 > 15)
    {
        ui->label_2->setText("STRONG");
        ui->label_2->setStyleSheet("QLabel { color : blue; }");
    }

    else {
        ui->label_2->setText("WEAK");
        ui->label_2->setStyleSheet("QLabel { color : red; }");
    }
}

QString generate_password(int length, int &s,int &n,int &l,int &u)
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec()+(uint)qrand());

    const QString upper("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    const QString lower("abcdefghijklmnopqrstuvwxyz");
    const QString numbers("0123456789");
    const QString symbols("!@#$%&");
    QString password = "";
    while(password.length()<length)
    {
        int random = qrand() % 4;
        if(random == 0)
        {
            int index = qrand() % upper.length();
            QChar nextChar = upper.at(index);
            password.append(nextChar);
            u++;
        }

        else if(random == 1)
        {
            int index = qrand() % lower.length();
            QChar nextChar = lower.at(index);
            password.append(nextChar);
            l++;
        }

        else if(random == 2)
        {
            int index = qrand() % numbers.length();
            QChar nextChar = numbers.at(index);
            password.append(nextChar);
            n++;
        }

        else
        {
            int index = qrand() % symbols.length();
            QChar nextChar = symbols.at(index);
            password.append(nextChar);
            s++;
        }
        //qDebug()<<random;
        //password.append(random);

    }
    return password;
}

void RandomPassword::on_pushButton_generate_clicked()
{
    int length = ui->spinBox->value();
    int s = 0,n = 0,l = 0,u = 0;
    QString password = generate_password(length, s, n, l, u);
    while(1)
    {
        if(n>=1 && s>=1 && l>1 && u>1)
        {
            ui->lineEdit_show_password->setText(password);
            break;
        }
        else
            generate_password(length,s,n,l,u);
    }

}


void RandomPassword::on_pushButton_clicked()
{
    ui->lineEdit_show_password->selectAll();
    ui->lineEdit_show_password->copy();
}

void RandomPassword::on_pushButton_2_clicked()
{
    int how_many = ui->spinBox_2_number_of_generation->value();
    QString file_name = QFileDialog::getSaveFileName(this, tr("Save File"),QDir::homePath());
    QFile file(file_name);
    if (file.open(QIODevice::ReadWrite))
    {
        for(int i = 0; i < how_many; i++)
        {
            QTextStream stream(&file);
            RandomPassword::on_pushButton_generate_clicked();
            stream << ui->lineEdit_show_password->text() << endl;
        }
        QMessageBox::information(this,"Passwords saved","Your passwords were saved to: "+file_name);
    }
    else
    {
        QMessageBox::warning(this,"Warning","File couldn't be opened.");

    }

    file.close();
}

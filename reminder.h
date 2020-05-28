#ifndef REMINDER_H
#define REMINDER_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Reminder;
}

class Reminder : public QDialog
{
    Q_OBJECT

public:
    explicit Reminder(QWidget *parent = nullptr);
    ~Reminder();

private slots:
    void on_pushButton_submit_user_clicked();

    void on_pushButton_s_question_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_clicked();

private:
    Ui::Reminder *ui;
    QSqlDatabase mydb;
    QString username = "";
};

#endif // REMINDER_H

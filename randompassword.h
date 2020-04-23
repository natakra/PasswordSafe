#ifndef RANDOMPASSWORD_H
#define RANDOMPASSWORD_H

#include <QDialog>

namespace Ui {
class RandomPassword;
}

class RandomPassword : public QDialog
{
    Q_OBJECT

public:
    explicit RandomPassword(QWidget *parent = nullptr);

    ~RandomPassword();

private slots:


    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_generate_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::RandomPassword *ui;
};

#endif // RANDOMPASSWORD_H

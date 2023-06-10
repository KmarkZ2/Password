
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString str = ui->lineEdit->text();
    PasswordValidator valid;
    if (valid.isValid(str))
        {
            ui->label->setStyleSheet("color: #57f542");
            ui->label_2->setText(str);
            ui->label->setText("Перевірку пройдено!");
        }
    else
        {
            ui->label->setStyleSheet("color: #f54242");
            ui->label_2->setText(str);
            ui->label->setText("Перевірку не пройдено!");
        }
}


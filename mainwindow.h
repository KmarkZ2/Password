
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QRegularExpressionValidator>
#include <QRegularExpressionMatch>


class Validator
{
public:
    virtual bool isValid(QString somestring)=0;
};

class PasswordValidator : public Validator
{
    QString str = "^(?=.*[a-z])(?=.*[0-9])(?=.*[A-Z])(?=.*[*#@+])[a-zA-Z0-9*@+#]{4,6}$";
    QRegularExpression reg=QRegularExpression(str);
public:

    virtual bool isValid(QString somestring)
    {
        QRegularExpressionMatch regmatch1 = reg.match(somestring);
        bool ismatch1 = regmatch1.hasMatch() ;
        bool ismatch = ismatch1;
        if  (ismatch==true)
            return true;
        else
            return false;
    }
};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

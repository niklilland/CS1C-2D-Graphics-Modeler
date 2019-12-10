#include "userlogin.h"
#include "ui_userlogin.h"
#include "C:\Users\Bernie\Desktop\C++ Bryson Jun2019\1C\projectCode\login.h"
#include "C:\Users\Bernie\Desktop\C++ Bryson Jun2019\1C\projectCode\userList.h"
#include "C:\Users\Bernie\Desktop\C++ Bryson Jun2019\1C\projectCode\utils.h"
#include <QMessageBox>

userlogin::userlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userlogin)
{
    ui->setupUi(this);
}

userlogin::~userlogin()
{
    delete ui;
}

void userlogin::on_btnLogin_clicked()
{
    // load user database
    userLinkedListType users;
    loadUserDatabase(LOGIN_FILE, users);

    string username, password;
    username=(ui->txtUsername->text()).toUtf8().constData();
    password=(ui->txtPassword->text()).toUtf8().constData();
    userType login(username, password, 1);
    bool validLogin = false;

    for( auto user: users)
    {
        if (user.equals(login)) // check password
        {
            validLogin = true;
        }
    }

    QMessageBox msgBox;
    QString x;
    string s;
    if (validLogin)
        s = "Valid Login";
    else
        s = "Invalid login";
    x = QString::fromStdString(s);
    msgBox.setText(x);
    msgBox.exec();
}

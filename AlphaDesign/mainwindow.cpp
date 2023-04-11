#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    changeMode();
    QPixmap avatar(QDir::currentPath() +  "/ava.jpg");
    avatar = avatar.scaled(128, 128, Qt::KeepAspectRatio);
    ui->LogoLabel->setPixmap(avatar);
    changePassMode();
    changeEmailMode();
    changeLoginMode();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeMode()
{
    passChange = !passChange;

    ui->Email->setVisible(mode);
    ui->EmailLine->setVisible(mode);
    ui->Pass_2->setVisible(mode);
    ui->PassLine_2->setVisible(mode);

    if (mode){
        ui->SignButton->setText("Sign Up");
        ui->changeModeButton->setText("I already have an account");
    }
    else{
        ui->SignButton->setText("Sign In");
        ui->changeModeButton->setText("I don't have an account");
    }
}

void MainWindow::changePassMode()
{
    mode = !mode;
    ui->OldPassLabel->setVisible(mode);
    ui->oldPassLine->setVisible(mode);
    ui->NewPassLabel->setVisible(mode);
    ui->NewPassLabel2->setVisible(mode);
    ui->NewPassLine->setVisible(mode);
    ui->NewPassLine_2->setVisible(mode);
}

void MainWindow::changeEmailMode()
{
    emailChange = !emailChange;

    ui->AccountEmalLabel->setVisible(!emailChange);

    ui->NewEmailLine->setVisible(emailChange);
}

void MainWindow::changeLoginMode()
{
    loginChange = !loginChange;

    ui->NewLogin->setText(ui->AccountLoginLabel->text());
    ui->NewLogin->setVisible(loginChange);

    ui->AccountLoginLabel->setVisible(!loginChange);
}


void MainWindow::on_changeModeButton_clicked()
{
    changeMode();
}

// пока пустышка
void MainWindow::on_SignButton_clicked()
{
    qDebug() << "Типа проверяем данные об аккаунте";
    if (!mode){
        qDebug() << "User Authorization:";
        qDebug() << "Login: " + ui->LoginLine->text();
        qDebug() << "Password: " + ui->PassLine->text();
    }
    else{
        qDebug() << "User Registration:";
        qDebug() << "Login: " + ui->LoginLine->text();
        qDebug() << "E-mail: " + ui->EmailLine->text();
        qDebug() << "Password: " + ui->PassLine->text();
        qDebug() << "Retyped password: " + ui->PassLine_2->text();
    }
    if (ui->checkBox->isChecked())
        qDebug() << "We will never forget you!";
}


void MainWindow::on_ChangePassBtn_clicked()
{
    changePassMode();
}


void MainWindow::on_ChangeEmailBtn_clicked()
{
    changeEmailMode();
}


void MainWindow::on_changeLoginBtn_clicked()
{
    changeLoginMode();
}


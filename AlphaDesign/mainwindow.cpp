#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    changeMode();
    changePassMode();
    changeEmailMode();
    changeLoginMode();
    changeChatMode();
    changeInvUserMode();

    changeAccountStatus(false);
    // потом удалить
    ui->NotifList->addItem("Здесь будут приглашения в чаты. Но пока тут ничего нет...");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeMode()
{
    mode = !mode;

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
    passChange = !passChange;
    ui->OldPassLabel->setVisible(passChange);
    ui->oldPassLine->setVisible(passChange);
    ui->NewPassLabel->setVisible(passChange);
    ui->NewPassLabel2->setVisible(passChange);
    ui->NewPassLine->setVisible(passChange);
    ui->NewPassLine_2->setVisible(passChange);
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

    changeAccountStatus(true);
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


void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    qDebug() << "Theme change";
}


void MainWindow::on_logoutBtn_clicked()
{
    qDebug() << "logout";
    changeAccountStatus(false);
}


void MainWindow::on_listWidget_itemSelectionChanged()
{
    qDebug() << ui->listWidget->currentIndex();
}

void MainWindow::changeChatMode()
{
    newChatCreate = !newChatCreate;

    if (!newChatCreate){
        ui->NewChatSp1->changeSize(0, 0, QSizePolicy::Fixed, QSizePolicy::Fixed);
        ui->NewChatSp2->changeSize(0, 0, QSizePolicy::Fixed, QSizePolicy::Fixed);
    }
    else{
        ui->NewChatSp1->changeSize(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);
        ui->NewChatSp2->changeSize(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);
    }

    ui->CreateNewChat->setVisible(newChatCreate);
    ui->NewChatDesc->setVisible(newChatCreate);
    ui->NewChatDescLabel->setVisible(newChatCreate);
    ui->NewChatHLine->setVisible(newChatCreate);
    ui->NewChatLabel->setVisible(newChatCreate);
    ui->NewChatNameLabel->setVisible(newChatCreate);
    ui->NewChatNameLine->setVisible(newChatCreate);

    ui->ChatBrowser->setVisible(!newChatCreate);
    ui->ChatLine->setVisible(!newChatCreate);
    ui->CurrentChatName->setVisible(!newChatCreate);
    ui->InviteUserBtn->setVisible(!newChatCreate);
    ui->leaveChatBtn->setVisible(!newChatCreate);
}


void MainWindow::createNewChat(){
    changeChatMode();

    ui->listWidget->addItem(ui->NewChatNameLine->text());
    qDebug() << "New chat created";
}

void MainWindow::on_pushButton_clicked()
{
    if (invNewUserMode) changeInvUserMode();
    changeChatMode();
}


void MainWindow::on_CreateNewChat_clicked()
{
    createNewChat();
}


void MainWindow::on_InviteUserBtn_clicked()
{
    changeInvUserMode();
}


void MainWindow::on_leaveChatBtn_clicked()
{
    ui->ChatBrowser->append("Вы вышли из этого чата");
}

void MainWindow::changeInvUserMode()
{
    invNewUserMode = !invNewUserMode;
    ui->InvUserBtn->setVisible(invNewUserMode);
    ui->InvUserIDLine->setVisible(invNewUserMode);
    ui->InvUserLabel->setVisible(invNewUserMode);
}


void MainWindow::on_InvUserBtn_clicked()
{
    ui->ChatBrowser->append("Вы добавили нового пользователя " + ui->InvUserIDLine->text());
    changeInvUserMode();
}


void MainWindow::on_ChatLine_returnPressed()
{
    ui->ChatBrowser->append(ui->ChatLine->text());
    ui->ChatLine->clear();
}

void MainWindow::changeAccountStatus(bool newStatus)
{
    loginedUser = newStatus;

    for (int i = 1; i < 5; i++)
        ui->tabWidget->setTabEnabled(i, newStatus);

    if (newStatus){
        ui->tabWidget->setCurrentIndex(1);
        ui->tabWidget->setTabEnabled(0, false);
    }
    else{
        ui->tabWidget->setCurrentIndex(0);
        ui->tabWidget->setTabEnabled(0, true);
    }
}


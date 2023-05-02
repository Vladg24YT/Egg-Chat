#include "mainwindow.h"
#include "ui_mainwindow.h"

server::server(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    qDebug() << "123";
    socket->connectToHost("95.165.152.146", 34197);
    connect(socket, &QTcpSocket::readyRead,
            this, &server::readSocket);
}

void server::parser(QString line)
{
    qDebug() << line;
    std::vector<QString> words;
    for (QString word : line.split("|")) words.push_back(word);
    if (words.size() <= 0) return;

    if (words[0] == "OK")
        ptr->changeAccountStatus(true);
    else if (words[0] == "BAD"){
        ptr->changeAccountStatus(false);
        ptr->setLoginTabEnable(true);
    }
    if (words[0] == "chatlist"){
        for (QString word : words) qDebug() << word;
        for (int i = 1; i < words.size(); i += 4){
            ptr->ui->listWidget->addItem(words[i+2]);
            ptr->ui->listWidget->item(ptr->ui->listWidget->count() - 1)->setToolTip(words[i]);
        }
    }
}

server *server::getInstance()
{
    if (!p_instance){
        p_instance = new server();
        destro.init(p_instance);
    }
    return p_instance;
}

void server::readSocket()
{
    QString msg = "";

    while (socket->bytesAvailable() > 0){
        msg.append(socket->readAll());
    }

    qDebug() << msg;
    parser(msg);
}

server* server::p_instance;
destroyer server::destro;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    server::getInstance()->ptr = this;

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
    server::getInstance()->socket->close();
}

void MainWindow::changeMode()
{
    mode = !mode;

    ui->Email->setVisible(mode);
    ui->EmailLine->setVisible(mode);
    ui->Pass_2->setVisible(mode);
    ui->PassLine_2->setVisible(mode);

    if (mode){
        ui->SignButton->setText("Зарегистрироваться");
        ui->changeModeButton->setText("У меня уже есть аккаунт");
    }
    else{
        ui->SignButton->setText("Войти");
        ui->changeModeButton->setText("У меня ещё нет аккаунта");
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
    QString login = ui->LoginLine->text();
    QString pass = ui->PassLine->text();
    QString pass2 = ui->PassLine_2->text();
    QString email = ui->EmailLine->text();
    QString msg;

    if (mode)
        if (pass == pass2){
            msg = "reg|" + login + "|" + pass + "|" + email;
            server::getInstance()->socket->write(msg.toUtf8());
        }
        else{
            qDebug() << "pass 1 != pass 2!";
            setLoginTabEnable(true);
        }
    else if (login != "" && pass != ""){
           msg = "login|" + login + "|" + pass;
           server::getInstance()->socket->write(msg.toUtf8());
        }
    else setLoginTabEnable(true);
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
    server::getInstance()->socket->write("logout");
    setLoginTabEnable(true);
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

void MainWindow::setLoginTabEnable(bool setTo)
{
    ui->LoginLine->setEnabled(setTo);
    ui->EmailLine->setEnabled(setTo);
    ui->PassLine->setEnabled(setTo);
    ui->PassLine_2->setEnabled(setTo);
    ui->SignButton->setEnabled(setTo);
    ui->changeModeButton->setEnabled(setTo);
    ui->checkBox->setEnabled(setTo);
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


void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (index == 1){
        server::getInstance()->socket->write("chat|get");
    }
}


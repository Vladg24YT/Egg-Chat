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

    if (!connected and words[0] == "Connected"){
        connected = true;
        ptr->changeConnectStat(true);
    }

    if (!ptr->loginedUser)
    {
        if (words[0] == "OK"){
            ptr->writeData(ptr->ui->checkBox->isChecked() ? 1 : 0);
            ptr->changeAccountStatus(true);
        }
        else if (words[0] == "BAD"){
            ptr->changeAccountStatus(false);
            ptr->setLoginTabEnable(true);
        }
    }
    if (words[0] == "chatlist" and words.size() >= 5){
        ptr->ui->listWidget->clear();
        ptr->chats.clear();
        ptr->ui->ChatBrowser->clear();
        for (int i = 1; i < words.size(); i += 4){
            ptr->ui->listWidget->addItem(words[i+2]);
            ptr->ui->listWidget->item(ptr->ui->listWidget->count() - 1)->setToolTip(words[i]);
        }
    }
    else if (words[0] == "messagelist" and words.size() >= 4){

        for (int i = 1; i < words.size(); i += 3){
            ptr->chats[ptr->currentChat].addMessage(message(words[i], words[i+2], words[i+1]));
        }
        for (message msg : ptr->chats[ptr->currentChat].msgs){
            //qDebug() << msg.show();
            ptr->ui->ChatBrowser->append(msg.show());
        }
    }
    else if (words[0] == "message" and words.size() >= 5 and ptr->chats.contains(words[2])){
        message nm = message(words[1], words[3], words[4]);
        ptr->chats[words[2]].addMessage(nm);
        if (ptr->currentChat == words[2])
            ptr->ui->ChatBrowser->append(nm.show());
    }
    else if (words[0] == "invitelist" and words.size() >= 5){
        ptr->invites.clear();
        ptr->ui->NotifList->clear();
        for (int i = 1; i < words.size(); i += 4)
            ptr->invites.insert(words[i], invite(words[i], words[i+1], words[i+2], words[i+3]));
        for (invite i : ptr->invites){
            ptr->ui->NotifList->addItem(i.toString());
            ptr->ui->NotifList->item(ptr->ui->NotifList->count() - 1)->setToolTip(i.getID());
        }
    }
    else if (words[0] == "invite" and words.size() >= 5){
        invite ni = invite(words[1], words[2], words[3], words[4]);
        ptr->ui->NotifList->addItem(ni.toString());
        ptr->ui->NotifList->item(ptr->ui->NotifList->count() - 1)->setToolTip(words[1]);
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
    changeConnectStat(false);

    homeDir = QDir::homePath() + "/Qlient";

    // потом удалить
    //ui->NotifList->addItem("Здесь будут приглашения в чаты. Но пока тут ничего нет...");
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

void MainWindow::changeConnectStat(bool setTo)
{
    ui->Login->setVisible(setTo);
    ui->Pass->setVisible(setTo);
    ui->Pass_2->setVisible(setTo & mode);
    ui->Email->setVisible(setTo & mode);
    ui->LoginLine->setVisible(setTo);
    ui->EmailLine->setVisible(setTo & mode);
    ui->PassLine->setVisible(setTo);
    ui->PassLine_2->setVisible(setTo & mode);
    ui->SignButton->setVisible(setTo);
    ui->changeModeButton->setVisible(setTo);
    ui->checkBox->setVisible(setTo);

    ui->ConStatLabel->setVisible(!setTo);

    if (setTo)
        this->readData();
}


void MainWindow::on_changeModeButton_clicked()
{
    changeMode();

}

void MainWindow::on_SignButton_clicked()
{
    setLoginTabEnable(false);
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
//           if(ui->checkBox->isChecked()){
//               writeData(1);
//           }
//           else{
//               writeData(0);
//           }
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
    /*
     * Надо делать через QPallete
    */
}

void MainWindow::on_logoutBtn_clicked()
{
    server::getInstance()->socket->write("logout");
    setLoginTabEnable(true);
    changeAccountStatus(false);
    ui->listWidget->clear();
    ui->NotifList->clear();
    ui->ChatBrowser->clear();
}


void MainWindow::on_listWidget_itemSelectionChanged()
{
    QString currentChatInd =  ui->listWidget->currentItem()->toolTip();
    ui->ChatBrowser->clear();
    this->currentChat = currentChatInd;
    if (chats.count(currentChatInd)){
        // выводим все сообщения в chatBrowser
        for (int i = 0; i < chats[currentChatInd].msgs.size(); i++)
            ui->ChatBrowser->append(chats[currentChatInd].msgs[i].show());
    }
    else{
        // запрос сообщений + вывод в chatBrowser
        QString msg = "message|get|" + currentChatInd;
        server::getInstance()->socket->write(msg.toUtf8());
    }
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
    QString chatName = ui->NewChatNameLine->text();
    QString chatDesc = ui->NewChatDesc->toPlainText();

    if (chatName != ""){
        QString msg = "chat|create|" + chatName + "|" + chatDesc;
        server::getInstance()->socket->write(msg.toUtf8());
        changeChatMode();
     }
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

void MainWindow::readData()
{
    qDebug() << "Reading data from file";
    /*для корректной работы должна быть предварительно
    создана папка Qlient в домашней папке пользователя*/
    QFile file(homeDir + "/data.txt");
    if (!file.open((QIODevice::ReadWrite | QIODevice::Text))){
        file.close();
    }
    else{
        std::vector<QString> lines;
        QString in = file.readAll();
        qDebug() << in;
        for (QString line : in.split("\n")) lines.push_back(line);

        if (lines.size() == 3){
            if (lines[0] == "1"){
                if (lines[1] != "" && lines[2] != "")
                {
                    ui->LoginLine->setText(lines[1]);
                    ui->PassLine->setText(lines[2]);
                    this->on_SignButton_clicked();
                }
            }
        }
        file.close();
    }
}

void MainWindow::writeData(int stat)
{
    qDebug() << "Writting data to file";
    QFile file(homeDir + "/data.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        file.close();
    else{
        file.Truncate;
        QString dt = QString::number(stat) + "\n" + ui->LoginLine->text() + "\n" + ui->PassLine->text();
        qDebug() << dt;
        QTextStream out(&file);
        out << dt;
        file.close();
    }
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
    QString msg = "chat|leave|" + currentChat;
    server::getInstance()->socket->write(msg.toUtf8());
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
    if (ui->InvUserIDLine->text() != "" and currentChat != ""){
        QString msg = "invite|send|" + ui->InvUserIDLine->text() + "|" + currentChat;
        qDebug() << msg;
        server::getInstance()->socket->write(msg.toUtf8());
        ui->InvUserIDLine->clear();
    }
    changeInvUserMode();
}


void MainWindow::on_ChatLine_returnPressed()
{
    QString msg = "message|send|" + currentChat + "|" + ui->ChatLine->text();
    server::getInstance()->socket->write(msg.toUtf8());
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
    //qDebug() << index;
    if (index == 1){
        server::getInstance()->socket->write("chat|get");
    }
    else if (index == 3){
        ui->NotifList->clear();
        invites.clear();
        server::getInstance()->socket->write("invite|get");
    }
}


void MainWindow::on_InviteAccept_clicked()
{
    try{
        QString ans = invites[ui->NotifList->currentItem()->toolTip()].answer(true);
        server::getInstance()->socket->write(ans.toUtf8());
    }
    catch (...){
        return;
    }
}


void MainWindow::on_InviteDecline_clicked()
{
    if (invites.contains(ui->NotifList->currentItem()->toolTip())) {
        QString ans = invites[ui->NotifList->currentItem()->toolTip()].answer(false);
        server::getInstance()->socket->write(ans.toUtf8());
    }
    return;
}

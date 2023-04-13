#include "client.h"

Client::Client(QObject *parent, QTcpSocket * socket) : QObject{parent}
{
    Socket = socket;
    connect(Socket, &QTcpSocket::readyRead, this, &Client::Read);
    connect(Socket, &QTcpSocket::disconnected, this, &Client::OnClosing);
}
// парсер комманд
void Client::parser(std::string line) {
    /*
        Эта функция делит входящую команду
        на комнаду и агрументы
    */
    // проверяем что получили именно команду
    if (line[0] != '/')
        send("This is not a command!");
    // вектор для хранения слов строки
    // 0-й элемент - команда
    std::vector<std::string> words;

    // вычленяем команду
    words.push_back(line.substr(1, 2));

    std::string tmp = "";

    for (int i = 3; i < line.size(); i++){
        if (line[i] == ':'){
            words.push_back(tmp);
            tmp = "";
        }
        else
            tmp = tmp + line[i];
    }
    words.push_back(tmp);
    commandRecognizer(words);
}
void Client::commandRecognizer(std::vector<std::string> words){
    /*
        Определяет какую команду получил на
        вход и кому её дальше отправлять
    */
    if (words[0] == "la") // логин админа
        if (words.size() == 3)
            return;
        else
            return send("Wrong data set!");
    else if (words[0] == "lu") // логин пользователя
        if (words.size() == 3)
            if (auth(QString::fromStdString(words[1]), QString::fromStdString(words[2]))){
                return send("Successful authorization!");
            }
            else return send("Wrong login or password!");
        else
            return send("Wrong data set!");
    if (isAuth){
        //        else if (words[0] == "lo") // выход из учётки)
        //            if (words.size() == 2)
        //                return logout();
        //            else
        //                return "No arguments expected!";
        if (words[0] == "rg"){ // регистрация
            if (words.size() == 3){
                if (registration(QString::fromStdString(words[1]), QString::fromStdString(words[2]))){
                    send("Successful registration!");
                }
                else send("Login is unavailable!");
                return;}}
        else if (words[0] == "me"){ // отправка сообщения
            if (words.size() == 3 && words[1] != "" && words[2] != ""){
                emit Message(QString::fromStdString(words[1]),QString::fromStdString(words[1]));
                return;}}
        //        else if (words[0] == "nc")
        //            if (words.size() == 2 && words[1] != "")
        //                return newChat(words[1]);
        //            else
        //                return "No chat name provided!";
        //        else if (words[0] == "rc")
        //            if (words.size() == 2 && words[1] != "")
        //                return removeChat(words[1]);
        //            else
        //                return "No chatID provided!";
        //        else if (words[0] == "lc")
        //            if (words.size() == 2 && words[1] != "")
        //                return leaveChat(words[1]);
        //            else
        //                return "No chatID provided!";
        //        else if (words[0] == "iu")
        //            if (words.size() == 3 && words[1] != "" && words[2] != "")
        //                return inviteUserToChat(words[1], words[2]);
        //            else
        //                return "Wrong data set!";
        //        else if (words[0] == "ai")
        //            if (words.size() == 3 && (words[1] == "0" || words[1] == "1") && words[2] != "")
        //                return answerInvite(words[1], words[2]);
        //            else
        //                return "Wrong data set!";
        //        else if (words[0] == "ku")
        //            if (words.size() == 3 && words[1] != "" && words[2] != "")
        //                return kickUserFromChat(words[1], words[2]);
        //            else
        //                return "Wrong data set!";
        //        else if (words[0] == "sr") // подать жалобу
        //            if (words.size() == 3 && words[1] != "" && words[2] != "")
        //                return sendReport(words[1], words[2]);
        //            else
        //                return "Wrong data set!";
        //        // команды админа
        //        else if (words[0] == "bn")
        //            if (words.size() == 3 && words[1] != "" && words[2] != "")
        //                return banUser(words[1], words[2]);
        //            else
        //                return "Wrong data set!";
        //        else if (words[0] == "ub")
        //            if (words.size() == 2 && words[1] != "")
        //                return unbanUser(words[1]);
        //            else
        //                return "No userID provided!";
        //        else
        //            return "No such command!";
    }
    send("Unauthorized access!");
}
// Считывание строки клиентом
void Client::Read(){
    while(Socket->bytesAvailable() > 0){
        QByteArray command = Socket->readAll();
        qDebug() << command;
        QString c = QString(command).at(1);
        c += QString(command).at(2);
        qDebug() << c;
        parser(command.toStdString());
        //        if (c == "me"){
        //            qDebug() << 1;
        //            emit Send(QByteArray::fromStdString(Parser::parser(command.toStdString())));
        //        }
        //        else{
        //            qDebug() << 2;

        //            emit Send(QByteArray::fromStdString(Parser::parser(command.toStdString())) + " ");
        //        }
    }
}
bool Client::auth(QString login, QString password){
    isAuth = DBWorker::SearchUser(login, password);
    return isAuth;
}
bool Client::registration(QString login, QString password){
    isAuth = true;
    return true;
}
void Client::send(QString text){
    Socket->write(text.toUtf8());
}
void Client::OnClosing(){
    emit Close(this);
}
Client::~Client(){
    Socket->close();
}

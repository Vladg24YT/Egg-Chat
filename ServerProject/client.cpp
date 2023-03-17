#include "client.h"

Client::Client(QObject *parent, QTcpSocket * socket) : QObject{parent}
{
    Socket = socket;
    connect(Socket, &QTcpSocket::readyRead, this, &Client::Read);
    connect(Socket, &QTcpSocket::disconnected, this, &Client::OnClosing);
}
void Client::Read(){
    while(Socket->bytesAvailable() > 0)
    {
        QByteArray command = Socket->readAll();
        qDebug() << command;

        std::vector<std::string> words;
        std::string tmp = "";

        for (int i = 0; i < command.size(); i++) {
            if (command[i] == ' ') {
                words.push_back(tmp);
                tmp = "";
            }
            else
                tmp += command[i];
        }
        if (tmp != "")
            words.push_back(tmp);

        if (words[0] == "/reg")
            if (words.size() != 3)
                emit Send(QByteArray::fromStdString("Wrong input data!"));
            else
                emit Send(QByteArray::fromStdString("Registration user"));
        else if (words[0] == "/login")
            if (words.size() != 4)
                emit Send(QByteArray::fromStdString("Wrong input data!"));
            else if (words[1] == "a")
                emit Send(QByteArray::fromStdString("Authorization admin with"));
            else if (words[1] == "u")
                emit Send(QByteArray::fromStdString("Authorization user with"));
            else emit Send(QByteArray::fromStdString("Not such login option!"));
        else if (words[0] == "/message"){
            if (words.size() < 2)
                emit Send(QByteArray::fromStdString("No message!"));
            else {
                emit Send(QByteArray::fromStdString(words[1]));
            }
        }
    }
}
void Client::OnClosing(){
    emit Close(this);
}
Client::~Client(){
    Socket->close();
}

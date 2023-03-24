#include "client.h"
#include "parser.h"

Client::Client(QObject *parent, QTcpSocket * socket) : QObject{parent}
{
    Socket = socket;
    connect(Socket, &QTcpSocket::readyRead, this, &Client::Read);
    connect(Socket, &QTcpSocket::disconnected, this, &Client::OnClosing);
}
// Считывание строки клиентом
void Client::Read(){
    while(Socket->bytesAvailable() > 0)
    {
        QByteArray command = Socket->readAll();
        qDebug() << command;
        emit Send(QByteArray::fromStdString(Parser::parser(command.toStdString())) + "\r\n");

    }
}
void Client::OnClosing(){
    emit Close(this);
}
Client::~Client(){
    Socket->close();
}

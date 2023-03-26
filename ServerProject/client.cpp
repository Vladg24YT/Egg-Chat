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
        QString c = QString::fromStdString(command.toStdString())[1];
        c += QString::fromStdString(command.toStdString())[2];
        qDebug() << c;
        if (c == "me"){
            qDebug() << 1;
             emit Send(QByteArray::fromStdString(Parser::parser(command.toStdString())));
        }
        else{
            qDebug() << 2;

            emit Send(QByteArray::fromStdString(Parser::parser(command.toStdString())) + " " + QString::number(this->Id).toUtf8());
        }
    }
}
void Client::OnClosing(){
    emit Close(this);
}
Client::~Client(){
    Socket->close();
}

#include "server.h"
#include "parser.h"
#include <string>

Server::Server(QObject *parent): QObject{parent}
{
    TcpServer = new QTcpServer(this);
    connect(TcpServer, &QTcpServer::newConnection, this, &Server::slotNewConnection);

    if (!TcpServer->listen(QHostAddress::Any, 34197)) {
        qDebug() << "server is not started";
    }
    else {
        serverStatus = 1;
        qDebug() << "server is started";
    }
}
void Server::slotNewConnection() {
    if (serverStatus == 1) {
        QTcpSocket * sok = TcpServer->nextPendingConnection();
        qDebug() << sok->peerAddress();
        Client *client = new Client(this, sok);
        client->Id = sok->peerPort();
        // подключение сигналов для отправки сообщения и закрытия соединения клиента к слотам сервера
        connect(client, &Client::Send, this, &Server::slotMessage);
        connect(client, &Client::Close, this, &Server::slotRemove);
        Clients << client;
        client->Socket->write("Welcome to the echo server!\r\n");
    }
}
// функция для широковещательного сообщения
void Server::slotMessage(QByteArray message){
    qDebug() << "Start broadcast";
    foreach(Client * cleint, Clients){
        cleint->Socket->write(message + "\r\n");
    }
}
// удаление из списка отключившегося клиента
void Server::slotRemove(Client * client){
    Clients.remove(Clients.indexOf(client));
    qDebug() << "Client disconnected";
}
// деструктор
Server::~Server() {
    foreach(Client * cleint, Clients){
        cleint->Socket->close();
    }
    serverStatus = 0;
}

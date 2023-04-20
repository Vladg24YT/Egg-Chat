#include "server.h"
#include <string>

Server::Server(QObject *parent): QObject{parent}
{
    DBWorker::createDB();

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
        qDebug() << sok->peerAddress() << sok->socketDescriptor();
        Client *client = new Client(this, sok);
        // подключение сигналов для отправки сообщения и закрытия соединения клиента к слотам сервера
        connect(client, &Client::Message, this, &Server::slotMessage);
        connect(client, &Client::Close, this, &Server::slotRemove);
        QString clID = QString::number(sok->socketDescriptor());
        QString message = "Welcome to the server! Your ID = " + clID;
        Clients.insert(sok->socketDescriptor(), client);
        client->Socket->write(message.toUtf8());
    }
}

void Server::slotMessage(QString chatID, QString text){
    qDebug() << "Start broadcast";
    foreach(Client * clnt, Clients){
        clnt->Socket->write(QByteArray(text.toUtf8()));
    }
}

// удаление из списка отключившегося клиента
void Server::slotRemove(Client * client){
    //Clients.remove(Clients.indexOf(client));
    Clients.remove(client->Socket->socketDescriptor());
    client->Socket->close();
    qDebug() << "Client disconnected";
}
// деструктор
Server::~Server() {
    //foreach(Client * cleint, Clients){
    //    cleint->Socket->close();
    //}
    foreach(Client * clnt, Clients){
        clnt->Socket->close();
    }
    DBWorker::close();
    serverStatus = 0;
}

#include "server.h"
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
        //Clients << client;
        QString clID = QString::number(client->Id);
        QString message = "Welcome to the echo server! Your ID = " + clID;
        //client->Socket->write("Welcome to the echo server!\r\n");
        Clnts.insert(client->Id, client);
        client->Socket->write(message.toUtf8());
    }
}
// функция для широковещательного сообщения
//void Server::slotMessage(QByteArray message){
//    qDebug() << "Start broadcast";
//    foreach(Client * cleint, Clients){
//        cleint->Socket->write(message + "\r\n");
//    }
//}

//функция отправки сообщения конкретному пользователю
void Server::slotMessage(QByteArray message){
    QString clID;
    int i = message.size() - 1;

    while (message[i] != ' ' && i >= 0){
        clID = message[i] + clID;
        i--;
    }

    if (clID != '0')
    {
        qDebug() << "Sending message to userID = " + clID;
        try{
            Clnts[clID.toInt()]->Socket->write(message);
        }
        catch(...){
            qDebug() << "Could not sent a message to userID = " + clID;
        }
    }
    else{
        qDebug() << "Sending message to everyone";
        foreach(Client * clnt, Clnts){
            clnt->Socket->write(message);
        }
    }
}

// удаление из списка отключившегося клиента
void Server::slotRemove(Client * client){
    client->Socket->close();
    //Clients.remove(Clients.indexOf(client));
    Clnts.remove(client->Id);
    qDebug() << "Client disconnected";
}
// деструктор
Server::~Server() {
    //foreach(Client * cleint, Clients){
    //    cleint->Socket->close();
    //}
    foreach(Client * clnt, Clnts){
        clnt->Socket->close();
    }
    serverStatus = 0;
}

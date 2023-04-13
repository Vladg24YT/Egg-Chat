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
//функция отправки сообщения конкретному пользователю
//void Server::slotSend(QByteArray message){
//    QString clID;
//    int i = message.size() - 1;

//    while (message[i] != ' ' && i >= 0){
//        clID = message[i] + clID;
//        i--;
//    }
//    if (clID != '0')
//    {
//        qDebug() << "Sending message to userID = " + clID;
//        try{
//            Clients[clID.toInt()]->Socket->write(message);
//        }
//        catch(...){
//            qDebug() << "Could not sent a message to userID = " + clID;
//        }
//    }
//    else{
//        qDebug() << "Sending message to everyone";
//        foreach(Client * clnt, Clients){
//            clnt->Socket->write(message);
//        }
//    }
//}
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
    serverStatus = 0;
}

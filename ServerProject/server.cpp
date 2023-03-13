#include "server.h"

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
        TcpSocket = TcpServer->nextPendingConnection();
        qDebug() << TcpSocket->peerAddress();
        TcpSocket->write("Welcome to the echo server!\r\n");
        connect(TcpSocket, &QTcpSocket::readyRead, this, &Server::slotRead);
        connect(TcpSocket,&QTcpSocket::disconnected, this, &Server::slotCloseClientConnection);
    }
}

void Server::slotRead() {
    while(TcpSocket->bytesAvailable()>0)
    {
        QByteArray array = TcpSocket->readAll();
        qDebug() << array;

        std::vector<std::string> words;
        std::string tmp = "";

        for (int i = 0; i < array.size(); i++) {
            if (array[i] == ' ') {
                words.push_back(tmp);
                tmp = "";
            }
            else
                tmp += array[i];
        }
        if (tmp != "")
            words.push_back(tmp);

        if (words[0] == "/reg")
            if (words.size() != 3)
                TcpSocket->write("Wrong input data!\n");
            else
                TcpSocket->write("Registration user ");
        else if (words[0] == "/login")
            if (words.size() != 4)
                TcpSocket->write("Wrong input data!\n");
            else if (words[1] == "a")
                TcpSocket->write("Authorization admin with \n");
            else if (words[1] == "u")
                TcpSocket->write("Authorization user with \n");
            else TcpSocket->write("Not such login option!\n");
        else if (words[0] == "/message"){
            if (words.size() < 2)
                TcpSocket->write("No message!\n");
            else {
                TcpSocket->write("Message!\n");
            }
        };

        TcpSocket->write(array);
    }
}
void Server::slotCloseClientConnection() {
    TcpSocket->close();
}

Server::~Server() {
    TcpSocket->close();
    serverStatus = 1;
}

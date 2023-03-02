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
        QByteArray array =TcpSocket->readAll();
        qDebug() << array;

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

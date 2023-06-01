#include "server.h"
#include <string>

Server::Server(QObject* parent) : QObject{ parent }{
	DBWorker::getInstance()->open();
	TcpServer = new QTcpServer(this);
	connect(TcpServer, &QTcpServer::newConnection, this, &Server::slotNewConnection);

	if (!TcpServer->listen(QHostAddress::Any, 34197)) {
		qDebug() << "\033[31m[SERVER] Server is not started\033[0m";
	}
	else {
		qDebug() << "\033[32m[SERVER] Server is started\033[0m";
	}
}
void Server::slotNewConnection() {
	QTcpSocket* sok = TcpServer->nextPendingConnection();
	Client* client = new Client(sok);
	Clients.insert(client->GetDescriptor(), client);
	connect(client, &Client::Message, this, &Server::slotMessage);
	connect(client, &Client::Kick, this, &Server::slotKick);
	connect(client, &Client::Close, this, &Server::slotRemove);
	QString message = "Connected|ID|" + QString::number(client->GetDescriptor());
	client->Send(message);
	qDebug() << "[SERVER] Client " << sok->peerAddress() << client->GetDescriptor() << "connected";
}
void Server::slotMessage(QString sender, int chatID, QString text) {
	QString response = "message|";
	response += sender + "|" + QString::number(chatID) + "|" + text + "|" + QDateTime::currentDateTime().toString();
	qDebug() << "[SERVER] Start broadcast: " << response;
	foreach(Client * c, Clients) {
		if (c->Chats.contains(chatID)) {
			c->Send(response);
		}
	}
}
void Server::slotKick(int userID, QString command) {
	foreach(Client * c, Clients) {
		if (c->GetID() == userID) {
			c->Send(command);
			break;
		}
	}
}
void Server::slotRemove(Client* client) {
	Clients.remove(client->GetDescriptor());
	client->Socket->close();
	qDebug() << "\033[33m[SERVER] Client disconnected\033[0m";
}
Server::~Server() {
	foreach(Client * clnt, Clients) {
		clnt->Socket->close();
	}
	DBWorker::getInstance()->close();
}

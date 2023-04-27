#include "server.h"
#include <string>

Server::Server(QObject* parent) : QObject{ parent }
{
	DBWorker::createDB();

	TcpServer = new QTcpServer(this);
	connect(TcpServer, &QTcpServer::newConnection, this, &Server::slotNewConnection);

	if (!TcpServer->listen(QHostAddress::Any, 34197)) {
		qDebug() << "server is not started";
	}
	else {
		qDebug() << "server is started";
	}
}
void Server::slotNewConnection() {
	QTcpSocket* sok = TcpServer->nextPendingConnection();
	qDebug() << sok->peerAddress() << sok->socketDescriptor();
	Client* client = new Client(this, sok);
	connect(client, &Client::Message, this, &Server::slotMessage);
	connect(client, &Client::Kick, this, &Server::slotKick);
	connect(client, &Client::Close, this, &Server::slotRemove);
	QString message = "Connected! Your ID = " + sok->socketDescriptor();
	Clients.insert(sok->socketDescriptor(), client);
	client->Socket->write(message.toUtf8());
}
// нужен id отправителя
void Server::slotMessage(int senderID, int chatID, QString text) {
	qDebug() << "Start broadcast";
	QString response = "message|" + senderID + '|' + chatID + '|' + text;
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

// удаление из списка отключившегося клиента
void Server::slotRemove(Client* client) {
	Clients.remove(client->Socket->socketDescriptor());
	client->Socket->close();
	qDebug() << "Client disconnected";
}
// деструктор
Server::~Server() {
	foreach(Client * clnt, Clients) {
		clnt->Socket->close();
	}
	DBWorker::close();
}

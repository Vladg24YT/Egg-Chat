#include "client.h"

#include <QList>

Client::Client(QTcpSocket* socket, QObject* parent) : QObject{ parent } {
	Socket = socket;
	descriptor = Socket->socketDescriptor();
	connect(Socket, &QTcpSocket::readyRead, this, &Client::Read);
	connect(Socket, &QTcpSocket::disconnected, this, &Client::OnClosing);
}
void Client::parser(QString line) {
	std::vector<QString> words;

	for (QString word : line.split("|")) words.push_back(word);
	if (words.size() <= 0) return Send("There is no any command!");

	if (words[0] == "login") return login(words);
	if (words[0] == "reg") return registration(words);
	if (words[0] == "logout") return logout();
	if (words[0] == "message") {
		if (words.size() > 1) {
			if (words[1] == "get") return getMessage(words);
			if (words[1] == "send") return sendMessage(words);
		}
		return Send("Invalid message command!");
	}
	if (words[0] == "chat") {
		if (words.size() > 1) {
			if (words[1] == "get") return getChats();
			if (words[1] == "create") return createChat(words);
			if (words[1] == "leave") return leaveChat(words);
			if (words[1] == "remove") return removeChat(words);
		}
		return Send("Invalid chat command!");
	}
	if (words[0] == "invite") {
		if (words.size() > 1) {
			if (words[1] == "get") return getInvite(words);
			if (words[1] == "send") return sendInvite(words);
			if (words[1] == "answer") return ansewerInvite(words);
		}
		return Send("Invalid invite command!");
	}
	if (words[0] == "kick") return kickUser(words);
	if (words[0] == "report") {
		if (words.size() > 1) {
			if (words[1] == "send") return sendReport(words);
			if (words[1] == "get") return getReport();
		}
		return Send("Invalid report command!");
	}
	Send("Invalid command!");
}
void Client::Read() {
	while (Socket->bytesAvailable() > 0) {
		QByteArray command = Socket->readAll();
		qDebug() << "[CLIENT] " << command;
		parser(command);
	}
}
void Client::login(std::vector<QString> words) {
	if (words.size() != 3 || (words[1] == "" || words[2] == ""))
		return Send("Wrong login or password!");
	else {
		isAuth = DBWorker::searchUser(words[1], words[2]);
		if (isAuth) {
			id = DBWorker::getUserID(words[1], words[2]);
			return Send("OK");
		}
		return Send("BAD");
	}
}
void Client::registration(std::vector<QString> words) {
	if (words.size() != 4 || (words[1] == "" || words[2] == "" || words[3] == ""))
		Send("Wrong data!");
	else {
		bool isExist = DBWorker::searchUser(words[1], words[2]);
		if (!isExist) {
			DBWorker::insertUser(words[1], words[2], words[3]);
			isAuth = true;
			id = DBWorker::getUserID(words[1], words[2]);
			return Send("OK");
		}
		Send("BAD");
	}
}
void Client::createChat(std::vector<QString> words) {
	if (words.size() == 4)
		if (words[2] != "" && words[3] != "") return DBWorker::insertChat(id, words[2], words[3]);
	return Send("Invalid chat command!");
}
void Client::leaveChat(std::vector<QString> words) {
	if (words.size() == 4)
		if (words[2] != "") return DBWorker::leaveChat(id, words[3].toInt());
	return Send("Invalid chat command!");
}
void Client::removeChat(std::vector<QString> words) {
	if (words.size() == 3)
		if (words[2] != "") return DBWorker::removeChat(words[3].toInt());
	return Send("Invalid chat command!");
}
void Client::sendInvite(std::vector<QString> words) {
	if (words.size() == 4)
		if (words[2] != "" && words[3] != "") return DBWorker::insertInvite(id, words[2], words[3].toInt());
	return Send("Invalid invite command!");
}
void Client::getInvite(std::vector<QString> words) {
	if (words.size() == 2) {
		QString response = "invitelist|" + DBWorker::selectInvite(id);
		response.remove(response.size() - 1, 1);
		Send(response);
	};
	Send("Invalid chat command!");
}
void Client::ansewerInvite(std::vector<QString> words) {
	if (words.size() == 4)
		if (words[3] != "" && words[4] != "") {
			bool answer = words[4].toInt();
			if (answer) DBWorker::addUserChat(id, words[3].toInt());
			return DBWorker::updateInvite(words[3].toInt(), answer);
		}
	return Send("Invalid invite command!");
}
void Client::kickUser(std::vector<QString> words) {
	if (words.size() == 3)
		if (words[1] != "" && words[2] != "") {
			DBWorker::removeUserChat(words[1].toInt(), words[2].toInt());
			emit Kick(words[1].toInt(), "kick|" + words[2]);
			return;
		}
	return Send("Invalid kick command!");
}
void Client::sendReport(std::vector<QString> words) {
	if (words.size() == 4)
		if (words[3] != "" && words[4] != "") return DBWorker::insertReport(words[3].toInt(), words[4]);
	return Send("Invalid report command!");
}
void Client::getReport() {
	QString response = "reportlist|" + DBWorker::selectReport();
	response.remove(response.size() - 1, 1);
	Send(response);
}
void Client::getChats() {
	QMap<int, QString> chats = DBWorker::selectUserChats(id);
	QString response = "chatlist|";
	QMapIterator<int, QString> i(chats);
	Chats = chats.keys();
	foreach(QString s, chats.values()) {
		response += s;
		if (s != chats.last()) response += '|';
	}
	Send(response);
}
void Client::Send(QString text) {
	qDebug() << "[SERVER] Send to client with id =" << id << ": " << text;
	Socket->write(text.toUtf8());
}
void Client::logout() {
	qDebug() << id << " logout";
	isAuth = false;
	id = 0;
}
void Client::getMessage(std::vector<QString> words) {
	if (words.size() == 3)
		if (words[2] != "") {
			QString response = "messagelist|" + DBWorker::selectMessages(words[2].toInt());
			response.remove(response.size() - 1, 1);
			return Send(response);
		}
	return Send("Invalid message command!");
}
void Client::sendMessage(std::vector<QString> words) {
	if (words.size() == 4)
		if (words[2] != "" && words[3] != "") {
			DBWorker::insertMessage(id, words[2].toInt(), words[3]);

			return emit Message(DBWorker::getUserNickname(id), words[2].toInt(), words[3]);
		}
	return Send("Invalid message command!");
}
void Client::OnClosing() {
	emit Close(this);
}
Client::~Client() {
	Socket->close();
}
int Client::GetID() { return id; }

int Client::GetDescriptor() { return descriptor; }

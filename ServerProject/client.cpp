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
	if (words[0] == "profile") {
		if (words.size() > 1) {
			if (words[1] == "get") return getProfile();
			if (words[1] == "update") return updateProfile(words);
		}
		return Send("Invalid profile command!");
	}
	if (words[0] == "invite") {
		if (words.size() > 1) {
			if (words[1] == "get") return getInvite();
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
		qDebug() << "[CLIENT]" << command;
		parser(command);
	}
}
void Client::login(std::vector<QString> words) {
	if (words.size() != 3 || (words[1] == "" || words[2] == ""))
		return Send("BAD");
	else {
		isAuth = DBWorker::getInstance()->authUser(words[1], words[2]);
		if (isAuth) {
			id = DBWorker::getInstance()->getUserID(words[1], words[2]);
			return Send("OK");
		}
		return Send("BAD");
	}
}
void Client::registration(std::vector<QString> words) {
	if (words.size() != 4 || (words[1] == "" || words[2] == "" || words[3] == ""))
		Send("BAD");
	else {
		bool isExist = DBWorker::getInstance()->searchUser(words[1]);
		if (!isExist) {
			DBWorker::getInstance()->insertUser(words[1], words[2], words[3]);
			isAuth = true;
			id = DBWorker::getInstance()->getUserID(words[1], words[2]);
			return Send("OK");
		}
		Send("BAD");
	}
}
void Client::createChat(std::vector<QString> words) {
	if (words.size() == 4)
		if (words[2] != "" && words[3] != "") {
			DBWorker::getInstance()->insertChat(id, words[2], words[3]);
			return getChats();
		}
	return Send("Invalid chat command!");
}
void Client::leaveChat(std::vector<QString> words) {
	if (words.size() == 3)
		if (words[2] != "") {
			DBWorker::getInstance()->leaveChat(id, words[2].toInt());
			emit Kick(words[1].toInt(), "kick|" + words[2]);
			int index = Chats.indexOf(words[2].toInt());
			if (index == -1) Chats.remove(index);
			return;
		}
	return Send("Invalid chat command!");
}
void Client::removeChat(std::vector<QString> words) {
	if (words.size() == 3)
		if (words[2] != "") {
			DBWorker::getInstance()->removeChat(words[2].toInt());
			int index = Chats.indexOf(words[2].toInt());
			if (index == -1) return Chats.remove(index);
			return;
		}
	return Send("Invalid chat command!");
}
void Client::sendInvite(std::vector<QString> words) {
	if (words.size() == 4)
		if (words[2] != "" && words[3] != "") return DBWorker::getInstance()->insertInvite(id, words[2], words[3].toInt());
	return Send("Invalid invite command!");
}
void Client::getInvite() {
	QString response = "invitelist|" + DBWorker::getInstance()->selectInvite(id);
	Send(response);
}
void Client::ansewerInvite(std::vector<QString> words) {
	if (words.size() == 5)
		if (words[2] != "" && words[3] != "" && words[4] != "") {
			bool answer = words[4].toInt();
			if (answer) {
				DBWorker::getInstance()->addUserChat(id, words[2].toInt());
				Chats.append(words[3].toInt());
				getChats();
			}
			DBWorker::getInstance()->removeInvite(words[2].toInt());
			return getInvite();
		}
	return Send("Invalid invite command!");
}
void Client::kickUser(std::vector<QString> words) {
	if (words.size() == 3)
		if (words[1] != "" && words[2] != "") {
			DBWorker::getInstance()->leaveChat(words[2].toInt(), words[1].toInt());
			emit Kick(words[1].toInt(), "kick|" + words[2]);
			return;
		}
	return Send("Invalid kick command!");
}
void Client::sendReport(std::vector<QString> words) {
	if (words.size() == 4)
		if (words[2] != "" && words[3] != "") return DBWorker::getInstance()->insertReport(words[2].toInt(), words[3]);
	return Send("Invalid report command!");
}
void Client::getProfile() {
	if (isAuth)
		Send("profile|" + DBWorker::getInstance()->getFullUser(id));
	else
		Send("BAD");
}
void Client::updateProfile(std::vector<QString> words) {
	if (isAuth && words.size() == 6) {
		if (DBWorker::getInstance()->updateUser(id, words[2], words[3], words[4], words[5]))
			getProfile();
	}
}
void Client::getReport() {
	QString response = "reportlist|" + DBWorker::getInstance()->selectReport();
	Send(response);
}
void Client::getChats() {
	QMap<int, QString> chats = DBWorker::getInstance()->selectUserChats(id);
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
	Socket->write(text.toUtf8() + "~");
	QTest::qSleep(50);
}
void Client::logout() {
	qDebug() << "[SERVER]" << id << "logout";
	isAuth = false;
	id = 0;
}
void Client::getMessage(std::vector<QString> words) {
	if (words.size() == 3)
		if (words[2] != "") {
			QString response = "messagelist|" + DBWorker::getInstance()->selectMessages(words[2].toInt());
			return Send(response);
		}
	return Send("Invalid message command!");
}
void Client::sendMessage(std::vector<QString> words) {
	if (words.size() == 4)
		if (words[2] != "" && words[3] != "") {
			DBWorker::getInstance()->insertMessage(id, words[2].toInt(), words[3]);
			return emit Message(DBWorker::getInstance()->getUserNickname(id), words[2].toInt(), words[3]);
		}
	return Send("Invalid message command!");
}
Client::~Client() { Socket->close(); }
void Client::OnClosing() { emit Close(this); }
int Client::GetID() { return id; }
int Client::GetDescriptor() { return descriptor; }

#include "client.h"

#include <QList>

Client::Client(QObject* parent, QTcpSocket* socket) : QObject{ parent }{
	Socket = socket;
	connect(Socket, &QTcpSocket::readyRead, this, &Client::Read);
	connect(Socket, &QTcpSocket::disconnected, this, &Client::OnClosing);
}
void Client::parser(QString line) {
	std::vector<QString> words;

	for (QString word : line.split("|")) words.push_back(word);
	if (words.size() <= 0) return send("There is no any command!");

	if (words[0] == "login") return login(words);
	if (words[0] == "reg") return registration(words);
	if (words[0] == "logout") return logout();
	if (words[0] == "message") {
		if (words.size() > 1) {
			if (words[1] == "get") return getMessage(words);
			if (words[1] == "send" && words.size() == 4)
				if (words[2] != "" && words[3] != "") return emit Message(words[2], words[3]); // нужно id или nickname
		}
		return send("Invalid message command!");
	}
	if (words[0] == "chat") {
		if (words.size() > 1) {
			if (words[1] == "get") return getChats();
			if (words[1] == "create") return createChat(words);
			if (words[1] == "leave") return leaveChat(words);
			if (words[1] == "remove") return removeChat(words);
		}
		return send("Invalid chat command!");
	}
	if (words[0] == "")
	{

	}

	return send("Invalid command!");
}

//		//        else if (words[0] == "iu")
//		//            if (words.size() == 3 && words[1] != "" && words[2] != "")
//		//                return inviteUserToChat(words[1], words[2]);
//		//            else
//		//                return "Wrong data set!";
//		//        else if (words[0] == "ai")
//		//            if (words.size() == 3 && (words[1] == "0" || words[1] == "1") && words[2] != "")
//		//                return answerInvite(words[1], words[2]);
//		//            else
//		//                return "Wrong data set!";
//		//        else if (words[0] == "ku")
//		//            if (words.size() == 3 && words[1] != "" && words[2] != "")
//		//                return kickUserFromChat(words[1], words[2]);
//		//            else
//		//                return "Wrong data set!";
//		//        else if (words[0] == "sr") // подать жалобу
//		//            if (words.size() == 3 && words[1] != "" && words[2] != "")
//		//                return sendReport(words[1], words[2]);


void Client::Read() {
	while (Socket->bytesAvailable() > 0) {
		QByteArray command = Socket->readAll();
		qDebug() << command;
		QString c = QString(command).at(1);
		c += QString(command).at(2);
		qDebug() << c;
		parser(command);
	}
}
void Client::login(std::vector<QString> words) {
	if (words.size() != 3 || (words[1] == "" || words[2] == ""))
		return send("Wrong login or password!");
	else {
		isAuth = DBWorker::searchUser(words[1], words[2]);
		if (isAuth) {
			id = DBWorker::getUserID(words[1], words[2]);
			return send("Successful authorization!");
		}
		return send("Wrong login or password!");
	}
}
void Client::registration(std::vector<QString> words) {
	if (words.size() != 4 || (words[1] == "" || words[2] == "" || words[3] == ""))
		send("Wrong data!");
	else {

		isAuth = DBWorker::searchUser(words[1], words[2]);
		if (isAuth) {
			id = DBWorker::getUserID(words[1], words[2]);
			send("Successful authorization!");
		}
		send("Wrong login or password!");
	}
}
void Client::createChat(std::vector<QString> words) {
	if (words.size() == 4)
		if (words[2] != "" && words[3] != "") return DBWorker::insertChat(id, words[2], words[3]);
	return send("Invalid chat command!");
}
void Client::leaveChat(std::vector<QString> words) {
	if (words.size() == 3)
		if (words[2] != "") return DBWorker::leaveChat(id, words[3].toInt());
	return send("Invalid chat command!");
}
void Client::removeChat(std::vector<QString> words) {
	if (words.size() == 3)
		if (words[2] != "") return DBWorker::removeChat(words[3].toInt());
	return send("Invalid chat command!");
}
void Client::getChats() {
	QList<Chat*> chats = DBWorker::selectUserChats(id);
	QString response;
	foreach(Chat * chat, chats) {
		response += chat->ToString();
	}
	for (int i = 0; i < chats.count(); i++) {
		delete chats.at(i);
	}
	chats.clear();
	send(response);
}
void Client::send(QString text) {
	Socket->write(text.toUtf8());
}
void Client::logout() {
	qDebug() << id << " logout";
	send("LOGOUT");
	isAuth = false;
	id = 0;
}
void Client::getMessage(std::vector<QString> words) {
	if (words.size() == 3)
		if (words[2] != "") return send(DBWorker::selectMessages(words[2].toInt()));
	return send("Invalid message command!");
}
void Client::OnClosing() {
	emit Close(this);
}
Client::~Client() {
	Socket->close();
}

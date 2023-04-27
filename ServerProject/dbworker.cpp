#include <DBWorker.h>


void DBWorker::open() {
	QString path = "";
#ifdef DEBUG
	path = "C:/Users/rustv/Documents/QtProjects/Egg-Chat/ServerProject/";
	qDebug() << "DEBUG mode";
#endif
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(path + "sqlite.db");
	if (!db.open()) qDebug() << db.lastError().text();
}

void DBWorker::createDB() {
	getInstance();
	if (!db.isOpen()) open();
}
void DBWorker::close() {
	if (db.isOpen()) db.close();
}

bool DBWorker::insertUser(QString login, QString password, QString email)
{
	QSqlQuery query = QSqlQuery(db);
	query.prepare("insert into users (login, password, nickname, email) values (?, ?, ?, ?) ");
	query.addBindValue(login);
	query.addBindValue(password);
	query.addBindValue(login);
	query.addBindValue(email);
	query.exec();
	return !query.lastError().isValid();
}

bool DBWorker::searchUser(QString login, QString password) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("select * from users where login = ? and password = ?");
	query.addBindValue(login);
	query.addBindValue(password);
	query.exec();
	bool isExist = false;
	while (query.next()) {
		isExist = true;
		QSqlRecord rec = query.record();
		const int idIndex = rec.indexOf("id");
	}
	return isExist;
}
int DBWorker::getUserID(QString login, QString password) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("select id from users where login = ? and password = ?");
	query.addBindValue(login);
	query.addBindValue(password);
	query.exec();
	while (query.next()) {
		QSqlRecord rec = query.record();
		const int idIndex = rec.indexOf("id");
		return query.value(idIndex).toInt();
	}
}
void DBWorker::insertChat(int userID, QString name, QString description) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("insert into chats (creator_id, name, description) VALUES (?, ?, ?)");
	query.addBindValue(userID);
	query.addBindValue(name);
	query.addBindValue(description);
	query.exec();
}
QMap<int, QString> DBWorker::selectUserChats(int userID) {
	QSqlQuery query = QSqlQuery(db);
	QMap<int, QString> chats;
	query.prepare("select chat_id, creator_id, name, description  from users_chats "
		"join chats on chats.id = users_chats.chat_id where user_id = ?");
	query.addBindValue(userID);
	query.exec();
	while (query.next()) {
		QString response;
		QSqlRecord rec = query.record();
		int id = query.value(0).toInt();
		response += query.value(0).toString() + '|';
		response += query.value(1).toString() + '|';
		response += query.value(2).toString() + '|';
		response += query.value(3).toString() + '|';
		chats.insert(id, response);
	}
	return chats;
}
void DBWorker::leaveChat(int userID, int chatID) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("delete from users_chats where chat_id = ? and user_id = ?");
	query.addBindValue(chatID);
	query.addBindValue(userID);
	query.exec();
}
void DBWorker::addUserChat(int userID, int inviteID) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("insert into users_chats (user_id, chat_id, is_admin) VALUES ( ?, (select chat from invites where id = ?), 0)");
	query.addBindValue(userID);
	query.addBindValue(inviteID);
	query.exec();
}
void DBWorker::removeChat(int chatID) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("delete from chats where id = ?");
	query.addBindValue(chatID);
	query.exec();
}
void DBWorker::insertMessage(int userID, int chatID, QString text) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("insert into messages (sender, chat, msg) VALUES ( ?, ?, ?)");
	query.addBindValue(userID);
	query.addBindValue(chatID);
	query.addBindValue(text);
	query.exec();
}
QString DBWorker::selectMessages(int chatID) {
	QSqlQuery query = QSqlQuery(db);
	QString response;
	query.prepare("select users.nickname, sendTime, msg from messages join users on users.id = sender where chat = ?");
	query.addBindValue(chatID);
	query.exec();
	while (query.next()) {
		QSqlRecord rec = query.record();
		response += query.value(0).toString() + query.value(1).toString() + query.value(2).toString() + "\n";
	}
	return response;
}
void DBWorker::insertInvite(int senderID, int receiverID, int ChatID) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("insert into invites (sender, receiver, chat, status) VALUES (?, ?, ?, 0)");
	query.addBindValue(senderID);
	query.addBindValue(receiverID);
	query.addBindValue(ChatID);
	query.exec();
}
QString DBWorker::selectInvite(int userID) {
	QSqlQuery query = QSqlQuery(db);
	QString response;
	query.prepare("select sender, chat from messages where receiver = ?");
	query.addBindValue(userID);
	query.exec();
	while (query.next()) {
		QSqlRecord rec = query.record();
		response += query.value(0).toString() + '|' + query.value(1).toString() + '|';
	}
	return response;
}
void DBWorker::updateInvite(int inviteID, bool answer) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("update invites set status = ? where id = ?");
	query.addBindValue(answer);
	query.addBindValue(inviteID);
	query.exec();
}
void DBWorker::removeUserChat(int userID, int chatID) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("delete from users_chats where user_id = ? and chat_id = ?");
	query.addBindValue(userID);
	query.addBindValue(chatID);
	query.exec();
}
void DBWorker::insertReport(int userID, QString text) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("insert into reports (user_id, decription) VALUES (?, ?)");
	query.addBindValue(userID);
	query.addBindValue(text);
	query.exec();
}
QString DBWorker::selectReport(){
	QSqlQuery query = QSqlQuery(db);
	QString response;
	query.prepare("select * from reports");
	query.exec();
	response += query.value(0).toString() + '|' + query.value(1).toString() + '|';
	while (query.next()) {
		QSqlRecord rec = query.record();
		response += query.value(0).toString() + '|' + query.value(1).toString() + '|' + query.value(2).toString() + '|';
	}
	return response;
}
QSqlDatabase DBWorker::db;

#include "DBWorker.h"


void DBWorker::open() {
	if (!DBWorker::getInstance()->db.isOpen()) {
		QString path = "";
#ifdef DEBUG
		path = "C:/Users/rustv/Documents/QtProjects/Egg-Chat/ServerProject/";
		qDebug() << "DEBUG mode";
#endif
		DBWorker::getInstance()->db = QSqlDatabase::addDatabase("QSQLITE");
		DBWorker::getInstance()->db.setDatabaseName(path + "sqlite.db");
		if (!DBWorker::getInstance()->db.open()) qDebug() << DBWorker::getInstance()->db.lastError().text();
	}
}
void DBWorker::close() {
	if (DBWorker::getInstance()->db.isOpen()) DBWorker::getInstance()->db.close();
}
QString DBWorker::getUserNickname(int userID) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("select nickname from users where id = ?");
	query.addBindValue(userID);
	query.exec();
	while (query.next()) {
		QSqlRecord rec = query.record();
		return query.value(0).toString();
	}
	return "";
}
bool DBWorker::insertUser(QString login, QString password, QString email) {
	if (login.isEmpty() || password.isEmpty() || email.isEmpty())
		return false;
	QSqlQuery query = QSqlQuery(db);
	query.prepare("insert into users (login, password, nickname, email) values (?, ?, ?, ?) ");
	query.addBindValue(login);
	query.addBindValue(password);
	query.addBindValue(login);
	query.addBindValue(email);
	query.exec();
	return !query.lastError().isValid();
}
bool DBWorker::searchUser(QString login) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("select * from users where login = ?");
	query.addBindValue(login);
	query.exec();
	bool isExist = false;
	while (query.next()) {
		isExist = true;
	}
	return isExist;
}
bool DBWorker::authUser(QString login, QString password) {
	if (login.isEmpty() || password.isEmpty())
		return false;
	QSqlQuery query = QSqlQuery(db);
	query.prepare("select * from users where login = ? and password = ?");
	query.addBindValue(login);
	query.addBindValue(password);
	query.exec();
	bool isExist = false;
	while (query.next()) {
		isExist = true;
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
		return query.value(0).toInt();
	}
	return 0;
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
		response += query.value(3).toString();
		chats.insert(id, response);
	}
	return chats;
}
void DBWorker::addUserChat(int userID, int inviteID) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("insert into users_chats (user_id, chat_id, is_admin) VALUES ( ?, (select chat from invites where id = ?), 0)");
	query.addBindValue(userID);
	query.addBindValue(inviteID);
	query.exec();
	qDebug() << query.lastError();
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
QString DBWorker::selectMessages(int chatID, int limit) {
	QSqlQuery query = QSqlQuery(db);
	QString response;
	query.prepare("select * from (select messages.id, users.nickname, sendTime, msg from messages join users on users.id = sender where chat = ? order by messages.id desc limit ?) order by id asc");
	query.addBindValue(chatID);
	query.addBindValue(limit);
	query.exec();
	while (query.next()) {
		QSqlRecord rec = query.record();
		response += query.value(1).toString() + '|' + query.value(2).toString() + '|' + query.value(3).toString() + '|';
	}
	response.chop(1);
	return response;
}
void DBWorker::insertInvite(int senderID, QString receiver, int ChatID) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("insert into invites (sender, receiver, chat, status) VALUES (?, (select users.id from users where login = ?), ?, 0)");
	query.addBindValue(senderID);
	query.addBindValue(receiver);
	query.addBindValue(ChatID);
	query.exec();
}
QString DBWorker::selectInvite(int userID) {
	QSqlQuery query = QSqlQuery(db);
	QString response;
	query.prepare("select invites.id, chats.name, chats.id, users.nickname from invites join chats on chats.id = invites.chat join users on users.id = invites.sender where receiver = ? and invites.status = 0");
	query.addBindValue(userID);
	query.exec();
	while (query.next()) {
		QSqlRecord rec = query.record();
		response += query.value(0).toString() + '|' + query.value(1).toString() + '|' + query.value(2).toString() + '|' + query.value(3).toString();
		if (!query.last()) response += '|';
	}
	return response;
}
void DBWorker::removeInvite(int inviteID) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("delete from invites where id = ?");
	query.addBindValue(inviteID);
	query.exec();
}
void DBWorker::leaveChat(int userID, int chatID) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("delete from users_chats where chat_id = ? and user_id = ?");
	query.addBindValue(chatID);
	query.addBindValue(userID);
	query.exec();
}
void DBWorker::insertReport(int userID, QString text) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("insert into reports (user_id, decription) VALUES (?, ?)");
	query.addBindValue(userID);
	query.addBindValue(text);
	query.exec();
}
QString DBWorker::selectReport() {
	QSqlQuery query = QSqlQuery(db);
	QString response;
	query.prepare("select * from reports");
	query.exec();
	while (query.next()) {
		QSqlRecord rec = query.record();
		response += query.value(0).toString() + '|' + query.value(1).toString() + '|' + query.value(2).toString();
		if (!query.last()) response += '|';
	}
	return response;
}
bool DBWorker::updateUser(int userID, QString login, QString password, QString email, QString nickname) {
	if (login.isEmpty() || password.isEmpty() || email.isEmpty() || nickname.isEmpty())
		return false;
	QSqlQuery query = QSqlQuery(db);
	query.prepare("update users set login = ?, password = ?, email = ?, nickname = ? where id = ?");
	query.addBindValue(login);
	query.addBindValue(password);
	query.addBindValue(email);
	query.addBindValue(nickname);
	query.addBindValue(userID);
	query.exec();
	return !query.lastError().isValid();
}
QString DBWorker::getFullUser(int userID){
	QSqlQuery query = QSqlQuery(db);
	QString response;
	query.prepare("select login, email, nickname from users where id = ? limit 1");
	query.addBindValue(userID);
	query.exec();
	while (query.next()) {
		QSqlRecord rec = query.record();
		response += query.value(0).toString() + '|' + query.value(1).toString() + '|' + query.value(2).toString();
		if (!query.last()) response += '|';
	}
	return response;
}
SingletonDestroyer::~SingletonDestroyer(){
    delete p_instance;
}
void SingletonDestroyer::init(DBWorker* p){
    p_instance = p;
}

DBWorker* DBWorker::getInstance(){
    if (!p_instance){
        p_instance = new DBWorker();
        destroyer.init(p_instance);
    }
    return p_instance;
}

DBWorker* DBWorker::p_instance;
SingletonDestroyer DBWorker::destroyer;
DBWorker* SingletonDestroyer::p_instance;

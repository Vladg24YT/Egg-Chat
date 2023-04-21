#include "dbworker.h"


void DBWorker::open() {
	// чтобы заставить работать этот код, нужно изменить переменную ниже на путь к файлу "sqlite.db"
	QString path = "";
#ifdef DEBUG
	path = "C:/Users/rustv/Documents/QtProjects/Egg-Chat/ServerProject/";
	qDebug() << "def DEBUG";
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

void DBWorker::selectFromDB() {
	static QSqlQuery query = QSqlQuery(db);
	query.exec("select * from chats");
	try {
		while (query.next()) {
			QSqlRecord rec = query.record();
			const int idIndex = rec.indexOf("id");
			const int loginIndex = rec.indexOf("name");
		}
	}
	catch (...) { qDebug() << "Виу-виу! Код красный - код не робит!"; }
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
QList<Chat*> DBWorker::selectUserChats(int userID) {
	static QSqlQuery query = QSqlQuery(db);
	QList<Chat*> chats;
	query.prepare("select chat_id, creator_id, name, description  from users_chats "
		"join chats on chats.id = users_chats.chat_id where user_id = ?");
	query.addBindValue(userID);
	query.exec();
	while (query.next()) {
		QSqlRecord rec = query.record();
		Chat* chat = new Chat();
		chat->id = query.value(0).toInt();
		chat->creator_id = query.value(1).toInt();
		chat->name = query.value(2).toString();
		chat->decription = query.value(3).toString();
		chats << chat;
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
void DBWorker::removeChat(int chatID) {
	QSqlQuery query = QSqlQuery(db);
	query.prepare("delete from chats where id = ?");
	query.addBindValue(chatID);
	query.exec();
}
void DBWorker::insertMessage(int userID, int chatID, QString text) {

}
QString DBWorker::selectMessages(int chatID) {
	static QSqlQuery query = QSqlQuery(db);
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
QSqlDatabase DBWorker::db;

#ifndef DBWORKER_H
#define DBWORKER_H

#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QList>
//#include <singleton.h>
//переключение режима, для запуска на винде или в докере
#define DEBUG
class DBWorker;
/// <summary>
/// Класс синглтон дестроера
/// </summary>
class SingletonDestroyer {
private:
	static DBWorker* p_instance;
public:
	/// <summary>
	/// Деструктор классла синглтон дестроера
	/// </summary>
	~SingletonDestroyer();
	/// <summary>
	/// Метод инициализации
	/// </summary>
	/// <param name=""></param>
	void init(DBWorker*);
};
/// <summary>
/// Синглтон класс для взаимодействи с базой данных
/// </summary>
class DBWorker {
	/// <summary>
	/// Предоставление доступа классу SingletonDestroyer
	/// </summary>
	friend class SingletonDestroyer;
private:
	QSqlDatabase db;
	static DBWorker* p_instance;
	static SingletonDestroyer destroyer;
protected:
	/// <summary>
	/// Конструктор класса Singleton.
	/// </summary>
	DBWorker() {}
	/// <summary>
	/// Блокировка конструктора копирования.
	/// </summary>
	/// <param name=""></param>
	DBWorker(const DBWorker&) = delete;
	/// <summary>
	/// Блокировка оператора равно (=).
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	DBWorker& operator = (DBWorker&) = delete;
public:
	/// <summary>
	/// Метод получения экземпляра класса DBWorker.
	/// </summary>
	/// <returns>класс DBWorker</returns>
	static DBWorker* getInstance();
	/// <summary>
	/// Метод инициализации экземпляра данного класса о открытия подключения к бд.
	/// </summary>
	static void open();
	/// <summary>
	/// Закрытие соединения с базой данных.
	/// </summary>
	static void close();
	/// <summary>
	/// Метод получения никнейма пользователя по его ID.
	/// </summary>
	/// <param name="userID">- ID необходимого пользователя</param>
	/// <returns>имя пользователя</returns>
	QString getUserNickname(int userID);
	/// <summary>
	/// Метод добавления пользователя в базу данных.
	/// </summary>
	/// <param name="login">- логин</param>
	/// <param name="password">- пароль</param>
	/// <param name="email">- email</param>
	/// <returns>если запись добавлена в бд вернется true иначе false</returns>
	bool insertUser(QString login, QString password, QString email);
	/// <summary>
	/// Метод проверки на существование пользователя.
	/// </summary>
	/// <param name="login">- логин</param>
	/// <returns>Если пользователь найдет, то вернет true иначе false</returns>
	bool searchUser(QString login);
	/// <summary>
	/// Метод проверки на существование пользователя.
	/// </summary>
	/// <param name="login">- логин</param>
	/// <param name="passwrod">- пароль</param>
	/// <returns>Если пользователь найдет, то вернет true иначе false</returns>
	bool authUser(QString login, QString password);
	/// <summary>
	/// Метод получения ID пользователя.
	/// </summary>
	/// <param name="login">- логин</param>
	/// <param name="password">- пароль</param>
	/// <returns>ID пользователя</returns>
	int getUserID(QString login, QString password);
	/// <summary>
	/// Метод создания чата.
	/// </summary>
	/// <param name="userID">- ID создателя чата</param>
	/// <param name="name">- название чата</param>
	/// <param name="description">- описание чата</param>
	void insertChat(int userID, QString name, QString description);
	/// <summary>
	/// Метод получения чатов пользователя.
	/// </summary>
	/// <param name="userID">- ID пользователя</param>
	/// <returns>QMap ключом является ID чата, значением его название</returns>
	QMap<int, QString> selectUserChats(int userID);
	/// <summary>
	/// Метод выхода из чата.
	/// </summary>
	/// <param name="userID">- ID пользователя</param>
	/// <param name="chatID">- ID чата</param>
	void leaveChat(int userID, int chatID);
	/// <summary>
	/// Метод добавления пользователя в чат
	/// </summary>
	/// <param name="userID">- ID пользователя</param>
	/// <param name="chatID">- ID чата</param>
	void addUserChat(int userID, int chatID);
	/// <summary>
	/// Метод удаления чата.
	/// </summary>
	/// <param name="chatID">- ID чата</param>
	void removeChat(int chatID);
	/// <summary>
	/// Метод добавления сообщения.
	/// </summary>
	/// <param name="userID">- ID отправителя</param>
	/// <param name="chatID">- ID чата назначения</param>
	/// <param name="text">- текст сообщения</param>
	void insertMessage(int userID, int chatID, QString text);
	/// <summary>
	/// Метод получения сообщений чата
	/// </summary>
	/// <param name="chatID">- ID чата</param>
	/// <param name="limit">- максимально возращаемое количество записей</param>
	/// <returns>Возвращает строку со всеми сообщения содержащую отправителя, время и текст сообщения</returns>
	QString selectMessages(int chatID, int limit = 50);
	/// <summary>
	/// Метод добавления приглашения.
	/// </summary>
	/// <param name="senderID">- ID отправителя</param>
	/// <param name="receiver">- логин приглашаемого</param>
	/// <param name="ChatID">- ID чата</param>
	void insertInvite(int senderID, QString receiver, int ChatID);
	/// <summary>
	/// Метод получения приглашений определенного пользователя
	/// </summary>
	/// <param name="userID">- ID пользователя</param>
	/// <returns>Возвращает строку со всеми приглашениями, содержащую ID приглашения, ID отправителя и ID чата</returns>
	QString selectInvite(int userID);
	/// <summary>
	/// Метод удаления приглашения после ответа на него.
	/// </summary>
	/// <param name="inviteID">- ID приглашения</param>
	void removeInvite(int inviteID);
	/// <summary>
	/// Метод добавления жалобы
	/// </summary>
	/// <param name="userID">- ID пользователя, на которого пожаловались</param>
	/// <param name="text">- сообщение жалобы</param>
	void insertReport(int userID, QString text);
	/// <summary>
	/// Метод получения всех доступных жалоб
	/// </summary>
	/// <returns>Возвращает строку со всеми жалобами, содержащие в себе ID жалобы, ID полььзователя, тест сообщения</returns>
	QString selectReport();
	/// <summary>
	/// Метод обновления данных пользователя.
	/// </summary>
	/// <param name="userID">- ID пользователя</param>
	/// <param name="login">- строка логина</param>
	/// <param name="password">- строка пароля</param>
	/// <param name="email">- строка почты</param>
	/// <param name="nickname">- строка никнейма</param>
	/// <returns></returns>
	bool updateUser(int userID, QString login, QString password, QString email, QString nickname);
};

#endif // DBWORKER_H

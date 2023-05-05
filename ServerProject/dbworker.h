#ifndef DBWORKER_H
#define DBWORKER_H

#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QList>
#include <singleton.h>
//переключение режима, для запуска на винде или в докере
#define DEBUG
/// <summary>
/// Синглтон класс для взаимодействи с базой данных
/// </summary>
class DBWorker : public Singleton {
private:
	DBWorker() = delete;
	DBWorker(const DBWorker&) = delete;
	static QSqlDatabase db;
	static void open();
public:
	/// <summary>
	/// Метод инициализации экземпляра данного класса о открытия подключения к бд.
	/// </summary>
	static void createDB();
	/// <summary>
	/// Закрытие соединения с базой данных.
	/// </summary>
	static void close();
	/// <summary>
	/// Метод получения никнейма пользователя по его ID.
	/// </summary>
	/// <param name="userID">- ID необходимого пользователя</param>
	/// <returns>имя пользователя</returns>
	static QString getUserNickname(int userID);
	/// <summary>
	/// Метод добавления пользователя в базу данных.
	/// </summary>
	/// <param name="login">- логин</param>
	/// <param name="password">- пароль</param>
	/// <param name="email">- email</param>
	/// <returns>если запись добавлена в бд вернется true иначе false</returns>
	static bool insertUser(QString login, QString password, QString email);
	/// <summary>
	/// Метод проверки на существование пользователя.
	/// </summary>
	/// <param name="login">- логин</param>
	/// <param name="password">- пароль</param>
	/// <returns>Если пользователь найдет, то вернет true иначе false</returns>
	static bool searchUser(QString login, QString password);
	/// <summary>
	/// Метод получения ID пользователя.
	/// </summary>
	/// <param name="login">- логин</param>
	/// <param name="password">- пароль</param>
	/// <returns>ID пользователя</returns>
	static int getUserID(QString login, QString password);
	/// <summary>
	/// Метод создания чата.
	/// </summary>
	/// <param name="userID">- ID создателя чата</param>
	/// <param name="name">- название чата</param>
	/// <param name="description">- описание чата</param>
	static void insertChat(int userID, QString name, QString description);
	/// <summary>
	/// Метод получения чатов пользователя.
	/// </summary>
	/// <param name="userID">- ID пользователя</param>
	/// <returns>QMap ключом является ID чата, значением его название</returns>
	static QMap<int, QString> selectUserChats(int userID);
	/// <summary>
	/// Метод выхода из чата.
	/// </summary>
	/// <param name="userID">- ID пользователя</param>
	/// <param name="chatID">- ID чата</param>
	static void leaveChat(int userID, int chatID);
	/// <summary>
	/// Метод добавления пользователя в чат
	/// </summary>
	/// <param name="userID">- ID пользователя</param>
	/// <param name="chatID">- ID чата</param>
	static void addUserChat(int userID, int chatID);
	/// <summary>
	/// Метод удаления чата.
	/// </summary>
	/// <param name="chatID">- ID чата</param>
	static void removeChat(int chatID);
	/// <summary>
	/// Метод добавления сообщения.
	/// </summary>
	/// <param name="userID">- ID отправителя</param>
	/// <param name="chatID">- ID чата назначения</param>
	/// <param name="text">- текст сообщения</param>
	static void insertMessage(int userID, int chatID, QString text);
	/// <summary>
	/// Метод получения сообщений чата
	/// </summary>
	/// <param name="chatID">- ID чата</param>
	/// <param name="limit">- максимально возращаемое количество записей</param>
	/// <returns>Возвращает строку со всеми сообщения содержащую отправителя, время и текст сообщения</returns>
	static QString selectMessages(int chatID, int limit = 50);
	/// <summary>
	/// Метод добавления приглашения.
	/// </summary>
	/// <param name="senderID">- ID отправителя</param>
	/// <param name="receiver">- логин приглашаемого</param>
	/// <param name="ChatID">- ID чата</param>
	static void insertInvite(int senderID, QString receiver, int ChatID);
	/// <summary>
	/// Метод получения приглашений определенного пользователя
	/// </summary>
	/// <param name="userID">- ID пользователя</param>
	/// <returns>Возвращает строку со всеми приглашениями, содержащую ID приглашения, ID отправителя и ID чата</returns>
	static QString selectInvite(int userID);
	/// <summary>
	/// Метод обновления статуса приглашения.
	/// </summary>
	/// <param name="inviteID">- ID приглашения</param>
	/// <param name="answer">- ответ в виде true или false</param>
	static void updateInvite(int inviteID, bool answer);
	/// <summary>
	/// Метод удаления пользователя из чата.
	/// </summary>
	/// <param name="userID">- ID Удаляемого пользователя</param>
	/// <param name="chatID">- ID чата из которого удаляется</param>
	static void removeUserChat(int userID, int chatID);
	/// <summary>
	/// Метод добавления жалобы
	/// </summary>
	/// <param name="userID">- ID пользователя, на которого пожаловались</param>
	/// <param name="text">- сообщение жалобы</param>
	static void insertReport(int userID, QString text);
	/// <summary>
	/// Метод получения всех доступных жалоб
	/// </summary>
	/// <returns>Возвращает строку со всеми жалобами, содержащие в себе ID жалобы, ID полььзователя, тест сообщения</returns>
	static QString selectReport();
};

#endif // DBWORKER_H

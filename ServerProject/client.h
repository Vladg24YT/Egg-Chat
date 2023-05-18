#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <string>
#include "DBWorker.h"

/// <summary>
/// Класс клиента, наследуется от QObject.
/// Содержит функционал парсера и взаимодействует с классом для использования базы данных.
/// </summary>
class Client : public QObject {
	Q_OBJECT
public:
	/// <summary>
	/// Конструктор класса Client. Принимает QTcpSocket для принятия подключения пользователя.
	/// </summary>
	/// <param name="socket">- класс QTcpSocket</param>
	/// <param name="parent">- опционально, указание родительского класса</param>
	explicit Client(QTcpSocket* socket, QObject* parent = nullptr);
	/// <summary>
	/// Деструктор класса Client.
	/// </summary>
	~Client();
	/// <summary>
	/// Экземпляр класса QTcpSocket, который является подключившимся клиентом.
	/// </summary>
	QTcpSocket* Socket;
	/// <summary>
	/// Метод получения ID пользователя.
	/// </summary>
	/// <returns>тип int</returns>
	int GetID();
	/// <summary>
	/// Метод получения дескриптора подключенного пользователя.
	/// </summary>
	/// <returns>тип int</returns>
	int GetDescriptor();
	/// <summary>
	/// Коллекция id чатов пользователя.
	/// </summary>
	QList<int> Chats;
	/// <summary>
	/// Метод отправка сообщения пользователя напрямую.
	/// </summary>
	/// <param name="text">- текст сообщения или команды</param>
	void Send(QString text);
public slots:
	/// <summary>
	/// Слот для считывания данных, отправленных пользователем.
	/// </summary>
	void Read();
	/// <summary>
	/// Слот, который обозначает что пользователь отключается и отправляет сигнал Close.
	/// </summary>
	void OnClosing();
signals:
	/// <summary>
	/// Сигнал для отправки сообщений.
	/// </summary>
	/// <param name="user">- никнейм пользователя</param>
	/// <param name="chatID">- ID чата, в который отправляется сообщение</param>
	/// <param name="text">- текст сообщения</param>
	void Message(QString user, int chatID, QString text);
	/// <summary>
	/// Сигнал, который указывает какой чат необходимо удалить у клиента.
	/// </summary>
	/// <param name="userID">- ID пользователя</param>
	/// <param name="command">- готовая комманда для удаления определенного чата</param>
	void Kick(int userID, QString command);
	/// <summary>
	/// Сигнал оповещающий что данного клиента необходимо удалить и отключить
	/// </summary>
	/// <param name="client">- клиент которого необходимо удалить</param>
	void Close(Client* client);
private:
	int id, descriptor;
	bool isAuth = false;
	void parser(QString line);
	void login(std::vector<QString>);
	void registration(std::vector<QString>);
	void logout();
	void getMessage(std::vector<QString> words);
	void sendMessage(std::vector<QString> words);
	void getChats();
	void createChat(std::vector<QString> words);
	void leaveChat(std::vector<QString> words);
	void removeChat(std::vector<QString> words);
	void sendInvite(std::vector<QString> words);
	void getInvite();
	void ansewerInvite(std::vector<QString> words);
	void kickUser(std::vector<QString> words);
	void sendReport(std::vector<QString> words);
	void getReport();
};
#endif // CLIENT_H

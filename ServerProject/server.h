#ifndef SERVER_H
#define SERVER_H

#include "client.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QMap>

/// <summary>
/// Класс сервера, наследуется от QObject. <br>
/// Реализует функционал прослушивания подключений, хранит подключенных пользователей и управляет ими.
/// </summary>
class Server : public QObject {
	Q_OBJECT
public:
	/// <summary>
	/// Конструктор класса, принимает QObject или ничего.
	/// </summary>
	/// <param name="parent"></param>
	explicit Server(QObject* parent = nullptr);
	/// <summary>
	/// Деструктор класса. Отключает все сокеты и закрывает соединение с базой данных.
	/// </summary>
	~Server();
public slots:
	/// <summary>
	/// Слот реализующий подключение клиента к серверу.
	/// Осуществляет подключение сигнало в слотам, а также добавляет нового клиента в QMap клиентов.
	/// </summary>
	void slotNewConnection();
	/// <summary>
	/// Слот отправляющий сообщение от определенного пользователя в конкретный чат.
	/// </summary>
	/// <param name="sender">- имя отправителя</param>
	/// <param name="chatID">- ID чата</param>
	/// <param name="message">- текст сообщения</param>
	void slotMessage(QString sender, int chatID, QString message);
	/// <summary>
	/// Слот для удаления пользователя из чата. Клиенту отправляется команда для удаления чата указанного в команде.
	/// </summary>
	/// <param name="userID"></param>
	/// <param name="command"></param>
	void slotKick(int userID, QString command);
	/// <summary>
	/// Слот отключения клиента от сервера. Закрывает сокет и удаляет клиента из QMap.
	/// </summary>
	/// <param name=""></param>
	void slotRemove(Client*);
private:
	QTcpServer* TcpServer;
	QMap<int, Client*> Clients;
};

#endif // SERVER_H
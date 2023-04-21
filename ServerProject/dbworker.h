#ifndef DBWORKER_H
#define DBWORKER_H

#include "models.h"
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

class DBWorker : public Singleton
{
private:
    DBWorker() = delete;
    DBWorker(const DBWorker&) = delete;
    static QSqlDatabase db;
    static void open();
public:
    static void createDB();
    static void close();

    // временный метод для проверки работоспособности
    static void selectFromDB();
    static bool insertUser(QString login, QString password, QString email);
    static bool searchUser(QString login, QString password);
    static int getUserID(QString login, QString password);
    static void insertChat(int userID, QString name, QString description);
    static QList<Chat*> selectUserChats(int userID);
    static void leaveChat(int userID, int chatID);
    static void removeChat(int chatID);
    static void insertMessage(int userID, int chatID, QString text);
    static QString selectMessages(int chatID);
    // методы обращения к бд (сделать отдельные модели или списки для данных, которые возращаются)
    // поиск пользователя по ID если нет вернуть false
    // получение чатов определенного пользователя
    // получение сообщений определенного чата
    // добавление пользователя
    // добавление сообщения в определенный чат
    // добавление чата

};



#endif // DBWORKER_H

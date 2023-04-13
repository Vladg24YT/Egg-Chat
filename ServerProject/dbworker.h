#ifndef DBWORKER_H
#define DBWORKER_H

#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
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
    static bool SearchUser(QString login, QString password);
    // методы обращения к бд (сделать отдельные модели или списки для данных, которые возращаются)
    // поиск пользователя по ID если нет вернуть false
    // получение чатов определенного пользователя
    // получение сообщений определенного чата
    // добавление пользователя
    // добавление сообщения в определенный чат
    // добавление чата

};



#endif // DBWORKER_H

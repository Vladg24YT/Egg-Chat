#ifndef DBWORKER_H
#define DBWORKER_H

#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "Singleton.h"
//переключение режима, для запуска на винде или в докере
#define DEBUG

class DBWorker : public Singleton
{
private:
    DBWorker() = delete;
    DBWorker(const DBWorker&) = delete;

    static QSqlDatabase db;

    static void open(){
        // чтобы заставить работать этот код, нужно изменить переменную ниже на путь к файлу "sqlite.db"
        QString path = "";
#ifdef DEBUG
        path = "C:/Users/rustv/Documents/QtProjects/Egg-Chat/bdWorker/";
        qDebug() << "def DEBUG";
#endif
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(path + "sqlite.db");
        if (!db.open()) qDebug() << db.lastError().text();
        qDebug() << "init";
    }
public:
    static void createDB(){
        getInstance();
        if (!db.isOpen()) open();
    }
    static void close(){
        if (db.isOpen()) db.close();
    }

    // временный метод для проверки работоспособности
    static void selectFromDB(){
        static QSqlQuery query = QSqlQuery(db);
        query.exec("select * from chats");
        try{
            while (query.next()){
                QSqlRecord rec = query.record();
                const int idIndex = rec.indexOf("id");
                const int loginIndex = rec.indexOf("name");
                qDebug() << query.value(idIndex).toString() + ' ' + query.value(loginIndex).toString();
            }}
        catch (...) {qDebug() << "Виу-виу! Код красный - код не робит!"; }
    }

    // методы обращения к бд (сделать отдельные модели или списки для данных, которые возращаются)
    // поиск пользователя по ID если нет вернуть false
    static void selectsingleuser(){
        static QSqlQuery query = QSqlQuery(db);
        query.exec("select * from users where id = 1");
        bool iftrue = false;
        try{
            while (query.next()){
                iftrue = true;
                QSqlRecord rec = query.record();
                const int idIndex = rec.indexOf("id");
                const int loginIndex = rec.indexOf("login");
                const int passIndex = rec.indexOf("password");
                const int nicknameIndex = rec.indexOf("nickname");
                qDebug() << query.value(idIndex).toString() + ' ' + query.value(loginIndex).toString();
            }}
        catch (...) {qDebug() << "Виу-виу! Код красный - код не робит!"; }
        return iftrue;
    }
    // получение чатов определенного пользователя
    static void selectuserschat(){
        static QSqlQuery query = QSqlQuery(db);
        query.exec("select chat_id from users_chats where user_id = 1");
        try{
            while (query.next()){
                QSqlRecord rec = query.record();
                const int idchatIndex = rec.indexOf("chat_id");
                const int useridIndex = rec.indexOf("user_id");
                qDebug() << query.value(idchatIndex).toString() + ' ' + query.value(useridIndex).toString();
            }}
        catch (...) {qDebug() << "Виу-виу! Код красный - код не робит!"; }
    }
    // получение сообщений определенного чата
    static void selectmessagesfromchat(){
        static QSqlQuery query = QSqlQuery(db);
        query.exec("select sender,msg,sendTime from messages where chat = 1 order by sendTime");
        try{
            while (query.next()){
                QSqlRecord rec = query.record();
                const int senderIndex = rec.indexOf("id");
                const int messageIndex = rec.indexOf("name");
                const int sendtimeIndex = rec.indexOf("sendTime");
                const int chatIndex = rec.indexOf("chat");
                qDebug() << query.value(senderIndex).toString() + ' ' + query.value(messageIndex).toString();
            }}
        catch (...) {qDebug() << "Виу-виу! Код красный - код не робит!"; }
    }
    //Все данные должны браться из заглушек
    // добавление пользователя
    static void insertuser(){
        static QSqlQuery query = QSqlQuery(db);
        query.prepare("insert into messages "
                          "VALUES (?, ?, ?,?)");
            query.addBindValue(1);
            query.addBindValue("qwerty");
            query.addBindValue("qwerty123");
            query.addBindValue("superkiller228");
            query.exec();

    }
    // добавление сообщения в определенный чат
    static void insertmsg(){
        static QSqlQuery query = QSqlQuery(db);
        query.prepare("insert into messages "
                          "VALUES (?, ?, ?,?)");
            query.addBindValue(1);
            query.addBindValue(1);
            query.addBindValue("halal");
            query.addBindValue("NOW()");
            query.exec();

    }
    // добавление чата
    static void insertchats(){
        static QSqlQuery query = QSqlQuery(db);
        query.prepare("insert into chats "
                          "VALUES (?, ?, ?,?)");
            query.addBindValue(1);
            query.addBindValue(1);
            query.addBindValue("test1");
            query.addBindValue("testing");
            query.exec();

    }
    //добавление инвайтов
    static void insertinvites(){
        static QSqlQuery query = QSqlQuery(db);
        query.prepare("insert into invites "
                          "VALUES (?, ?, ?, ?)");
            query.addBindValue(1);
            query.addBindValue(1);
            query.addBindValue(1);
            query.addBindValue(true);
            query.exec();

    }

};



#endif // DBWORKER_H

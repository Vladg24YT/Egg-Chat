#ifndef DBWORKER_H
#define DBWORKER_H

#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "Singleton.h"

class DBWorker : public Singleton
{
private:
    DBWorker() = delete;
    DBWorker(const DBWorker&) = delete;

    static QSqlDatabase db;

    static void open(){
        // чтобы заставить работать этот код, нужно изменить переменную ниже на путь к файлу "sqlite.db"
        QString path = "C:/Users/mayor/Downloads/";
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(path + "sqlite.db");
        if (!db.open()) qDebug() << db.lastError().text();
    }
public:
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
    static void createDB(){
        Singleton::getInstance();
        if (!db.isOpen()) open();
    }
    static void close(){
        if (db.isOpen()) db.close();
    }

};

QSqlDatabase DBWorker::db;

#endif // DBWORKER_H
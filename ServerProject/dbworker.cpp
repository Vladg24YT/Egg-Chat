#include "dbworker.h"

void DBWorker::open(){
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

void DBWorker::createDB(){
    getInstance();
    if (!db.isOpen()) open();
}
void DBWorker::close(){
     if (db.isOpen()) db.close();
}

void DBWorker::selectFromDB(){
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

QSqlDatabase DBWorker::db;

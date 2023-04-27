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
//#define DEBUG

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

    static bool insertUser(QString login, QString password, QString email);
    static bool searchUser(QString login, QString password);
    static int getUserID(QString login, QString password);
    static void insertChat(int userID, QString name, QString description);
    static QMap<int, QString> selectUserChats(int userID);
    static void leaveChat(int userID, int chatID);
    static void addUserChat(int userID, int chatID);
    static void removeChat(int chatID);
    static void insertMessage(int userID, int chatID, QString text);
    static QString selectMessages(int chatID);
    static void insertInvite(int senderID, int receiverID, int ChatID);
    static QString selectInvite(int userID);
    static void updateInvite(int inviteID, bool answer);
    static void removeUserChat(int userID, int chatID);
    static void insertReport(int userID, QString text);
    static QString selectReport();
};



#endif // DBWORKER_H

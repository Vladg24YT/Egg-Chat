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

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
public slots:
    void slotNewConnection();
//    void slotSend(QByteArray);
    void slotMessage(int senderID, int chatID, QString message);
    void slotKick(int, QString);
    void slotRemove(Client*);
private:
    QTcpServer * TcpServer;
    QMap<int, Client*> Clients;
};

#endif // SERVER_H

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
    void slotMessage(QString, QString);
    void slotRemove(Client*);
private:
    QTcpServer * TcpServer;
    //QList<Client*> Clients;
    QMap<int, Client*> Clients;
    int serverStatus;
};

#endif // SERVER_H

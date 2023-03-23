#ifndef SERVER_H
#define SERVER_H

#include "client.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
public slots:
    void slotNewConnection();
    void slotMessage(QByteArray);
    void slotRemove(Client*);
private:
    QTcpServer * TcpServer;
    QList<Client*> Clients;
    int serverStatus;
};

#endif // SERVER_H
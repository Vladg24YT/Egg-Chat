#ifndef SERVER_H
#define SERVER_H

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
    void slotCloseClientConnection();
    void slotRead();
private:
    QTcpServer * TcpServer;
    QTcpSocket * TcpSocket;
    int serverStatus;
};

#endif // SERVER_H

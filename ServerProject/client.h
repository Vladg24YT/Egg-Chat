#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr, QTcpSocket *socket = nullptr);
    ~Client();
    QTcpSocket *Socket;
    int Id;
public slots:
    void Read();
    void OnClosing();
signals:
    void Send(QByteArray);
    void Close(Client*);
private:

};

#endif // CLIENT_H

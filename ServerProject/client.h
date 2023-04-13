#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <string>
#include <DBWorker.h>


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr, QTcpSocket *socket = nullptr);
    ~Client();
    QTcpSocket *Socket;
public slots:
    void Read();
    void OnClosing();
signals:
    void Message(QString chatID, QString text);
    void Close(Client*);
private:
    bool isAuth = false;
    void parser(std::string line);
    void commandRecognizer(std::vector<std::string> words);
    bool auth(QString login, QString password);
    bool registration(QString login, QString password);
    void send(QString text);
};
#endif // CLIENT_H

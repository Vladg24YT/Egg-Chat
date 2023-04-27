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
    int GetID();
    QList<int> Chats;
    void Send(QString text);
public slots:
    void Read();
    void OnClosing();
signals:
    void Message(int userID, int chatID, QString text);
    void Kick(int userID, QString command);
    void Close(Client*);
private:
    int id;
    bool isAuth = false;
    ///
    /// \brief parser
    /// \param line
    ///
    void parser(QString line);
    /// Авторизация пользователя
    /// \brief auth
    /// \param login
    /// \param password
    /// \return true если пользователь найден, иначе false
    ///
    void login(std::vector<QString>);
    /// Регистрация пользователя
    /// \brief registration
    /// \param login
    /// \param password
    /// \return true если удалось зарегестрироваться, иначе false
    ///
    void registration(std::vector<QString>);
    /// Метод выхода из учетной записи
    /// \brief logout
    ///
    void logout();
    /// <summary>
    /// 
    /// </summary>
    /// <param name="words"></param>
    void getMessage(std::vector<QString> words);
    void sendMessage(std::vector<QString> words);
    void getChats();
    void createChat(std::vector<QString> words);
    void leaveChat(std::vector<QString> words);
    void removeChat(std::vector<QString> words);
    void sendInvite(std::vector<QString> words);
    void getInvite(std::vector<QString> words);
    void ansewerInvite(std::vector<QString> words);
    void kickUser(std::vector<QString> words);
    void sendReport(std::vector<QString> words);
    void getReport();


};
#endif // CLIENT_H

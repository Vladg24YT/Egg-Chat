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
    static int num;
public slots:
    void Read();
    void OnClosing();
signals:
    void Message(QString chatID, QString text);
    void Close(Client*);
private:
    int id;
    bool isAuth = false;
    inline void send(QString text);
    ///
    /// \brief parser
    /// \param line
    ///
    inline void parser(QString line);
    /// Авторизация пользователя
    /// \brief auth
    /// \param login
    /// \param password
    /// \return true если пользователь найден, иначе false
    ///
    inline void login(std::vector<QString>);
    /// Регистрация пользователя
    /// \brief registration
    /// \param login
    /// \param password
    /// \return true если удалось зарегестрироваться, иначе false
    ///
    inline void registration(std::vector<QString>);
    /// Метод выхода из учетной записи
    /// \brief logout
    ///
    inline void logout();
    inline void getMessage(std::vector<QString> words);
    inline void getChats();
    inline void createChat(std::vector<QString> words);
    inline void leaveChat(std::vector<QString> words);
    inline void removeChat(std::vector<QString> words);
    inline void kickUser(int userID, int chatID);
    inline void createInvite(int userID);
    inline void ansewerInvite(int inviteID, bool answer);
    inline void report(int userID, QString text);

};
#endif // CLIENT_H

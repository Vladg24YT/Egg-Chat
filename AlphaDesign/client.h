#ifndef CLIENT_H
#define CLIENT_H

#include <QString>

class client
{
public:
    QString lgn;
    QString email;
    QString pwd;
    QString nick;
    client();
    client(QString lgn, QString email, QString pwd, QString nick);

    QString getLogin();
    QString getEmail();
    QString getPass();
    QString getNick();
    bool compPassword(QString cPass);
    QString toString();

};

#endif // CLIENT_H

#include "client.h"

client::client()
{

}

client::client(QString lgn, QString email, QString pwd, QString nick)
{
    this->lgn = lgn;
    this->email = email;
    this->pwd = pwd;
    this->nick = nick;
}

QString client::getLogin()
{
    return this->lgn;
}

QString client::getEmail()
{
    return this->email;
}

QString client::getPass()
{
    return this->pwd;
}

QString client::getNick()
{
    return this->nick;
}

bool client::compPassword(QString cPass)
{
    return this->pwd == cPass;
}

QString client::toString()
{
    return this->lgn + "|" + this->pwd + "|" + this->email + "|" + this->lgn;
}

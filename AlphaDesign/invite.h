#ifndef INVITE_H
#define INVITE_H

#include <QString>

class invite
{
private:
    QString chatName;
    QString chatID;
    QString inviterName;
    QString ID;
public:
    invite();
    invite(QString invID, QString chat, QString chat_id, QString inviter);
    QString getID();
    QString toString();
    QString answer(bool answer); // true - accept, false - decline
};

#endif // INVITE_H

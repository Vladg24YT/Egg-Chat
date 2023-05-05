#include "invite.h"

invite::invite(){}

invite::invite(QString invID, QString chat, QString chat_id, QString inviter)
{
    this->ID = invID;
    this->chatName = chat;
    this->chatID = chat_id;
    this->inviterName = inviter;
}

QString invite::toString()
{
    QString str;
    str = "Приглашение в чат \"" + chatName + "\" от " + inviterName;
    return str;
}

QString invite::answer(bool answer)
{
    QString str;
    QString ans = answer ? "1" : "0";
    // пока так, ибо не помню какой должен быть ответ
    str = "invite|answer|" + ID + "|" + ans;
    return str;
}

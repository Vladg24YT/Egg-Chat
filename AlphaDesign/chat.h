#ifndef CHAT_H
#define CHAT_H

#include <QString>
#include <vector>

struct message
{
    QString sender;
    QString text;
    QString time;

    message(QString snd, QString txt, QString tm){
        this->sender = snd;
        this->text = txt;
        this->time = tm;
    }

    QString show(){
        return "[" + sender + "] " + text + "\n (" + time + ")";
    }
};

class chat
{
private:
    int chat_id;
    int ureadMessages = 0;
public:
    void addMessage(message nm);
    int messagesCount;
    std::vector<message> msgs;

    chat();
    chat(int chat_id);
    //~chat();
};

#endif // CHAT_H

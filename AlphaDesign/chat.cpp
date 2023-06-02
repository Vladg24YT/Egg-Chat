#include "chat.h"

void chat::addMessage(message nm)
{
    this->msgs.push_back(nm);
    messagesCount++;
}

chat::chat()
{

}

chat::chat(int chatId)
{
    this->chat_id = chatId;
}

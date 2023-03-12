#include <iostream>

// функции пустышки
void signInAdmin(std::string name, std::string password){
    std::cout << "Admin login as " << name << ":" << password << "\n";
}
void signInUser(std::string name, std::string password){
    std::cout << "User login as " << name << ":" << password << "\n";
}
void registration(std::string name, std::string password){
    std::cout << "New user registered with " << name << ":" << password << "\n";
}
void sendMessage(std::string chatID, std::string text){
    std::cout << "User sent message \"" << text << "\" to chat " << chatID <<"\n";
}

void newChat(std::string chatName){
    std::cout << "User created chat \"" << chatName << "\"\n";
}

void removeChat(std::string chatID){
    std::cout << "User deleted chat with ID = \"" << chatID << "\"\n";
}

void leaveChat(std::string chatID){
    std::cout << "User left chat with ID = \"" << chatID << "\"\n";
}

void inviteUserToChat(std::string userID, std::string chatID){
    std::cout << "You invited userID = " << userID << " to chatID = " << chatID << "\n";
}

void answerInvite(std::string answer, std::string chatID){
    std::cout << "You ";
    if (answer == "1")
        std::cout << "accepted ";
    else
        std::cout << "denied ";
    std::cout << "the invite to chatID = " << chatID << "\n";
}

void kickUserFromChat(std::string userID, std::string chatID){
    std::cout << "userID = " << userID << " was kicked from chatID = " << chatID << "\n";
}

void banUser(std::string userID, std::string reason){
    std::cout  << "userID = " << userID << " was banned. Reason: " << reason << "\n";
}

void unbanUser(std::string userID){
    std::cout << "userID = " << userID << " was unbanned.\n";
}

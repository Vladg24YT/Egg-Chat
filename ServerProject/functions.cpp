#include "functions.h"
#include <string>
#include <iostream>

// функции пустышки
std::string signInAdmin(std::string name, std::string password){
    std::string out = "Admin login as " + name  + ":" + password;
    return out;
}
std::string signInUser(std::string name, std::string password){
    std::string out = "User login as " + name + ":" + password;
    return out;
}

std::string logout(){
    return "User logged out";
}

std::string registration(std::string name, std::string password){
    std::string out = "New user registered with " + name + ":" + password;
    return out;
}
std::string sendMessage(std::string chatID, std::string text){
    //std::string out = "User sent message \"" + text + "\" to chat " + chatID;
    // временно передалал для отправки сообщения одному пользователю (chatID = userID получаетеля)
    std::string out = text + " " + chatID;
    return out;
}

std::string newChat(std::string chatName){
    std::string out = "User created chat \"" + chatName + "\"";
    return out;
}

std::string removeChat(std::string chatID){
    std::string out = "User deleted chat with ID = \"" + chatID + "\"";
    return out;
}

std::string leaveChat(std::string chatID){
    std::string out = "User left chat with ID = \"" + chatID + "\"";
    return out;
}

std::string inviteUserToChat(std::string userID, std::string chatID){
    std::string out = "You invited userID = " + userID + " to chatID = " + chatID;
    return out;
}

std::string answerInvite(std::string answer, std::string chatID){
    std::string out = "You ";
    if (answer == "1")
        out += "accepted ";
    else
        out +=  "denied ";
    out +=  "the invite to chatID = " + chatID;
    return out;
}

std::string kickUserFromChat(std::string userID, std::string chatID){
    std::string out = "userID = " + userID + " was kicked from chatID = " + chatID;
    return out;
}

std::string sendReport(std::string userID, std::string reason){
    std::string out = "userID = " + userID + " was reported for " + reason;
    return out;
}

std::string banUser(std::string userID, std::string reason){
    std::string out = "userID = " + userID + " was banned. Reason: " + reason;
    return out;
}

std::string unbanUser(std::string userID){
    std::string out = "userID = " + userID + " was unbanned.";
    return out;
}


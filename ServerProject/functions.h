#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

std::string signInAdmin(std::string name, std::string password);
std::string signInUser(std::string name, std::string password);
std::string logout();
std::string registration(std::string name, std::string password);
std::string sendMessage(std::string chatID, std::string text);
std::string newChat(std::string chatName);
std::string removeChat(std::string chatID);
std::string leaveChat(std::string chatID);
std::string inviteUserToChat(std::string userID, std::string chatID);
std::string answerInvite(std::string answer, std::string chatID);
std::string kickUserFromChat(std::string userID, std::string chatID);
std::string sendReport(std::string userID, std::string reason);
// админские функции
std::string banUser(std::string userID, std::string reason);
std::string unbanUser(std::string userID);
#endif // FUNCTIONS_H

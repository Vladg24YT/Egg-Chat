void signInAdmin(std::string name, std::string password);
void signInUser(std::string name, std::string password);
void registration(std::string name, std::string password);
void sendMessage(std::string chatID, std::string text);
void newChat(std::string chatName);
void removeChat(std::string chatID);
void leaveChat(std::string chatID);
void inviteUserToChat(std::string userID, std::string chatID);
void answerInvite(std::string answer, std::string chatID);
void kickUserFromChat(std::string userID, std::string chatID);
// админские функции
void banUser(std::string userID, std::string reason);
void unbanUser(std::string userID);
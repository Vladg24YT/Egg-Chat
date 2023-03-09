#include <iostream>

// функции пустышки
void signInAdmin(std::string name, std::string password){
    std::cout << "Admin logines with " << name << ":" << password << "\n";
}
void signInUser(std::string name, std::string password){
    std::cout << "User logines with " << name << ":" << password << "\n";
}
void registration(std::string name, std::string password){
    std::cout << "New user registred with " << name << ":" << password << "\n";
}
void sendMessage(std::string text){
    std::cout << "User sent message \"" << text << "\"\n";
}
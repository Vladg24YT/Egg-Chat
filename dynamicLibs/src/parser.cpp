#include <string>
#include <iostream>
#include <vector>

/* Структура команд
1) логин админа: /la<name>:<password>
2) логин юзера: /lu<name>:<password>
3) регистрация: /rg<name>:<password>
4) отправка сообщения: /me<message>

Двоеточие - разделитель между аргументами
Все коды комманд в ДВА символа

Сделано из расчёта, что эти команды отправляет
не пользователь, а клиент пользователя.
*/

void commandRecognizer(std::vector<std::string> words);
void signInAdmin(std::string name, std::string password);
void signInUser(std::string name, std::string password);
void registration(std::string name, std::string password);
void sendMessage(std::string text);

void parser(std::string line){
    /*
        Эта функция делит входящую команду
        на комнаду и агрументы
    */
   // проверяем что получили именно команду
   if (line[0] != '/'){
    std::cout << "This is not a command!\n";
    return;
    }

    // вектор для хранения слов строки
    // 0-й элемент - команда
    std::vector<std::string> words;
    
    // вычленяем команду
    words.push_back(line.substr(1, 2));

    std::string tmp = "";

    for (int i = 3; i < line.size(); i++){
        if (line[i] == ':'){
            words.push_back(tmp);
            tmp = "";
        }
        else
            tmp = tmp + line[i];
    }  
    words.push_back(tmp);
    commandRecognizer(words);
}

void commandRecognizer(std::vector<std::string> words){
    /*
        Определяет какую команду получил на
        вход и кому её дальше отправлять
    */

    // к сожалению только лесенкой условий(
    std::cout << words.size() << "\n";
    if (words[0] == "la")
        if (words.size() == 3)
            signInAdmin(words[1], words[2]);
        else
            std::cout << "Wrong data set!\n";
    else if (words[0] == "lu")
        if (words.size() == 3)
                signInUser(words[1], words[2]);
            else
                std::cout << "Wrong data set!\n";
    else if (words[0] == "rg")
        if (words.size() == 3)
                registration(words[1], words[2]);
            else
                std::cout << "Wrong data set!\n";
    else if (words[0] == "me")
        if (words.size() == 2)
                sendMessage(words[1]);
            else
                std::cout << "No message found!\n";
    else
        std::cout << "No such command!\n";
    return;
}


int main(){
    std::string cmd = "";
    while (true){
        std::getline(std::cin, cmd);
        parser(cmd);
    }
    return 0;
}

// функции пустышки
/*
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
}*/
#include <string>
#include <iostream>
#include <vector>
#include "functions.h"


/* Структура команд
1) логин админа: /la<name>:<password> +
2) логин юзера: /lu<name>:<password> +
3) регистрация: /rg<name>:<password> +
4) отправка сообщения: /me<chatID>:<message> +
5) создать чат: /nc<chat_name> +
6) удалить чат: /rc<chatID> +
7) выйти из чата: /lc<chatID>  +
8) пригласить в чат: /iu<userID>:<chatID> +
9) ответ на приглашение в чат: /ai<answer>:<chatID> 0 - deny, 1 - accept +
10) исключить пользователя из чата: /ku<userID>:<chatID> +
--  Для админов 
11) бан пользователя на совсем: /bn<userID>:<reason> +
12) разбанить пользователя: /ub<userID> +

Двоеточие - разделитель между аргументами
Все коды комманд в ДВА символа

Сделано из расчёта, что эти команды отправляет
не пользователь, а клиент пользователя.
*/

void parser(std::string line);
void commandRecognizer(std::vector<std::string> words);


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
    if (words[0] == "la") // логин админа
        if (words.size() == 3)
            signInAdmin(words[1], words[2]);
        else
            std::cout << "Wrong data set!\n";
    else if (words[0] == "lu") // логин пользователя
        if (words.size() == 3)
                signInUser(words[1], words[2]);
            else
                std::cout << "Wrong data set!\n";
    else if (words[0] == "rg") // регистрация
        if (words.size() == 3)
                registration(words[1], words[2]);
            else
                std::cout << "Wrong data set!\n";
    else if (words[0] == "me") // отправка сообщения
        if (words.size() == 3 && words[1] != "" && words[2] != "")
                sendMessage(words[1], words[2]);
            else
                std::cout << "No message found!\n";
    else if (words[0] == "nc")
        if (words.size() == 2 && words[1] != "")
            newChat(words[1]);
        else
            std::cout << "No chat name provided!\n";
    else if (words[0] == "rc")
        if (words.size() == 2 && words[1] != "")
            removeChat(words[1]);
        else
            std::cout << "No chatID provided!\n";
    else if (words[0] == "lc")
        if (words.size() == 2 && words[1] != "")
            leaveChat(words[1]);
        else
            std::cout << "No chatID provided!\n";
    else if (words[0] == "iu")
        if (words.size() == 3 && words[1] != "" && words[2] != "")
            inviteUserToChat(words[1], words[2]);
        else
            std::cout << "Wrong data set!\n";
    else if (words[0] == "ai")
        if (words.size() == 3 && (words[1] == "0" || words[1] == "1") && words[2] != "")
            answerInvite(words[1], words[2]);
        else
            std::cout << "Wrong data set!\n";
    else if (words[0] == "ku")
        if (words.size() == 3 && words[1] != "" && words[2] != "")
            kickUserFromChat(words[1], words[2]);
        else
            std::cout << "Wrong data set!\n";
    else if (words[0] == "bn")
        if (words.size() == 3 && words[1] != "" && words[2] != "")
            banUser(words[1], words[2]);
        else
            std::cout << "Wrong data set!\n";
    else if (words[0] == "ub")
        if (words.size() == 2 && words[1] != "")
            unbanUser(words[1]);
        else
            std::cout << "No userID provided!\n";
    else
        std::cout << "No such command!\n";
    return;
}


int main(){
    // цикл while ТОЛЬКО НА ТЕСТ!
    // перед добавлением на сервер УБРАТЬ!!!!
    std::string cmd = "";
    while (true){
        std::cout << "Enter a command:\n";
        std::getline(std::cin, cmd);
        parser(cmd);
    }
    return 0;
}

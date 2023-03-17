#include "parser.h"
#include "functions.h"

#include <string>
#include <vector>
std::string parser(std::string line);
std::string commandRecognizer(std::vector<std::string> words);

std::string parser(std::string line) {
    /*
        Эта функция делит входящую команду
        на комнаду и агрументы
    */

   // проверяем что получили именно команду
   if (line[0] != '/')
        return "This is not a command!\n";
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
    return commandRecognizer(words);
}

std::string commandRecognizer(std::vector<std::string> words){
    /*
        Определяет какую команду получил на
        вход и кому её дальше отправлять
    */

    // к сожалению только лесенкой условий(
    if (words[0] == "la") // логин админа
        if (words.size() == 3)
            return signInAdmin(words[1], words[2]);
        else
            return "Wrong data set!\n";
    else if (words[0] == "lu") // логин пользователя
        if (words.size() == 3)
                return signInUser(words[1], words[2]);
            else
                return "Wrong data set!\n";
    else if (words[0] == "lo") // выход из учётки)
        if (words.size() == 2)
            return logout();
        else
            return "No arguments expected!\n";
    else if (words[0] == "rg") // регистрация
        if (words.size() == 3)
                return registration(words[1], words[2]);
            else
                return "Wrong data set!\n";
    else if (words[0] == "me") // отправка сообщения
        if (words.size() == 3 && words[1] != "" && words[2] != "")
                return sendMessage(words[1], words[2]);
            else
                return "No message found!\n";
    else if (words[0] == "nc")
        if (words.size() == 2 && words[1] != "")
            return newChat(words[1]);
        else
            return "No chat name provided!\n";
    else if (words[0] == "rc")
        if (words.size() == 2 && words[1] != "")
            return removeChat(words[1]);
        else
            return "No chatID provided!\n";
    else if (words[0] == "lc")
        if (words.size() == 2 && words[1] != "")
            return leaveChat(words[1]);
        else
            return "No chatID provided!\n";
    else if (words[0] == "iu")
        if (words.size() == 3 && words[1] != "" && words[2] != "")
            return inviteUserToChat(words[1], words[2]);
        else
            return "Wrong data set!\n";
    else if (words[0] == "ai")
        if (words.size() == 3 && (words[1] == "0" || words[1] == "1") && words[2] != "")
            return answerInvite(words[1], words[2]);
        else
            return "Wrong data set!\n";
    else if (words[0] == "ku")
        if (words.size() == 3 && words[1] != "" && words[2] != "")
            return kickUserFromChat(words[1], words[2]);
        else
            return "Wrong data set!\n";
    else if (words[0] == "sr") // подать жалобу
        if (words.size() == 3 && words[1] != "" && words[2] != "")
            return sendReport(words[1], words[2]);
        else
            return "Wrong data set!\n";
    // команды админа
    else if (words[0] == "bn")
        if (words.size() == 3 && words[1] != "" && words[2] != "")
            return banUser(words[1], words[2]);
        else
            return "Wrong data set!\n";
    else if (words[0] == "ub")
        if (words.size() == 2 && words[1] != "")
            return unbanUser(words[1]);
        else
            return "No userID provided!\n";
    else
        return "No such command!\n";
    return "No such command!\n";
}

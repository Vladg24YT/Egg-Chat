#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

class Parser
{
public:
    Parser();
    static std::string parser(std::string line);
    static std::string commandRecognizer(std::vector<std::string> words);
};

#endif // PARSER_H

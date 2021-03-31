#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include "command.hpp"
#include "braceguard2.hpp"

bool readFileToStringList(const std::string &filename, std::vector<std::string> &content)
{
    std::ifstream input(filename.c_str());
    std::string linestr;
    if (!input)
        return false;
    while (std::getline(input, linestr))
    {
        if (linestr.size() > 0)
            content.push_back(linestr);
    }
    input.close();
    return true;
}

int main()
{
    std::vector<std::string> List;
    std::vector<Command> CommandList;
    BraceGuard2 BG('{', '}');
    readFileToStringList("words.txt", List);

    bool Analizuj = false;
    bool Start = true;
    bool DescR = false;

    for (auto it = List.begin(); it != List.end(); it++)
    {
        if ((it->find("if") != std::string::npos) && (!Analizuj))
        {
            CommandList.push_back(Command{it->substr(it->find("Header(")+7, (it->find(")")-(it->find("Header(")+7)))});
            Analizuj = true;
        }

        if (Analizuj && (!DescR))
        {
            (CommandList.end() - 1)->Body.push_back(*it);
            if ((it->find("{") == std::string::npos) && (Start))
            {
                Start = false;
                continue;
            };
            if (BG.Analize(*it))
            {
                std::cout << "Skladnia domknięta" << std::endl;
                Analizuj = false;
                Start = true;
                BG.reset();
            }
            else
            {
                std::cout << "Składnia otwarta" << std::endl;
                continue;
            };
        };
        if ((it->find("/* DESCRIPTION:") != std::string::npos))
        {
            DescR = true;
        };
        if (DescR)
            (CommandList.end() - 1)->Description.push_back(*it);
        if ((it->find("END */") != std::string::npos))
        {
            DescR = false;
        };
    };

    for (auto &cmd : CommandList)
    {
        std::cout << "---------------------"<< std::endl;
        std::cout << cmd.ExecuteText << std::endl;
        for (auto &bodyline : cmd.Body)
            std::cout << bodyline << std::endl;
        for (auto &descline : cmd.Description)
            std::cout << descline << std::endl;
            std::cout << "---------------------"<< std::endl;
    };
};
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include "quizer.hpp"


int main()
{
   quizer Quiz;
    Quiz.loadFile("questions");
    for (auto &cmd : Quiz.getQuestionList())
    {

        std::cout << "---------------------" << std::endl;
        std::cout << cmd.Content << std::endl;
        for (auto &bodyline : cmd.Answers)
            std::cout << bodyline << std::endl;
        for (auto &descline : cmd.Description)
            std::cout << descline << std::endl;
        std::cout << "---------------------" << std::endl;
    };

 
}
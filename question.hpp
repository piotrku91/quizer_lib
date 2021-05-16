#pragma once
#include <string>
#include <fstream>
#include <vector>

class Question
{
private:
    int m_CorrectId;

public:
    std::string Content;
    std::vector<std::string> Answers;
    std::vector<std::string> Description;

    const int &getCorrectId() { return m_CorrectId; };
    void setCorrectId(const int &newId) { m_CorrectId = newId; };

    Question(const std::string &ET) : m_CorrectId(0), Content(ET) {};
};

#pragma once

#include "question.hpp"
#include <vector>
#include "braceguard.cpp"

class quizer
{
private:
    std::vector<std::string> fileContent;
    std::vector<Question> QuestionList;
    std::vector<Question>::iterator Actual;
    braceguard BG;
    bool m_Analize = false;
    bool m_Start = true;
    bool m_DescR = false;

    bool checkAnswer(Question &Q, int &Try);
    void reload();

public:

    bool loadFile(const std::string &filename);
    std::vector<Question> getQuestionList() const {return QuestionList;};
    inline size_t questionCount() const {return QuestionList.size();};
    inline size_t getQuestionNumber() const {return Actual-QuestionList.begin();};
    Question getActualQuestion(){return *Actual;};
    void nextQuestion() { if (Actual!=QuestionList.end()) std::next(Actual); };
    void lastQuestion() { if (Actual!=QuestionList.begin()) std::prev(Actual); };
    
};
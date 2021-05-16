#include "quizer.hpp"

bool quizer::checkAnswer(Question &Q, int &Try)
{
    return (Try == Q.getCorrectId());
}

bool quizer::loadFile(const std::string &filename)
{
    
    std::ifstream input(filename.c_str());
    std::string linestr;
    if (!input)
        return false;
    while (std::getline(input, linestr))
    {
        if (linestr.size() > 0)
            fileContent.push_back(linestr);
    }
    input.close();
    reload();
    return true;
}

void quizer::reload()
{
    for (auto it = fileContent.begin(); it != fileContent.end(); it++)
    {
        if ((it->find("question") != std::string::npos) && (!m_Analize))
        {
            QuestionList.push_back(Question{it->substr(it->find("<$$ \"") + 5, (it->find("\" $$>") - (it->find("<$$ \"") + 5)))});
            m_Analize = true;
        }

        if (m_Analize && (!m_DescR))
        {
            if ((it->find("$$ Answer: \"") != (std::string::npos)))
            {
                (QuestionList.end() - 1)->Answers.push_back(it->substr(it->find(": \"") + 3, it->find("\"$") - it->find(": \"") - 3));
            };
            if ((it->find("$$ Correct: \"") != (std::string::npos)))
            {
                (QuestionList.end() - 1)->setCorrectId(std::stoi(it->substr(it->find(": \"") + 3, it->find("\"$") - it->find(": \"") - 3)));
            };
            if ((it->find("{") == std::string::npos) && (m_Start))
            {
                m_Start = false;
                continue;
            };
            if (BG.Analizer(*it))
            {
                // brackets closed
                m_Analize = false;
                m_Start = true;
                BG.reset();
            }
            else
            {
                // brackets open
                continue;
            };
        };
        if ((it->find("/* DESCRIPTION:") != std::string::npos))
        {
            m_DescR = true;
            continue;
        };

        if ((it->find("END */") != std::string::npos))
        {
            m_DescR = false;
            continue;
        };
        if (m_DescR)
            (QuestionList.end() - 1)->Description.push_back(*it);
    };
    Actual=QuestionList.begin();
}
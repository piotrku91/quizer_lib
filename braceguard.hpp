#pragma once
#include <string>
#include <stack>

class braceguard
{
private:
    char m_OpenStr;
    char m_CloseStr;

public:
    std::stack<char> S;
    bool Analizer(const std::string& lines)
    {

        for (auto it = lines.begin(); it != lines.end(); it++)
        {
            if (static_cast<char>(*it) == m_OpenStr)
            {
                S.push(*it);
            }
            else if (static_cast<char>(*it) == m_CloseStr)
            {
                if ((S.empty()) || (S.top() == *it))
                {
                    return false;
                }
                else
                {
                    S.pop();
                };
            };
        };

        return (S.empty() ? true : false);
    }

    void reset()
    {
        while (!S.empty()) {S.pop();};
    };


    braceguard() : m_OpenStr{'{'}, m_CloseStr{'}'}{};
    ~braceguard(){};
};
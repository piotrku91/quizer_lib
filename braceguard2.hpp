#pragma once
#include <string>
#include <iostream>
#include "stacky.hpp"

class BraceGuard2
{
private:
char m_OpenStr;
char m_CloseStr;



public:
stacky<char> S;

void reset()
{S.clear();};

bool Analize(std::string line)
{

for (auto it=line.begin();it!=line.end();it++)
{
    if (*it==m_OpenStr) { S.push(*it);}
    else if (*it==m_CloseStr)
    {
        if ((S.isEmpty()) || (S.top()==*it))
        {
            return false;
        }

    else {S.pop();};
    };

};

return (S.isEmpty()? true:false);
};

BraceGuard2(const char& openstring, const char& closestring):m_OpenStr(openstring),m_CloseStr(closestring) {};

};
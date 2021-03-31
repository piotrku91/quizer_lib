#include <string>

class BraceGuard
{
private:
int m_Count_left;
int m_Count_right;
std::string m_OpenStr;
std::string m_CloseStr;

void openB() 
{
m_Count_left++;
};

void closeB()
{
m_Count_right++;
};

public:
int getCount() const
{
  return m_Count_right-m_Count_left;
};

bool isSymetric()
{
return m_Count_right==m_Count_left;
};

void Analize(std::string line)
{

int pos=line.find(m_OpenStr);

while (pos!=std::string::npos)
{
openB();
pos=line.find(m_OpenStr,pos+1);
};

pos=line.find(m_CloseStr);

while (pos!=std::string::npos)
{

closeB();
pos=line.find(m_CloseStr,pos+1);
};

};

void reset() 
{
m_Count_left=0;
m_Count_right=0;
};

BraceGuard(const std::string& openstring, const std::string& closestring):m_OpenStr{openstring},m_CloseStr{closestring} {reset();};

};
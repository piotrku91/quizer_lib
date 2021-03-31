#include <string>
#include <fstream>
#include <vector>

class Command
{
public:
std::string ExecuteText;
std::vector<std::string> Body;
std::vector<std::string> Description;

bool Integrity;
int Group;

Command(const std::string&& ET, int Gr=0): ExecuteText(std::move(ET)) {};
};



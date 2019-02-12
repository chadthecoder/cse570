#include <fstream>
#include <string>
#include <iostream>
#include <vector>

bool isTerminal(std::string s, std::vector<std::string>terminals)
{
    for(int i=0; i<terminals.size(); i++)
    {
        if(terminals[i] == s)
        {
            return true;
        }
    }
    return false;
}

std::string getFirstSet(std::string sI, std::vector<std::string>terminals)
{
    std::string sO = "";
    for(int i=0; i<sI.length(); i++)
    {
        if(sI.substr(i, 2) == "->")
        {
            if(isTerminal(sI.substr(i+2, 1), terminals) || sI.substr(i+2, 1) == "e") sO += sI.substr(i+2, 1); 
        }
        if(sI.substr(i, 1) == "|") 
        {
            if(isTerminal(sI.substr(i+1, 1), terminals) || sI.substr(i+2, 1) == "e") sO += sI.substr(i+1, 1);
        }
    }
    return sO;
}

int main () {
  std::string line;
  std::ifstream inGram("g417.in");
  std::ofstream outGram("sets_g417.out");
  int lineNum = 1;
  int terminals = 0;
  std::vector<std::string>vTerminals;
  if(inGram.is_open())
  {
    		while (std::getline(inGram, line))
    		{
                if(outGram.is_open())
                {
                    if(terminals == 0)
                    {
                        vTerminals.push_back(line.substr(0, 1));
                    }
                    else if(terminals == 1)
                    {
                        outGram << getFirstSet(line, vTerminals);
                    }
                    else
                    {
                        //return 0;
                    }
                    if(line == "$")
                    {
                        terminals++;
                    }
                    lineNum++;
                }
  	        }
  }
  outGram.close();
  inGram.close();
  return 0;
}

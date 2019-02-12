#include <fstream>
#include <string>
#include <iostream>

std::string getFirstSet(std::string sI)
{
    std::string sO = "";
    for(int i=0; i<sI.length(); i++)
    {
        if(sI.substr(i, 2) == "->") sO += sI.substr(i+2, 1);
        else if(sI.substr(i, 1) == "|") sO += sI.substr(i+2, 1);
    }
    return sO;
}

int main () {
  std::string line;
  std::ifstream inGram("g417");
  std::ofstream outGram("sets.out");
  int lineNum = 1;
  int terminals = 0;
  if(inGram.is_open())
  {
    		while (std::getline(inGram, line))
    		{
                if(outGram.is_open())
                {
                    if(terminals == 0)
                    {
                        
                    }
                    else if(terminals == 1)
                    {
                        outGram << getFirstSet(line);
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

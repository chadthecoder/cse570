/*
Chad McAdams
005966723
Lab 2
*/

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

//prints contents of vector into terminal
void printV(std::vector<std::string>v)
{
    std::cout << "{";
    for(int i=0; i<v.size(); i++)
    {
        if(i+1 == v.size()) std::cout << v[i];
        else std::cout << v[i] << ", ";
    }
    std::cout << "}";
}

//returns true if a given string is a given vector
bool functIsInV(std::string s, std::vector<std::string> v)
{
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] == s) return true;
    }
    return false;
}

//returns true if given string is in given terminal vector
bool functIsTerminal(std::string s, std::vector<std::string> terminals)
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

//gets all terminals from file and returns a vector of strings that are the terminals
std::vector<std::string> getTerminals(std::string inFile)
{
    std::ifstream inGram(inFile);
    std::vector<std::string> v;
    std::string line;
    bool isTerminal = true;

    if(inGram.is_open())
    {
    		while (std::getline(inGram, line))
    		{
                if(isTerminal == true)
                {
                    if(line == "$")
                    {
                        isTerminal = false;
                        break;
                    }
                    else
                    {
                            
                        v.push_back(line.substr(0, 1));
                    }
                }
            }
    }
    inGram.close();
    inGram.clear();
    return v;
}

//returns the non-terminals in a given file grammar 
std::vector<std::string> getTest(std::string inFile)
{
    std::ifstream inGram(inFile);
    std::vector<std::string> v;
    std::string line;
    bool isTerminal = true;

    if(inGram.is_open())
    {
    		while (std::getline(inGram, line))
    		{
                if(isTerminal == true)
                {
                    if(line == "$")
                    {
                        isTerminal = false;
                    }
                }
                else
                {
                    if(!functIsInV(line.substr(0, 1), v) && line != "$") v.push_back(line.substr(0, 1));
                }
                
            }
    }
    inGram.close();
    inGram.clear();
    return v;
}

//gives a vector of strings of the first sets in a given grammar file
std::vector<std::string> getFirstSets(std::string inFile, std::string outFile, std::string e, std::vector<std::string> & sO)
{
  std::ifstream inGram(inFile);
  std::ofstream outGram(outFile);
  
  std::string line;
  int lineNum = 1;
  bool isTerminal = true;
  if(inGram.is_open())
  {
    		while (std::getline(inGram, line))
    		{
                    if(isTerminal == true)
                    {
                        if(line == "$")
                        {
                            isTerminal = false;
                        }
                    }
                    else if(isTerminal == false)
                    {
                        for(int i=0; i<line.length(); i++)
                        {
                            if(line.substr(0, 1) == e){
                                if(line.substr(i, 2) == "->")
                                {
                                    if((functIsTerminal(line.substr(i+2, 1), getTerminals(inFile)) || line.substr(i+2, 1) == "e") && !functIsInV(line.substr(i+2, 1), sO)) { sO.push_back(line.substr(i+2, 1)); }
                                    else { getFirstSets(inFile, outFile, line.substr(i+2, 1), sO); }
                                }
                                else if(line.substr(i, 1) == "|") 
                                {
                                    if((functIsTerminal(line.substr(i+1, 1), getTerminals(inFile)) || line.substr(i+2, 1) == "e") && !functIsInV(line.substr(i+2, 1), sO)) { sO.push_back(line.substr(i+1, 1)); }
                                    else { getFirstSets(inFile, outFile, line.substr(i+1, 1), sO); }
                                }
                            }
                        }
                    }
                    lineNum++;
  	        }
  }
    inGram.close();
    inGram.clear();
    outGram.close();
    outGram.clear();
    return sO;
    
}

//gives a vector of strings of the follow sets in a given grammar file
std::vector<std::string> getFollowSets(std::string inFile, std::string outFile, std::string e, std::vector<std::string> & sO)
{
  std::ifstream inGram(inFile);
  std::ofstream outGram(outFile);
  
  std::string line;
  int lineNum = 1;
  bool isTerminal = true;
  //std::vector<std::string>sO;
  if(inGram.is_open())
  {
    		while (std::getline(inGram, line))
    		{
                    if(isTerminal == true)
                    {
                        if(line == "$")
                        {
                            isTerminal = false;
                        }
                    }
                    else if(isTerminal == false)
                    {
                        for(int i=0; i<line.length(); i++)
                        {
                                if(line.substr(i, 1) == e)
                                {
                                    if((functIsTerminal(line.substr(i+1, 1), getTerminals(inFile)) || line.substr(i+1, 1) == "e") && !functIsInV(line.substr(i+1, 1), sO)) { sO.push_back(line.substr(i+1, 1)); }
                                    else { getFirstSets(inFile, outFile, line.substr(i+1, 1), sO); }
                                }
                                /*else if(line.substr(i, 1) == "|") 
                                {
                                    if((functIsTerminal(line.substr(i+1, 1), getTerminals(inFile)) || line.substr(i+2, 1) == "e") && !functIsInV(line.substr(i+2, 1), sO)) { sO.push_back(line.substr(i+1, 1)); }
                                    else { getFirstSets(inFile, outFile, line.substr(i+1, 1), sO); }
                                }*/
                            //}
                        }
                    }
                    else
                    {
                        //return 0;
                    }
                    lineNum++;
  	        }
  }
    inGram.close();
    inGram.clear();
    outGram.close();
    outGram.clear();
    return sO;
    
}

int main () {
  std::string inFile = "g417.in", outFile = "sets_g417.out";
  std::vector<std::string> vTerminals, vTest, ans;

  //gets the terminals
  vTerminals = getTerminals(inFile);

  //gets the non-terminals
  vTest = getTest(inFile);

  //prints the non-terminals and terminals 
  printV(vTest);
  printV(vTerminals);
  std::cout << std::endl << std::endl;

  //prints the first sets
  std::cout << "First Sets: " << std::endl;
  for(int i=0; i<vTest.size(); i++)
  {
      std::vector<std::string> sO;
      getFirstSets(inFile, outFile, vTest[i], sO);
      std::cout << vTest[i] << ": ";
      printV(sO);
      std::cout << std::endl;
  }

  std::cout << std::endl << std::endl;

// prints the follow sets
  std::cout << "Follow Sets: " << std::endl;
  for(int i=0; i<vTest.size(); i++)
  {
      std::vector<std::string> sO;
      getFollowSets(inFile, outFile, vTest[i], sO);
      std::cout << vTest[i] << ": ";
      printV(sO);
      std::cout << std::endl;
  }
  
  return 0;
}

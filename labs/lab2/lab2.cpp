#include <fstream>
#include <string>
#include <iostream>
#include <vector>

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

bool functIsInV(std::string s, std::vector<std::string> v)
{
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] == s) return true;
    }
    return false;
}

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
                    else
                    {
                            
                        //v.push_back(line.substr(0, 1));
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

std::vector<std::string> getFirstSets(std::string inFile, std::string outFile, std::string e, std::vector<std::string> & sO)
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
                        //std::cout << "term: " << line << std::endl;
                        if(line == "$")
                        {
                            isTerminal = false;
                            //std::cout << "test";
                        }
                        else
                        {
                            
                            //vTerminals.push_back(line.substr(0, 1));
                            //std::cout << line.substr(0, 1);
                        }
                    }
                    else if(isTerminal == false)
                    {
                        //std::cout << "non: " << line << std::endl;
                        //std::cout << "test2";
                        //printV(getFirstSets(inFile, outFile));
                        //std::cout << getFirstSet(line, vTerminals);

                        //std::vector<std::string> sO;
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
                        //std::cout << "term: " << line << std::endl;
                        if(line == "$")
                        {
                            isTerminal = false;
                            //std::cout << "test";
                        }
                        else
                        {
                            
                            //vTerminals.push_back(line.substr(0, 1));
                            //std::cout << line.substr(0, 1);
                        }
                    }
                    else if(isTerminal == false)
                    {
                        //std::cout << "non: " << line << std::endl;
                        //std::cout << "test2";
                        //printV(getFirstSets(inFile, outFile));
                        //std::cout << getFirstSet(line, vTerminals);

                        //std::vector<std::string> sO;
                        for(int i=0; i<line.length(); i++)
                        {
                            //if(line.substr(0, 1) == e){
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
  //std::ifstream inGram("g417.in");
  //std::ofstream outGram("sets_g417.out");
  std::string inFile = "g417.in", outFile = "sets_g417.out";
  std::vector<std::string> vTerminals, vTest, ans;
/*
  std::string line;
  int lineNum = 1;
  bool terminals = true;
  std::vector<std::string>vTerminals;
  if(inGram.is_open())
  {
    		while (std::getline(inGram, line))
    		{
                if(outGram.is_open())
                {
                    if(terminals == true)
                    {
                        if(line == "$")
                        {
                            terminals = false;
                            //std::cout << "test";
                        }
                        else
                        {
                            
                            vTerminals.push_back(line.substr(0, 1));
                            //std::cout << line.substr(0, 1);
                        }
                    }
                    else if(terminals == false)
                    {
                        //std::cout << "test2";
                        printV(getFirstSets(inGram, vTerminals, line));
                        //std::cout << getFirstSet(line, vTerminals);
                    }
                    else
                    {
                        //return 0;
                    }
                    lineNum++;
                }
  	        }
  }
  //printV(vTerminals);
  outGram.close();
  inGram.close();*/
  vTerminals = getTerminals(inFile);
  vTest = getTest(inFile);
  printV(vTest);
  printV(vTerminals);
  std::cout << std::endl << std::endl;
  //printV(vTerminals);
  //getFirstSets(inFile, outFile, sO, "E", vTerminals);

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

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum state
{
  zero = 0, one = 1, two = 2, three = 3
};

bool dfaCheck1(int lineNum, std::string dfa)
{
    state currentState = zero;
    bool test = false;
    //std::vector<char>dfa;
    for(int i = 0; i < dfa.length(); i++)
    {
      switch(currentState)
      {
        case zero:
          switch(dfa[i])
          {
            case 'a':
              currentState = one;
              std::cout << "0a\n";
              break;
            case 'b':
              currentState = zero;
              std::cout << "0b\n";
              break;
            default:
              std::cout << "Ivalid character detected on line " << lineNum << "!!!" << std::endl;
              return false;
              break;
          }
          break;
        case one:
          switch(dfa[i])
          {
            case 'a':
              currentState = one;
              std::cout << "1a\n";
              break;
            case 'b':
              currentState = two;
              std::cout << "1b\n";
              break;
            default:
              std::cout << "Ivalid character detected on line " << lineNum << "!!!" << std::endl;
              return false;
              break;
          }
          break;
        case two:
          switch(dfa[i])
          {
            case 'a':
              currentState = one;
              std::cout << "2a\n";
              break;
            case 'b':
              currentState = three;
              std::cout << "2b\n";
              test = true;
              break;
            default:
              std::cout << "Ivalid character detected on line " << lineNum << "!!!" << std::endl;
              return false;
              break;
          }
          break;
        case three:
          switch(dfa[i])
          {
            case 'a':
              currentState = one;
              std::cout << "3a\n";
              test = false;
              break;
            case 'b':
              currentState = zero;
              std::cout << "3b\n";
              test = false;
              break;
            default:
              std::cout << "Ivalid character detected on line " << lineNum << "!!!" << std::endl;
              return false;
              break;
          }
          break;
        default:
          std::cout << "Ivalid State detected on line " << lineNum << "!!!" << std::endl;
          return false;
          break;
      }

      //std::cout << dfa[i] << std::endl;
    }
    return test;
}

bool dfaCheck2(int lineNum, std::string dfa)
{
    state currentState = zero;
    bool test = false;
    //std::vector<char>dfa;
    for(int i = 0; i < dfa.length(); i++)
    {
      switch(currentState)
      {
        case zero:
          switch(dfa[i])
          {
            case 'a':
              currentState = one;
              std::cout << "0a\n";
              break;
            case 'b':
              currentState = zero;
              std::cout << "0b\n";
              break;
            default:
              std::cout << "Ivalid character detected on line " << lineNum << "!!!" << std::endl;
              return false;
              break;
          }
          break;
        case one:
          switch(dfa[i])
          {
            case 'a':
              currentState = one;
              std::cout << "1a\n";
              break;
            case 'b':
              currentState = two;
              std::cout << "1b\n";
              break;
            default:
              std::cout << "Ivalid character detected on line " << lineNum << "!!!" << std::endl;
              return false;
              break;
          }
          break;
        case two:
          switch(dfa[i])
          {
            case 'a':
              currentState = one;
              std::cout << "2a\n";
              break;
            case 'b':
              currentState = three;
              std::cout << "2b\n";
              test = true;
              break;
            default:
              std::cout << "Ivalid character detected on line " << lineNum << "!!!" << std::endl;
              return false;
              break;
          }
          break;
        case three:
          switch(dfa[i])
          {
            case 'a':
              currentState = one;
              std::cout << "3a\n";
              test = false;
              break;
            case 'b':
              currentState = zero;
              std::cout << "3b\n";
              test = false;
              break;
            default:
              std::cout << "Ivalid character detected on line " << lineNum << "!!!" << std::endl;
              return false;
              break;
          }
          break;
        default:
          std::cout << "Ivalid State detected on line " << lineNum << "!!!" << std::endl;
          return false;
          break;
      }

      //std::cout << dfa[i] << std::endl;
    }
    return test;
}

int main () {
  std::string line;
  std::ifstream inDFA ("dfa.in");
  int lineNum = 1;
  if (inDFA.is_open())
  {
	std::ofstream outDFA("dfa.out");
  	if (outDFA.is_open())
  	{
    		while (std::getline(inDFA, line))
    		{
      			if(dfaCheck1(lineNum, line))
      			{
        			outDFA << "congrats on line " << lineNum << std::endl;
      			}
    			else
    			{
      				outDFA << "wrong on line " << lineNum << std::endl;
    			}
      			lineNum++;
    		}
    		outDFA.close();
  	}
  	else { std::cout << "Unable to open file"; }
    	inDFA.close();
  }
  else { std::cout << "Unable to open file"; }
  return 0;
}

/*
* Chad McAdams
* 005966723
* Lab 1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//defines the states
enum state
{
  zero = 0, one = 1, two = 2, three = 3
};

/*
* if L=(a|b)*abb returns true
* else returns false
*/
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
              //std::cout << "0a ";
	      test = false;
              break;
            case 'b':
              currentState = zero;
              //std::cout << "0b ";
	      test = false;
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
              //std::cout << "1a ";
	      test = false;
              break;
            case 'b':
              currentState = two;
              //std::cout << "1b ";
	      test = false;
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
              //std::cout << "2a ";
	      test = false;
              break;
            case 'b':
              currentState = three;
              //std::cout << "2b ";
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
              //std::cout << "3a ";
              test = false;
              break;
            case 'b':
              currentState = zero;
              //std::cout << "3b ";
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
    //std::cout << std::endl;
    return test;
}

/*
* if L=(a|b)a* returns true
* else returns false
*/
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
              //std::cout << "0a ";
	      test = true;
              break;
            case 'b':
              currentState = one;
              //std::cout << "0b ";
	      test = true;
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
              //std::cout << "1a ";
	      test = true;
              break;
            case 'b':
              currentState = two;
              //std::cout << "1b ";
	      test = false;
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
              currentState = two;
              //std::cout << "2a ";
	      test = false;
              break;
            case 'b':
              currentState = two;
              //std::cout << "2b ";
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
    //std::cout << std::endl;
    return test;
}

int main () {
  std::string line;

  //gives the filestream
  std::ifstream inDFA ("dfa.in");

  int lineNum = 1;

  //checks if the dfas will accepts the string from the given file
  if (inDFA.is_open())
  {
	std::ofstream outDFA("dfa.out");
  	if (outDFA.is_open())
  	{
    		while (std::getline(inDFA, line))
    		{
			bool check1 = dfaCheck1(lineNum, line);
			bool check2 = dfaCheck2(lineNum, line);
      			if(check1 && check2)
      			{
        			outDFA << "Line " << lineNum << " is accepted by both DFAs." << std::endl;
      			}
			else if(check1 && !check2)
			{
				outDFA << "Line " << lineNum << " is accepted by DFA1 and rejected by DFA2." << std::endl; 
			}
			else if(!check1 && check2)
			{
				outDFA << "Line " << lineNum << " is rejected by DFA1 and accepted by DFA2." << std::endl;
			}
			else if(!check1 && !check2)
			{
				outDFA << "Line " << lineNum << " is rejected by both DFAs." << std::endl;
			}	   			
			else
    			{
      				outDFA << "Line " << lineNum << " has returned a strange sequence." << std::endl;
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

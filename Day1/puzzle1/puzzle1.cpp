#include "puzzle1.h"
#include <string>
#include <sstream>
#include "../../BaseClasses/defines.h"

namespace Day1
{
  Puzzle1::Puzzle1():
    Puzzle("Day1/puzzle1/basicTest.txt",
        "Day1/puzzle1/actualTest.txt")
  {
    PRINT("Puzzle 1 of Day 1 started.");
  }

  std::string Puzzle1::run(const std::string& input)
  {

    std::stringstream  ss(input);

    int count = 0;
    std::string currValueStr;
    std::string prevValueStr;

    if(!std::getline(ss, prevValueStr, '\n'))
    {
      return "";
    }
    while(std::getline(ss, currValueStr, '\n'))
    {
        
      int currVal = std::stoi(currValueStr);
      int prevVal = std::stoi(prevValueStr);

      if(currVal > prevVal)
      {
        ++count;
      }

      prevValueStr = std::move(currValueStr);
    }
    return std::to_string(count);
  }
}


#include "puzzle2.h"
#include <iostream>
#include <sstream>

namespace Day2
{
  Puzzle2::Puzzle2():
    Puzzle("Day2/puzzle2/basicTest.txt",
        "Day2/puzzle2/actualTest.txt")
  {
  }

  std::string  Puzzle2::run(const std::string& input)
  {
    std::stringstream  ss(input);

    std::string command;

    int64_t x = 0;
    int64_t y = 0;
    int64_t aim = 0;
    
    while(std::getline(ss, command, '\n'))
    {
      std::stringstream  commandSs(command);

      std::string query;
      std::getline(commandSs, query, ' ');

      std::string valStr;
      std::getline(commandSs, valStr);

      int val = std::stoi(valStr);

      if(query == "forward")
      {
        x += val;
        y += aim*val;
      }
      else if(query == "up")
      {
        aim -= val; 
      }
      else if(query == "down")
      {
        aim += val;
      }

    }

    return std::to_string(x*y);
  }
}

#include "puzzle1.h"
#include <iostream>
#include <sstream>

namespace Day2
{
  Puzzle1::Puzzle1():
    Puzzle("Day2/puzzle1/basicTest.txt",
        "Day2/puzzle1/actualTest.txt")
  {
  }

  std::string  Puzzle1::run(const std::string& input)
  {
    std::stringstream  ss(input);

    std::string command;

    int64_t x = 0;
    int64_t y = 0;

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
      }
      else if(query == "up")
      {
        y -= val; 
      }
      else if(query == "down")
      {
        y += val;
      }

    }

    return std::to_string(x*y);
  }
}

#include "puzzle2.h"
#include <vector>
#include <sstream>

namespace Day1
{
  Puzzle2::Puzzle2():
    Puzzle("Day1/puzzle2/basicTest.txt",
        "Day1/puzzle2/actualTest.txt")
  {
  }

  std::string Puzzle2::run(const std::string& input)
  {
    std::stringstream  ss(input);

    std::vector<int> inputVec;
    std::string value;

    while(std::getline(ss, value, '\n'))
    {
      inputVec.push_back(std::stoi(value));
    }

    if(inputVec.size() < 3)
    {
      return std::to_string(0);
    }

    int64_t prevValue = inputVec[0]+inputVec[1]+inputVec[2];
    int64_t currValue = 0;

    int count = 0;
    for(int i = 0; i < inputVec.size()-2; ++i)
    {
      currValue = inputVec[i]+inputVec[i+1]+inputVec[i+2];

      if(currValue > prevValue)
      {
        ++count;
      }
      prevValue = currValue;
    }
    return std::to_string(count);
  }
} // Day1

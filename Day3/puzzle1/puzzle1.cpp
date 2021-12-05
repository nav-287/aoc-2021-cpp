#include "puzzle1.h"
#include <string>
#include <sstream>
#include "../../BaseClasses/defines.h"
#include <vector>
#include <cmath>

namespace Day3
{
  Puzzle1::Puzzle1():
    Puzzle("Day3/puzzle1/basicTest.txt",
        "Day3/puzzle1/actualTest.txt")
  {
    PRINT("Puzzle 1 of Day 3 started.");
  }

  std::string Puzzle1::run(const std::string& input)
  {
    std::stringstream  ss(input);

    std::vector<int> zeroArr;
    zeroArr.reserve(5);

    std::vector<int> oneArr;
    oneArr.reserve(5);

    std::string valueStr;
    while(std::getline(ss, valueStr, '\n'))
    {
      valueStr = valueStr.substr(0, valueStr.size()-1);
      for(int i = 0; i < valueStr.size(); ++i)
      {
        if(valueStr[i] == '0')
        {
          if(zeroArr.size() <= i)
          {
            zeroArr.push_back(1);
          }
          else
          {
            ++zeroArr[i];
          }
        }
        else if(valueStr[i] == '1')
        {
          if(oneArr.size() <= i)
          {
            oneArr.push_back(1);
          }
          else
          {
            ++oneArr[i];
          }
        }
      }
    }
    int64_t gamma=0;
    int64_t epsilon=0;

    for(int i = 0; i < zeroArr.size(); ++i)
    {
      if(zeroArr[i] <= oneArr[i])
      {
        gamma += pow(2, zeroArr.size()-i-1);
      }
      else
      {
        epsilon += pow(2, zeroArr.size()-i-1);
      }
    }

    PRINT("Gamma : " << gamma);
    PRINT("Epsilon : " << epsilon);

    return std::to_string(gamma*epsilon);
  }
}


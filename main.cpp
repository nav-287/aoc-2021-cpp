#include <iostream>

#include "BaseClasses/defines.h"
#include "BaseClasses/enums.h"

#include "Day1/puzzle1/puzzle1.h"
#include "Day1/puzzle2/puzzle2.h"
#include "Day2/puzzle1/puzzle1.h"
#include "Day2/puzzle2/puzzle2.h"
#include "Day3/puzzle1/puzzle1.h"


Puzzle* puzzleFactory(PuzzleType puzzleType)
{
  switch((PuzzleType)puzzleType)
  {
    case PuzzleType_DAY1_PUZZLE1 :
      {
        return new Day1::Puzzle1();
      }
      break;
    case PuzzleType_DAY1_PUZZLE2 :
      {
        return new Day1::Puzzle2();
      }
      break;
    case PuzzleType_DAY2_PUZZLE1 :
      {
        return new Day2::Puzzle1();
      }
      break;

    case PuzzleType_DAY2_PUZZLE2 :
      {
        return new Day2::Puzzle2();
      }
      break;

    case PuzzleType_DAY3_PUZZLE1 :
      {
        return new Day3::Puzzle1();
      }
      break;


  }

  return nullptr;
}


int main()
{
  int puzzleN = 0;
  while(true)
  {
    PRINT("-------------------------------------");
    PRINT("Please enter PuzzleNumber : ");
    std::cin >> puzzleN;
    if(!puzzleN)
    {
      break;
    }

    Puzzle *puzzle = puzzleFactory((PuzzleType)puzzleN);
    if(puzzle)
    {
      bool isError = false;
      puzzle->init();

      PRINT("Output : " << puzzle->runTests(isError));
      delete puzzle;
    }
  }
  return 0;
}

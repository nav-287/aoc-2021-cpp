#include <iostream>
#include "Day1/puzzle1/puzzle1.h"

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

    Puzzle *puzzle = 0;
    switch(puzzleN)
    {
      case 1 :
        {
          puzzle = new Day1::Puzzle1();
        }
    }

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

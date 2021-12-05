#ifndef DAY1_PUZZLE1_H
#define DAY1_PUZZLE1_H

#include "../../BaseClasses/puzzle.h"
#include "../../BaseClasses/defines.h"

namespace Day1
{
  class Puzzle1 : public Puzzle
  {
    std::string run(const std::string& input) override;
    
    public:

    Puzzle1();

  };
}

#endif

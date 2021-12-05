#ifndef DAY1_PUZZLE2_H
#define DAY1_PUZZLE2_H

#include <iostream>
#include "../../BaseClasses/puzzle.h"

namespace Day1
{
  class Puzzle2 : public Puzzle
  {
    std::string run(const std::string& input) override;

    public:

    Puzzle2();
  };
}
#endif //DAY1_PUZZLE2_H


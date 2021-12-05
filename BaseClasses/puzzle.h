#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>

class Puzzle
{
  private: 
    std::string _actualTestFile;
    std::string _basicTestFile;

    std::string _testData;
    std::string _basicTestData;

    std::string _basicExpectedOutput;
    bool _isTestDataInit;

    bool readFile(const std::string& fileName,
        std::string& readData);

    bool readTestData();

    bool runBasicTest();

    virtual std::string run(const std::string& input) = 0;

  public:

    Puzzle(const std::string& basicFilePath,
        const std::string& testFilePath);

    void init();

    std::string runTests(bool isError);
};

#endif

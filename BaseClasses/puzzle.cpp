#include "puzzle.h"
#include <fstream>
#include <sstream>
#include <string>

#include "defines.h"

Puzzle::Puzzle(const std::string& basicFilePath,
    const std::string& testFilePath):
  _basicTestFile(basicFilePath),
  _actualTestFile(testFilePath),
  _isTestDataInit(false)
{
}

bool Puzzle::readFile(const std::string& fileName,
    std::string& readData)
{
  PRINT("Reading file : " << fileName);

  std::ifstream file(fileName.c_str());
  if(!file)
  {
    PRINT("Reading file failed : " << fileName );
    return false;
  }

  std::ostringstream ss;
  ss << file.rdbuf();
  readData = ss.str();

  //PRINT("Read Data : " << readData);
  return true;
}

void Puzzle::init()
{
  PRINT("Initializing Puzzle");
  readTestData();
}

bool Puzzle::readTestData()
{
  PRINT("Reading Puzzle Test Data");
 
  _isTestDataInit = false;
  
  //read basic file
  if(!readFile(_basicTestFile, _basicTestData))
  {
    return false;
  }

  if(!runBasicTest())
  {
    PRINT("Puzzle basic test case failed.");
    return false;
  }
  
  PRINT("Puzzle basic test case passed.");
 
  //read actual test file
  if(!readFile(_actualTestFile, _testData))
  {
    return false;
  }
 
  _isTestDataInit = true;
}

bool Puzzle::runBasicTest()
{
  std::stringstream  ss(_basicTestData);
  std::string expectedOutput;
  if(!std::getline(ss, expectedOutput, '\n'))
  {
    return false; 
  }

  expectedOutput = expectedOutput.substr(0, expectedOutput.size()-1);

  std::string remainingStr = _basicTestData.substr(expectedOutput.size()+2,
      _basicTestData.size() - expectedOutput.size()-1 );

  std::string output = run(remainingStr);

  return (output == expectedOutput);
}

std::string Puzzle::runTests(bool isError)
{
  PRINT("Running Puzzle test cases.");
 
  if(!_isTestDataInit)
  {
    PRINT("Puzzle test data not initialized.");
    isError = true;
    
    return "";
  }

  return run(_testData);
}


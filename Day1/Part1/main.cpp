#include <iostream>
#include <fstream>
#include <string>

std::pair<char, int> ParseLine(const std::string& currentLine);

int main() {
  // Declare variables to hold values
  int currentNum{50};
  int zeroCounter{0};
  constexpr int minValue{0};
  constexpr int maxValue{99};
  std::string currentLine;

  // Open the input file
  std::ifstream input("../input.txt");
  if(!input) {
    std::cerr << "Could not open input txt file.\n";
    return 1;
  }
  
  //Process each line in the file
  while(std::getline(input, currentLine)) { // Increments to next line when complete
    auto [nextDirection, numClicks] = ParseLine(currentLine);
    
    if(nextDirection == 'L') {  // Left decreases number
      currentNum -= numClicks;
      while(currentNum < minValue) {
        currentNum = ((maxValue + 1) - abs(currentNum));
      }
    }

    else if(nextDirection == 'R') {  // Right increases number
      currentNum += numClicks;
      while(currentNum > maxValue) {
        currentNum = ((currentNum - 1) - maxValue);
      }
    }

    if(currentNum == 0) {
      zeroCounter++;
    }
  }

  std::cout << zeroCounter;

  input.close();
  return 0;
}

std::pair<char, int> ParseLine(const std::string& currentLine) {
  char letter = currentLine[0];
  int number = std::stoi(currentLine.substr(1));
  return{letter, number};
}

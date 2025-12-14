#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::string currentBank{""};  // Current bank we are processing
  long outputJoltage{0};    // Store the total output joltage from each bank

  // Open the input file
  std::ifstream input("input.txt");
  if(!input){
    std::cerr << "Could not open input txt file.\n";
    return 1;
  }

  // Process each bank of batteries
  while(std::getline(input, currentBank)){
    // Walk the bank digit-by-digit
    // Store the index and value of the highest digit (compare currentVal to firstVal), exclude final digit, end if we reach 9
    // Walk the bank a second time, starting at firstIndex + 1
    // Store the value of the second digit (compare currentVal to secondVal), include final digit, end if we reach 9
    // std::to_string, concatenate, std::stoi -> store in maxJoltage
    // outputJoltage += maxJoltage

    int firstIndex{0};  // Store the index of the first digit
    int firstVal{0};    // Store the value of the first digit
    int secondVal{0};   // Store the value of the second digit
    int currentVal{0};     // Value of the digit we are currently checking
    int maxJoltage{0};  // The maximum joltage value obtained from the bank
  }

  // Return the solution
  std::cout << "Output Joltage: " << outputJoltage << std::endl;

  // Close the input file
  input.close();
  return 0;
}

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
    int firstIndex{0};      // Store the index of the first digit
    int firstVal{0};        // Store the value of the first digit
    int secondVal{0};       // Store the value of the second digit
    int currentVal{0};      // Value of the digit we are currently checking
    int maxJoltage{0};      // The maximum joltage value obtained from the bank

    // Walk the bank digit-by-digit, exclude final digit
    for(int i = 0; i < currentBank.length() - 1; i++){
      currentVal = currentBank[i] - '0';    // Extract the char at the current index and convert to an int
      if(currentVal > firstVal){            // Store the index and value of the highest digit (compare currentVal to firstVal)
        firstVal = currentVal;
        firstIndex = i;
      }
      if(firstVal == 9) break;            // Break the loop if we find 9
    }

    // Walk the bank a second time, starting at firstIndex + 1
    for(int i = firstIndex + 1; i < currentBank.length(); i++){
      currentVal = currentBank[i] - '0';    // Extract the value at the current index
      if(currentVal > secondVal){           // Check for a new greatest second val
        secondVal = currentVal;
      }
      if(secondVal == 9) break;            // Break the loop if we find 9
    }

    // Format conversion and concatenation
    std::string firstString = std::to_string(firstVal);
    std::string secondString = std::to_string(secondVal);
    std::string valString = firstString + secondString;
    maxJoltage = std::stoi(valString);

    // Add the max bank joltage to the total output
    outputJoltage += maxJoltage;
  }

  // Return the solution
  std::cout << "Output Joltage: " << outputJoltage << std::endl;

  // Close the input file
  input.close();
  return 0;
}

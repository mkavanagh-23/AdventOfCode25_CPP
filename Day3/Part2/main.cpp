#include <vector>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::string currentBank{""}; // Current bank we are processing
  long long outputJoltage{0};  // Store the total output joltage from each bank

  // Open the input file
  std::ifstream input("input.txt");
  if (!input) {
    std::cerr << "Could not open input txt file.\n";
    return 1;
  }

  // Process each bank of batteries
  while (std::getline(input, currentBank)) {
    int currentVal{0};       // Value of the digit we are currently checking
    long long maxJoltage{0}; // The maximum joltage value obtained from the bank

    // number of digits to keep
    int numDigits = 12;

    // how many digits we are allowed to remove
    int toRemove = currentBank.length() - numDigits;

    std::vector<int> stack;

    for (char c : currentBank) {
      int value = c - '0';

      while (!stack.empty() && toRemove > 0 && stack.back() < value) {
        stack.pop_back();
        --toRemove;
      }

      stack.push_back(value);
    }

    // Ensure exactly numDigits digits
    stack.resize(numDigits);

    // Convert to integer
    std::string valString;
    for (int value : stack) {
      valString += std::to_string(value);
    }

    maxJoltage = std::stoll(valString);

    std::cout << maxJoltage << '\n';

    // Add the max bank joltage to the total output
    outputJoltage += maxJoltage;
  }

  // Return the solution
  std::cout << "Output Joltage: " << outputJoltage << std::endl;

  // Close the input file
  input.close();
  return 0;
}

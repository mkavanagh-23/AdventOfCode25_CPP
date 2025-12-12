//  For each range iterate ovber each value within. If mod by 2 is equal to zero it can possibly be invalid. Convert to string, split to two substrings, check if substrings are equal. If invalid, convert back to an int and add to the invalid sum.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main() {
  std::string currentRange;
  std::vector<std::pair<long long, long long>> ranges;
  long long invalidSum{0};

  // Open the input file
  std::ifstream input("input.txt");
  if(!input){
    std::cerr << "Could not open input txt file.\n";
    return 1;
  }

  // Extract the ranges from the input
  while(std::getline(input, currentRange, ',')){
    long long start, end;
    char dash;
    std::stringstream range(currentRange);
    range >> start >> dash >> end;  // Read the values into the variables
    ranges.emplace_back(start, end);
  }

  // Process each range
  for(auto& [start, end] : ranges) {
    for(long long i = start; i <= end; i++) {
      std::string valString = std::to_string(i);
      int length = valString.length();
      // Mod length by 2 to see if we have even num of digits
      if(length % 2 == 0) {
        std::string first = valString.substr(0, length/2);
        std::string second = valString.substr(length/2, length/2);
        if(first == second) {
          invalidSum += std::stoll(valString);
        }
      }
    }
  }

  std::cout << invalidSum;
}

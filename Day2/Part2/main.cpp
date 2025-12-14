#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>

int main() {
  std::string currentRange;
  std::vector<std::pair<long long, long long>> ranges;
  long long invalidSum{0};

  std::ifstream input("input.txt");
  if (!input) {
    std::cerr << "Could not open input txt file.\n";
    return 1;
  }

  while (std::getline(input, currentRange, ',')) {
    long long start, end;
    char dash;
    std::stringstream range(currentRange);
    range >> start >> dash >> end;
    ranges.emplace_back(start, end);
  }

  // Use regex to calculate the repeated half
  std::regex repeatedNum(R"(^(\d+)\1+$)");

  for (auto& [start, end] : ranges) {
    for (long long i = start; i <= end; i++) {
      std::string s = std::to_string(i);

      if (std::regex_match(s, repeatedNum)) {
        invalidSum += i;
      }
    }
  }

  std::cout << invalidSum;
}

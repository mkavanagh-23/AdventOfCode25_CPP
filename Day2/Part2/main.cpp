#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>

int main() {
  std::string currentRange;
  long long invalidSum{0};
  std::regex repeatedNum(R"(^(\d+)\1+$)");

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
    for (long long i = start; i <= end; i++) {
      std::string s = std::to_string(i);
      if (std::regex_match(s, repeatedNum)) {
        invalidSum += i;
      }
    }
  }

  std::cout << invalidSum;
}

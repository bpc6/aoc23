#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"

int main() {
  auto lines = readLines("input/test.txt");
  for (const auto& line : lines) {
    for (auto num : ints(line)) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "day09" << std::endl;
}

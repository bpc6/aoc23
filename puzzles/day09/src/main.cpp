#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"

std::vector<int> diff(std::vector<int>::iterator it, std::vector<int>::iterator end) {
  std::vector<int> ret;
  int last = *it;
  for (advance(it, 1); it != end; ++it) {
    ret.push_back(*it - last);
    last = *it;
  }
  return ret;
}

int extrapolate(std::vector<int> sequence) {
  auto dif = diff(sequence.begin(), sequence.end());
  if (std::all_of(dif.begin(), dif.end(), [](int n) { return n == 0; })) {
    return sequence.back();
  }
  int difExtrap = extrapolate(dif);
  return sequence.back() + difExtrap;
}

int main() {
  auto lines = readLines("input/input.txt");
  int sum = 0;
  for (const auto& line : lines) {
    sum += extrapolate(ints(line));
  }
  std::cout << sum << std::endl;
  std::cout << "day09" << std::endl;
}

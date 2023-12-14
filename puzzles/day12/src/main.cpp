#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"

bool isValid(std::string springs, const std::vector<int>& nums) {
  springs += '.';
  auto numPtr = nums.begin();
  char last = '.';
  int springCount = 0;
  int qCount = 0;
  for (char c : springs) {
    if (c == '#') {
      springCount++;
    } else if (c == '?') {
      qCount++;
    } else if (c == '.' && last != '.') {
      if (*numPtr > springCount + qCount) {
        return false;
      }
      springCount = 0;
      qCount = 0;
      numPtr++;
    }

    if (springCount > *numPtr) {
      return false;
    }
    if (qCount + springCount > *numPtr) {
      return true;
    }
    last = c;
  }
  return numPtr == nums.end();
}

int countOptions(std::string springs, const std::vector<int>& nums) {
  if (!isValid(springs, nums)) {
    return 0;
  }
  std::string strCpy = springs;
  std::replace(strCpy.begin(), strCpy.end(), '?', '.');
  if (isValid(strCpy, nums)) {
    return 1;
  }
  int qCount = 0;
  for (int i = 0; i < springs.size(); i++) {
    if (springs[i] == '?') {
      springs[i] = '#';
      qCount += countOptions(springs, nums);
      springs[i] = '.';
    }
  }
  return qCount;
}

int countOptions(const std::string& line) {
  auto lineParts = split(line);
  std::string springs = lineParts[0];
  auto nums = ints(lineParts[1], ',');

  return countOptions(springs, nums);
}

int main() {
  auto lines = readLines("input/input.txt");
  int sum = 0;
  for (const auto& line : lines) {
    int options = countOptions(line);
    std::cout << options << std::endl;
    sum += options;
  }
  std::cout << sum << std::endl;
}

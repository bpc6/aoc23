#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"

std::function<uint64_t(uint64_t)> chainFunctions(
    const std::vector<std::function<uint64_t(uint64_t)>>& functions) {
  return [functions](uint64_t input) {
    for (const auto& f : functions) {
      input = f(input);
    }
    return input;
  };
}

std::function<uint64_t(uint64_t)> createMapper(const std::string& txt) {
  std::vector<std::string> lines = split(txt, '\n');
  return [lines](uint64_t input) {
    for (int i = 1; i < lines.size(); i++) {
      std::vector<std::string> numStrs = split(lines[i], ' ');
      uint64_t destStart = std::stoull(numStrs[0]);
      uint64_t sourceStart = std::stoull(numStrs[1]);
      uint64_t rangeLen = std::stoull(numStrs[2]);
      if (input >= sourceStart and input < sourceStart + rangeLen) {
        return input + destStart - sourceStart;
      }
    }
    return input;
  };
}

int main() {
  std::string txt = readFile("input/input.txt");
  std::vector<std::string> txtGroups = split(txt, "\n\n");

  std::vector<std::function<uint64_t(uint64_t)>> functions;
  for (int i = 1; i < txtGroups.size(); i++) {
    functions.push_back(createMapper(txtGroups[i]));
  }
  auto findLocation = chainFunctions(functions);

  std::vector<uint64_t> locations;
  std::string numsStr = split(txtGroups[0], ": ")[1];
  auto strNums = split(numsStr, ' ');
  locations.reserve(strNums.size());
  for (const std::string& strNum : strNums) {
    uint64_t num = std::stoull(strNum);
    locations.push_back(findLocation(num));
  }
  auto minLocationPtr = std::min_element(locations.begin(), locations.end());

  std::cout << "day05" << std::endl;
  std::cout << *minLocationPtr << std::endl;
}

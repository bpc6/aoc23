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
  std::vector<std::vector<uint64_t>> table;
  for (const std::string& line : lines) {
    if (isdigit(line.at(0))) {
      std::vector<std::string> numStrs = split(line, ' ');
      std::vector<uint64_t> nums;
      nums.reserve(numStrs.size());
      for (const std::string& numStr : numStrs) {
        nums.push_back(std::stoull(numStr));
      }
      table.push_back(nums);
    }
  }

  std::vector<std::vector<uint64_t>>::size_type ydim = table.size();
  std::vector<uint64_t>::size_type xdim = table[0].size();
  // allocate memory for the array
  auto** arr = new uint64_t*[ydim];
  for (std::size_t i = 0; i < ydim; ++i) {
    arr[i] = new uint64_t[xdim];
  }

  // copy the data from the vector to the array
  for (std::size_t i = 0; i < ydim; ++i) {
    for (std::size_t j = 0; j < xdim; ++j) {
      arr[i][j] = table[i][j];
    }
  }

  return [arr, ydim](uint64_t input) {
    for (std::size_t yidx = 0; yidx < ydim; yidx++) {
      uint64_t destStart = arr[yidx][0];
      uint64_t sourceStart = arr[yidx][1];
      uint64_t rangeLen = arr[yidx][2];
      if (input >= sourceStart and input < sourceStart + rangeLen) {
        return input + destStart - sourceStart;
      }
    }
    return input;
  };
}

uint64_t p1MinLocation(std::vector<std::string> strNums,
                       const std::function<uint64_t(uint64_t)>& findLocation) {
  auto minLocation = uint64_t(-1);
  for (const auto& strNum : strNums) {
    uint64_t seed = std::stoull(strNum);
    uint64_t location = findLocation(seed);
    if (location < minLocation) {
      minLocation = location;
    }
  }
  return minLocation;
}

uint64_t p2MinLocation(std::vector<std::string> strNums,
                       const std::function<uint64_t(uint64_t)>& findLocation) {
  auto minLocation = uint64_t(-1);
  for (int i = 0; i < strNums.size(); i++) {
    std::cout << i << "/" << strNums.size() << std::endl;
    uint64_t start = std::stoull(strNums[i]);
    uint64_t numSeeds = std::stoull(strNums[++i]);
    for (uint64_t seed = start; seed < start + numSeeds; seed++) {
      uint64_t location = findLocation(seed);
      if (location < minLocation) {
        minLocation = location;
      }
    }
  }
  return minLocation;
}

int main() {
  std::string txt = readFile("input/input.txt");
  std::vector<std::string> txtGroups = split(txt, "\n\n");

  std::vector<std::function<uint64_t(uint64_t)>> functions;
  for (int i = 1; i < txtGroups.size(); i++) {
    functions.push_back(createMapper(txtGroups[i]));
  }
  auto findLocation = chainFunctions(functions);
  std::string numsStr = split(txtGroups[0], ": ")[1];
  auto strNums = split(numsStr, ' ');

  uint64_t minLocation = p2MinLocation(strNums, findLocation);

  std::cout << "day05" << std::endl;
  std::cout << minLocation << std::endl;
}

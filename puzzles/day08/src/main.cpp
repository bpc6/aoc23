#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"

bool notAlpha(char c) { return !isalnum(c); }

std::string alphaOnly(std::string s) {
  s.erase(std::remove_if(s.begin(), s.end(), notAlpha), s.end());
  return s;
}

bool allAtZ(const std::vector<std::string>& strings) {
  for (std::string s : strings) {
    if (s.back() != 'Z') {
      return false;
    }
  }
  return true;
}

int main() {
  std::vector<std::string> lines = readLines("input/test2.txt");
  std::string instructions = lines[0];

  std::unordered_map<std::string, std::unordered_map<char, std::string>> map;
  map.reserve(lines.size() - 2);

  std::vector<std::string> curr;
  auto lineIter = lines.begin();
  for (advance(lineIter, 2); lineIter != lines.end(); ++lineIter) {
    auto splitOnEq = split(*lineIter, " = ");
    std::string key = splitOnEq[0];
    if (key.back() == 'A') {
      curr.push_back(key);
    }
    auto splitOnComma = split(splitOnEq[1], ',');
    std::string left = alphaOnly(splitOnComma[0]);
    std::string right = alphaOnly(splitOnComma[1]);
    map[key] = {{'L', left}, {'R', right}};
  }

  int steps = 0;
  int instructionIdx = 0;
  auto instructSize = instructions.size();
  while (!allAtZ(curr)) {
    char c = instructions[instructionIdx++ % instructSize];
    for (auto& currStr : curr) {
      currStr = map[currStr][c];
    }
    steps++;
  }
  std::cout << steps << std::endl;
  std::cout << "day08" << std::endl;
}

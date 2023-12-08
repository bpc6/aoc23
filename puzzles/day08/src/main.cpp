#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "utils.h"

bool notAlpha(char c) { return !isalnum(c); }

std::string alphaOnly(std::string s) {
  s.erase(std::remove_if(s.begin(), s.end(), notAlpha), s.end());
  return s;
}

int main() {
  std::vector<std::string> lines = readLines("input/input.txt");
  std::string instructions = lines[0];

  std::unordered_map<std::string, std::unordered_map<char, std::string>> map;
  map.reserve(lines.size() - 2);

  std::vector<std::string> start;
  auto lineIter = lines.begin();
  for (advance(lineIter, 2); lineIter != lines.end(); ++lineIter) {
    auto splitOnEq = split(*lineIter, " = ");
    std::string key = splitOnEq[0];
    if (key.back() == 'A') {
      start.push_back(key);
    }
    auto splitOnComma = split(splitOnEq[1], ',');
    std::string left = alphaOnly(splitOnComma[0]);
    std::string right = alphaOnly(splitOnComma[1]);
    map[key] = {{'L', left}, {'R', right}};
  }

  std::vector<int> stepCounts;
  for (auto curr : start) {
    int steps = 0;
    int instructionIdx = 0;
    while (curr.back() != 'Z') {
      char c = instructions[instructionIdx++ % instructions.size()];
      curr = map[curr][c];
      steps++;
    }
    stepCounts.push_back(steps);
  }

  uint64_t total = 1;
  for (int count : stepCounts) {
    total = lcd(total, count);
  }
  std::cout << total << std::endl;
  std::cout << "day08" << std::endl;
}

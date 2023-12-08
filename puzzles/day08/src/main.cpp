#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "utils.h"

bool notAlpha(char c) { return !isalpha(c); }

std::string alphaOnly(std::string s) {
  s.erase(std::remove_if(s.begin(), s.end(), notAlpha), s.end());
  return s;
}

int main() {
  std::vector<std::string> lines = readLines("input/input.txt");
  std::string instructions = lines[0];

  std::unordered_map<std::string, std::unordered_map<char, std::string>> map;
  map.reserve(lines.size() - 2);

  auto lineIter = lines.begin();
  for (advance(lineIter, 2); lineIter != lines.end(); ++lineIter) {
    auto splitOnEq = split(*lineIter, " = ");
    std::string key = splitOnEq[0];
    auto splitOnComma = split(splitOnEq[1], ',');
    std::string left = alphaOnly(splitOnComma[0]);
    std::string right = alphaOnly(splitOnComma[1]);
    map[key] = {{'L', left}, {'R', right}};
  }

  int steps = 0;
  int instructionIdx = 0;
  std::string curr = "AAA";
  while (curr != "ZZZ") {
    char c = instructions[instructionIdx++ % instructions.size()];
    curr = map[curr][c];
    steps++;
  }
  std::cout << steps << std::endl;
  std::cout << "day08" << std::endl;
}

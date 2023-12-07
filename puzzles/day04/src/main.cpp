#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

#include "utils.h"

bool isInVector(std::vector<int>& vec, int value) {
  return std::find(vec.begin(), vec.end(), value) != vec.end();
}

int score(int count) {
  if (count <= 1) {
    return count;
  }
  return int(pow(2.0, static_cast<float>(count - 1)));
}

int numMatches(const std::string& numberSequence) {
  int matchCount = 0;
  std::vector<std::string> groups = split(numberSequence, '|');
  std::vector<int> winners, mine;
  for (const std::string& nstr : split(groups[0], ' ')) {
    if (!nstr.empty()) {
      winners.push_back(stoi(nstr));
    }
  }
  for (const std::string& nstr : split(groups[1], ' ')) {
    if (!nstr.empty()) {
      int asInt = stoi(nstr);
      if (isInVector(winners, asInt)) {
        matchCount++;
      }
    }
  }
  return matchCount;
}

int p1(const std::vector<std::string>& lines) {
  int sum = 0;
  for (const std::string& line : lines) {
    std::string numbers = split(line, ':')[1];
    sum += score(numMatches(numbers));
  }
  return sum;
}

int p2(const std::vector<std::string>& lines) {
  std::vector<int> counter(lines.size(), 1);
  for (int i = 0; i < lines.size(); i++) {
    std::string numbers = split(lines[i], ':')[1];
    int matches = numMatches(numbers);
    for (int counterIdx = i + 1; counterIdx < i + 1 + matches; counterIdx++) {
      counter[counterIdx] += counter[i];
    }
  }
  return std::accumulate(counter.begin(), counter.end(), 0);
}

int main() {
  std::vector<std::string> lines = readLines("input/input.txt");
  std::cout << p1(lines) << std::endl;
  std::cout << p2(lines) << std::endl;
}

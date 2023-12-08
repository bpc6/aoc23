#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"

uint64_t waysToWin(uint64_t time, uint64_t dist) {
  uint64_t count = 0;
  for (uint64_t speed = 1; speed < time; speed++) {
    uint64_t remainingTime = time - speed;
    if (speed * remainingTime > dist) {
      count++;
    }
  }
  return count;
}

uint64_t p1(std::vector<std::string> timeStrings, std::vector<std::string> distStrings) {
  uint64_t total = 1;
  for (int i = 0; i < timeStrings.size(); i++) {
    int time = stoi(timeStrings[i]);
    int dist = stoi(distStrings[i]);
    total *= waysToWin(time, dist);
  }
  return total;
}

uint64_t p2(const std::vector<std::string>& timeStrings,
            const std::vector<std::string>& distStrings) {
  uint64_t time = std::stoull(join(timeStrings));
  uint64_t dist = std::stoull(join(distStrings));
  return waysToWin(time, dist);
}

int main() {
  auto lines = readLines("input/input.txt");
  auto timeRowStrings = split(lines[0]);
  auto distRowStrings = split(lines[1]);

  uint64_t ways = p2(std::vector<std::string>(timeRowStrings.begin() + 1, timeRowStrings.end()),
                     std::vector<std::string>(distRowStrings.begin() + 1, distRowStrings.end()));

  std::cout << "day06" << std::endl;
  std::cout << ways << std::endl;
}

#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"

int waysToWin(int time, int dist) {
  int count = 0;
  for (int speed = 1; speed < time; speed++) {
    int remainingTime = time - speed;
    if (speed * remainingTime > dist) {
      count++;
    }
  }
  return count;
}

int main() {
  auto lines = readLines("input/input.txt");
  auto timeRowStrings = split(lines[0]);
  auto distRowStrings = split(lines[1]);

  int total = 1;
  for (int i = 1; i < timeRowStrings.size(); i++) {
    int time = stoi(timeRowStrings[i]);
    int dist = stoi(distRowStrings[i]);
    total *= waysToWin(time, dist);
  }

  std::cout << "day06" << std::endl;
  std::cout << total << std::endl;
}

#include <algorithm>
#include <iostream>
#include <vector>

#include "hand.h"
#include "utils.h"

int main() {
  std::vector<Hand> hands;
  for (const std::string& line : readLines("input/input.txt")) {
    auto words = split(line, ' ');
    hands.emplace_back(words[0], stoi(words[1]));
  }
  std::sort(hands.begin(), hands.end());
  int score = 0;
  for (int rank = 0; rank < hands.size(); rank++) {
    Hand hand = hands[rank];
    score += (rank + 1) * hand.getBid();
  }
  std::cout << "day07" << std::endl;
  std::cout << score << std::endl;
}

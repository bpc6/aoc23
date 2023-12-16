#include <algorithm>
#include <iostream>
#include <map>

#include "utils.h"

using optionsType = std::map<std::pair<int, int>, int>;

void insertOrIncreasePerm(optionsType& options, const std::pair<int, int>& key, int perm) {
  auto it = options.find(key);
  if (it != options.end()) {
    it->second += perm;
  } else {
    options[key] = perm;
  }
}

int countOptions(const std::string& springs, const std::vector<int>& nums) {
  optionsType options = {{std::make_pair(0, 0), 1}};
  for (char c : springs) {
    optionsType next;
    for (auto& [key, perms] : options) {
      auto& [group, amount] = key;
      if (group == nums.size()) {
        insertOrIncreasePerm(next, key, perms);
        continue;
      }
      if (c == '.' || c == '?') {
        if (amount == nums[group]) {
          insertOrIncreasePerm(next, {group + 1, 0}, perms);
        } else if (amount == 0) {
          insertOrIncreasePerm(next, {group, amount}, perms);
        }
      }
      if (c == '#' || c == '?') {
        if (amount < nums[group]) {
          insertOrIncreasePerm(next, {group, amount + 1}, perms);
        }
      }
    }
    options = next;
  }
  return options[{nums.size(), 0}];
}

int countOptions(const std::string& line) {
  auto lineParts = split(line);
  std::string springs = lineParts[0] + '.';
  auto nums = ints(lineParts[1], ',');

  return countOptions(springs, nums);
}

int main() {
  auto lines = readLines("input/input.txt");
  int sum = 0;
  for (const auto& line : lines) {
    int options = countOptions(line);
    sum += options;
  }
  std::cout << sum << std::endl;
}

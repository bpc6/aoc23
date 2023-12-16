#include <algorithm>
#include <iostream>
#include <limits>
#include <map>

#include "utils.h"

using optionsType = std::map<std::pair<int, int>, long int>;

void insertOrIncreasePerm(optionsType& options, const std::pair<int, int>& key, long int perm) {
  auto it = options.find(key);
  if (it != options.end()) {
    it->second += perm;
  } else {
    options[key] = perm;
  }
}

long int countOptions(const std::string& springs, const std::vector<int>& nums) {
  optionsType options = {{std::make_pair(0, 0), 1}};
  for (char c : springs) {
    optionsType next;
    for (auto& [key, perms] : options) {
      auto& [group, amount] = key;
      if (c == '.' || c == '?') {
        if (amount == 0) {
          insertOrIncreasePerm(next, {group, amount}, perms);
        } else if (amount == nums[group]) {
          insertOrIncreasePerm(next, {group + 1, 0}, perms);
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

long int countOptions(const std::string& line) {
  auto lineParts = split(line);
  std::string springsBase = lineParts[0];
  std::string springs = springsBase;
  auto numsBase = ints(lineParts[1], ',');
  std::vector<int> nums = numsBase;
  for (int i = 0; i < 4; i++) {
    springs += '?' + springsBase;
    std::copy(numsBase.begin(), numsBase.end(), std::back_inserter(nums));
  }
  springs += '.';

  return countOptions(springs, nums);
}

int main() {
  auto lines = readLines("input/input.txt");
  long int sum = 0;
  for (const auto& line : lines) {
    long int options = countOptions(line);
    sum += options;
  }
  std::cout << sum << std::endl;
  std::cout << std::numeric_limits<long int>::max() << std::endl;
}

#include <iostream>
#include <vector>

#include "utils.h"

bool adjacent_to_symbol(const std::vector<std::vector<char>>& m, const int i, const int j) {
  for (int ii = std::max(i - 1, 0); ii < std::min(i + 2, int(m.size())); ii++) {
    for (int jj = std::max(j - 1, 0); jj < std::min(j + 2, int(m[0].size())); jj++) {
      char c = m[ii][jj];
      if (c != '.' and not isdigit(c)) {
        return true;
      }
    }
  }
  return false;
}

int p1(std::vector<std::vector<char>> m) {
  std::vector<int> adjacents{}, nonadjacents{};

  for (int i = 0; i < m.size(); i++) {
    std::vector<char> curr_num{};
    bool adjacent = false;

    for (int j = 0; j < m[i].size(); j++) {
      char c = m[i][j];

      // if it's a number, figure out where it goes
      if (isdigit(c)) {
        curr_num.push_back(c);
        if (adjacent_to_symbol(m, i, j)) {
          adjacent = true;
        }
      }

      if ((not isdigit(c) or j == m[i].size() - 1) and not curr_num.empty()) {
        int num = stoi(std::string(curr_num.begin(), curr_num.end()));
        if (adjacent) {
          adjacents.push_back(num);
        } else {
          nonadjacents.push_back(num);
        }
        curr_num.clear();
        adjacent = false;
      }
    }
  }

  int sum = 0;
  for (int num : adjacents) {
    sum += num;
  }
  return sum;
}

int main() {
  int solution1 = p1(readCharMatrix("input/input.txt"));
  std::cout << solution1 << std::endl;
}

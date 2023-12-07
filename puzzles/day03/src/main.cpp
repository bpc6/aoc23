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
    std::vector<char> currNum{};
    bool adjacent = false;

    for (int j = 0; j < m[i].size(); j++) {
      char c = m[i][j];

      // if it's a number, figure out where it goes
      if (isdigit(c)) {
        currNum.push_back(c);
        if (adjacent_to_symbol(m, i, j)) {
          adjacent = true;
        }
      }

      if ((not isdigit(c) or j == m[i].size() - 1) and not currNum.empty()) {
        int num = stoi(std::string(currNum.begin(), currNum.end()));
        if (adjacent) {
          adjacents.push_back(num);
        } else {
          nonadjacents.push_back(num);
        }
        currNum.clear();
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

std::vector<int> find_adjacent_nums(const std::vector<std::vector<char>>& m, int i, int j) {
  std::vector<int> adjacents;
  for (int ii = std::max(i - 1, 0); ii < std::min(i + 2, int(m.size())); ii++) {
    for (int jj = std::max(j - 1, 0); jj < std::min(j + 2, int(m[0].size())); jj++) {
      char c = m[ii][jj];
      if (isdigit(c)) {
        while (jj - 1 >= 0 and isdigit(m[ii][jj - 1])) {
          jj--;
        }
        std::vector<char> currNum = {m[ii][jj]};
        while (jj + 1 < m[0].size() and isdigit(m[ii][jj + 1])) {
          currNum.push_back(m[ii][++jj]);
        }
        int num = stoi(std::string(currNum.begin(), currNum.end()));
        adjacents.push_back(num);
      }
    }
  }
  return adjacents;
}

int p2(std::vector<std::vector<char>> m) {
  int sum = 0;

  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[i].size(); j++) {
      char c = m[i][j];
      if (c == '*') {
        std::vector<int> adjacents = find_adjacent_nums(m, i, j);
        if (adjacents.size() == 2) {
          int gear_ratio = adjacents[0] * adjacents[1];
          sum += gear_ratio;
        }
      }
    }
  }
  return sum;
}

int main() {
  std::vector<std::vector<char>> mat = readCharMatrix("input/input.txt");
  int solution1 = p1(mat);
  std::cout << solution1 << std::endl;
  int solution2 = p2(mat);
  std::cout << solution2 << std::endl;
}

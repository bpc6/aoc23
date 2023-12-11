#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

#include "utils.h"

std::pair<int, int> nextPair(std::pair<int, int> currXY, std::pair<int, int> lastXY, char pipe) {
  auto [x, y] = currXY;
  if (pipe == '|') {
    if (lastXY.second != y + 1) {
      return std::make_pair(x, y + 1);
    }
    return std::make_pair(x, y - 1);
  } else if (pipe == '-') {
    if (lastXY.first != x + 1) {
      return std::make_pair(x + 1, y);
    }
    return std::make_pair(x - 1, y);
  } else if (pipe == '7') {
    if (lastXY.first != x - 1) {
      return std::make_pair(x - 1, y);
    }
    return std::make_pair(x, y + 1);
  } else if (pipe == 'F') {
    if (lastXY.first != x + 1) {
      return std::make_pair(x + 1, y);
    }
    return std::make_pair(x, y + 1);
  } else if (pipe == 'L') {
    if (lastXY.first != x + 1) {
      return std::make_pair(x + 1, y);
    }
    return std::make_pair(x, y - 1);
  } else if (pipe == 'J') {
    if (lastXY.first != x - 1) {
      return std::make_pair(x - 1, y);
    }
    return std::make_pair(x, y - 1);
  } else {
    std::ostringstream oss;
    oss << "invalid pipe: " << pipe << " at (" << x << ", " << y << ")";
    throw std::runtime_error(oss.str());
  }
}

std::pair<int, int> findS(std::vector<std::vector<char>> m) {
  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[0].size(); j++) {
      if (m[i][j] == 'S') {
        return std::make_pair(j, i);
      }
    }
  }
  return std::make_pair(-1, -1);
}

int main() {
  auto mat = readCharMatrix("input/input.txt");
  std::pair<int, int> last = findS(mat);
  std::pair<int, int> curr = std::make_pair(last.first, last.second + 1);  // down first
  int step = 1;
  while (mat[curr.second][curr.first] != 'S') {
    auto temp = nextPair(curr, last, mat[curr.second][curr.first]);
    last = curr;
    curr = temp;
    step++;
  }

  std::cout << step / 2 << std::endl;
}

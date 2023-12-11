#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

#include "utils.h"

void printMat(const std::vector<std::vector<char>>& m) {
  for (const auto& y : m) {
    for (char x : y) {
      std::cout << x;
    }
    std::cout << std::endl;
  }
  std::cout << "--------------------" << std::endl;
}

int count(const std::vector<std::vector<char>>& m, char c) {
  int sum = 0;
  for (const auto& y : m) {
    for (char x : y) {
      if (x == c) {
        sum++;
      };
    }
  }
  return sum;
}

void setRight(int x, int y, std::vector<std::vector<char>>& m, char c) {
  int num = x;
  for (int mx = x + 1; mx < m[y].size(); mx++) {
    if (m[y][mx] == '|' || m[y][mx] == '-' || m[y][mx] == 'J' || m[y][mx] == 'F' ||
        m[y][mx] == '7' || m[y][mx] == 'L') {
      num = mx - 1;
      break;
    }
  }
  for (int mx = x + 1; mx <= num; mx++) {
    m[y][mx] = c;
  }
}

void setLeft(int x, int y, std::vector<std::vector<char>>& m, char c) {
  int num = x;
  for (int mx = x - 1; mx >= 0; mx--) {
    if (m[y][mx] == '|' || m[y][mx] == '-' || m[y][mx] == 'J' || m[y][mx] == 'F' ||
        m[y][mx] == '7' || m[y][mx] == 'L') {
      num = mx + 1;
      break;
    }
  }
  for (int mx = x - 1; mx >= num; mx--) {
    m[y][mx] = c;
  }
}

std::pair<int, int> goDown(int x, int y, std::vector<std::vector<char>>& m) {
  setLeft(x, y, m, 'O');
  setRight(x, y, m, 'I');
  return std::make_pair(x, y + 1);
}

std::pair<int, int> goUp(int x, int y, std::vector<std::vector<char>>& m) {
  setLeft(x, y, m, 'I');
  setRight(x, y, m, 'O');
  return std::make_pair(x, y - 1);
}

std::pair<int, int> nextPair(std::pair<int, int> currXY, std::pair<int, int> lastXY, char pipe,
                             std::vector<std::vector<char>>& m) {
  auto [x, y] = currXY;
  if (pipe == '|') {
    if (lastXY.second != y + 1) {
      return goDown(x, y, m);
    }
    return goUp(x, y, m);
  } else if (pipe == '-') {
    if (lastXY.first != x + 1) {
      return std::make_pair(x + 1, y);
    }
    return std::make_pair(x - 1, y);
  } else if (pipe == '7') {
    if (lastXY.first != x - 1) {
      setRight(x, y, m, 'O');
      //      setLeft(x, y, m, 'I');
      return std::make_pair(x - 1, y);
    }
    return goDown(x, y, m);
  } else if (pipe == 'F') {
    if (lastXY.first != x + 1) {
      setLeft(x, y, m, 'I');
      //      setRight(x, y, m, 'I');
      return std::make_pair(x + 1, y);
    }
    return goDown(x, y, m);
  } else if (pipe == 'L') {
    if (lastXY.first != x + 1) {
      setLeft(x, y, m, 'O');
      //      setRight(x, y, m, 'I');
      return std::make_pair(x + 1, y);
    }
    return goUp(x, y, m);
  } else if (pipe == 'J') {
    if (lastXY.first != x - 1) {
      setRight(x, y, m, 'I');
      //      setLeft(x, y, m, 'I');
      return std::make_pair(x - 1, y);
    }
    return goUp(x, y, m);
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

std::vector<std::vector<char>> emptyMat(int w, int h) {
  std::vector<std::vector<char>> m;
  m.reserve(h);
  for (int i = 0; i < h; i++) {
    m.emplace_back(w, '.');
  }
  return m;
}

int main() {
  auto mat = readCharMatrix("input/input.txt");
  auto model = emptyMat(int(mat[0].size()), int(mat.size()));

  std::pair<int, int> last = findS(mat);
  model[last.second][last.first] = 'S';

  std::pair<int, int> curr = std::make_pair(last.first, last.second + 1);  // down first

  int step = 1;
  while (mat[curr.second][curr.first] != 'S') {
    model[curr.second][curr.first] = mat[curr.second][curr.first];
    auto temp = nextPair(curr, last, mat[curr.second][curr.first], model);
    //    printMat(model);
    last = curr;
    curr = temp;
    step++;
  }
  printMat(model);
  int is = count(model, 'I');
  int os = count(model, 'O');

  std::cout << step / 2 << std::endl;
  std::cout << "Is: " << is << std::endl;
  std::cout << "Os: " << os << std::endl;
}

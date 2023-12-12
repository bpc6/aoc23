#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"

std::vector<std::pair<int64_t, int64_t>> expandedCoordinates(std::vector<std::vector<char>> mat,
                                                             int expansionRate) {
  std::vector<std::pair<int64_t, int64_t>> coords;
  int64_t yExpansion = 0;
  for (int y = 0; y < mat.size(); y++) {
    bool inRow = false;
    for (int x = 0; x < mat[0].size(); x++) {
      if (mat[y][x] == '#') {
        coords.emplace_back(x, y + yExpansion);
        inRow = true;
      }
    }
    yExpansion += !inRow * (expansionRate - 1);
  }
  std::sort(coords.begin(), coords.end(),
            [](const std::pair<int64_t, int64_t>& a, const std::pair<int64_t, int64_t>& b) {
              return a.first < b.first;
            });
  int64_t xExpansion = 0;
  int64_t lastX = 0;
  for (auto& coord : coords) {
    xExpansion += std::max(coord.first - lastX - 1, static_cast<int64_t>(0)) * (expansionRate - 1);
    lastX = coord.first;
    coord.first += xExpansion;
  }
  return coords;
}

using pairIter = std::vector<std::pair<int64_t, int64_t>>::iterator;
int64_t accumulatedDistances(pairIter it, pairIter end) {
  if (it == end) {
    return 0;
  }
  auto curr = *it;
  auto next = (it + 1);
  int64_t sum = 0;
  for (advance(it, 1); it != end; ++it) {
    sum += std::abs(curr.first - it->first) + std::abs(curr.second - it->second);
  }
  return sum + accumulatedDistances(next, end);
}

int main() {
  auto mat = readCharMatrix("input/input.txt");
  auto coords = expandedCoordinates(mat, 1000000);

  int64_t total = accumulatedDistances(coords.begin(), coords.end());
  std::cout << total << std::endl;
}

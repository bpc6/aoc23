#include <iostream>
#include <sstream>
#include <vector>

#include "read_lines.h"

std::vector<std::string> split(const std::string& s, char delim) {
  std::vector<std::string> result;
  std::stringstream ss(s);
  std::string item;

  while (getline(ss, item, delim)) {
    result.push_back(item);
  }
  return result;
}

bool game_is_possible(const std::string& game_string) {
  for (const std::string& round_string : split(game_string, ';')) {
    int red = 0, blue = 0, green = 0;
    for (const std::string& color_count : split(round_string, ',')) {
      std::vector<std::string> seq = split(color_count, ' ');
      if (seq[2] == "blue") {
        blue = stoi(seq[1]);
      } else if (seq[2] == "red") {
        red = stoi(seq[1]);
      } else {
        green = stoi(seq[1]);
      }
    }
    if (red > 12 or green > 13 or blue > 14) {
      return false;
    }
  }
  return true;
}

int main() {
  std::vector<std::string> lines = readLines("input/input.txt");
  int count = 1;
  int sum = 0;
  for (const std::string& line : lines) {
    if (game_is_possible(split(line, ':')[1])) {
      sum += count;
    }
    count++;
  }

  std::cout << sum << std::endl;
}

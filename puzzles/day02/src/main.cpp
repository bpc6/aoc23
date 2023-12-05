#include <iostream>
#include <vector>

#include "utils.h"

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

int game_power(const std::string& game_string) {
  int maxR = -1, maxG = -1, maxB = -1;
  for (const std::string& round_string : split(game_string, ';')) {
    for (const std::string& color_count : split(round_string, ',')) {
      std::vector<std::string> seq = split(color_count, ' ');
      int num_color = stoi(seq[1]);
      if (seq[2] == "blue" and num_color > maxB) {
        maxB = num_color;
      } else if (seq[2] == "green" and num_color > maxG) {
        maxG = num_color;
      } else if (seq[2] == "red" and num_color > maxR) {
        maxR = num_color;
      }
    }
  }
  return maxR * maxG * maxB;
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

  sum = 0;
  for (const std::string& line : lines) {
    sum += game_power(split(line, ':')[1]);
  }
  std::cout << sum << std::endl;
}

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> readLines(const std::string& file_path) {
  std::ifstream file(file_path);
  if (!file.is_open()) {
    throw std::runtime_error("Error opening the file.");
  }

  std::vector<std::string> lines;
  std::string line;

  while (std::getline(file, line)) {
    lines.push_back(line);
  }
  file.close();
  return lines;
}

const std::vector<std::string> INT_STRINGS = {"one", "two",   "three", "four", "five",
                                              "six", "seven", "eight", "nine"};

int firstNumOrText(const std::string& s, const std::vector<std::string>& int_strings) {
  for (std::string::size_type i = 0; i < s.size(); ++i) {
    if (isdigit(s[i])) {
      return s[i] - '0';
    }
    std::string substring = s.substr(i);
    for (int j = 0; j < int_strings.size(); ++j) {
      if (substring.rfind(int_strings[j], 0) == 0) {
        return j + 1;
      }
    }
  }
}

int lastNumOrText(std::string s, std::vector<std::string> int_strings) {
  for (auto& int_string : int_strings) {
    std::reverse(int_string.begin(), int_string.end());
  }
  reverse(s.begin(), s.end());
  return firstNumOrText(s, int_strings);
}

int day01(const std::vector<std::string>& lines) {
  int sum = 0;
  for (const auto& l : lines) {
    sum += firstNumOrText(l, INT_STRINGS) * 10 + lastNumOrText(l, INT_STRINGS);
  }
  std::cout << sum << std::endl;
  return EXIT_SUCCESS;
}

int main() {
  day01(readLines("input/input.txt"));
  return EXIT_SUCCESS;
}

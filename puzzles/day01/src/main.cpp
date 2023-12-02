#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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


int firstNum(const std::string& s) {
  for (const char& c : s) {
    if (isdigit(c)) {
      return c - '0';
    }
  }
  throw std::runtime_error("No number found");
}

int lastNum(const std::string& s) {
  for (std::string::const_reverse_iterator it = s.rbegin(); it != s.rend(); ++it) {
    if (isdigit(*it)) {
      return *it - '0';
    }
  }
}


int main() {
  std::string file_path = "input/input.txt";
  std::vector<std::string> lines = readLines(file_path);

  int sum = 0;
  for (const auto& l : lines) {
    sum += firstNum(l) * 10 + lastNum(l);
  }
  std::cout << sum << std::endl;
  return EXIT_SUCCESS;
}

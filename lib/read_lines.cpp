#include "read_lines.h"

#include <fstream>

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

#include "utils.h"

#include <fstream>
#include <sstream>

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

std::vector<std::vector<char>> readCharMatrix(const std::string& file_path) {
  std::ifstream file(file_path);
  if (!file.is_open()) {
    throw std::runtime_error("Error opening the file.");
  }

  std::vector<std::vector<char>> mat;
  std::string line;

  while (std::getline(file, line)) {
    mat.emplace_back(line.begin(), line.end());
  }
  file.close();
  return mat;
}

std::vector<std::string> split(const std::string& s, char delim) {
  std::vector<std::string> result;
  std::stringstream ss(s);
  std::string item;

  while (getline(ss, item, delim)) {
    result.push_back(item);
  }
  return result;
}

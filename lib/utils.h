#ifndef AOC23_UTILS_H
#define AOC23_UTILS_H

#include <string>
#include <vector>

std::string readFile(const std::string& file_path);
std::vector<std::string> readLines(const std::string& file_path);
std::vector<std::vector<char>> readCharMatrix(const std::string& file_path);
std::vector<std::string> split(const std::string& s, char delim);
std::vector<std::string> split(const std::string& s, const std::string& delimiter);
std::vector<std::string> split(std::string const& input);

#endif  // AOC23_UTILS_H

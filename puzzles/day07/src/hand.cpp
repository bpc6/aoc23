#include "hand.h"

#include <algorithm>
#include <stdexcept>
#include <unordered_map>

std::unordered_map<char, int> VALUES = {{'T', 10}, {'J', 1}, {'Q', 12}, {'K', 13}, {'A', 14}};

Hand::Hand(const std::string& cardString, int bid) : bid(bid) {
  cards.clear();
  std::vector<std::vector<char>> scorer(5, std::vector<char>());
  int jCount = 0;
  for (const char& c : cardString) {
    int value;
    if (isdigit(c)) {
      value = c - '0';
    } else {
      value = VALUES[c];
    }
    cards.push_back(value);

    if (c == 'J') {
      jCount++;
    } else {
      for (std::vector<char>& place : scorer) {
        if (place.empty() or place.back() == c) {
          place.push_back(c);
          break;
        }
      }
    }
  }
  std::sort(
      scorer.begin(), scorer.end(),
      [](const std::vector<char>& a, const std::vector<char>& b) { return b.size() < a.size(); });
  for (int i = 0; i < jCount; i++) {
    scorer[0].push_back('J');
  }
  if (scorer[0].size() == 5) {
    handType = 6;
  } else if (scorer[0].size() == 4) {
    handType = 5;
  } else if (scorer[0].size() == 3 and scorer[1].size() == 2) {
    handType = 4;
  } else if (scorer[0].size() == 3) {
    handType = 3;
  } else if (scorer[0].size() == 2 and scorer[1].size() == 2) {
    handType = 2;
  } else if (scorer[0].size() == 2) {
    handType = 1;
  } else if (scorer[0].size() == 1) {
    handType = 0;
  } else {
    throw std::runtime_error("Undefined hand");
  }
}

bool Hand::operator<(const Hand& other) const {
  if (handType == other.handType) {
    for (int i = 0; i < cards.size(); i++) {
      if (cards[i] != other.cards[i]) {
        return cards[i] < other.cards[i];
      }
    }
    return false;  // they are equal
  }
  return handType < other.handType;
}
int Hand::getBid() const { return bid; }

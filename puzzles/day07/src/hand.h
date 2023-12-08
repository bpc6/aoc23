#ifndef AOC23_HAND_H
#define AOC23_HAND_H

#include <string>
#include <vector>

class Hand {
 private:
  std::vector<int> cards;
  int bid;
  int handType;

 public:
  Hand(const std::string& cardString, int bid);
  bool operator<(const Hand& other) const;
  int getBid() const;
};

#endif  // AOC23_HAND_H

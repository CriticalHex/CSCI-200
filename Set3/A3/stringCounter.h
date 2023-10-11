#ifndef STRINGCOUNTER_H
#define STRINGCOUNTER_H

#include <string>
#include <vector>

class StringCounter {
private:
  std::vector<std::string> _allWords;
  std::vector<unsigned int> _letterCounts;
  unsigned int _totalLetterCount = 0;

public:
  StringCounter();
  ~StringCounter();
  void readAllWords(std::istream &, std::string);
  const void printLetterCounts(std::ostream &);
  const void printLetterStats(std::ostream &);
  const std::vector<std::string> getAllWords();
};

#endif // STRINGCOUNTER_H
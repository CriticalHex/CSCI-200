#ifndef STRINGFILTER_H
#define STRINGFILTER_H

#include <iostream>
#include <string>
#include <vector>

class StringFilter {
private:
  std::vector<std::string> _uniqueWords;
  std::vector<uint32_t> _wordCounts;
  uint32_t _totalWordCount = 0;
  uint16_t _longestWordLength = 0;

public:
  StringFilter();
  ~StringFilter();
  void addWords(std::vector<std::string>);
  const void printUniqueWordCounts(std::ostream &);
  const void printUniqueWordStats(std::ostream &);
  const std::vector<std::string> getUniqueWords();
};

#endif // STRINGFILTER_H
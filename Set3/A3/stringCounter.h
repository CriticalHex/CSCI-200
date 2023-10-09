#include <string>
#include <vector>

class StringCounter {
private:
  std::vector<std::string> allWords;
  std::vector<unsigned int> letterCounts;
  unsigned int totalLetterCount;

public:
  StringCounter();
  ~StringCounter();
  void readAllWords(std::istream &, std::string);
  void printLetterCount(std::ostream &);
  void printLetterStats(std::ostream &);
  std::vector<std::string> getAllWords();
};

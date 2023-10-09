#include "stringCounter.h"
#include <iostream>

using namespace std;

StringCounter::StringCounter() {}
StringCounter::~StringCounter() {}
void StringCounter::readAllWords(istream &in, string textToFilter) {
  string word;
  string upper;
  bool passed;
  while (in >> word) {
    for (char c : word) {
      passed = true;
      for (char o : textToFilter) {
        if (o == c)
          passed = false;
      }
      if (passed)
        upper += toupper(c);
    }
    allWords.push_back(upper);
    upper = "";
    word = "";
  }
}
void StringCounter::printLetterCount(ostream &out) {}
void StringCounter::printLetterStats(ostream &out) {}
vector<string> StringCounter::getAllWords() { return allWords; }
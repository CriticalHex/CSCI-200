#include "stringCounter.h"
#include "algorithm.h"
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
/**
 * @brief Construct a new StringCounter object
 *
 */
StringCounter::StringCounter() {
  // reinitialize to a vector of 26 0s
  _letterCounts = vector<uint32_t>(26, 0);
}

/**
 * @brief Destroy the StringCounter object
 *
 */
StringCounter::~StringCounter() {
  _allWords.clear();
  _letterCounts.clear();
}

/**
 * @brief Read all words in the provided file stream, converting them to
 * uppercase, and removing characters provided
 *
 * @param in the filestream to read from
 * @param textToFilter the characters to remove
 */
void StringCounter::readAllWords(istream &in, string textToFilter) {
  string word;
  string upper;
  char letter;
  bool passed;
  while (in >> word) {
    for (char c : word) {
      passed = true;
      for (char o : textToFilter) {
        if (o == c)
          passed = false;
      }
      if (passed) {
        letter = toupper(c);
        upper += letter;
        _totalLetterCount++;
        // indexing based on ascii value of the letter
        _letterCounts[(int)letter - 65]++;
      }
    }
    _allWords.push_back(upper);
    upper = "";
    word = "";
  }
}

/**
 * @brief Print the counts of each letter to the provided output stream
 *
 * @param out the output stream to write to
 */
const void StringCounter::printLetterCounts(ostream &out) {
  // uint32_t is (barely) short for unsigned int
  const uint32_t largest =
      to_string(*max_element(_letterCounts.begin(), _letterCounts.end()))
          .size();

  for (int i = 0; i < 26; i++) {
    out << (char)(i + 65) << ": " << setw(largest) << right << _letterCounts[i]
        << endl;
  }
}

/**
 * @brief Print the most and least frequently used letter
 *
 * @param out the output stream to write to
 */
const void StringCounter::printLetterStats(ostream &out) {
  uint32_t maxIndex = max_element(_letterCounts.begin(), _letterCounts.end()) -
                      _letterCounts.begin();
  uint32_t minIndex = min_element(_letterCounts.begin(), _letterCounts.end()) -
                      _letterCounts.begin();
  uint32_t maxVal = _letterCounts[maxIndex];
  uint32_t minVal = _letterCounts[minIndex];
  float maxPercent = (maxVal * 100.0f) / _totalLetterCount;
  float minPercent = (minVal * 100.0f) / _totalLetterCount;
  const uint32_t countSize = to_string(maxVal).size();
  out << " Most Frequent Letter: " << (char)(maxIndex + 65) << " "
      << setw(countSize) << right << maxVal << " (" << setw(7) << right << fixed
      << setprecision(3) << maxPercent << "%)" << endl;
  out << "Least Frequent Letter: " << (char)(minIndex + 65) << " "
      << setw(countSize) << right << minVal << " (" << setw(7) << right << fixed
      << setprecision(3) << minPercent << "%)" << endl;
}

/**
 * @brief Get the Counter member variable allWords
 *
 * @return vector<string> vector of capitilized words, with filtered characters
 * removed
 */
const vector<string> StringCounter::getAllWords() { return _allWords; }
#include "stringFilter.h"
#include "algorithm.h"
#include <iomanip>

using namespace std;

/**
 * @brief Construct a new StringFilter object
 *
 */
StringFilter::StringFilter() {}

/**
 * @brief Destroy the StringFilter object
 *
 */
StringFilter::~StringFilter() {
  _uniqueWords.clear();
  _wordCounts.clear();
}

/**
 * @brief initialize the filter with words.
 * unique words are identified and counted.
 *
 * @param words vector of words to add to the filter
 */
void StringFilter::addWords(std::vector<std::string> words) {
  _totalWordCount = words.size();
  int len;
  for (string word : words) {
    auto found = find(_uniqueWords.begin(), _uniqueWords.end(), word);
    if (found == _uniqueWords.end()) {
      // if the word wasn't found in already added words
      len = word.length();
      if (len > _longestWordLength)
        _longestWordLength = len;
      _uniqueWords.push_back(word);
    }
  }
  string uniqueWord;
  for (uint32_t i = 0; i < _uniqueWords.size(); i++) {
    uniqueWord = _uniqueWords[i];
    _wordCounts.push_back(0);
    for (string word : words) {
      if (word == uniqueWord) {
        _wordCounts[i]++;
      }
    }
  }
}

/**
 * @brief print the count of each word in allWords
 *
 * @param out the output stream to write to
 */
const void StringFilter::printUniqueWordCounts(std::ostream &out) {
  const uint32_t largest =
      to_string(*max_element(_wordCounts.begin(), _wordCounts.end())).size();

  for (uint32_t i = 0; i < _wordCounts.size(); i++) {
    out << setw(_longestWordLength) << left << _uniqueWords[i] << " : "
        << setw(largest) << right << _wordCounts[i] << endl;
  }
}

/**
 * @brief prrint the most and least frequent word in the data set
 *
 * @param out the output stream to write to
 */
const void StringFilter::printUniqueWordStats(std::ostream &out) {
  uint32_t maxIndex =
      max_element(_wordCounts.begin(), _wordCounts.end()) - _wordCounts.begin();
  uint32_t minIndex =
      min_element(_wordCounts.begin(), _wordCounts.end()) - _wordCounts.begin();
  uint32_t maxVal = _wordCounts[maxIndex];
  uint32_t minVal = _wordCounts[minIndex];
  uint16_t minLen = _uniqueWords[minIndex].size();
  uint16_t maxLen = _uniqueWords[maxIndex].size();
  uint16_t longer = max(minLen, maxLen);
  float maxPercent = (maxVal * 100.0f) / _totalWordCount;
  float minPercent = (minVal * 100.0f) / _totalWordCount;
  const uint32_t countSize = to_string(maxVal).size();
  out << " Most Frequent Word: " << setw(longer) << left
      << _uniqueWords[maxIndex] << " " << setw(countSize) << right << maxVal
      << " ( " << setw(6) << right << fixed << setprecision(3) << maxPercent
      << "%)" << endl;
  out << "Least Frequent Word: " << setw(longer) << left
      << _uniqueWords[minIndex] << " " << setw(countSize) << right << minVal
      << " ( " << setw(6) << right << fixed << setprecision(3) << minPercent
      << "%)" << endl;
}

/**
 * @brief return member variable uniqueWords
 *
 * @return std::vector<std::string> uniqueWords
 */
const std::vector<std::string> StringFilter::getUniqueWords() {
  return _uniqueWords;
}

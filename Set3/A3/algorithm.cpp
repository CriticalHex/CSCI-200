#include "algorithm.h"

using namespace std;
/**
 * @brief self implemented max_element from algorithm
 *
 * @param start
 * @param end
 * @return vector<uint32_t>::iterator
 */
vector<uint32_t>::iterator max_element(vector<uint32_t>::iterator start,
                                       vector<uint32_t>::iterator end) {
  uint32_t largest = 0;
  vector<uint32_t>::iterator largestIndex;
  for (auto it = start; it != end; it++) {
    if ((*it) > largest) {
      largest = (*it);
      largestIndex = it;
    }
  }
  return largestIndex;
}

/**
 * @brief self implemented min_element from algorithm
 *
 * @param start
 * @param end
 * @return vector<uint32_t>::iterator
 */
vector<uint32_t>::iterator min_element(vector<uint32_t>::iterator start,
                                       vector<uint32_t>::iterator end) {
  uint32_t smallest = -1;
  vector<uint32_t>::iterator smallestIndex;
  for (auto it = start; it != end; it++) {
    if ((*it) < smallest) {
      smallest = (*it);
      smallestIndex = it;
    }
  }
  return smallestIndex;
}

/**
 * @brief self implemented find from algorithm
 *
 * @param start
 * @param end
 * @param value to find
 * @return vector<string>::iterator
 */
vector<string>::iterator find(vector<string>::iterator start,
                              vector<string>::iterator end, string value) {
  for (auto it = start; it != end; it++) {
    if ((*it) == value) {
      return it;
    }
  }
  return end;
}
#include "string_functions.h"

#include <iostream>

using namespace std;

unsigned long string_length(const string STR) { return STR.length(); }

char string_char_at(const string STR, const int IDX) { return STR[IDX]; }

string string_append(const string LEFT, const string RIGHT) {
  return LEFT + RIGHT;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
  string result = STR;
  result.insert(IDX, TO_INSERT);
  return result;
}

size_t string_find(const string STR, const char C) { return STR.find(C); }

string string_substring(const string STR, const int IDX, const int LEN) {
  return STR.substr(IDX, LEN);
}

string string_replace(const string STR, const string TEXT_TO_REPLACE,
                      const string REPLACE_WITH) {
  string result = STR;
  const int IDX = STR.find(TEXT_TO_REPLACE);
  if (IDX == -1)
    return result;
  result.replace(IDX, TEXT_TO_REPLACE.length(), REPLACE_WITH);
  return result;
}

string string_first_word(const string STR) {
  const int IDX = STR.find(' ');
  return STR.substr(0, IDX);
}

string string_remove_first_word(const string STR) {
  const int IDX = STR.find(' ');
  if (IDX == -1)
    return "";
  return STR.substr(IDX + 1);
}

string string_second_word(const string STR) {
  string result = string_remove_first_word(STR);
  return string_first_word(result);
}

string string_third_word(const string STR) {
  string result = STR;
  for (int i = 0; i < 2; i++) {
    if (result.find(' ') == 0)
      result = string_remove_first_word(result.substr(1));
    else if ((int)result.find(' ') != -1)
      result = string_remove_first_word(result);
    else
      return "";
  }
  return string_first_word(result);
}

string string_nth_word(const string STR, const int N) {
  string result = STR;
  for (int i = 0; i < N - 1; i++) {
    if (result.find(' ') == 0)
      result = string_remove_first_word(result.substr(1));
    else if ((int)result.find(' ') != -1)
      result = string_remove_first_word(result);
    else
      return "";
  }
  return string_first_word(result);
}

vector<string> string_tokenize(const string STR, const char DELIMINATOR) {
  vector<string> result;
  int start = 0, stop = 0;
  while (stop != -1 && start != -1) {
    stop = STR.find(DELIMINATOR, start);
    result.push_back(STR.substr(start, stop - start));
    start = stop + 1;
  }
  return result;
}

string string_substitute(const string STR, const char TARGET,
                         const char REPLACEMENT) {
  string result = STR;
  int index = 0;
  while (1) {
    index = result.find(TARGET);
    if (index == -1)
      break;
    result.replace(index, 1, string(1, REPLACEMENT));
  }
  return result;
}

string string_to_lower(const string STR) {
  string result;
  for (int i = 0; i < (int)STR.length(); i++) {
    result += tolower(STR[i]);
  }
  return result;
}

string string_to_upper(const string STR) {
  string result;
  for (int i = 0; i < (int)STR.length(); i++) {
    result += toupper(STR[i]);
  }
  return result;
}

int string_compare(const string LHS, const string RHS) {
  int result = LHS.compare(RHS);
  return (result != 0) ? (result > 0) ? 1 : -1 : 0;
}
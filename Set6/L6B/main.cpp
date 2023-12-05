#include <iostream>
using namespace std;

#include "Array.hpp"
#include "LinkedList.hpp"
template <typename T> void testArraySort(T *toSort, int size) {
  Array<T> list;
  for (int i = 0; i < size; i++) {
    list.insert(size, toSort[i]);
  }
  cout << "Sorting an array:" << endl;
  cout << "Initial array: ";
  for (int i = 0; i < list.size(); i++) {
    cout << list.get(i) << " ";
  }
  cout << endl;
  list.sort();
  cout << "Sorted array: ";
  for (int i = 0; i < list.size(); i++) {
    cout << list.get(i) << " ";
  }
  cout << endl;
}

template <typename T> void testLinkedListSort(T *toSort, int size) {
  LinkedList<T> list;
  for (int i = 0; i < size; i++) {
    list.insert(size, toSort[i]);
  }
  cout << "Sorting a Linked List:" << endl;
  cout << "Initial list: ";
  for (int i = 0; i < list.size(); i++) {
    cout << list.get(i) << " ";
  }
  cout << endl;
  list.sort();
  cout << "Sorted list: ";
  for (int i = 0; i < list.size(); i++) {
    cout << list.get(i) << " ";
  }
  cout << endl;
}

void promptInt(int *value, string prompt) {
  while (true) {
    cout << prompt;
    cin >> *value;
    if (!cin.fail())
      break;

    cin.clear();
    char badChar = ' ';
    do {
      badChar = cin.get();
    } while (badChar != '\n');
  }
}

int randint(const int MIN, const int MAX) {
  return MIN + (rand() % (MAX - MIN + 1));
}

int main() {
  srand(time(NULL));
  int intSort[] = {4, 3, 8, 1, 5, 9, 7, 2, 6};
  string stringSort[] = {"dog", "cat", "bird", "elephant"};
  testArraySort(intSort, 9);
  cout << endl;
  testLinkedListSort(intSort, 9);
  cout << endl;
  testLinkedListSort(stringSort, 4);
  cout << endl;
  cout << "Testing search:" << endl;
  IList<int> *list;
  int method, length, minimum, maximum, searches, searchFor;
  promptInt(&method, "Which list do you wish to test? 1 - Array 2 - "
                     "LinkedList: ");
  if (method != 1 && method != 2)
    method = 1;
  switch (method) {
  case 1: {
    list = new Array<int>;
    break;
  }
  case 2: {
    list = new LinkedList<int>;
    break;
  }
  }
  promptInt(&length, "How many values would you like in the list?: ");
  promptInt(&minimum,
            "What is the minimum value you would like in the list?: ");
  promptInt(&maximum,
            "What is the maximum value you would like in the list?: ");
  for (int i = 0; i < length; i++) {
    list->insert(list->size(), randint(minimum, maximum));
  }
  list->sort();
  cout << "Sorted list: ";
  for (int i = 0; i < list->size(); i++) {
    cout << list->get(i) << " ";
  }
  cout << endl;
  promptInt(&searches, "How many numbers would you like to search for?: ");
  for (int i = 0; i < searches; i++) {
    promptInt(&searchFor, "What number would you like to search for?: ");
    cout << "Value is found at position " << list->search(searchFor) << "."
         << endl;
  }
  return 0;
}
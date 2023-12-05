#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template <typename T> class LinkedList final : public IList<T> {
public:
  LinkedList();
  ~LinkedList();

  int size() const override;
  T get(const int POS) const override;
  void set(const int POS, const T VALUE) override;
  void insert(const int POS, const T VALUE) override;
  void remove(const int POS) override;
  T min() const override;
  T max() const override;
  int find(const T VALUE) const override;

private:
  struct Node {
    T value;
    Node *pNext;
    Node *pPrev;
  };

  Node *_pHead;
  Node *_pTail;
  int _size;
};

//---------------------------------------------------------

template <typename T> LinkedList<T>::LinkedList() {
  // set size to zero
  _size = 0;
  // set head to be a nullptr
  _pHead = nullptr;
  // set tail to be a nullptr
  _pTail = nullptr;
}

template <typename T> LinkedList<T>::~LinkedList() {
  // remove each node in the list
  Node *node = _pHead;
  Node *tempNode = nullptr;
  while (node) {
    tempNode = node->pNext;
    delete node;
    node = tempNode;
  }
  node = tempNode = nullptr;
}

template <typename T> int LinkedList<T>::size() const { return _size; }

template <typename T> T LinkedList<T>::get(const int POS) const {
  // if POS is out of range, throw std::out_of_range exception
  if (POS >= _size || POS < 0)
    throw std::out_of_range("OUT OF RANGE");
  Node *node = _pHead;
  if (_size / 2 > POS) {
    // advance current node to POS
    for (int i = 0; i < POS; i++) {
      node = node->pNext;
    }
  } else {
    node = _pTail;
    for (int i = _size - 1; i > POS; i--) {
      node = node->pPrev;
    }
  }
  // return value of current node
  return node->value;
}

template <typename T> void LinkedList<T>::set(const int POS, const T VALUE) {
  // if POS is out of range, throw std::out_of_range exception
  if (POS >= _size || POS < 0)
    throw std::out_of_range("OUT OF RANGE");
  // set current node to head
  Node *node = _pHead;
  if (_size / 2 > POS) {
    // advance current node to POS
    for (int i = 0; i < POS; i++) {
      node = node->pNext;
    }
  } else {
    node = _pTail;
    for (int i = _size - 1; i > POS; i--) {
      node = node->pPrev;
    }
  }
  // set value of current node
  node->value = VALUE;
}

template <typename T> void LinkedList<T>::insert(int pos, const T VALUE) {
  // if POS is before zero, clamp to zero
  if (pos < 0)
    pos = 0;
  // if POS is after size, clamp to size
  if (pos > _size)
    pos = _size;
  // create pointer to new node
  Node *newNode = new Node;
  // set value to be VALUE
  newNode->value = VALUE;
  // set previous pointer to nullptr
  newNode->pPrev = nullptr;
  // set next pointer to nullptr
  newNode->pNext = nullptr;
  // if list is currently empty
  if (_size == 0) {
    // set head and tail to new node
    _pHead = newNode;
    _pTail = newNode;
  }
  // otherwise if position is before head
  else if (pos == 0) {
    // set new node next to be head
    newNode->pNext = _pHead;
    // set head previous to be new node
    _pHead->pPrev = newNode;
    // set head to be new ndoe
    _pHead = newNode;
  }
  // else if position is after tail
  else if (pos == _size) {
    // set new node previous to be tail
    newNode->pPrev = _pTail;
    // set tail next to be new node
    _pTail->pNext = newNode;
    // set tail to be new ndoe
    _pTail = newNode;
  }
  // otherwise
  else {
    // set current node to head
    Node *node = _pHead;
    if (_size / 2 > pos) {
      // advance current node to position
      for (int i = 0; i < pos; i++) {
        node = node->pNext;
      }
    } else {
      node = _pTail;
      for (int i = _size - 1; i > pos; i--) {
        node = node->pPrev;
      }
    }
    // link new node into current list
    node->pPrev->pNext = newNode;
    newNode->pPrev = node->pPrev;
    newNode->pNext = node;
    // link current list to new node
    node->pPrev = newNode;
  }
  // increment size
  _size++;
}

template <typename T> void LinkedList<T>::remove(int pos) {
  // if array is empty, throw std::out_of_range exception
  if (_size == 0)
    throw std::out_of_range("EMPTY ARRAY");
  // if POS is before zero, clamp to zero
  if (pos < 0)
    pos = 0;
  // if POS is after size, clamp to size
  if (pos > _size)
    pos = _size;
  Node *deleting = nullptr;
  // if list has one element
  if (_size == 1) {
    // set node to delete to head
    deleting = _pHead;
    // set head and tail to be nullptr
    _pHead = _pTail = nullptr;
  }
  // otherwise if deleting head
  else if (pos == 0) {
    // set node to delete to head
    deleting = _pHead;
    // advance head to next
    _pHead = _pHead->pNext;
    // set head previous to nullptr
    _pHead->pPrev = nullptr;
  }
  // else if deleting tail
  else if (pos >= _size - 1) { // the pos of tail or greater
    // set node to delete to tail
    deleting = _pTail;
    // step tail to previous
    _pTail = _pTail->pPrev;
    // set tail next to nullptr
    _pTail->pNext = nullptr;
  }
  // otherwise
  else {
    // set current node to head
    Node *node = _pHead;
    // advance current node to space before position
    if (_size / 2 > pos) {
      // advance current node to position
      for (int i = 0; i < pos; i++) {
        node = node->pNext;
      }
    } else {
      node = _pTail;
      for (int i = _size - 1; i > pos; i--) {
        node = node->pPrev;
      }
    }
    // set node to delete to the current node's next node
    deleting = node;
    // unlink node to delete
    node->pPrev->pNext = node->pNext;
    node->pNext->pPrev = node->pPrev;
  }
  // delete node
  delete deleting;
  // decrement size
  _size--;
}

template <typename T> T LinkedList<T>::min() const {
  // if list is empty, throw std::out_of_range exception
  if (_size == 0) {
    throw std::out_of_range("LIST EMPTY");
  }
  // find minimum value within list
  Node *node = _pHead;
  T smallest = node->value;
  for (int i = 1; i < _size; i++) {
    node = node->pNext;
    if (smallest > node->value)
      smallest = node->value;
  }
  // return min value
  return smallest;
}

template <typename T> T LinkedList<T>::max() const {
  // if list is empty, throw std::out_of_range exception
  if (_size == 0) {
    throw std::out_of_range("LIST EMPTY");
  }
  // find maximum value within list
  Node *node = _pHead;
  T largest = node->value;
  for (int i = 1; i < _size; i++) {
    node = node->pNext;
    if (largest < node->value)
      largest = node->value;
  }
  // return max value
  return largest;
}

template <typename T> int LinkedList<T>::find(const T VALUE) const {
  // search for first occurrence of VALUE
  if (_size > 0) {
    Node *node = _pHead;
    int i = 0;
    while (true) {
      if (node->value == VALUE) {
        // return index of first occurrence if found
        return i;
      }
      if (node->pNext)
        node = node->pNext;
      else
        break;
      i++;
    }
  }
  // otherwise return -1
  return -1;
}

#endif // LINKED_LIST_H

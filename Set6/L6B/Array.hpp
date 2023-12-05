#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template <typename T> class Array final : public IList<T> {
public:
  Array();
  ~Array();

  int size() const override;
  T get(const int POS) const override;
  void set(const int POS, const T VALUE) override;
  void insert(const int POS, const T VALUE) override;
  void remove(const int POS) override;
  T min() const override;
  T max() const override;
  int find(const T VALUE) const override;
  void sort() override;
  int search(const T VALUE) const override;

private:
  void mergeSort(T *arr, int start, int stop);
  void merge(T *mergedArray, T *leftArray, T *rightArray, int leftLength,
             int rightLength);
  int _size;
  T *_pArray;
};

//---------------------------------------------------------

template <typename T> Array<T>::Array() {
  // set size to zero
  _size = 0;
  // set array to be a nullptr
  _pArray = nullptr;
}

template <typename T> Array<T>::~Array() {
  // deallocate current array
  delete[] _pArray;
}

template <typename T> int Array<T>::size() const { return _size; }

template <typename T> T Array<T>::get(const int POS) const {
  // if POS is out of range, throw std::out_of_range exception
  if (POS >= _size || POS < 0)
    throw std::out_of_range("OUT OF RANGE");
  // return value at POS within array
  return _pArray[POS];
}

template <typename T> void Array<T>::set(const int POS, const T VALUE) {
  // if POS is out of range, throw std::out_of_range exception
  if (POS >= _size || POS < 0)
    throw std::out_of_range("OUT OF RANGE");
  // set VALUE at POS within array
  _pArray[POS] = VALUE;
}

template <typename T> void Array<T>::insert(int pos, const T VALUE) {
  // if POS is before zero, clamp to zero
  if (pos < 0)
    pos = 0;
  // if POS is after size, clamp to size
  if (pos > _size)
    pos = _size;
  // create new array of size + 1
  T *arr = new T[_size + 1];
  // copy elements 0 to POS from old array to new array
  std::copy(_pArray, _pArray + pos, arr);
  // set element at POS in new array to VALUE
  arr[pos] = std::move(VALUE);
  // copy elements POS to size from old array to new array
  std::copy(_pArray + pos, _pArray + _size, arr + pos + 1);
  // delete old array
  delete[] _pArray;
  // set old array to be new array
  _pArray = arr;
  // increment size
  _size++;
}

template <typename T> void Array<T>::remove(int pos) {
  // if array is empty, throw std::out_of_range exception
  if (_size == 0)
    throw std::out_of_range("EMPTY ARRAY");
  // if POS is before zero, clamp to zero
  if (pos < 0)
    pos = 0;
  // if POS is after size, clamp to size
  if (pos >= _size)
    pos = _size - 1;
  // create new array of size - 1
  T *arr = new T[_size - 1];
  // copy elements from 0 to POS from old array to new array
  std::copy(_pArray, _pArray + pos, arr);
  // copy elements from POS+1 to size from old array to new array
  std::copy(_pArray + pos + 1, _pArray + _size, arr + pos);
  // delete old array
  delete[] _pArray;
  // set old array to be new array
  _pArray = arr;
  // decrement size
  _size--;
}

template <typename T> T Array<T>::min() const {
  // if array is empty, throw std::out_of_range exception
  if (_size == 0) {
    throw std::out_of_range("LIST EMPTY");
  }
  // find minimum value within array
  T smallest = _pArray[0];
  for (int i = 1; i < _size; i++) {
    if (smallest > _pArray[i])
      smallest = _pArray[i];
  }
  // return min value
  return smallest;
}

template <typename T> T Array<T>::max() const {
  // if array is empty, throw std::out_of_range exception
  if (_size == 0) {
    throw std::out_of_range("LIST EMPTY");
  }
  // find maximum value within array
  T largest = _pArray[0];
  for (int i = 1; i < _size; i++) {
    if (largest < _pArray[i])
      largest = _pArray[i];
  }
  // return max value
  return largest;
}

template <typename T> int Array<T>::find(const T VALUE) const {
  // search for first occurrence of VALUE
  for (int i = 0; i < _size; i++) {
    if (_pArray[i] == VALUE)
      // return index of first occurrence if found
      return i;
  }
  // otherwise return -1
  return -1;
}

template <typename T> void Array<T>::sort() {
  mergeSort(_pArray, 0, _size - 1);
}

template <typename T>
void Array<T>::merge(T *mergedArray, T *leftArray, T *rightArray,
                     int leftLength, int rightLength) {
  int leftIndex = 0, rightIndex = 0, mergedIndex = 0;
  while (leftIndex < leftLength && rightIndex < rightLength) {
    if (leftArray[leftIndex] < rightArray[rightIndex]) {
      mergedArray[mergedIndex] = leftArray[leftIndex];
      leftIndex++;
    } else {
      mergedArray[mergedIndex] = rightArray[rightIndex];
      rightIndex++;
    }
    mergedIndex++;
  }
  for (int i = leftIndex; i < leftLength; i++) {
    mergedArray[mergedIndex] = leftArray[i];
    mergedIndex++;
  }
  for (int i = rightIndex; i < rightLength; i++) {
    mergedArray[mergedIndex] = rightArray[i];
    mergedIndex++;
  }
}

template <typename T>
void Array<T>::mergeSort(T *array, int startIndex, int stopIndex) {
  // stopIndex should be an accesible index, not indicative of a range UP TO
  // stop index. This will hold true of middleIndex as well.
  if (startIndex >= stopIndex)
    return;
  int middleIndex = startIndex + (stopIndex - startIndex) / 2;

  mergeSort(array, startIndex, middleIndex);
  mergeSort(array, middleIndex + 1, stopIndex);

  int leftLength = middleIndex - startIndex + 1;
  int rightLength = stopIndex - middleIndex;
  T *leftArray = new T[leftLength], *rightArray = new T[rightLength];
  for (int i = 0; i < leftLength; i++) {
    leftArray[i] = array[startIndex + i];
  }
  for (int i = 0; i < rightLength; i++) {
    rightArray[i] = array[middleIndex + 1 + i];
  }
  T *mergedArray = new T[stopIndex - startIndex + 1];

  merge(mergedArray, leftArray, rightArray, leftLength, rightLength);

  for (int i = startIndex; i <= stopIndex; i++) {
    array[i] = mergedArray[i - startIndex];
  }

  delete[] leftArray;
  delete[] rightArray;
  delete[] mergedArray;
}

template <typename T> int Array<T>::search(const T VALUE) const {
  int left = 0, right = _size - 1, middle;
  while (left <= right) {
    middle = left + (right - left) / 2;
    if (_pArray[middle] == VALUE)
      return middle;
    if (_pArray[middle] < VALUE)
      // shift range to above the middle
      left = middle + 1;
    else
      // shift range to below the middle
      right = middle - 1;
  }
  // not found
  return -1;
}

#endif // ARRAY_H
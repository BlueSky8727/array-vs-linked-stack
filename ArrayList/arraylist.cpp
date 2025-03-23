#include "arraylist.h"
#include <iostream>
#include <stdexcept>

ArrayList::ArrayList(int cap) : capacity(cap), currentSize(0) {
    arr = new int[capacity];
}

ArrayList::~ArrayList() {
    delete[] arr;
}

int ArrayList::size() const {
    return currentSize;
}

int ArrayList::indexOf(int e) const {
    for (int i = 0; i < currentSize; ++i) {
        if (arr[i] == e) return i;
    }
    return -1;
}

int ArrayList::get(int i) const {
    if (i < 0 || i >= currentSize) throw std::out_of_range("Index out of range");
    return arr[i];
}

int ArrayList::remove(int i) {
    if (i < 0 || i >= currentSize) throw std::out_of_range("Index out of range");
    int removedValue = arr[i];
    for (int j = i; j < currentSize - 1; ++j) {
        arr[j] = arr[j + 1];
    }
    --currentSize;
    return removedValue;
}

void ArrayList::set(int i, int e) {
    if (i < 0 || i >= currentSize) throw std::out_of_range("Index out of range");
    arr[i] = e;
}

void ArrayList::add(int i, int e) {
    if (i < 0 || i > currentSize) 
    //throw std::out_of_range("Index out of range");
    std::cout << "error\n";
    else{

    
    if (currentSize == capacity) {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int j = 0; j < currentSize; ++j) {
            newArr[j] = arr[j];
        }
        delete[] arr;
        arr = newArr;
    }
    for (int j = currentSize; j > i; --j) {
        arr[j] = arr[j - 1];
    }
    arr[i] = e;
    ++currentSize;
    }
}

void ArrayList::display() const {
    if (currentSize == 0) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    for (int i = 0; i < currentSize; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void ArrayList::clear() {
    currentSize = 0;
}

int ArrayList::min() const {
    if (currentSize == 0) throw std::out_of_range("No elements to find min");
    int minValue = arr[0];
    for (int i = 1; i < currentSize; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    return minValue;
}

int ArrayList::max() const {
    if (currentSize == 0) throw std::out_of_range("No elements to find max");
    int maxValue = arr[0];
    for (int i = 1; i < currentSize; ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

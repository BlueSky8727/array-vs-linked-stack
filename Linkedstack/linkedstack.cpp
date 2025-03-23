#include "linkedstack.h"
#include <iostream>

LinkedStack::LinkedStack() {}

void LinkedStack::push(int value) {
    list.add(0, value);  // ใช้ add ที่ตำแหน่ง 0 เพื่อให้เหมือน stack (LIFO)
}

int LinkedStack::pop() {
    if (list.size() == 0) {
        throw std::out_of_range("Stack is empty");
    }
    return list.remove(0);
}

bool LinkedStack::isEmpty() const {
    return list.size() == 0;
}

void LinkedStack::display() const {
    std::cout << "Stack contents (top to bottom): ";
    for (int i = 0; i < list.size(); ++i) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;
}
#include "arraystack.h"


ArrayStack::ArrayStack() {
    top = -1;
}

void ArrayStack::push(int value) {
    if (isFull()) {
        std::cout << "Stack Overflow!\n";
        return;
    }
    arr[++top] = value;
    list.add(top, value); // บันทึกลง ArrayList ด้วย
}

int ArrayStack::pop() {
    if (isEmpty()) {
        std::cout << "Stack Underflow!\n";
        return -1;
    }
    int val = arr[top--];
    list.remove(top + 1); // ลบออกจาก ArrayList ด้วย
    return val;
}

int ArrayStack::peek() {
    if (isEmpty()) {
        std::cout << "Stack is empty!\n";
        return -1;
    }
    return arr[top];
}

bool ArrayStack::isEmpty() {
    return top == -1;
}

bool ArrayStack::isFull() {
    return top == MAX_SIZE - 1;
}

void ArrayStack::display() {
    if (isEmpty()) {
        std::cout << "Stack is empty!\n";
        return;
    }
    std::cout << "Stack elements: ";
    list.display(); // ใช้ฟังก์ชันแสดงค่าของ ArrayList แทน
    std::cout << "\n";
}

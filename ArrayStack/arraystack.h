#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <iostream>
#include "../ArrayList/arraylist.h"  // รวม ArrayList เข้าไปใช้งาน

class ArrayStack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;
    ArrayList list; // ใช้ ArrayList ภายใน Stack

public:
    ArrayStack();
    void push(int value);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void display();
};

#endif

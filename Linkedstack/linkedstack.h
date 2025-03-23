#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "../LinkedList/LinkedList.h"

class LinkedStack {
private:
    LinkedList list;  // ใช้ LinkedList ในการจัดการข้อมูล

public:
    LinkedStack();
    void push(int value);
    int pop();
    bool isEmpty() const;
    void display() const;
};

#endif
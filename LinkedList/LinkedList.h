#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

#pragma once  // ✅ ป้องกันการ include ซ้ำ

struct Node {
    int data;
    Node* next;

    // ✅ ให้แน่ใจว่ามี constructor ตัวนี้
    Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

class LinkedList {
private:
    Node* head;
    int count;

public:
    LinkedList();
    ~LinkedList();
    int size() const;
    int indexOf(int e) const;
    int get(int i) const;
    int remove(int i);
    void set(int i, int e);
    void add(int i, int e);
    void display() const;
    void clear();
    bool isEmpty() const;
};

#endif
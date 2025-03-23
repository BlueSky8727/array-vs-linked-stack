#include "LinkedList.h"
#include <stdexcept>

LinkedList::LinkedList() : head(nullptr), count(0) {}

LinkedList::~LinkedList() {
    clear();
}

int LinkedList::size() const {
    return count;
}

int LinkedList::indexOf(int e) const {
    Node* current = head;
    int index = 0;
    while (current) {
        if (current->data == e) return index;
        current = current->next;
        index++;
    }
    return -1;
}

int LinkedList::get(int i) const {
    if (i < 0 || i >= count) throw std::out_of_range("Index out of range");
    Node* current = head;
    for (int j = 0; j < i; j++) {
        current = current->next;
    }
    return current->data;
}

int LinkedList::remove(int i) {
    if (i < 0 || i >= count) throw std::out_of_range("Index out of range");

    Node* current = head;
    if (i == 0) {
        head = current->next;
    } else {
        Node* prev = nullptr;
        for (int j = 0; j < i; j++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
    }
    int removedData = current->data;
    delete current;
    count--;
    return removedData;
}

void LinkedList::set(int i, int e) {
    if (i < 0 || i >= count) throw std::out_of_range("Index out of range");
    Node* current = head;
    for (int j = 0; j < i; j++) {
        current = current->next;
    }
    current->data = e;
}

void LinkedList::add(int i, int e) {
    if (i < 0 || i > count) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    // ✅ ใช้ constructor ที่มีพารามิเตอร์แทน
    Node* newNode = new Node(e, nullptr);

    if (i == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        for (int j = 0; j < i - 1; ++j) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    count++;
}

void LinkedList::display() const {
    if (count == 0) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Node* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

void LinkedList::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    count = 0;
}

bool LinkedList::isEmpty() const {
    return count == 0;
}

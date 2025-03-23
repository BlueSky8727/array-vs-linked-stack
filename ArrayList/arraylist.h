#ifndef ARRAYLIST_H
#define ARRAYLIST_H

class ArrayList {
private:
    int* arr;
    int capacity;
    int currentSize;

public:
    ArrayList(int cap = 10);  // Constructor
    ~ArrayList();             // Destructor
    int size() const;         // Returns current size
    int indexOf(int e) const; // Returns index of element e
    int get(int i) const;     // Returns element at index i
    int remove(int i);        // Removes element at index i
    void set(int i, int e);   // Sets element at index i to e
    void add(int i, int e);   // Adds element e at index i

    void display() const;     // Displays all elements
    void clear();             // Clears the list
    int min() const;          // Finds the minimum element
    int max() const;          // Finds the maximum element
};

#endif

#pragma once

class DynamicArray {
private:
    int* data;
    int capacity;
    int size;
    void resize();

public:
    DynamicArray(int n);
    ~DynamicArray();

    void addFront(int val);
    void addEnd(int val);
    void addAtIndex(int idx, int val);
    void removeFront();
    void removeEnd();
    void removeAtIndex(int idx);
    int find(int val);
};
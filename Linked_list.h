#pragma once

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void addFront(int value);
    void addEnd(int value);
    void addAtIndex(int index, int value);
    void removeFront();
    void removeEnd();
    void removeAtIndex(int index);
    int find(int value);
};
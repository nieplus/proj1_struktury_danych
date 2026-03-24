#include"Linked_list.h"

LinkedList::LinkedList(): head(nullptr) {}

LinkedList::~LinkedList(){
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void LinkedList::addFront(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void LinkedList::addEnd(int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void LinkedList::addAtIndex(int index, int value) {
    if (index == 0) {
        addFront(value);
        return;
    }

    Node* newNode = new Node{value, nullptr};
    Node* current = head;
    for (int i = 0; i < index - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current != nullptr) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        delete newNode; // Index out of bounds
    }
}

void LinkedList::removeFront() {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::removeEnd() {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

void LinkedList::removeAtIndex(int index) {
    if (index == 0) {
        removeFront();
        return;
    }

    Node* current = head;
    for (int i = 0; i < index - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current != nullptr && current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}   
int LinkedList::find(int value) {
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1; // Nie znaleziono wartości
} 
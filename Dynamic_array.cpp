#include"Dynamic_array.h"

DynamicArray::DynamicArray(int n): capacity(n), size(0) {
    if(capacity <= 0) capacity = 1;
    data = new int[capacity];
}

DynamicArray::~DynamicArray() {
    delete[] data;
}
// Przydzielenie nowego rozmiaru dla tablicydynamicznej gdy jest pełna
void DynamicArray::resize(){
    int newCapacity = capacity * 2;
    int*newData = new int[newCapacity];
    for(int i = 0; i < size; i++){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}
void DynamicArray::resizeDown(){
    // Zapobieganie zmniejszeniu capacity poniezej rozmiaru
    if(capacity/2 < size) return;
    int newCapacity = capacity / 2;
    int* newData = new int[newCapacity];
    for(int i = 0; i < size; i++){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}
void DynamicArray::addFront(int val){
    if (size == capacity) resize();
    for(int i = size; i > 0; --i)
    {
        data[i] = data[i - 1];
    }
    data[0] = val;
    size++;
}
void DynamicArray::addEnd(int val){
    if(size == capacity) resize();
    data[size] = val;
    size++;
}
void DynamicArray::addAtIndex(int idx, int val){
    if(size == capacity) resize();
    if(idx < 0 || idx > size) return;
    for(int i = size; i > idx; --i)
    {
        data[i] = data[i - 1];
    }
    data[idx] = val;
    size++;
}
void DynamicArray::removeFront(){
    if (capacity == 1 || capacity == 0) {
        size = 0;
        return;
    }
    for(int i = 0; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
    if(capacity > 1 && size < capacity / 2) resizeDown();
}
void DynamicArray::removeEnd(){ 
    size--;
    if(capacity > 1 && size < capacity / 2) resizeDown();
}
void DynamicArray::removeAtIndex(int idx){
    if(idx < 0 || idx >= size) return; // Index nie w zasięgu
    for(int i = idx; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
    if(capacity > 1 && size < capacity / 2) resizeDown();
}
int DynamicArray::find(int val){
    for(int i = 0; i < size; i++)
    {
        if(data[i] == val)
            return i;
    }
    return -1;
}
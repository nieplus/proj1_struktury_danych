#include"Dynamic_array.h"

DynamicArray::DynamicArray(int n): capacity(n), size(0) {
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
    for(unsigned int i = size - 1; i >= 0; i--)
    {
        data[i] = data[i - 1];
    }
    data[0] = val;
    size++;
}
void DynamicArray::addEnd(int val){
    if(size == capacity) resize();
    data[size - 1] = val;
    size++;
}
void DynamicArray::addAtIndex(int index, int val){
    if(size == capacity) resize();
    for(unsigned int i = size - 1; i >= index; i--)
    {
        data[i] = data[i - 1];
    }
    data[index] = val;
    size++;
}
void DynamicArray::removeFront(){
    for(unsigned int i = 0; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
    if(size < capacity / 2) resizeDown();
}
void DynamicArray::removeEnd(){ 
    size--;
    if(size < capacity / 2) resizeDown();
}
void DynamicArray::removeAtIndex(int idx){
    for(unsigned int i = idx; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
    if(size < capacity / 2) resizeDown();
}
int DynamicArray::find(int val){
    for(unsigned int i = 0; i < size; i++)
    {
        if(data[i] == val)
            return i;
    }
    return -1;
}
#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <iostream>

//min heap for integers
class PriorityQueue{
    private:
    int *array;
    int size;
    int capacity;

    void heapify(int i);
    void swap(int *a,int *b);
    

    public:

    PriorityQueue(){
        this->size = 0;
        this->capacity = 100;
        this->array = new int[capacity];
    }


    ~PriorityQueue(){
        delete[] this->array;
    }



   
    int peekMin();
    int extractMin();
    void deleteNode(int key);
    void insertNode(int val);
    bool isEmpty();





};




#endif
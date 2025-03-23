#include "Queue.hpp"
#include <iostream>

void Queue::offer(int number){
 if (this->rear == this->capacity -1)
 {
    int newCapacity = 2 * this->capacity;
    int *temp = array;

    this->array = new int[newCapacity];

    for (int i = 0; i < capacity; i++)
    {
        this->array[i] = temp[i];
    }

    delete[] temp;

    this->capacity = newCapacity;
    
 }

 this->rear = (this->rear + 1) % this->capacity;

 this->array[rear] = number;

 this->count++;
 


 
}

int Queue::poll(){
    if (isEmpty())
    {
        throw std::out_of_range("Queue is empty");
    }
    int item = this->array[front];
    this->front = (this->front + 1) % this->capacity;
    this->count--;

    return item;
}


bool Queue::isEmpty(){
    return this->count == 0;
}

int Queue::peek(){
    if (isEmpty())
    {
        throw std::out_of_range("Queue is empty");

    }

    return this->array[front];
    
}


    int Queue::size(){
        return this->count;
    }
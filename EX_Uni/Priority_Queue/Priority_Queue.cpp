#include "Priority_Queue.hpp"


void PriorityQueue::heapify(int i){
    int smallest = i;
    int leftChild = 2*i +1;
    int rightChild = 2*i + 2;



    if (leftChild < size && this->array[leftChild] < this->array[smallest])
    {
        smallest = leftChild;

    }

    if (rightChild < size && this->array[rightChild] < this->array[smallest])
    {
        smallest = rightChild;
    }

    if (smallest != i)
    {
        //perform a swap
        swap(&array[i],&array[smallest]);

        heapify(smallest);
    }
    

}




int PriorityQueue::peekMin(){
    if(size <= 0){
        throw "size is a positive number";
    }

    return array[0];
  
}



int PriorityQueue::extractMin(){
    
    if(size <= 0){
        throw "size is a positive number";
    }

    if (size == 1)
    {
        size--;
     return array[0];
    }

    int root = array[0];
    array[0] = array[size - 1];
    this->size--;
    
    heapify(0);
    return root;
}

void PriorityQueue::deleteNode(int key){
   int index = -1;

   for (size_t i = 0; i < size; i++)
   {
        if(array[i] == key){
            index = i;
            break;
        }
   }

   if (index == -1)
   {
    throw "Item was not found";
   }
   if (index == size - 1)
   {
    size--;
    return;
   }
   

   array[index] = array[size - 1];
   heapify(index);
   
   
}



void PriorityQueue::insertNode(int val){
    if (size == capacity)
    {
        int newCapacity = capacity*2;
        int*temp = this->array;

        this->array = new int[newCapacity];

        for (size_t i = 0; i < size; i++)
        {
            this->array[i] = temp[i];
        }
        delete[] temp;

        capacity = newCapacity;
        
    }
    
    size++;

    int i = size - 1;
    this->array[i] = val;


    while(i != 0 && array[(i - 1) / 2] > array[i]){
       swap(&array[i],&array[(i - 1)/2]);
        i = (i - 1) / 2;
    }



}

void PriorityQueue::swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool PriorityQueue::isEmpty(){
    return size == 0;
}
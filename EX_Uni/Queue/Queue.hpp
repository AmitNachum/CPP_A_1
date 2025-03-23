#ifndef QUEUE_HPP
#define QUEUE_HPP


class Queue{
    private:

    int rear;
    int front;
    int *array;
    int capacity;
    int count;

    public:
    Queue(){
        this->capacity = 100;
        this->array = new int[capacity];
        this->front = 0;
        this->rear = -1;
        this->count = 0;
    }

    ~Queue(){
        delete[]this->array;
    }

    void offer(int number);
    int poll();
    int peek();
    bool isEmpty();
    int size();


};


#endif
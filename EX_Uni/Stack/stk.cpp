#include "stk.hpp"
#include <iostream>


void stk::push(int number){
    if (top >= initLength - 1)
    {
        int newSize = initLength*2;
        int *temp = this->stack;

        this->stack = new int[newSize];
    
        for (int i = 0; i < initLength; i++)
        {
            this->stack[i] = temp[i];
        }

        initLength = newSize;
        delete[] temp;
        
    }
    
    this->top++;
    this->stack[this->top] = number;
    
}

int stk::pop(){
    if (this->top < 0)
    {
        throw std::out_of_range("stack is empty");
    }
    int res = stack[top];
    this->top--;

    return res;
}

int stk::peek(){
    if (this->top < 0)
    {
        throw std::out_of_range("no elements in the stack");
    }
    return this->stack[top];
    
}

bool stk::isEmpty(){
    return (this->top < 0);
}

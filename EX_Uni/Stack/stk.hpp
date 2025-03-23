#ifndef STK_HPP
#define STK_HPP
#include <iostream>
 
class stk{
    private:
    int top;
    int *stack;
    int initLength;
  
    public:
    

    stk(int capaity){
        if (capaity <= 0)
        {
            throw std::invalid_argument("capacity must be a positive integer");
        }
        
        this->initLength = 100;
        this->stack = new int[initLength];
        this->top = -1;
    }


    stk(){
    this->initLength = 100;
    this->stack = new int[initLength];
    this->top = -1;
    }

    ~stk(){
        delete[]this->stack;
    }

    void push(int number);
    int pop();
    bool isEmpty();
    int peek();

};
#endif



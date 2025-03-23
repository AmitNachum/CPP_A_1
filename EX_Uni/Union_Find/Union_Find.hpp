#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP


class Union_Find{

    private:
    int *parent;
    int *rank;
    int index;



    public:

    Union_Find(int verticiesNum){
        this->index = 0;
        this->parent = new int[verticiesNum];
        this->rank = new int[verticiesNum];

        for(int i = 0; i < verticiesNum; i++){
            parent[i] = i;       
            rank[i] = 0;         
        }
    }

    ~Union_Find(){

        delete[] this->parent;
        delete[] this->rank;

    }

    void unionNumbers(int x, int y);
    int find(int x);
    bool isConnected(int x,int y);








};





#endif
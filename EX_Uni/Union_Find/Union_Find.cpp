#include "Union_Find.hpp"

int Union_Find::find(int x){
    if (x != parent[x])
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
    
}

void Union_Find::unionNumbers(int x, int y)
{
    int root_x = find(x);
    int root_y = find(y);

    if (root_x == root_y){
        //x and y are in the same set
       return;
    }

    if (rank[root_x] < rank[root_y]){
        parent[root_x] = root_y;
    }

    else if(rank[root_x] > rank[root_y]){
        parent[root_y] = root_x;
    }
    else{
        parent[root_y] = root_x;
        rank[root_x] += 1;
    }


}


bool Union_Find::isConnected(int x, int y){
    return find(x) == find(y);
}
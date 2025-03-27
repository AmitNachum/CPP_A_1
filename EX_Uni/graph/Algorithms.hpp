#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "Priority_Queue.hpp"
#include "Queue.hpp"
#include "stk.hpp"
#include "Union_Find.hpp"
#include "Graph.hpp"



namespace graph
{
    enum Colors { WHITE, GRAY, BLACK };
    
    struct Edge {
        int v;       
        int u;      
        int weight;  
    };
   
    class Algorithms{
    private:
        static void dfsTravers(Graph *g, int vertex, Colors *color, int *discoveryTime, int *finishTime, int *time);
        static void customSort(Edge *start, Edge *end,bool compare(const Edge *,const Edge *));
        static bool compare(const Edge *a, const Edge *b){
            return (a->weight) < (b->weight);
        }

    public:
        static void bfs(Graph *g, int vertex); 
        static void dfs(Graph *g, int s); 
        static Graph* kruskalsAlgorithm(Graph *g); 
        static Graph* primsAlgorithm(Graph *g); 
        static Graph* dijkstraAlgorithm(Graph *g, int s);
    };
} 
#endif

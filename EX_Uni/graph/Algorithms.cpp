#include "Algorithms.hpp"
#include "../Priority_Queue/Priority_Queue.hpp"
#include "../Stack/stk.hpp"
#include "../Union_Find/Union_Find.hpp"
#include "../Queue/Queue.hpp"
#include <iostream>


    
void graph::Algorithms::bfs(Graph *g, int vertex){
    
    int len = g->getVerAmount();
    Node** adjacencyList = g->getAdj();

    Colors *c = new Colors[len];
    for (size_t i = 0; i < len; i++) {
        c[i] = WHITE;
    }
        
    Queue q;
    q.offer(vertex);

    while(!q.isEmpty()){
        int v = q.poll();
        c[v] = GRAY;

        std::cout << v << " ";

        Node* curr = adjacencyList[v];
        while (curr != nullptr) {
            if (c[curr->vertex] == WHITE) {
                c[curr->vertex] = GRAY;
                q.offer(curr->vertex);
            }
            curr = curr->next;
        }
        
        c[v] = BLACK;
    }

    delete[] c;
}

void graph::Algorithms::dfsTravers(Graph *g, int vertex, Colors *colors ,int *discoveryTime,int *finishTime, int *time){
    ++(*time);
    discoveryTime[vertex] = *time;
    colors[vertex] = GRAY;

    Node** adjList = g->getAdj();

    std::cout << vertex << " ";

    Node* curr = adjList[vertex];
    while (curr != nullptr) {
        if (colors[curr->vertex] == WHITE) {
            dfsTravers(g, curr->vertex, colors, discoveryTime, finishTime, time);
        }
        curr = curr->next;
    }

    colors[vertex] = BLACK;
    ++(*time);
    finishTime[vertex] = *time;
}

void graph::Algorithms::dfs(Graph *g, int s){
    int len = g->getVerAmount();
    int *time = new int(0);
    int *finishTime = new int[len];
    int *discoveryTime = new int[len];
    Colors *color = new Colors[len];

    for (size_t i = 0; i < len; i++) {
        finishTime[i] = -1;
        discoveryTime[i] = -1;
        color[i] = WHITE;
    }

    dfsTravers(g, s, color, discoveryTime, finishTime, time);

    delete[] finishTime;
    delete[] discoveryTime;
    delete[] color;
    delete time;
}

graph::Graph *graph::Algorithms::kruskalsAlgorithm(Graph *g){
    Node** adjList = g->getAdj();
    int len = g->getVerAmount();
    Edge *edges = new Edge[len * len];

    int edgeCount = 0;
    for (int i = 0; i < len; i++) {

        Node* curr = adjList[i];

        while (curr != nullptr) {
            edges[edgeCount++] = {i, curr->vertex, curr->weight};
            curr = curr->next;
        }
    }

    graph::Algorithms::customSort(edges, edges + edgeCount, Algorithms::compare);

    Graph *MST = new Graph(len);
    Union_Find *uf = new Union_Find(len);

    for (int i = 0; i < edgeCount; i++) {
        int v1 = edges[i].v;
        int v2 = edges[i].u;
        int currWeight = edges[i].weight;
        
        if (uf->find(v1) != uf->find(v2)) {
            uf->unionNumbers(v1, v2);
            MST->addEdge(v1, v2, currWeight);
        }
    }

    delete uf;
    delete[] edges;
    return MST;
}

graph::Graph *graph::Algorithms::primsAlgorithm(Graph *g){
    
    Node** adjList = g->getAdj();
    int len = g->getVerAmount();

    int *weights = new int[len];
    int *parent = new int[len];
    bool *inMST = new bool[len];
    PriorityQueue *pq = new PriorityQueue();

    for (int i = 0; i < len; i++) {
        weights[i] = INF;
        parent[i] = -1;
        inMST[i] = false;
    }

    weights[0] = 0;
    pq->insertNode(0);

    while(!pq->isEmpty()){

        int v = pq->extractMin();
        if (inMST[v]) continue;


        inMST[v] = true;

        Node* curr = adjList[v];
        while (curr != nullptr) {
            int u = curr->vertex;
            int weight = curr->weight;

            if (!inMST[u] && weight < weights[u]) {
                weights[u] = weight;
                parent[u] = v;
                pq->insertNode(u);
            }
            curr = curr->next;
        }
    }

    Graph *MST = new Graph(len);
    for (int i = 1; i < len; i++) {
        if (parent[i] != -1) {
            MST->addEdge(parent[i], i, weights[i]);
        }
    }

    delete[] weights;
    delete[] inMST;
    delete[] parent;
    delete pq;
    return MST;
}

graph::Graph *graph::Algorithms::dijkstraAlgorithm(Graph *g, int s){
    
    Node** adjList = g->getAdj();
    int len = g->getVerAmount();

    int *dist = new int[len];
    int *parent = new int[len];
    bool *visited = new bool[len];
    PriorityQueue *pq = new PriorityQueue();

    for (int i = 0; i < len; i++) {
        dist[i] = INF;
        parent[i] = -1;
        visited[i] = false;
    }

    dist[s] = 0;
    pq->insertNode(s);

    while (!pq->isEmpty()) {
        int v = pq->extractMin();
        if (visited[v]) continue;
        visited[v] = true;

        Node* curr = adjList[v];
        while (curr != nullptr) {
            int u = curr->vertex;
            int weight = curr->weight;
            if (weight < 0)
            {
                throw "Negative weight detected in Dijkstra's ALgorithm";
            }
            

            if (!visited[u] && dist[v] + weight < dist[u]) {
                dist[u] = dist[v] + weight;
                parent[u] = v;
                pq->insertNode(u);
            }
            curr = curr->next;
        }
    }

    Graph *SPT = new Graph(len);
    for (int i = 1; i < len; i++) {
        if (parent[i] != -1) {
            SPT->addEdge(parent[i], i, dist[i]);
        }
    }

    delete[] dist;
    delete[] parent;
    delete[] visited;
    delete pq;
    return SPT;
}



void graph::Algorithms::customSort(Edge *start, Edge *end,bool compare(const Edge *,const Edge *)){
    int i = 0;
    int j = i + 1;
    int size = end - start;

    for (int i = 0; i < size; i++)
    { 
        for (int j = i + 1; j < size; j++)
        {
            if (!compare( &start[i], &start[j] ))
            {
                Edge temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
            
        }
        
    }
    

    
    
}
#include "Graph.hpp"

using namespace graph;

Graph::Graph(int vertexAmount) : vertexAmount(vertexAmount) {
    this->adjList = new Node*[vertexAmount];
    for (int i = 0; i < vertexAmount; ++i) {
        adjList[i] = nullptr; 
    }
}

Graph::Graph(Graph *other){

    int amount = other->getVerAmount();
    this->adjList = new Node*[amount]();
    
    for (int i = 0; i < amount; i++)
    {
        Node *currOther = other->adjList[i];       

        while (currOther != nullptr)
        {
            int otherJth = currOther->vertex;
            int otherWeight = currOther->weight;                                              

            this->addEdge(i,otherJth,otherWeight);
            currOther = currOther->next;
        }
        
        
    }

    this->vertexAmount = amount;
    
}



Graph::~Graph() {
    for (int i = 0; i < vertexAmount; ++i) {
        Node* current = adjList[i];
        while (current) {

            Node* temp = current;  
            current = current->next;
            delete temp;
        }
    }
    delete[] adjList;
}

bool Graph::isWithinBounds(int vertex) const {
    return vertex >= 0 && vertex < vertexAmount;
}

int Graph::getVerAmount() const {
    return vertexAmount;
}

void Graph::expandGraph(int newAmount){

    if (newAmount <= this->vertexAmount)
    {
        return;
    }
    
    Node **newAdj = new Node*[newAmount];

    for (int i = 0; i < newAmount; i++)
    {
        newAdj[i] = nullptr;    
    }

    for (int i = 0; i < newAmount; i++)
    {
        Node *curr = this->adjList[i];
        Node **newCurr = &(newAdj[i]);

        while (curr != nullptr)
        {
            *newCurr = new Node(curr->vertex,curr->weight);
            newCurr = &((*newCurr)->next);
            curr = curr->next;
        }
        
    }
    
    delete[] adjList;

    adjList = newAdj;
    vertexAmount = newAmount;
    
    
}


void Graph::addEdge(int u, int v, int weight) {

    if (!isWithinBounds(u) || !isWithinBounds(v)) {
        int max = (u > v) ? u : v;
        expandGraph(max + 1);
        
    }
     


    Node* newNode = new Node(v, weight);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    Node *newNode2 = new Node(u,weight);
    newNode2->next = adjList[v];
    adjList[v] = newNode2;
}

void Graph::removeEdge(int u, int v) {
    if (!isWithinBounds(u) || !isWithinBounds(v)) {
        throw "Error: Vertex out of bounds";
    }

    Node* current = adjList[u];
    Node* prev = nullptr;

    while (current != nullptr && current->vertex != v) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        throw "Error: Edge not found";
    }

    if (prev == nullptr) { 
        adjList[u] = current->next;
    } else {
        prev->next = current->next;
    }


    Node *curr2 = adjList[v];
    Node *prev2 = nullptr;

    while (curr2 != nullptr && curr2->vertex != u){
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if (curr2 == nullptr){
        throw "Error: Edge not Found";
        
    }

    if (prev2== nullptr){        
        adjList[v] = curr2->next;
    }else{
        prev2->next = curr2->next;
    }
    
    

    
    
    delete curr2;
    delete current;
}


void Graph::printGraph() {

    std::cout<<std::endl;
    for (int i = 0; i < vertexAmount; ++i) {
        std::cout << "Vertex " << i << " : ";
        Node* current = adjList[i];
        while (current != nullptr) {
            std::cout << "-> (" << current->vertex << ", weight: " << current->weight << ")";
            current = current->next;
        }
        std::cout << std::endl;
    }
}


Node** Graph::getAdj() {
    return adjList;
}

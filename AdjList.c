/*------------------------------------------------------------------
A class that creates an adjacency list for use in Dijkstra's algorithm.
It creates a struct that contains a sink, cost, and next node, and then populates
the adjacency list with these nodes at specific places.

Written by Matthew Karnes
------------------------------------------------------------------*/
#include "AdjList.h"
#include <iostream>
#include <cstdlib>
#include <string>

// ************************** Public Functions *********************
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------
The AdjList constructor. This takes in an int n which is used as the 
total amount of nodes to be put into the list.  It then instantiates each 
part of the adjacency list as NULL.

Preconditions: none.
Postconditions: count = n and the array is NULL at all points.
------------------------------------------------------------------*/
AdjList::AdjList(int n){
    count = n;
    int i;
    for(i=0;i<n;i++){
        List[i]=NULL;
    }                    
}

AdjList::~AdjList(){

}

/*------------------------------------------------------------------
This creates edges within the adjacency list by taking in ints i,j,and weight.
i is the position within the graph, j is the sink to be set, and weight is the cost to be set.
This places new nodes as the next node from the previous.

Preconditions: none
Postconditions: If the list is null at the current point, it adds a new node.
If it is not null, it adds a node onto the next position at this point.
------------------------------------------------------------------*/
void AdjList::addEdge(int i, int j, int weight){
    Node* Point = new Node;
    Point->sink = j;
    Point->cost = weight;
    Point->next = List[i];
    List[i] = Point;
}

/*------------------------------------------------------------------
This finds the first node at the specified position, int i, in the graph and returns
it.

Preconditions: There is a graph.
Postconditions: The specified node is returned.
------------------------------------------------------------------*/
Node* AdjList::getFirst(int i){
    current= List[i];
    return (List[i]);
}

/*------------------------------------------------------------------
This looks at the current node and then finds the node after it.
If there is no node after it, it will return null.

Preconditions: There is a current node.
Postconditions: The node next to the current node will be added.
------------------------------------------------------------------*/
Node* AdjList::getNext(){

    current=current->next;
    return (current);
}



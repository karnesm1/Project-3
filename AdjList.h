/*------------------------------------------------------------------
A class that creates an adjacency list for use in Dijkstra's algorithm.
It creates a struct that contains a sink, cost, and next node, and then populates
the adjacency list with these nodes at specific places.

Written by Matthew Karnes
------------------------------------------------------------------*/
#ifndef _AdjList_H
#define _AdjList_H

#include <iostream>
#include <string>

using namespace std;
/*------------------------------------------------------------------
This is a struct that holds the data for the adjacency list.  It holds a sink, a cost, and points to the next node in the list.
------------------------------------------------------------------*/
struct Node {
    int sink;
    int cost;
    Node*next;
};

class AdjList{
public:
/*------------------------------------------------------------------
The AdjList constructor. This takes in an int n which is used as the 
total amount of nodes to be put into the list.  It then instantiates each 
part of the adjacency list as NULL.

Preconditions: none.
Postconditions: count = n and the array is NULL at all points.
------------------------------------------------------------------*/
    AdjList(int n);
    
    ~AdjList();
/*------------------------------------------------------------------
This creates edges within the adjacency list by taking in ints i,j,and weight.
i is the position within the graph, j is the sink to be set, and weight is the cost to be set.
This places new nodes as the next node from the previous.

Preconditions: none
Postconditions: If the list is null at the current point, it adds a new node.
If it is not null, it adds a node onto the next position at this point.
------------------------------------------------------------------*/
    void addEdge(int i, int j, int weight);
/*------------------------------------------------------------------
This finds the first node at the specified position in the graph and returns
it.

Preconditions: There is a graph.
Postconditions: The specified node is returned.
------------------------------------------------------------------*//*------------------------------------------------------------------
This creates edges within the adjacency list by taking in ints i,j,and weight.
i is the position within the graph, j is the sink to be set, and weight is the cost to be set.
This places new nodes as the next node from the previous.

Preconditions: none
Postconditions: If the list is null at the current point, it adds a new node.
If it is not null, it adds a node onto the next position at this point.
------------------------------------------------------------------*/
    Node* getFirst(int i);
    /*------------------------------------------------------------------
This looks at the current node and then finds the node after it.
If there is no node after it, it will return null.

Preconditions: There is a current node.
Postconditions: The node next to the current node will be added.
------------------------------------------------------------------*/
    Node* getNext();
    
private:
    //this is the amount of nodes that we have
    int count;

    //this is our array of nodes initialized to 100, as this is enough for the purposes we have
    Node*List[20];
    
    //this is a node that is used to find our current node in the array
    Node*current;

};
#endif
    
    
    
    
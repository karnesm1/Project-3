/*------------------------------------------------------------------
This class creates an array that holds a tentative distance between other nodes, whether or not a node has been visited, and what that nodes parent is.  

Written by Matthew Karnes
------------------------------------------------------------------*/
#ifndef _Distance_H
#define _Distance_H

#include <iostream>
#include <string>

using namespace std;

/*------------------------------------------------------------------
This creates a struct that contains an int tentative distance, an int parent, and a boolean that tells whether the node has been visited or not.
------------------------------------------------------------------*/
struct Dist{
    int tentDist;
    int parent;
    bool visited;
};

class Distance{
    
public:
    /*------------------------------------------------------------------
This constructor takes an int n, and uses it as the total amount of nodes in the array.  It then sets the tentDist of each node, other than 0, which is set to 0, to maximum, visited to false, and the parent to -1, for each node.

Preconditions: none
Postconditions:All tentDists are max, all visiteds are false, and all parents are -1.
------------------------------------------------------------------*/
        Distance(int n);

        ~Distance();
            
    /*------------------------------------------------------------------
This will return the tentDist for a given node.

Preconditions: There is a node.
Postconditions: A node's tentDist is returned.
------------------------------------------------------------------*/
        int getDistance(int n);

    /*------------------------------------------------------------------
This will return the parent of a given node, where the node is given by int i.

Preconditions: There is a node.
Postconditions: The node's parent is returned.
------------------------------------------------------------------*/
        int getParent(int i);

    /*------------------------------------------------------------------
This will look to see if a given node, given by int n, has been visited or not. If it has not been, then it will change that node's visited to true.  If it has been visited already, it will do nothing.

Preconditions: there is a node n
Postconditions: node n's visited is changed from false to true
------------------------------------------------------------------*/
        void visit(int n);

    /*------------------------------------------------------------------
This returns whether a specific node, specified by int i, in the array is visited or not.

Preconditions: there  is a node, i.
Postconditions: returns the visited status of node i
------------------------------------------------------------------*/
        bool getVisit(int i);

    
/*------------------------------------------------------------------
This sets the parent of a specific node, specified by int i, to another node, specified by int n.

Preconditions: there are at least two nodes.
Postconditions:the parent of node i is set to be node n.
------------------------------------------------------------------*/
        void setParent(int i, int n);
    /*------------------------------------------------------------------
This will take two ints, n and i, and then use them to change the tentDist of the node in the array.  n is the position in the array, and i is the new tentDist.

Preconditions: There is a node.
Postconditions: A node's, n, has its tentDist changed to i.
------------------------------------------------------------------*/
        void setDistance(int n,int i);
/*------------------------------------------------------------------
This will check to see what the next node that needs to be visited that has the smallest tentDist and has not already been visited. 

Preconditions:an array with nodes.
Postconditions:the next node to be visited will be returned
------------------------------------------------------------------*/
        int visitNext(int n);
private:
    //this is our array that holds our distance nodes
       Dist*DistArray;
//this is the number of nodes we have
        int count;

};
#endif

        
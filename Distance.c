/*------------------------------------------------------------------
This class creates an array that holds a tentative distance between other nodes, whether or not a node has been visited, and what that nodes parent is.  

Written by Matthew Karnes
------------------------------------------------------------------*/
#include "Distance.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
/*------------------------------------------------------------------
This constructor takes an int n, and uses it as the total amount of nodes in the array.  It then sets the tentDist of each node, other than 0, which is set to 0, to maximum, visited to false, and the parent to -1, for each node.

Preconditions: none
Postconditions:All tentDists are max, all visiteds are false, and all parents are -1.
------------------------------------------------------------------*/
Distance::Distance(int n){
    int i;
    int count=n;
    DistArray=new Dist[n];
    for(i=1;i<n;i++){
        DistArray[i].tentDist=INT_MAX;
        DistArray[i].visited=false;
        DistArray[i].parent=-1;
        }
    DistArray[0].tentDist=0;
}
/*This deletes every in the graph and the graph itself

Preconditions: a graph
PostCondition: there is no graph*/
Distance::~Distance(){
        delete DistArray;  
}

/*------------------------------------------------------------------
This will return the tentDist for a given node, given by int n.

Preconditions: There is a node.
Postconditions: A node's tentDist is returned.
------------------------------------------------------------------*/
int Distance::getDistance(int n){
    return (DistArray[n].tentDist);
}
/*------------------------------------------------------------------
This will take two ints, n and i, and then use them to change the tentDist of the node in the array.  n is the position in the array, and i is the new tentDist.

Preconditions: There is a node.
Postconditions: A node's, n, has its tentDist changed to i.
------------------------------------------------------------------*/
void Distance::setDistance(int n,int i){
    DistArray[n].tentDist=i;
}
/*------------------------------------------------------------------
This will return the parent of a given node, where the node is given by int i.

Preconditions: There is a node.
Postconditions: The node's parent is returned.
------------------------------------------------------------------*/
int Distance::getParent(int i){
    return (DistArray[i].parent);
}

/*------------------------------------------------------------------
This will look to see if a given node, given by int n, has been visited or not. If it has not been, then it will change that node's visited to true.  If it has been visited already, it will do nothing.

Preconditions: there is a node n
Postconditions: node n's visited is changed from false to true
------------------------------------------------------------------*/
void Distance::visit(int n){ 
        DistArray[n].visited=true;  
}
/*------------------------------------------------------------------
This returns whether a specific node, specified by int i, in the array is visited or not.

Preconditions: there  is a node, i.
Postconditions: returns the visited status of node i
------------------------------------------------------------------*/
bool Distance::getVisit(int i){
    return (DistArray[i].visited);
}

/*------------------------------------------------------------------
This sets the parent of a specific node, specified by int i, to another node, specified by int n.

Preconditions: there are at least two nodes.
Postconditions:the parent of node i is set to be node n.
------------------------------------------------------------------*/
void Distance::setParent(int i, int n){
    DistArray[i].parent=n;
}

/*------------------------------------------------------------------
This will check to see what the next node that needs to be visited that has the smallest tentDist and has not already been visited. 

Preconditions:an array with nodes.
Postconditions:the next node to be visited will be returned
------------------------------------------------------------------*/
int Distance::visitNext(){
    if(getVisit(0)==false){
        return(0);
    }
    int dist=INT_MAX;
    int next;
    //this looks through the array to find a node that is smaller and has not been visited yet
  for(int i=1;i<count;i++){  
      if(dist>getDistance(i) && getVisit(i)==false){
          dist=getDistance(i);
      next = i;
      }   
  }
    return(next);
}

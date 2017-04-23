#include "AdjList.h"
#include "Distance.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <climits>

/*------------------------------------------------------------------
This main function will add various edges to an adjacency list called EdgeGraph and will also create an a Distance array called DistArray.  It will then perform Dijkstra's algorithm in order to find the shortest path from the 0 node to each other node.
------------------------------------------------------------------*/
int main(){
    /*This initializes an int count to a number of ten, an Adjacency list, called EdgeGraph, that is currently set to have 30 nodes, and a distance array called DistArray that is initialized to count.  Each of these can be changed by reading in a file but as of now they are set to a specific amount. */
    int count=10;
    AdjList* EdgeGraph = new AdjList(30); 
    Distance* DistArray= new Distance(count);
    
/*These create various edges between the nodes of the EdgeGraph. It creates an edge going in both directions as this is an undirected graph.  If it is set as addEdge(x,y,z) then x is the node in the array, y is the sink or destination, and z is the weight of the edge.  This is called as a pointer of the adjacency list.  This can be accomplished more effeciently by reading in from a graph */
EdgeGraph->addEdge(1,2,42);
    
EdgeGraph->addEdge(2,1,42);
    
EdgeGraph->addEdge(2,3,101);

EdgeGraph->addEdge(3,2,101);
    
EdgeGraph->addEdge(3,4,9);
    
EdgeGraph->addEdge(4,3,9);
    
EdgeGraph->addEdge(0,3,3);
    
EdgeGraph->addEdge(3,0,3);

EdgeGraph->addEdge(1,3,60);
    
EdgeGraph->addEdge(3,1,60);
    
EdgeGraph->addEdge(1,4,4);
    
EdgeGraph->addEdge(4,1,4);
    
EdgeGraph->addEdge(2,4,13);
    
EdgeGraph->addEdge(4,2,13);
    
EdgeGraph->addEdge(0,2,6);
    
EdgeGraph->addEdge(2,0,6);    
 //these are two ints used for things later in the main 
int current;  
int i;
//This is the main point of the program which performs Dijkstra's
//it is a loop that performs for as long as there are nodes in the DistArray
for(i=0;i=count;i++){
    
     //this sets current to the next distArray node that needs to be visited by calling visitNext, which chooses the node with the smallest tentDist that has not been visited
   current = DistArray->visitNext();
    
    //it then sets that node to visited=true
    DistArray->visit(current);
    
     //and then creates an Edge node that points to the first struct at point in the array
    Node*neighbor=EdgeGraph->getFirst(current);
    
    //then as long as neighbor is not null it will perform these actions
        while(neighbor!=NULL){
            
        //it sets an int to the tentDist of the current DistArray node
           int costDist=DistArray->getDistance(current);
            
            //then sets an int to the distance to a node connected to that node
            int sinkDist=DistArray->getDistance(neighbor->sink);
            
            //and finds the weight of the edge between them
            int edgeWeight=neighbor->cost;
            
            //if the edge weight + the distance of the current node is less than the cost of the neighboring node
                if((costDist+edgeWeight)<sinkDist){
                    //then the distance of the neighbor is set to the edge weight + the distance of the current node
                    DistArray->setDistance(neighbor->sink, (costDist+edgeWeight));
                        
                //and the parent of the sink is set to the current node
                   DistArray->setParent(neighbor->sink, current);
        }
            //the neighbor then becomes the next struct in the edgeGraph
            neighbor=EdgeGraph->getNext();
    }
   //this continues until all points in the edgeGraph have been completed
}
    
    //this then prints out each distance node and its parents going back to the zero node.  It also prints out the distance to each of those nodes
   for(i=1;i<count;i++){
       cout<<i;
           int next = DistArray->getParent(i);
       while(next!=0){
           cout<<next;
           next=DistArray->getParent(next);
       }
   }
    cout<<endl<<endl;
    return(0);
}



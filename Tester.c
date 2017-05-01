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
    
    int count;
    int edges;
    /* This is the main file read in.  It opens a files, in this cases edges.txt, and then creates an array of distance objects intialized to count, which is the first number in the file.  Then it creates an adjacency list called EdgeGraph that creates a number of nodes equal to "edges" from the file.  It then takes the start, sink, and cost of each edge and implements the edges going in each direction since this is an undirected graph*/
    ifstream(MyInputFile);
    MyInputFile.open("edges.txt");
    MyInputFile>>count>>edges;
    AdjList* EdgeGraph = new AdjList(edges); 
    Distance* DistArray= new Distance(count);
    int start, sink, cost;
    MyInputFile>>start>>sink>>cost;
    while(!MyInputFile.eof()){
        EdgeGraph->addEdge(start, sink, cost);
        EdgeGraph->addEdge(sink, start, cost);
        MyInputFile>>start>>sink>>cost;
    }
    MyInputFile.close();
    
 //these are two ints used for things later in the main 
int current;  
int i;
//This is the main point of the program which performs Dijkstra's
//it is a loop that performs for as long as there are nodes in the DistArray
for(i=0;i<count;i++){
    
     //this sets current to the next distArray node that needs to be visited by calling visitNext, which chooses the node with the smallest tentDist that has not been visited yet
   current = DistArray->visitNext(count);
    
    
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
    
    //this then prints out each distance node and its parents going back to the zero node.  It also prints out the distance to each of those nodes.  It prints in order of farthest node to closest node, followed by the distance

    //this goes through each node and finds its parents and then prints each of them until the last parent left is zero 
   for(i=1;i<count;i++){
       cout<<i<<" ";
           int next = DistArray->getParent(i);
       while(next!=0){
           cout<<next<<" ";
           next=DistArray->getParent(next);
       }
       //zero is always the last parent but the above loop does not print zero so this puts it at the end
       cout<<0<<" ";
       //it then prints the distance after the list of nodes
       cout<< DistArray->getDistance(i)<<" ";
       cout<<endl;
   }

    cout<<endl<<endl;
    return(0);
}



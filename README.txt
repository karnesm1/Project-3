This is a program which creates an adjacency list and an array of distance structs in order to perform Dijkstra's algorithm.
In order to run the program you type ./compute.

The program takes in a file, in this case edge.txt, and then creates an array of distance objects intialized to count, which is the first number in the file.  Then it creates an adjacency list called EdgeGraph that creates a number of nodes equal to "edges" from the file.  It then takes the start, sink, and cost of each edge and implements the edges going in each direction since this is an undirected graph.  

The file should be formatted

count	edges

start	sink	cost

repeating the second line for as many edges as needed.
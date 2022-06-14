// graphs have vertices and edges
// use a array to store vertices (can use hash tables to store named lists)
// vertices = new int[v]

// for edges we could use array of edges, but it will generate big lists, and time
// complexity will increase to O(e) = O(v^2) if search for specific edge (is A connected to D?)
// edges = new int[e][2] (worst case e = v^2, mostly e is mush less e<<v^2)

// for edges we can use Matrix of size V x V
// edges = new int[v][v]

// this will increase space usage O(v^2), but less search time O(1)
// but as most graphs are sparse, better to use Array of Pointers.
// Pointers can be pointing to arrays, but to insert there is a cost of duplicating the array when inserting.
// edges = new *int[v]
// edges[0] = new int[e]

// Another option is to use arary of Linked list. Will increase search time to O(v),
// but will reduce space to O(e) which mostly are much less than O(v^2)
// edges = new *LinkedNode[v]

// To be better, we can use Binary Search Tree which will reduce time search to O(log v)
// edges = new *BstNode[v]

#include <iostream>

int main()
{
    printf("Hello\n");
}

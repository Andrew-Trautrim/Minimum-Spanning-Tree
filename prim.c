#include <stdio.h>

#define N 10
#define I 999
#define U -1

int prim(int graph[N][N], int start);
void getMinimum(int *from, int *to, int visited[N], int graph[N][N]);
void printMST(int parent[N], int key[N]);

int main(void) {

  // adjacency matrix
  int graph[N][N] = {{ I, 10,  I, 20, 20,  5, 15,  5,  I,  I},
                     {10,  I,  5, 10,  I,  I,  I, 20, 15,  5},
                     { I,  5,  I,  5,  I,  I,  I,  I,  I, 15},
                     {20, 10,  5,  I, 10,  I,  I,  I,  I,  I},
                     {20,  I,  I, 10,  I,  5,  I,  I,  I,  I},
                     { 5,  I,  I,  I,  5,  I, 10,  I,  I,  I},
                     {15,  I,  I,  I,  I, 10,  I,  5,  I,  I},
                     { 5, 20,  I,  I,  I,  I,  5,  I, 20,  I},
                     { I, 15,  I,  I,  I,  I,  I, 20,  I, 10},
                     { I,  5, 15,  I,  I,  I,  I,  I, 10,  I}
                    };

  // calculates and prints the minimum spanning spanning tree through the use of Prim's algorithm
  int graphWeight = prim(graph, 0);
  printf("MST weight: %d\n", graphWeight);

  return 0;
}

// Prim's algorithm for finding the Minimum Spanning Tree (MST) of a given undirected weighted graph
int prim(int graph[N][N], int start) {
  int visited[N], parent[N], key[N], weight, from, to;

  // sets all nodes to an unvisited state
  for(int i = 0; i < N; ++i) {
    visited[i] = 0;
    parent[i], key[i] = U;
  }

  visited[start] = 1;
  weight = 0; // keeps track of the total edge weight of the MST

  // MST calculations
  for(int i = 0; i < N-1; ++i) {
    getMinimum(&from, &to, visited, graph);
    visited[to] = 1;
    parent[i] = from; // to keep track of the MST
    key[i] = to;
    weight += graph[from][to];
    from, to = U;
  }
  printMST(parent, key);

  return weight;
}

// function calculates and returns the smallest weight of the verticies not yet visited
void getMinimum(int *from, int *to, int visited[N], int graph[N][N]) {
  int min = I;

  // i represents current node
  for(int i = 0; i < N; ++i) {
    // j represents the next possible node in the tree
    for(int j = 0; j < N; ++j) {
      // if current node is already in the set, the next one isn't, and has the smallest magnitude
      // searches for the smallest weighted node
      if(visited[i] == 1 && visited[j] == 0 && graph[j][i] < min) {
        min = graph[j][i];
        *from = i;
        *to = j;
      }
    }
  }

  return;
}

// function prints the path of the Minimum Spanning Tree
void printMST(int parent[N], int key[N]) {

  for(int i = 0; i < N-1; ++i)
    printf("%d - %d\n", parent[i], key[i]);

  return;
}

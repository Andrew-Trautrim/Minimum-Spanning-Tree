#include <stdio.h>

#define N 10
#define I 999
#define U -1

int prim(int graph[N][N], int start);
void getMinimum(int *from, int *to, int visited[N], int graph[N][N]);

int main(void) {

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
  int graphWeight = prim(graph, 0);

  return 0;
}

int prim(int graph[N][N], int start) {
  int visited[N], weight[N], previous[N], from, to;

  printf("test1\n");

  // sets all nodes to an unvisited state
  for(int i = 0; i < N; ++i) {
    visited[i] = 0;
  }
  visited[start] = 1;

  // MST calculations
  for(int i = 0; i < N; ++i) {
    getMinimum(&from, &to, visited, graph);
    visited[to] = 1;
    printf("%d - %d: %d\n", from, to, graph[from][to]);
    from, to = U;
  }

  return 1;
}

// function calculates and returns the smallest weight of the vertexes not yet visited
void getMinimum(int *from, int *to, int visited[N], int graph[N][N]) {
  int min;

  // i represents current node
  for(int i = 0; i < N; ++i) {
    // j represents the next node in the tree
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

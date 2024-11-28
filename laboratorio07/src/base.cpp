#include <iostream>
#include <vector>

using namespace std;

typedef int vertex;
typedef struct
{
  int V;
  vector<vector<int>> adj;
} Graph;

static int visited[1000];
static void reachR(Graph &G, vertex v);

bool GRAPHreach(Graph &G, vertex s, vertex t)
{
  for (vertex v = 0; v < G.V; ++v)
    visited[v] = 0;

  reachR(G, s);

  if (visited[t] == 1)
    return true;
  else
    return false;
}

static void reachR(Graph &G, vertex v)
{
  visited[v] = 1;

  for (vertex w = 0; w < G.V; ++w)
  {
    if (G.adj[v][w] == 1 && visited[w] == 0)
      reachR(G, w);
  }
}

int main()
{
  return 0;
}

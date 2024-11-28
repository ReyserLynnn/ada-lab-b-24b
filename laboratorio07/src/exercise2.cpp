#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef int vertex;
typedef struct
{
  int V;
  vector<vector<int>> adj;
} Graph;

static int visited[1000];
static bool reachR(Graph &G, vertex v, vertex t);

static vector<vertex> path;

bool GRAPHreach(Graph &G, vertex s, vertex t)
{
  for (vertex v = 0; v < G.V; ++v)
    visited[v] = 0;

  path.clear();

  if (reachR(G, s, t))
  {
    cout << "[+] Camino encontrado de " << s << " a " << t << ": ";
    for (vertex v : path)
      cout << v << " ";
    cout << endl;
    return true;
  }
  else
  {
    cout << "\n[-] No hay camino de " << s << " a " << t << "." << endl;
    return false;
  }
}

static bool reachR(Graph &G, vertex v, vertex t)
{
  visited[v] = 1;

  path.push_back(v);

  if (v == t)
    return true;

  for (vertex w = 0; w < G.V; ++w)
  {
    if (G.adj[v][w] == 1 && visited[w] == 0)
    {
      if (reachR(G, w, t))
        return true;
    }
  }

  path.pop_back();
  return false;
}

int main()
{
  Graph G;
  G.V = 6;
  G.adj = vector<vector<int>>(G.V, vector<int>(G.V, 0));

  G.adj[0][2] = 1;
  G.adj[0][3] = 1;
  G.adj[0][4] = 1;
  G.adj[2][1] = 1;
  G.adj[2][4] = 1;
  G.adj[3][4] = 1;
  G.adj[3][5] = 1;
  G.adj[4][1] = 1;
  G.adj[4][5] = 1;
  G.adj[5][1] = 1;

  if (GRAPHreach(G, 0, 5))
  {
    cout << "\n[+] El vertice 5 esta al alcance del vertice 0." << endl;
  }
  else
  {
    cout << "\n[-] El vertice 5 NO esta al alcance del vertice 0." << endl;
  }

  if (GRAPHreach(G, 2, 3))
  {
    cout << "\n[+] El vertice 3 esta al alcance del vertice 2." << endl;
  }
  else
  {
    cout << "\n[-] El vertice 3 NO esta al alcance del vertice 2." << endl;
  }

  cout << endl;
  return 0;
}

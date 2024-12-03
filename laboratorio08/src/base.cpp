#include <iostream>
#include <vector>

using namespace std;

typedef int vertex;

struct Graph
{
  int V;
  vector<vector<int>> adj;
};

static int cnt;
static int pre[1000];

static void dfsR(Graph &G, vertex v, int depth, vector<int> &order);

void GRAPHdfs(Graph &G, vector<int> &order)
{
  cnt = 0;
  for (vertex v = 0; v < G.V; ++v)
    pre[v] = -1;

  for (vertex v = 0; v < G.V; ++v)
    if (pre[v] == -1)
      dfsR(G, v, 0, order);
}

static void dfsR(Graph &G, vertex v, int depth, vector<int> &order)
{
  // Imprime la indentación correspondiente a la profundidad
  for (int i = 0; i < depth; ++i)
    cout << ". ";

  // Imprime la llamada a dfsR para el vértice actual
  cout << v << " dfsR(G," << v << ")\n";

  pre[v] = cnt++;
  order.push_back(v);

  for (int w = 0; w < G.V; ++w)
  {
    if (G.adj[v][w] == 1)
    {
      for (int i = 0; i < depth; ++i)
        cout << ". ";

      if (pre[w] == -1)
      {
        cout << v << "-" << w << " dfsR(G," << w << ")\n";
        dfsR(G, w, depth + 1, order);
      }
      else
      {
        cout << v << "-" << w << "\n";
      }
    }
  }

  for (int i = 0; i < depth; ++i)
    cout << ". ";
  cout << v << "\n";
}

int main()
{
  Graph G;
  G.V = 12;
  G.adj = vector<vector<int>>(G.V, vector<int>(G.V, 0));

  G.adj[0][1] = 1;
  G.adj[0][4] = 1;
  G.adj[1][2] = 1;
  G.adj[1][5] = 1;
  G.adj[2][3] = 1;
  G.adj[3][7] = 1;
  G.adj[4][8] = 1;
  G.adj[5][4] = 1;
  G.adj[6][5] = 1;
  G.adj[6][10] = 1;
  G.adj[6][2] = 1;
  G.adj[7][11] = 1;
  G.adj[7][6] = 1;
  G.adj[8][9] = 1;
  G.adj[9][5] = 1;
  G.adj[9][8] = 1;
  G.adj[10][9] = 1;
  G.adj[11][10] = 1;

  vector<int> order;

  GRAPHdfs(G, order);

  // Imprime el orden de visita y los números de orden
  cout << "\nw ";
  for (size_t i = 0; i < order.size(); ++i)
    cout << order[i] << " ";
  cout << "\npre[w] ";
  for (size_t i = 0; i < order.size(); ++i)
    cout << pre[order[i]] << " ";
  cout << "\n";

  // Imprime el vector pre[] ordenado por vértice
  cout << "\nv ";
  for (int v = 0; v < G.V; ++v)
    cout << v << " ";
  cout << "\npre[v] ";
  for (int v = 0; v < G.V; ++v)
    cout << pre[v] << " ";
  cout << "\n";

  return 0;
}

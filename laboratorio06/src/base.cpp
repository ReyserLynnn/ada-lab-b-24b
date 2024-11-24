#include <iostream>
using namespace std;

typedef int vertex;
struct node;

struct node
{
  vertex w;
  node *next;
};

struct graph
{
  int V;      // Numero de vertices
  int A;      // Numero de arcos
  node **adj; // Vector de listas de adyacencia

  graph(int V) : V(V), A(0)
  {
    adj = new node *[V];
    for (int v = 0; v < V; ++v)
    {
      adj[v] = nullptr;
    }
  }

  ~graph()
  {
    for (int v = 0; v < V; ++v)
    {
      node *a = adj[v];
      while (a != nullptr)
      {
        node *temp = a;
        a = a->next;
        delete temp;
      }
    }
    delete[] adj;
  }
};

node *NEWnode(vertex w, node *next)
{
  node *a = new node;
  a->w = w;
  a->next = next;
  return a;
}

// Inserta un arco dirigido v-w
void GRAPHinsertArc(graph *G, vertex v, vertex w)
{
  for (node *a = G->adj[v]; a != nullptr; a = a->next)
  {
    if (a->w == w)
      return;
  }
  G->adj[v] = NEWnode(w, G->adj[v]);
  G->A++;
}

int main()
{
  graph *G = new graph(5);

  GRAPHinsertArc(G, 0, 1);
  GRAPHinsertArc(G, 0, 2);
  GRAPHinsertArc(G, 1, 0);
  GRAPHinsertArc(G, 2, 3);
  GRAPHinsertArc(G, 3, 2);

  delete G;
  return 0;
}
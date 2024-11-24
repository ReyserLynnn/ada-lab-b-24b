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

void UGRAPHinsertEdge(graph *G, vertex v, vertex w)
{
  // Inserta el arco v -> w
  bool exists = false;
  for (node *a = G->adj[v]; a != nullptr; a = a->next)
  {
    if (a->w == w)
    {
      exists = true;
      break;
    }
  }
  if (!exists)
  {
    G->adj[v] = NEWnode(w, G->adj[v]);
    G->A++;
  }

  // Inserta el arco w -> v
  exists = false;
  for (node *a = G->adj[w]; a != nullptr; a = a->next)
  {
    if (a->w == v)
    {
      exists = true;
      break;
    }
  }
  if (!exists)
  {
    G->adj[w] = NEWnode(v, G->adj[w]);
    G->A++;
  }
}

void UGRAPHremoveEdge(graph *G, vertex v, vertex w)
{
  // Eliminar el arco v -> w
  node *prev = nullptr;
  node *current = G->adj[v];
  while (current != nullptr)
  {
    if (current->w == w)
    {
      if (prev == nullptr)
      {
        G->adj[v] = current->next;
      }
      else
      {
        prev->next = current->next;
      }
      delete current;
      G->A--;
      break;
    }
    prev = current;
    current = current->next;
  }

  // Eliminar el arco w -> v
  prev = nullptr;
  current = G->adj[w];
  while (current != nullptr)
  {
    if (current->w == v)
    {
      if (prev == nullptr)
      {
        G->adj[w] = current->next;
      }
      else
      {
        prev->next = current->next;
      }
      delete current;
      G->A--;
      break;
    }
    prev = current;
    current = current->next;
  }
}

void GRAPHdestroy(graph *G)
{
  for (int v = 0; v < G->V; ++v)
  {
    node *a = G->adj[v];
    while (a != nullptr)
    {
      node *temp = a;
      a = a->next;
      delete temp;
    }
  }
  delete[] G->adj;
  delete G;
}

void GRAPHshow(graph *G)
{
  for (int v = 0; v < G->V; ++v)
  {
    cout << "Vertice " << v << ":";
    for (node *a = G->adj[v]; a != nullptr; a = a->next)
    {
      cout << " " << a->w;
    }
    cout << endl;
  }
}

bool GRAPHundir(graph *G)
{
  for (int v = 0; v < G->V; ++v)
  {
    for (node *a = G->adj[v]; a != nullptr; a = a->next)
    {
      vertex w = a->w;
      bool found = false;
      for (node *b = G->adj[w]; b != nullptr; b = b->next)
      {
        if (b->w == v)
        {
          found = true;
          break;
        }
      }
      if (!found)
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  graph *G = new graph(5);

  // Insertar aristas no dirigidas
  UGRAPHinsertEdge(G, 0, 1);
  UGRAPHinsertEdge(G, 1, 2);
  UGRAPHinsertEdge(G, 2, 3);
  UGRAPHinsertEdge(G, 3, 4);

  cout << "\n[+] Listas de adyacencia del grafo no dirigido:\n";
  GRAPHshow(G);

  cout << "\n[+] Es no dirigido?: " << (GRAPHundir(G) ? "Si" : "No") << endl;

  // Eliminar una arista
  UGRAPHremoveEdge(G, 1, 2);
  cout << "\n[+] Despues de eliminar la arista 1-2:\n";
  GRAPHshow(G);
  cout << endl;

  GRAPHdestroy(G);
  return 0;
}

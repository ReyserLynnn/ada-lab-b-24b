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

int GRAPHindeg(graph *G, vertex v)
{
  int indeg = 0;
  for (vertex u = 0; u < G->V; ++u)
  {
    for (node *a = G->adj[u]; a != nullptr; a = a->next)
    {
      if (a->w == v)
      {
        ++indeg;
      }
    }
  }
  return indeg;
}

int GRAPHoutdeg(graph *G, vertex v)
{
  int outdeg = 0;
  for (node *a = G->adj[v]; a != nullptr; a = a->next)
  {
    ++outdeg;
  }
  return outdeg;
}

bool GRAPHareAdjacent(graph *G, vertex v, vertex w)
{
  for (node *a = G->adj[v]; a != nullptr; a = a->next)
  {
    if (a->w == w)
    {
      return true;
    }
  }
  return false;
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

void GRAPHremoveArc(graph *G, vertex v, vertex w)
{
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
      return;
    }
    prev = current;
    current = current->next;
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

  GRAPHinsertArc(G, 0, 1);
  GRAPHinsertArc(G, 0, 2);
  GRAPHinsertArc(G, 0, 3);
  GRAPHinsertArc(G, 2, 3);
  GRAPHinsertArc(G, 1, 0);
  GRAPHinsertArc(G, 2, 3);
  GRAPHinsertArc(G, 3, 2);

  // Imprimir grados de entrada y salida de cada vertice
  printf("\n[+] Grados de entrada y salida de cada vertice:\n");
  for (vertex v = 0; v < G->V; ++v)
  {
    printf("Vertice %d: Grado de entrada = %d, Grado de salida = %d\n",
           v, GRAPHindeg(G, v), GRAPHoutdeg(G, v));
  }

  // Verificar adyacencia entre vertices
  printf("\n[+] Verificando adyacencia:\n");
  printf("0 -> 1: %s\n", GRAPHareAdjacent(G, 0, 1) ? "Si" : "No");
  printf("1 -> 0: %s\n", GRAPHareAdjacent(G, 1, 0) ? "Si" : "No");
  printf("2 -> 3: %s\n", GRAPHareAdjacent(G, 1, 3) ? "Si" : "No");
  printf("3 -> 2: %s\n", GRAPHareAdjacent(G, 3, 2) ? "Si" : "No");

  cout << "\n[+] Listas de adyacencia del grafo:\n";
  GRAPHshow(G);

  GRAPHremoveArc(G, 0, 1);
  cout << "\n[+] Despues de eliminar el arco 0 -> 1:\n";
  GRAPHshow(G);

  cout << "\n[+] Es no dirigido?: " << (GRAPHundir(G) ? "Si" : "No") << endl;
  cout << endl;

  GRAPHdestroy(G);

  return 0;
}

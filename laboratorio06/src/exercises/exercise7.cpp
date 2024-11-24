// Inserta una arista no dirigida v-w
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
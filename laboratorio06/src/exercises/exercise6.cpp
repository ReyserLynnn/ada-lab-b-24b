// Verifica si el grafo G es no dirigido
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
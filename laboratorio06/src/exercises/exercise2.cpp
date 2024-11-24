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
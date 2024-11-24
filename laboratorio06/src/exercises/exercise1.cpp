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
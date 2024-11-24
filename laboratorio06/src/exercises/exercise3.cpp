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
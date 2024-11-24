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
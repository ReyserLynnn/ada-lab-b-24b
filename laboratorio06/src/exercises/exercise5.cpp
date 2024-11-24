// Elimina el arco v-w del grafo G
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
// Elimina una arista no dirigida v-w
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
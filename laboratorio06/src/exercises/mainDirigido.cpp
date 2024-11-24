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

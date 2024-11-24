int main()
{
  graph *G = new graph(5);

  // Insertar aristas no dirigidas
  UGRAPHinsertEdge(G, 0, 1);
  UGRAPHinsertEdge(G, 1, 2);
  UGRAPHinsertEdge(G, 2, 3);
  UGRAPHinsertEdge(G, 3, 4);

  cout << "\n[+] Listas de adyacencia del grafo no dirigido:\n";
  GRAPHshow(G);

  cout << "\n[+] Es no dirigido?: " << (GRAPHundir(G) ? "Si" : "No") << endl;

  // Eliminar una arista
  UGRAPHremoveEdge(G, 1, 2);
  cout << "\n[+] Despues de eliminar la arista 1-2:\n";
  GRAPHshow(G);
  cout << endl;

  GRAPHdestroy(G);
  return 0;
}

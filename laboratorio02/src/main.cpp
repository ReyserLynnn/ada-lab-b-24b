#include <iostream>
#include <filesystem>
#include <string>
#include <cstdlib>

int busquedaBinariaOriginal(int x, int n, int v[])
{
  int i = -1, d = n;
  while (i < d - 1)
  {
    int m = (i + d) / 2;
    if (v[m] < x)
      i = m;
    else
      d = m;
  }
  return d;
}

int main(int argc, char *argv[])
{
  std::string fileName = std::filesystem::path(argv[0]).filename().string();

  if (argc < 3)
  {
    std::cout << "\n[-] Uso: ./" << fileName << " <x> <numero1> <numero2> ... <numero n>\n"
              << std::endl;
    return 1;
  }

  int x = std::stoi(argv[1]);
  int n = argc - 2;
  int *numbers = new int[n];

  std::cout << "\n[*] v: ";
  for (int i = 0; i < n; i++)
  {
    numbers[i] = std::stoi(argv[i + 2]);
    std::cout << argv[i + 2] << ", ";
  }

  std::cout << "\n[*] x: " << x << "\n[*] n: " << n << std::endl;

  int r1 = busquedaBinariaOriginal(x, n, numbers);
  std::cout << "\n\n[+] Result : " << r1 << std::endl;

  printf("\n\n");
  delete argv;
  return 0;
}
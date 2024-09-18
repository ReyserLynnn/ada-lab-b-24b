#include <iostream>
#include <cstdlib>
#include <string>
#include <filesystem>

int main(int argc, char *argv[])
{
  std::filesystem::path filePath(argv[0]);
  std::string fileName = filePath.filename().string();

  if (argc < 2)
  {
    std::cout << "\n[+] Uso: ./" << fileName << " <numero1> <numero2> ... <numeroN>\n\n";
    return 1;
  }

  int *numbers = new int[argc - 1];
  int min = std::atoi(argv[1]);

  for (int i = 1; i < argc; ++i)
  {
    numbers[i - 1] = std::atoi(argv[i]);
  }

  for (int i = 1; i < argc - 1; ++i)
  {
    if (numbers[i] < min)
    {
      min = numbers[i];
    }
  }

  std::cout << "\n[+] Numero menor del array ingresado: " << min << "\n";

  delete[] numbers;
  printf("\n\n");
  return 0;
}
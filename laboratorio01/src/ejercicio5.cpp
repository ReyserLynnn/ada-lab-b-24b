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

  for (int i = 1; i < argc; ++i)
  {
    numbers[i - 1] = std::atoi(argv[i]);
  }

  int totalSum = 0;

  for (int i = 0; i < argc - 1; ++i)
  {
    totalSum += numbers[i];
  }

  bool matchFound = false;

  for (int i = 0; i < argc - 1; ++i)
  {
    if (numbers[i] == (totalSum - numbers[i]))
    {
      std::cout << "\n[+] El numero "
                << numbers[i] << " equivale a la suma de los demas numeros.\n";
      matchFound = true;
      break;
    }
  }

  if (!matchFound)
  {
    std::cout << "\n[-] No hay ningun numero que sea la suma de los demas.\n";
  }

  delete[] numbers;
  printf("\n\n");
  return 0;
}
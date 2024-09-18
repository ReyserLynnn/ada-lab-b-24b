#include <iostream>
#include <cstdlib>
#include <filesystem>

void printArray(const int array[], int size, const std::string &name)
{
  std::cout << name << " = [";
  for (int i = 0; i < size; ++i)
  {
    std::cout << array[i];
    if (i < size - 1)
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char *argv[])
{
  std::filesystem::path filePath(argv[0]);
  std::string fileName = filePath.filename().string();

  if (argc < 2)
  {
    std::cout << "\n[>] Uso: ./" << fileName << " <numero1> <numero2> ... <numeroN>\n\n";
    return 1;
  }

  int size = argc - 1;
  int *numbers = new int[size];

  int *numPar = new int[size];
  int *numImpar = new int[size];
  int sizePar = 0;
  int sizeImpar = 0;

  for (int i = 1; i < argc; ++i)
  {
    numbers[i - 1] = std::atoi(argv[i]);
  }

  for (int i = 0; i < size; ++i)
  {
    if (numbers[i] % 2 == 0)
    {
      numPar[sizePar++] = numbers[i];
    }
    else
    {
      numImpar[sizeImpar++] = numbers[i];
    }
  }

  printArray(numbers, size, "\n[#] A1: ");
  printArray(numPar, sizePar, "\n[+] numPar");
  printArray(numImpar, sizeImpar, "\n[+] numImpar");

  delete[] numbers;
  delete[] numPar;
  delete[] numImpar;
  printf("\n\n");
  return 0;
}

#include <iostream>
#include <cstdlib>
#include <string>
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

  if (argc != 11)
  {
    std::cout << "\n[>] Uso: ./" << fileName << " <numero1> <numero2> ... <numero10>\n\n";
    return 1;
  }

  const int size = 10;
  int *numbers = new int[size];
  int *products = new int[size];
  int numberToMultiply;

  for (int i = 0; i < size; ++i)
  {
    numbers[i] = std::atoi(argv[i + 1]);
  }

  std::cout << "\n[+] Ingrese el numero a multiplicar: ";
  std::cin >> numberToMultiply;

  printArray(numbers, size, "\n[#] A1");

  for (int i = 0; i < size; ++i)
  {
    products[i] = numbers[i] * numberToMultiply;
  }

  printArray(products, size, "\n[+] A2");

  delete[] numbers;
  delete[] products;
  printf("\n\n");
  return 0;
}
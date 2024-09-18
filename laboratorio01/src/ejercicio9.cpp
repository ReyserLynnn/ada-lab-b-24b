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

void moveZerosToEnd(int arr[], int n)
{
  int lastNonZeroIndex = 0;

  for (int i = 0; i < n; ++i)
  {
    if (arr[i] != 0)
    {
      arr[lastNonZeroIndex] = arr[i];
      lastNonZeroIndex++;
    }
  }

  for (int i = lastNonZeroIndex; i < n; ++i)
  {
    arr[i] = 0;
  }
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

  const int size = argc - 1;
  int *numbers = new int[size];

  for (int i = 1; i < argc; ++i)
  {
    numbers[i - 1] = std::atoi(argv[i]);
  }

  printArray(numbers, size, "\nA1");

  moveZerosToEnd(numbers, size);

  printArray(numbers, size, "\nA2");

  delete[] numbers;
  printf("\n\n");
  return 0;
}

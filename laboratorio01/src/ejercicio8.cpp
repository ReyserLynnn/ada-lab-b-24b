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

bool hasZeroSumSubarray(int arr[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    int total = 0;

    for (int j = i; j < n; ++j)
    {
      total += arr[j];

      if (total == 0)
      {
        return true;
      }
    }
  }

  return false;
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

  printArray(numbers, size, "\n[#] Array");

  if (hasZeroSumSubarray(numbers, size))
  {
    std::cout << "\n[+] Subarray existe." << std::endl;
  }
  else
  {
    std::cout << "\n[-] No existe subarray con suma cero." << std::endl;
  }

  delete[] numbers;
  printf("\n\n");
  return 0;
}

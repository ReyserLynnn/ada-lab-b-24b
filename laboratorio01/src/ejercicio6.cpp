#include <iostream>
#include <string>

void printArray(const char array[], int size, const std::string &name)
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

int main()
{
  char array1[] = {'a', 'b', 'c', 'd', 'e'};
  char array2[] = {'v', 'w', 'x', 'y', 'z'};

  int size1 = sizeof(array1) / sizeof(array1[0]);
  int size2 = sizeof(array2) / sizeof(array2[0]);

  printf("\n");
  printArray(array1, size1, "A1");
  printArray(array2, size2, "A2");

  char *array3 = new char[size1 + size2];

  for (int i = 0; i < size1; ++i)
  {
    array3[i] = array1[i];
  }

  for (int i = 0; i < size2; ++i)
  {
    array3[size1 + i] = array2[i];
  }

  printArray(array3, size1 + size2, "A3");

  delete[] array3;
  printf("\n\n");
  return 0;
}

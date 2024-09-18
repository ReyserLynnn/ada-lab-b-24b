#include <iostream>

int main()
{
  int size;

  std::cout << "\n[+] Ingrese la cantidad de numeros a multiplicar : ";
  std::cin >> size;

  int *numbers = new int[size];

  std::cout << "\n[+] Ingrese los numeros (separados por un espacio): ";
  for (int i = 0; i < size; ++i)
  {
    std::cin >> numbers[i];
  }

  int product = 1;
  for (int i = 0; i < size; ++i)
  {
    product *= numbers[i];
  }

  std::cout << "\n- La multiplicacion de los numeros es: " << product << std::endl;

  printf("\n\n");
  delete[] numbers;

  return 0;
}

#include <iostream>

int main() { 
  char ch;
  while (std::cin) {
    std::cin >> ch;
    std::cout << "[" << ch << "]" << std::endl;
  }
  return 0;
}

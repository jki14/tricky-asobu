#include <iostream>
#include <random>

int main() {
  std::random_device rd;
  srand(rd());
  unsigned long long foo = 0LL;
  for (int i = 0; i < 100000000; ++i) {
    foo += rand();
  }
  std::cout << foo << std::endl;
  return 0;
}

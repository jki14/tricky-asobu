#include <cstdlib>
#include <iostream>

int main() {
  uint64_t foo = 1LL << 63;
  auto const bar = foo & (-foo);
  std::cout << bar << std::endl;

  size_t req = 1LL << 64;
  std::cout << req << std::endl;

  req = 1LL << 65;
  std::cout << req << std::endl;
  return 0;
}

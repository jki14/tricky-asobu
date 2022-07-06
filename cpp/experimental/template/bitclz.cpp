#include "bitclz.hpp"

#include <iostream>

typename std::enable_if<std::is_same<size_t, unsigned long>::value, size_t>::type
bitclz(size_t const i) {
  static constexpr size_t fullsize = __builtin_clzl(1) + 1;
  return i ? fullsize - __builtin_clzl(i) : 0;
}

int main() {
  for (size_t i = 0; i < 64; ++i) {
    size_t const x = 1LL << i, y = (1LL << i) + 1;
    std::cout << "bitclz(" << x << ") = " << bitclz(x) << std::endl;
    std::cout << "bitclz(" << y << ") = " << bitclz(y) << std::endl;
  }
  std::cout << "bitclz(" << 0 << ") = " << bitclz(0) << std::endl;
  return 0;
}

#include <cassert>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> empty;
  auto const d = empty.size() - 1;
  std::cout << d << std::endl;
  assert(1 < d);
  return 0;
}

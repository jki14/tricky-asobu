#include <cassert>

int main() {
  bool found = false;
  constexpr int d = 4;
  found |= d;
  assert(found);
  return 0;
};

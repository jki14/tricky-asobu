#include <cassert>
#include <iterator>
#include <list>
#include <vector>

int main() {
  std::vector<int> foo;
  for (int i = 0; i < 100; ++i) {
    auto const it = foo.end();
    auto const prev = foo.capacity();
    foo.emplace_back(i);
    assert((prev == foo.capacity()) == (it == std::prev(foo.end())));
  }
  return 0;
}

#include <cassert>
#include <vector>
#include <utility>

int main() {
  std::vector<int> foo;
  foo.reserve(8);
  auto const it = foo.begin();
  std::vector<int> bar = std::move(foo);
  assert(it == bar.begin());
  assert(it != foo.begin());
  return 0;
}

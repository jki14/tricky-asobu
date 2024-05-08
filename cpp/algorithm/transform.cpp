#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
  std::vector<int> foo = {2, 3, 5, 7};

  std::vector<int> goo;
  goo.resize(foo.size());
  std::transform(foo.begin(), foo.end(), goo.begin(), [](int const i){ return i + 1; });
  std::ranges::for_each(goo, [](int const i){ std::cout << i << std::endl; });
  std::cout << "size = " << goo.size() << std::endl;

  auto rv = foo | std::views::transform([](int const i){ return i + 1; });
  std::vector<int> hoo(rv.begin(), rv.end());
  std::ranges::for_each(hoo, [](int const i){ std::cout << i << std::endl; });
  std::cout << "size = " << hoo.size() << std::endl;

  return 0;
}

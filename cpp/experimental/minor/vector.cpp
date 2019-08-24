#include <iostream>
#include <vector>

int main() {
  std::vector<int> foo;
  std::cout << foo.capacity() << std::endl;
  foo.reserve(4);
  std::cout << foo.capacity() << std::endl;
  foo.clear();
  std::cout << foo.capacity() << std::endl;
  foo.emplace_back(4);
  std::cout << foo.capacity() << std::endl;
  foo.clear();
  std::cout << foo.capacity() << std::endl;
  foo.emplace_back(4);
  foo.emplace_back(4);
  foo.emplace_back(4);
  foo.emplace_back(4);
  foo.emplace_back(4);
  std::cout << foo.capacity() << std::endl;
  foo.clear();
  std::cout << foo.capacity() << std::endl;
  return 0;
}

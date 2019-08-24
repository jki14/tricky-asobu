#include <cassert>
#include <iostream>

bool func() {
  std::cout << "func()" << std::endl;
  return true;
}

int main() {
  bool foo = false;
  foo |= func();
  assert(foo);
  foo |= func();
  assert(foo);
  return 0;
}

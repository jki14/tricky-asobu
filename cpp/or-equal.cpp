#include <iostream>


bool isodd(int const i) {
  std::cout << "isodd(" << i << ")" << std::endl;
  return i & 1;
}

int main() {
  bool flag = false;
  flag |= isodd(0);
  std::cout << "    flag = " << flag << std::endl;
  flag |= isodd(1);
  std::cout << "    flag = " << flag << std::endl;
  flag |= isodd(2);
  std::cout << "    flag = " << flag << std::endl;
  flag |= isodd(3);
  std::cout << "    flag = " << flag << std::endl;
  flag |= isodd(4);
  std::cout << "    flag = " << flag << std::endl;
  return 0;
}

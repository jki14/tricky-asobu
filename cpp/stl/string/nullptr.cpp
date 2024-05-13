#include <iostream>
#include <string>

int main() {
  static char const* const nullstr = nullptr;
  std::string str(nullstr);
  std::cout << str << std::endl;
  return 0;
}

#include <iostream>

#include <boost/optional/optional.hpp>

int main() {
  boost::optional<unsigned> foo = boost::none;
  std::cout << static_cast<bool>(foo) << std::endl;
  foo = 14;
  std::cout << static_cast<bool>(foo) << std::endl;
  return 0;
}

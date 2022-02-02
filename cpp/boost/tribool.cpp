#include <iostream>

#include <boost/logic/tribool.hpp>

void solution(boost::tribool const& tb) {
  std::cout << tb << std::endl;
  if (tb) {
    std::cout << "true" << std::endl;
  } else if (!tb) {
    std::cout << "false" << std::endl;
  } else {
    std::cout << "indeterminate" << std::endl;
  }
}

int main() {
  boost::tribool tb = boost::indeterminate;
  solution(tb);
  tb = true;
  solution(tb);
  tb = false;
  solution(tb);
  return 0;
}

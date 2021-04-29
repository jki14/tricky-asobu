#include <iostream>
#include <random>

int main() {
  std::random_device rd;
  std::cout << "rd.max() = " << rd.max() << std::endl;
  std::cout << "rd.min() = " << rd.min() << std::endl;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(0, 9);
  for (int i = 0; i < 32; ++i) {
    std::cout << distrib(gen) << std::endl;
  }
  return 0;
}

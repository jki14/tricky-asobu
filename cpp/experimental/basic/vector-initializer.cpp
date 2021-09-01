#include <iostream>
#include <vector>

void solution(std::vector<std::vector<int>> const& foo) {
  for (auto const& row : foo) {
    for (auto const& cell : row) {
      std::cout << cell << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  solution({ 
    {5, 1, 4},
    {1, 1, 1, 4}
  });
  return 0;
}

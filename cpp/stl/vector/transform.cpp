#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::vector<std::pair<std::string, int>> const foo {
    {"tier-1", 1},
    {"tier-2", 2},
    {"tier-3", 3},
    {"tier-4", 4},
    {"tier-5", 5},
    {"tier-robot", 5},
    {"tier-unknown", 5}
  };
  std::vector<std::pair<std::string, double>> bar;
  bar.reserve(foo.size());
  std::transform(foo.begin(), foo.end(), std::back_inserter(bar),
                 [](std::pair<std::string, int> const& e) ->
                     std::pair<std::string, double> {
                         return {e.first, 0.0};
                     });
  for (auto const& e : bar) {
    std::cout << e.first << ", " << e.second << std::endl;
  }
  return 0;
}

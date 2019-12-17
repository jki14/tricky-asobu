#include <cassert>
#include <chrono>
#include <iostream>

static constexpr int i = 1024;
static constexpr double d = 3.14;
static constexpr unsigned u = 4;

// decltype(std::chrono::milliseconds(u))::oti4go();

int main() {
  auto const foo = std::chrono::milliseconds(1u);
  decltype(std::chrono::microseconds(u)) bar(1000u);
  std::cerr << bar.count() << std::endl;
  assert(foo == bar);
  return 0;
}

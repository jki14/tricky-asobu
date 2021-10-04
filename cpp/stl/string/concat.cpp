#include <cstring>
#include <iostream>
#include <string>

static char const* const names[3] = {
  "Control",
  "T1",
  "T2"
};

std::string solution(size_t const offset) {
  std::string foo = offset > 0 ? std::string(names[offset]) + "-X-" : "X-";
  return foo;
}

int main() {
  for (int i = 0; i < 3; ++i) {
    std::cout << solution(i) << std::endl;
  }
  return 0;
}

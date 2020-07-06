#include <iostream>
#include <sys/time.h>

int main() {
  struct timeval foo = {0, 0};
  gettimeofday(&foo, NULL);
  auto const bar = (uint64_t)foo.tv_sec * 1000000 + foo.tv_usec;
  std::cout << bar << std::endl;
  return 0;
}

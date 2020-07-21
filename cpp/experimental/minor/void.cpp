#include <cstdio>

struct custom_t {
  int foo;
  void bar;
};

int main() {
  printf("%lu\n", sizeof(custom_t));
  return 0;
}

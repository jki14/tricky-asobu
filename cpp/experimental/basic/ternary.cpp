#include <cstdio>

int main() {
  int foo = 4;
  for (int i = 0; i < 4; ++i) {
    printf(": %d => ", foo);
    foo = (foo - 2) ? : (foo + 1);
    printf("%d\n", foo);
  }
  return 0;
}

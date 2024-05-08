#include <cstdio>
#include <iostream>
#include <sys/mman.h>
#include <unistd.h>

struct context_t {
  int serial_number;
  
  context_t() {
    static int serial_number_used = 0;
    serial_number = ++serial_number_used;
  }
};

int main() {
  pid_t pid = fork();
  for (int i = 0; i < 4; ++i) {
    context_t const foo;
    std::cout << "serial_num = " << foo.serial_number << " @ " << pid << std::endl;
  }
  return 0;
}

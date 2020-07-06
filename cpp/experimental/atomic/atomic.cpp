#include <array>
#include <atomic>
#include <iostream>

#include <sys/mman.h>

typedef std::array<std::atomic<int>, 101> table_t;

int main() {
  table_t* foo = reinterpret_cast<table_t*>(mmap(NULL,
                                                 sizeof(table_t),
                                                 PROT_READ | PROT_WRITE,
                                                 MAP_SHARED | MAP_ANONYMOUS,
                                                 -1,
                                                 0));
  
  for (auto &cell : *foo) {
    cell = 0;
  }
  for (int k = 0; k < 10000000; ++k) {
    for (int i = 0; i < 101; ++i) {
      ++(*foo)[i];
    }
  }
  std::cout << (*foo)[14].is_lock_free() << std::endl;
  return 0;
}

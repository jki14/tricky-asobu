#include <array>
#include <atomic>
#include <cstdio>
#include <iostream>
#include <sys/mman.h>
#include <unistd.h>

using vanilla_t = std::array<int, 100>;
using volatile_t = std::array<volatile int, 100>;
using atomic_t = std::array<std::atomic<int>, 100>;

int main() {
  vanilla_t* vanilla_ = reinterpret_cast<vanilla_t*>(
      mmap(NULL,
           sizeof(vanilla_t),
           PROT_READ | PROT_WRITE,
           MAP_SHARED | MAP_ANONYMOUS,
           -1,
           0));
  volatile_t* volatile_ = reinterpret_cast<volatile_t*>(
      mmap(NULL,
           sizeof(volatile_t),
           PROT_READ | PROT_WRITE,
           MAP_SHARED | MAP_ANONYMOUS,
           -1,
           0));
  atomic_t* atomic_ = reinterpret_cast<atomic_t*>(
      mmap(NULL,
           sizeof(atomic_t),
           PROT_READ | PROT_WRITE,
           MAP_SHARED | MAP_ANONYMOUS,
           -1,
           0));

  (*vanilla_)[14] = 0;
  (*volatile_)[14] = 0;
  (*atomic_)[14] = 0;

  int pid = fork();
  for (int i = 0; i < 1000000; ++i) {
    ++(*vanilla_)[14];
    ++(*volatile_)[14];
    ++(*atomic_)[14];
  }

  std::cout << "[" << pid << "] vanilla = " << (*vanilla_)[14] << std::endl;
  std::cout << "[" << pid << "] volatile = " << (*volatile_)[14] << std::endl;
  std::cout << "[" << pid << "] atomic = " << (*atomic_)[14] << std::endl;

  return 0;
}

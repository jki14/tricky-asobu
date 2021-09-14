#include <cassert>
#include <cstdio>
#include <iostream>

#include <sys/mman.h>
#include <unistd.h>

void statm(pid_t pid) {
  static size_t const pagesize = sysconf(_SC_PAGESIZE);
  static size_t constexpr mb = 1048576;

  FILE *procStatm = fopen("/proc/self/statm", "r");
  assert(procStatm != NULL);
  long size, resident, share, text, lib, data, dt;
  assert(fscanf(procStatm, "%ld %ld %ld %ld %ld %ld %ld",
                &size, &resident, &share, &text, &lib, &data, &dt) == 7);
  fclose(procStatm);

  std::cout << "[" << pid << "]"
            << " data = " << data * pagesize / mb << " MB"
            << ", share = " << share * pagesize / mb << " MB"
            << std::endl;
}

int main() {
  static size_t constexpr num = 134217728;

  int* foo = static_cast<int*>(malloc(sizeof(int) * num));
  int* bar = static_cast<int*>(
      mmap(NULL,
           sizeof(int) * num,
           PROT_READ | PROT_WRITE,
           MAP_SHARED | MAP_ANONYMOUS,
           -1,
           0));

  auto pid = fork();

  for (size_t i = 0; i < num / 2; ++i) {
    foo[i] = pid;
  }

  for (size_t i = 0; i < num / 2; ++i) {
    bar[i] = pid;
  }

  statm(pid);
  return 0;
}

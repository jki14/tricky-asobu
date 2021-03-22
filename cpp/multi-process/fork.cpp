#include <cstdio>
#include <iostream>
#include <sys/mman.h>
#include <unistd.h>

class myclass_t {
public:
  myclass_t() = delete;
  myclass_t(pid_t id) {
    std::cout << "Construct at: "<< id << std::endl;
  }
};

int main() {
  static myclass_t before_fork(-1);
  int* non_shared_int_ptr = reinterpret_cast<int*>(malloc(sizeof(int)));
  int* shared_int_ptr = reinterpret_cast<int*>(
      mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0));
  pid_t pid = fork();
  static myclass_t after_fork(pid);
  if (pid != 0) {
    *non_shared_int_ptr = pid;
    *shared_int_ptr = pid;
  } else {
    sleep(1);
  }
  std::cout << "[" << pid << "] " << *non_shared_int_ptr << " @ " << non_shared_int_ptr << std::endl;
  std::cout << "[" << pid << "] " << *shared_int_ptr << " @ " << shared_int_ptr << std::endl;
  return 0;
}

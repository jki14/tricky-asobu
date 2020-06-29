#include <cstdio>

class tracker_t {
public:
tracker_t() = delete;
tracker_t(int const init) {
  foo = init;
}

tracker_t(tracker_t const&) = default;
tracker_t(tracker_t&&) = default;

tracker_t& operator=(tracker_t const&) = default;
tracker_t& operator=(tracker_t&&) = default;

tracker_t& operator+(int const inc) {
  foo += inc;
  return *this;
}

int get() const {
  return foo;
}

operator bool() const {
  return (foo & 1) != 0;
}

private:
int foo = 0;
};

int main() {
  int foo = 4;
  for (int i = 0; i < 4; ++i) {
    printf(": %d => ", foo);
    foo = (foo - 2) ? : (foo + 1);
    printf("%d\n", foo);
  }
  tracker_t bar(3);
  for (int i = 0; i < 2; ++i) {
    printf(": %d => ", bar.get());
    bar = (bar) ? : bar + 1;
    printf("%d\n", bar.get());
  }
  bar = bar + 1;
  for (int i = 0; i < 2; ++i) {
    printf(": %d => ", bar.get());
    bar = (bar) ? : bar + 1;
    printf("%d\n", bar.get());
  }
  return 0;
}

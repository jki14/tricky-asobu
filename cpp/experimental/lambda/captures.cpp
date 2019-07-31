#include <algorithm>
#include <iostream>
#include <vector>

#include "tracker_t.hpp"

class mutable_tracker_t : tracker_t {
public:
  void execute() {
    ++count;
  }
  void show() const {
    std::cout << count << std::endl;
  }
private:
  int count = 0;
};

int main() {
  mutable_tracker_t obj;

  auto const foo = [&inner = static_cast<mutable_tracker_t const&>(obj)]() -> mutable_tracker_t const& {
    inner.show();
    return inner;
  };

  auto const bar = foo;

  foo();
  bar().show();

  return 0;
}

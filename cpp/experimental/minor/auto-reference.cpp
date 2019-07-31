#include <map>

#include "tracker_t.hpp"

typedef tracker_t const ctracker_t;

ctracker_t const& foobar() {
  static ctracker_t foo;
  return foo;
}

int main() {
  std::map<int, ctracker_t&> const foo {
    {4, foobar()}
  };
  auto const bar = foo.at(4);
  bar.show();
  return 0;
}

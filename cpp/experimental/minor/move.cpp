#include "tracker_t.hpp"

#include <utility>

class container_t {
public:
  container_t() = default;
  container_t(container_t const&) = delete;
  container_t(container_t&& rhs)
    : foo_(rhs.foo_) { }  // copy constructing foo_
private:
  tracker_t foo_;
};

int main() {
  container_t foo;
  container_t bar(std::move(foo));
  return 0;
}

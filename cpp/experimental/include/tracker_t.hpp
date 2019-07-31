#include <iostream>

class tracker_t {
public:
  tracker_t() {
    std::cerr << "[tracker] new instance **construct** at " << (size_t)this << std::endl;
  }
  tracker_t(tracker_t const& rhs) {
    std::cerr << "[tracker] new instance **copy construct** at " << (size_t)this << " from " << (size_t)&rhs << std::endl;
  }
  tracker_t(tracker_t&& rhs) {
    std::cerr << "[tracker] new instance **move construct** at " << (size_t)this << " from " << (size_t)&rhs << std::endl;
  }

  ~tracker_t() {
    std::cerr << "[tracker] the instance at " << (size_t)this << " destruct" << std::endl;
  }

  tracker_t& operator=(tracker_t const& rhs) {
    std::cerr << "[tracker] the instance at " << (size_t)this << " **copy assignment from " << (size_t)&rhs << std::endl;
    return *this;
  }
  tracker_t& operator=(tracker_t&& rhs) {
    std::cerr << "[tracker] the instance at " << (size_t)this << " **move assignment from " << (size_t)&rhs << std::endl;
    return *this;
  }

  void show() const {
    std::cout << "[tracker] show tracker at " << (size_t)this << std::endl;
  }
};

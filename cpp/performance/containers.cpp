#include <chrono>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class tester {
public:
  tester() = default;

  virtual void init() = 0;
  virtual void access() = 0;

protected:
  class timer {
  public:
    timer() = delete;
    timer(std::string const& title) : title_(title) {
      tic_ = std::chrono::steady_clock::now();
    }
    ~timer() {
      auto const tac = std::chrono::steady_clock::now();
      std::chrono::duration<double> const walltime = tac - tic_;
      std::cout << title_ << " : " 
                << std::fixed << std::setprecision(6)
                << walltime.count()
                << std::endl;
    }
  private:
    std::string title_;
    decltype(std::chrono::steady_clock::now()) tic_;
  };

  static constexpr size_t size = 1048576;
  static constexpr size_t loop = 128;
};

class raw_t : public tester {
public:
  raw_t() = default;
  raw_t(raw_t const&) = delete;
  raw_t(raw_t&&) = delete;

  ~raw_t() {
    delete foo_;
  }

  void init() override {
    tester::timer t("raw.init()");
    for (size_t k = 0; k < tester::loop; ++k) {
      // clean
      for (size_t i = 0; i < tester::size; ++i) {
        foo_[i] = 0;
      }
      // init
      for (size_t i = 0; i < tester::size; ++i) {
        foo_[i] = i;
      }
    }
  }
 
  void access() override {
    tester::timer t("raw.access()");
    static int64_t sum = 0;
    for (size_t k = 0; k < tester::loop; ++k) {
      for (size_t i = 0; i < tester::size; ++i) {
        sum += foo_[i];
      }
    }
  }
private:
  int64_t* foo_ = new int64_t[tester::size];
};

class vector_t : public tester {
public:
  vector_t() {
    foo_.reserve(tester::size);
  }

  void init() override {
    tester::timer t("vector.init()");
    for (size_t k = 0; k < tester::loop; ++k) {
      // clean
      foo_.clear();
      // init
      for (size_t i = 0; i < tester::size; ++i) {
        foo_.push_back(i);
      }
    }
  }
  void access() override {
    tester::timer t("vector.access()");
    static int64_t sum = 0;
    for (size_t k = 0; k < tester::loop; ++k) {
      for (size_t i = 0; i < tester::size; ++i) {
        sum += foo_[i];
      }
    }
  }
private:
  std::vector<int64_t> foo_;
};

class umap_t : public tester {
public:
  umap_t() {
    //foo_.reserve(tester::size);
  }

  void init() override {
    tester::timer t("unordered_map.init()");
    for (size_t k = 0; k < tester::loop; ++k) {
      // clean
      foo_.clear();
      // init
      for (size_t i = 0; i < tester::size; ++i) {
        foo_.emplace(i, static_cast<int64_t>(i));
      }
    }
  }
  void access() override {
    tester::timer t("unordered_map.access()");
    static int64_t sum = 0;
    for (size_t k = 0; k < tester::loop; ++k) {
      for (size_t i = 0; i < tester::size; ++i) {
        sum += foo_[i];
      }
    }
  }
private:
  std::unordered_map<size_t, int64_t> foo_;
};

class map_t : public tester {
public:
  map_t() = default;

  void init() override {
    tester::timer t("unordered_map.init()");
    for (size_t k = 0; k < tester::loop; ++k) {
      // clean
      foo_.clear();
      // init
      for (size_t i = 0; i < tester::size; ++i) {
        foo_.emplace(i, static_cast<int64_t>(i));
      }
    }
  }
  void access() override {
    tester::timer t("unordered_map.access()");
    static int64_t sum = 0;
    for (size_t k = 0; k < tester::loop; ++k) {
      for (size_t i = 0; i < tester::size; ++i) {
        sum += foo_[i];
      }
    }
  }
private:
  std::map<size_t, int64_t> foo_;
};

int main() {
  raw_t raw;
  raw.init();
  raw.access();
  vector_t vec;
  vec.init();
  vec.access();
  /*
  umap_t umap;
  umap.init();
  umap.access();
  map_t map;
  map.init();
  map.access();
  */
  return 0;
}

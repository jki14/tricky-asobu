#include <algorithm>
#include <iostream>
#include <vector>

#include "range/v3/all.hpp"

#include "tracker_t.hpp"

template<typename Rng>
class reverse_block_view
    : public ranges::view_adaptor<reverse_block_view<Rng>, Rng, ranges::finite> {
public:
  using item_t = ranges::value_type_t<ranges::iterator_t<Rng>>;

  template<typename Rhs>
  reverse_block_view(Rng rng, Rhs rhs)
      : reverse_block_view<Rng>::view_adaptor(std::move(rng))
      , sentinel_(ranges::end(this->rng_))
      , len_(std::max(rhs, 1)) {
  }

  reverse_block_view() = default;

private:
  friend struct ranges::range_access;

  struct adaptor : ranges::adaptor_base {
    adaptor() = default;

    adaptor(reverse_block_view* view)
        : view_(view) {
      view_->compile(ranges::begin(view_->rng_), 0);
    }

    item_t const& read(ranges::iterator_t<Rng> const& iter) const {
      return view_->get(loc_);
    }

    void next(ranges::iterator_t<Rng>& iter) {
      ++iter;
      ++loc_;
      view_->compile(iter, loc_);
    }

    reverse_block_view* view_ = nullptr;
    size_t loc_ = 0;
  };

  struct sentinel_adaptor : ranges::adaptor_base {
    sentinel_adaptor() = default;
    static bool empty(ranges::iterator_t<Rng> const& iter,
                      adaptor const& adapt,
                      ranges::sentinel_t<Rng> const& sentinel) {
      return iter == sentinel;
    }
  };

  void compile(ranges::iterator_t<Rng> iter, size_t loc) {
    if (iter == sentinel_) return;

    size_t const id = loc / len_;
    if (store_.size() <= id) {
      store_.resize(id + 1, {});
    }
    auto& block = store_[id];
    if (block.empty()) {
      for (size_t const first = len_ * id; loc > first; --loc) {
        --iter;
      }
      block.reserve(len_);
      for (size_t const last = len_ * (id + 1);
           iter != sentinel_ && loc < last;
           ++loc) {
        block.emplace_back(*iter);
        ++iter;
      }
      std::reverse(block.begin(), block.end());
    }
  }

  item_t const& get(size_t const loc) const {
    size_t const k = loc / len_;
    size_t const p = loc - len_ * k;
    return store_[k][p];
  }

  adaptor begin_adaptor() {
    return {this};
  }

  sentinel_adaptor end_adaptor() {
    return {};
  }

  ranges::sentinel_t<Rng> sentinel_;
  std::vector<std::vector<item_t>> store_;
  size_t len_ = 1;
  tracker_t tracker;
};

struct reverse_block_fn {
private:
  friend struct ranges::view::view_access;

  template<typename Rhs>
  static auto bind(reverse_block_fn fn, Rhs rhs) -> decltype(
    ranges::make_pipeable(std::bind(fn, std::placeholders::_1,  ranges::protect(std::move(rhs))))
  ) {
    return ranges::make_pipeable(std::bind(fn, std::placeholders::_1,  ranges::protect(std::move(rhs))));
  }

public:
  template<typename Rng, typename Rhs>
  reverse_block_view<ranges::view::all_t<Rng>>
  operator () (Rng&& rng, Rhs rhs) const {
    return {ranges::view::all(static_cast<Rng&&>(rng)), std::move(rhs)};
  }
};

inline namespace {
  constexpr auto& reverse_block = ranges::static_const<ranges::view::view<reverse_block_fn>>::value;
}

int main() {
  auto foo = ranges::view::ints
    | ranges::view::take(7)
    | reverse_block(4)
    | reverse_block(4)
    | reverse_block(4)
    | ranges::view::take(7);

  std::vector<int> goo = foo;
  for (int x : goo) {
    std::cout << x << std::endl;
  }

  return 0;
}

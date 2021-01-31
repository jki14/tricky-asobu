#include <array>
#include <atomic>
#include <iostream>
#include <type_traits>

template<bool IsAtomic>
class stat_t {
public:
  stat_t();
  stat_t(int const lhs, int const rhs);

  stat_t(stat_t const&) = default;
  stat_t(stat_t&&) = default;
  stat_t& operator=(stat_t const&) = default;
  stat_t& operator=(stat_t&&) = default;

  stat_t(stat_t<!IsAtomic> const&);
  stat_t(stat_t<!IsAtomic>&&);
  stat_t& operator=(stat_t<!IsAtomic> const&);
  stat_t& operator=(stat_t<!IsAtomic>&&);

  template<bool IsAtomicRhs>
  stat_t& operator+=(stat_t<IsAtomicRhs> const& rhs);
  template<bool IsAtomicRhs>
  stat_t& operator-=(stat_t<IsAtomicRhs> const& rhs);

  void reset();
  stat_t<false> fetch();

  typename std::conditional<IsAtomic, std::atomic<int>, int>::type
  hit, cnt;
};

template<bool IsAtomic>
stat_t<IsAtomic>::stat_t() : hit(0), cnt(0) {
}

template<bool IsAtomic>
stat_t<IsAtomic>::stat_t(int const lhs, int const rhs) : hit(lhs), cnt(rhs) {
}

template<bool IsAtomic>
stat_t<IsAtomic>::stat_t(stat_t<!IsAtomic> const& rhs) : hit(rhs.hit),
                                                         cnt(rhs.cnt) {
}

template<bool IsAtomic>
stat_t<IsAtomic>::stat_t(stat_t<!IsAtomic>&& rhs) :
    hit(std::move(rhs.hit)),
    cnt(std::move(rhs.cnt)) {
}

template<bool IsAtomic>
stat_t<IsAtomic>&
stat_t<IsAtomic>::operator=(stat_t<!IsAtomic> const& rhs) {
  return {rhs.hit, rhs.cnt};
}

template<bool IsAtomic>
stat_t<IsAtomic>&
stat_t<IsAtomic>::operator=(stat_t<!IsAtomic>&& rhs) {
  return {rhs.hit, rhs.cnt};
}

template<bool IsAtomic>
template<bool IsAtomicRhs>
stat_t<IsAtomic>&
stat_t<IsAtomic>::operator+=(stat_t<IsAtomicRhs> const& rhs) {
  hit += rhs.hit;
  cnt += rhs.cnt;
  return *this;
}

template stat_t<false>& stat_t<false>::operator+=(stat_t<false> const& rhs);
template stat_t<true>& stat_t<true>::operator+=(stat_t<true> const& rhs);
template stat_t<false>& stat_t<false>::operator+=(stat_t<true> const& rhs);
template stat_t<true>& stat_t<true>::operator+=(stat_t<false> const& rhs);

template<bool IsAtomic>
template<bool IsAtomicRhs>
stat_t<IsAtomic>&
stat_t<IsAtomic>::operator-=(stat_t<IsAtomicRhs> const& rhs) {
  hit -= rhs.hit;
  cnt -= rhs.cnt;
  return *this;
}

template stat_t<false>& stat_t<false>::operator-=(stat_t<false> const& rhs);
template stat_t<true>& stat_t<true>::operator-=(stat_t<true> const& rhs);
template stat_t<false>& stat_t<false>::operator-=(stat_t<true> const& rhs);
template stat_t<true>& stat_t<true>::operator-=(stat_t<false> const& rhs);

template<bool IsAtomic>
void stat_t<IsAtomic>::reset() {
  hit = 0;
  cnt = 0;
}

template<bool IsAtomic>
stat_t<false> stat_t<IsAtomic>::fetch() {
  return {hit, cnt};
}

int main() {
  stat_t<false> stat;
  stat_t<true> atomic_stat;
  stat.reset();
  atomic_stat.reset();
  atomic_stat.fetch();
  stat_t<false> snapshot = atomic_stat;
  atomic_stat.reset();
  snapshot.fetch();
  snapshot += stat;
  snapshot += atomic_stat;
  return 0;
}

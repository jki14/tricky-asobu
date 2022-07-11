#include <iostream>
#include <map>
#include <string>

static constexpr char const* powers[] = {
  "0000FF",
  "FF0000",
  "FF8040",
  "FFFF00",
  "FFF569",
  "808080",
  "00D1FF",
  "80528C",
  "4D85E6",
  "F2E699",
  "0080FF",
  "6600CC",
  "B5FFEB",
  "1A1AFA",
  "C942FD",
  "FF9C00",
  "CC9900",
  "008C80",
  "85FF85",
  "FFFAB8",
  "FF6B6B"
};

static constexpr int bar = 16777215;

int main() {
  static constexpr int m = sizeof(powers) / sizeof(powers[0]);
  std::map<double, std::string> foo;
  for (int i = 0; i < m; ++i) {
    int num;
    sscanf(powers[i], "%X", &num);
    foo.emplace(std::piecewise_construct,
                std::make_tuple(num * 1.0 / bar),
                std::make_tuple(powers[i]));
  }
  for (auto const& entry : foo) {
    std::cout << entry.second << std::endl;
  }
  std::cout << "------\n";
  static constexpr int n = 12;
  for (int i = 1; i <= n; ++i) {
    double k = i * 1.0 / n;
    auto it = foo.lower_bound(k);
    if (it == foo.end()) --it;
    if (it != foo.begin()) {
      auto jt = it;
      --jt;
      if (it->first - k > k - jt->first) {
        it = jt;
      }
    }
    std::cout << it->second << std::endl;
  }
  return 0;
}

#include <iostream>
#include <random>
#include <string>

class demo_t {
public:
  demo_t() : str(config_const_value_emptystr_for_null()) {
    std::cout << "str: " << str << std::endl;
  }

private:
  static char const* config_const_value_emptystr_for_null() {
    static char const* const emptystr = "";

    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(0, 1);
    char const* const const_value  = dist(gen) ? "gacha" : nullptr;

    return const_value ? const_value : emptystr;
  }

  std::string str;
};

int main() {
  for (int i = 0; i < 16; ++i) {
    demo_t demo;
  }
  return 0;
}

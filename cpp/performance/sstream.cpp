#include <string>
#include <sstream>

int main() {
  std::string const foo("#include <string> #include <sstream> int main() { "
                        "std::string const foo(""); for (int i = 0; i < "
                        "1000000; ++i) { std::stringstream bar; bar << foo;"
                        "bar.str(); } return 0; }");
  for (int i = 0; i < 10000000; ++i) {
    std::stringstream const bar(foo);
    bar.str();
  }
  return 0;
}

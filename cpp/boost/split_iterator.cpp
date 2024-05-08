#include <iostream>
#include <string>

#include <boost/algorithm/string.hpp>

int main() {
    static std::string const foo = "asobu tricky demo";
    using string_split_sentinel = boost::split_iterator<std::string::const_iterator>;
    for (auto it = boost::make_split_iterator(foo, boost::first_finder(" ")); it != string_split_sentinel(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}

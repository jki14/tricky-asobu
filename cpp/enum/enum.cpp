#include "bits/stdc++.h"

class Card {
    public:
        enum CardType {
            kPike_ = 0,
            kHeart_,
            kClover_,
            kTiles_
        };
};

enum Alphabet {
    a = 1,
    b,
    c = 2,
    d,
    e
};

int main() {
    Alphabet alphabet = d;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << alphabet << std::endl;
    std::cout << Card::kHeart_ << std::endl;
    return 0;
}

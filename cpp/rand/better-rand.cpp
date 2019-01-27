#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>

long long nogaps_rand(const long long min, const long long max) {
    assert(min <= max);
    long long range = max - min + 1LL;

    if (range <= RAND_MAX + 1LL) {
        long long scale = (RAND_MAX + 1LL) / range;
        long long scaledRange = scale * range;
        while (true) {
            long long r = rand();
            if (r < scaledRange) return r / scale + min;
        }
    }

    long long RAND_MAX_2 = (RAND_MAX + 1LL) * (RAND_MAX + 1LL) - 1LL;

    if (range <= RAND_MAX_2 + 1LL) {
        long long scale = (RAND_MAX_2 + 1LL) / range;
        long long scaledRange = scale * range;
        while (true) {
            long long r = rand() * (RAND_MAX + 1LL) + rand();
            if (r < scaledRange) return r / scale + min;
        }
    }

    return -1;
}

int main(){
    srand(time(NULL));
    int min, max;
    std::cin>>min>>max;
    for (int i = 0; i < 32; i ++) {
        std::cout<<nogaps_rand(min, max)<<std::endl;
    }
    return 0;
}
